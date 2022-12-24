#include <stdio.h>
#include <stdlib.h>

#define LENGTH 50
#define COUNTRY 10
#define CASE_COLUMN 4

//Function Declaration (Prototype)
void sort_quick(int **matrix, int bottom, int top, int column);
int partition(int **matrix, int left, int right, int column);
void swap(int *data1, int *data2);
void print_matrix(int **matrix, int rows, int cols);

int main(void){

    int casesOrigin[COUNTRY][CASE_COLUMN]=
        {{0, 739803, 35107459, 9702580},
        {0, 451509, 33362709, 208787},
        {0, 601643, 20740267, 256039},
        {0, 138080, 6765629, 1369174},
        {0, 220315, 6937756, 734909},
        {0, 66841, 6987778, 485604},
        {0, 117173, 6860549, 91367},
        {0, 123498, 5280624, 349925},
        {0, 115582, 5135343, 17728},
        {0, 86869, 4823235, 70102}};

    for(int loop=0;loop<COUNTRY;loop++){
        casesOrigin[loop][0]=casesOrigin[loop][1]+casesOrigin[loop][2]+casesOrigin[loop][3];}

    int loopRow, loopColumn, rows=10, cols=4;
    int **matrix=malloc(sizeof(int*) *rows);

    // Init of a 2D array with random numbers:
    for(loopRow=0;loopRow<rows;loopRow++){

        matrix[loopRow]=malloc(sizeof(int) *cols);

        for (loopColumn=0;loopColumn<cols;loopColumn++){
            matrix[loopRow][loopColumn]=casesOrigin[loopRow][loopColumn];}

    }

    //Before:
    printf("BEFORE SORTING:");
    print_matrix(matrix, rows, cols);

    //After:
    sort_quick(matrix, 0, rows*cols-1, cols);

    printf("\nAFTER SORTING (quick sort):");
    print_matrix(matrix, rows, cols);

return 0;
}

//Function Definition: sort_quick
void sort_quick(int **matrix, int bottom, int top, int column){

    int pivot;

    if(top>bottom){
        pivot=partition(matrix, bottom, top, column);
        sort_quick(matrix, bottom, pivot-1, column);
        sort_quick(matrix, pivot+1, top, column);}

}

//Function Definition: partition
int partition(int **matrix, int left, int right, int column){

    int loop;

    // Left pivot
    int pivot_value=matrix[left/column][left%column];

    // Move pivot to end
    swap(&matrix[left/column][left%column], &matrix[right/column][right%column]);

    //If data <= to the pivot value, swap
    int data=left;

    for(loop=left;loop<right;loop++){

        if(matrix[loop/column][loop%column] <= pivot_value){
            swap(&matrix[loop/column][loop%column], &matrix[data/column][data%column]);
            data++;}

    }

    //Move pivot to its place
    swap(&matrix[data/column][data%column], &matrix[right/column][right%column]);

    return data;
}

//Function Definition: swap
void swap(int *data1, int *data2){

    int temp;

    temp=*data1;
    *data1=*data2;
    *data2=temp;
}

//Function Definition: print_matrix
void print_matrix(int **matrix, int rows, int cols){

    int loopRow, loopColumn;

    char country[][LENGTH]={"USA", "INDIA", "BRAZIL", "UK", "RUSSIA", "TURKEY", "FRANCE", "IRAN", "ARGENTINA", "SPAIN"};

    printf("\n\nCOUNTRY\t\t TOTAL_CASES\t TOTAL_DEATH\t TOTAL_RECOVERED\t ACTIVE_CASES\n");
    printf("=====================================================================================\n");

    for(loopRow=0;loopRow<rows;loopRow++){

        printf("%-16s ", country[loopRow]);

        for(loopColumn=0;loopColumn<cols;loopColumn++){
            printf("%-19d", matrix[loopRow][loopColumn]);}

        printf("\n");}

}
