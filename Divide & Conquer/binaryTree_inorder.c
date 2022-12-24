#include <stdio.h>
#include <stdlib.h>

//Structure Declaration (Template)
struct BinaryTree{

    //Data Field
    int number;

    //Pointer (Link) Field
    struct BinaryTree *left,*right;};

struct BinaryTree *ptrRoot, *ptrNew, *ptrCurrent, *ptrPrevious, *ptrTemp;

//Function Declaration (Prototype)
struct BinaryTree* search_node(struct BinaryTree *node, int number);
void insert_node(int number);
void traverse_inorder(struct BinaryTree *node);
void delete_node(int number);
struct BinaryTree* COPY(struct BinaryTree *node);

int main (){

    int element,choice;

    ptrRoot=NULL;

    while(choice!=0){

        printf("\n\n MENU ");
        printf("\n 0: Quit");
        printf("\n 1: Search");
        printf("\n 2: Insert a node");
        printf("\n 3: Display ascending");
        printf("\n 4: Delete by copying");
        printf("\n\n Enter your choice: ");
        scanf("\t%d", &choice);

        switch(choice){

            case 0: break;

            case 1: printf("\n SEARCH");

                    printf("\n Enter the searching number: ");
                    scanf(" %d", &element);

                    ptrTemp=search_node(ptrRoot, element);

                    if(ptrTemp!=NULL){
                        printf("\n The number %d is found", ptrTemp->number);}
                    else{
                        printf("\n The number %d is not found", element);}

                    break;

            case 2: printf("\n INSERT A NODE");

                    printf("\n Enter an integer number: ");
                    scanf(" %d", &element);

                    insert_node(element);
                    printf ("\n Insertion is successful");
                    break;

         	case 3: printf("\n DISPLAY NUMBER in ascending order \n\n");
                    traverse_inorder(ptrRoot);
                  	break;

         	case 4: printf ("\n DELETE BY COPY");

                    printf("\n Enter a number to delete: ");
                    scanf(" %d", &element);

                    delete_node(element);
                    break;

            default: printf("\n Please enter number only from the MENU");
        }
    }

return 0;
}

void insert_node(int number){

    ptrNew=(struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    ptrNew->left=NULL;
    ptrNew->right=NULL;
    ptrNew->number=number;

    ptrCurrent=ptrRoot;

    while(ptrCurrent!=NULL){

        ptrPrevious=ptrCurrent;

        if(number > ptrCurrent->number){
            ptrCurrent=ptrCurrent->right;}
        else{
            ptrCurrent=ptrCurrent->left;}

    }

    if(ptrRoot==NULL){
        ptrRoot=ptrNew;}
    else if(number > ptrPrevious->number){
        ptrPrevious->right=ptrNew;}
    else{
        ptrPrevious->left=ptrNew;}

}

void traverse_inorder(struct BinaryTree *node){

    if(node!=NULL){
        traverse_inorder(node->left);
        printf("\n -- %d",node->number);
        traverse_inorder(node->right);}

}

struct BinaryTree* search_node(struct BinaryTree *node, int number){

    if(node!=NULL){

        if(number==node->number){
            return node;}
        else if(number > node->number){
            return search_node(node->right, number);}
        else{
            return search_node(node->left, number);}

    }

    else{
        return NULL;}

}

void delete_node(int number){

    ptrCurrent = ptrRoot;

    while(ptrCurrent!=NULL){

        if(ptrCurrent->number == number){
            break;}

        ptrPrevious=ptrCurrent;

        if(number > ptrCurrent->number){
            ptrCurrent=ptrCurrent->right;}
        else{
            ptrCurrent=ptrCurrent->left;}

    }

    if(ptrCurrent==NULL){
        printf("\n Number %d is not in the tree!", number);
        return;}

    else if(ptrCurrent->number==number){

        if(ptrCurrent==ptrRoot){
            ptrRoot=COPY(ptrRoot);}
        else if(ptrPrevious->left==ptrCurrent){
            ptrPrevious->left=COPY(ptrPrevious->left);}
        else{
            ptrPrevious->right=COPY(ptrPrevious->right);}

    }

}

struct BinaryTree* COPY(struct BinaryTree *node){

    struct BinaryTree *ptrPrevious2;

    ptrTemp=node;

    if(node->right==NULL){
        node=node->left;}

    else if(node->left==NULL){
        node=node->right;}

    else{

        ptrTemp = node->left;
        ptrPrevious2=node;

        while(ptrTemp->right!=NULL){
            ptrPrevious2=ptrTemp;
            ptrTemp=ptrTemp->right;}

        node->number=ptrTemp->number;//copy the element to node

        if(ptrPrevious2==node){
            ptrPrevious2->left=ptrTemp->left;}
        else{
            ptrPrevious2->right=ptrTemp->left;}

    }

    free(ptrTemp);
    return node;
}
