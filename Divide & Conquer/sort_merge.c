#include <stdio.h>
#include <time.h>

#define MAX 100000

//Function Declaration (Prototype)
void sort_merge(int randomNum[], int first, int last);
void mergeList(int randomNum[], int first, int middle, int last);
clock_t timer_begin();
clock_t timer_end(clock_t timeBegin);

int totalCompare=0, totalMove=0;

int main(void){

    double timeBegin;
    int loop, totalNum=0, randomNum[MAX];
    float elapseTicks, elapseMsec, elapseSec;

    printf("BEFORE SORTING:\n\n");

    FILE *randomNumberList;

    //read from file
    randomNumberList = fopen("listOfRandomNum.txt", "r");

    while(fscanf(randomNumberList, "%d", &randomNum[totalNum])!=EOF){
        printf("%d\t", randomNum[totalNum]);
        totalNum++;}

    fclose(randomNumberList);

    printf("\n\nTimer set to: %.2f", timeBegin);
    timeBegin = timer_begin();

    sort_merge(randomNum, 0, totalNum-1);

    printf("\n\nAFTER SORTING (merge sort):\n\n");

    for(loop=0;loop<totalNum;loop++){
        printf("%d\t", randomNum[loop]);}

    printf("\n\nNumber of data compares = %d", totalCompare);
    printf("\nNumber of data moves    = %d", totalMove);

    elapseTicks = timer_end(timeBegin);
    elapseMsec = elapseTicks/1000;
    elapseSec = elapseMsec/1000;

    printf("\n\nRunning time (in milliseconds)  = %.2f", elapseMsec);
    printf("\nRunning time (in seconds)       = %.2f", elapseSec);

    printf("\n");

return 0;
}

//Function Definition: sort_merge
void sort_merge(int randomNum[], int first, int last){

    int middle;

    if(first<last){
        middle=(first+last)/2;
        sort_merge(randomNum, first, middle);
        sort_merge(randomNum, middle+1, last);
        mergeList(randomNum, first, middle, last);}

}

//Function Definition: mergeList
void mergeList(int randomNum[], int first, int middle, int last){

    int loop, left, right, count, temp[MAX];

    left=first;
    count=first;
    right=middle+1;

    while((left<=middle) && (right<=last)){

        if(randomNum[left]<=randomNum[right]){
            temp[count]=randomNum[left];
            left++;}

        else{
            temp[count]=randomNum[right];
            right++;}

        count++;
    }

    if(left>middle){

        for(loop=right;loop<=last;loop++){
            temp[count]=randomNum[loop];
            count++;}
    }

    else{

        for(loop=left;loop<=middle;loop++){
            temp[count]=randomNum[loop];
            count++;}
    }

    for(loop=first;loop<=last;loop++){
        randomNum[loop]=temp[loop];}

}

//Function Definition: timer_begin
clock_t timer_begin(){

    clock_t Begin;

    //start timer
    Begin=clock()*CLK_TCK;

    return Begin;
}

//Function Definition: timer_end
clock_t timer_end(clock_t timeBegin){

    clock_t End;

    //stop timer
    End=clock()*CLK_TCK;

    return End;
}
