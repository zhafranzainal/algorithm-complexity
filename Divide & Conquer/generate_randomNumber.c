#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int displayRandomNum, loop;

    FILE *randomNumberList;

    //write to file
    randomNumberList = fopen("listOfRandomNum.txt", "w");

    srand(time(NULL));

    for(loop=0;loop<20000;loop++){
        fprintf(randomNumberList, "%d\n", rand()%33000);}

    fclose(randomNumberList);

    //read from file
    randomNumberList = fopen("listOfRandomNum.txt", "r");

    while(1){

        displayRandomNum = fgetc(randomNumberList);

        if(feof(randomNumberList)){
            break;}

        printf("%c", displayRandomNum);

    }

    fclose(randomNumberList);

return 0;
}
