#include <stdio.h>
#include <time.h>

//Function Declaration (Prototype)
void sort_quick(int randomNum[], int bottom, int top);
clock_t timer_begin();
clock_t timer_end(clock_t timeBegin);

int totalCompare=0, totalMove=0;

int main(void){

    double timeBegin;
    int loop, totalNum=0, randomNum[100000];
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

    sort_quick(randomNum, 0, totalNum-1);

    printf("\n\nAFTER SORTING (quick sort):\n\n");

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

//Function Definition: sort_quick
void sort_quick(int randomNum[], int bottom, int top){

    int left, right, temp, pivot, flag;

    if(top>bottom){
        pivot=randomNum[top];
        right=top;
        left=bottom-1;

        do{
            flag=1;
            while(randomNum[++left]<pivot);
            while(randomNum[--right]>pivot);

            if(left<right){
                temp=randomNum[left];
                randomNum[left]=randomNum[right];
                randomNum[right]=temp;}

            else{
                break;}

        }while(flag>0);

        temp=randomNum[left];
        randomNum[left]=randomNum[top];
        randomNum[top]=temp;

        sort_quick(randomNum, bottom, left-1);
        sort_quick(randomNum, left+1, top);

    }

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
