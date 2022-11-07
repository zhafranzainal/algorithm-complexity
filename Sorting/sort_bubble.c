#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(long[], long);

clock_t start, end;
double cpu_time_used;
int tot_comp, tot_step;

int main()
{
    int num = 1, n = 5000;
    long array[30000];
    float elapseMsec;

    for (int i = 1; i <= 6; i++)
    {
        srand(time(0));
        tot_comp = 0, tot_step = 0;

        for (int j = 0; j < n; j++)
        {
            array[j] = rand() % n;
        }

        // printf("\n\nBEFORE SORTING:\n\n");

        // // Unsorted list
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d\t", array[j]);
        // }

        // start timer
        start = clock() * CLK_TCK;

        bubble_sort(array, n);

        // printf("\n\nAFTER SORTING:\n\n");

        // // Sorted list
        // for (int j = 0; j < n; j++)
        // {
        //     printf("%d\t", array[j]);
        // }

        // stop timer
        end = clock() * CLK_TCK;
        elapseMsec = end / 1000;
        cpu_time_used = elapseMsec / 1000;

        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.2f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n += 5000;
    }

    return 0;
}

void bubble_sort(long list[], long n)
{
    int temp, loop;

    while (n > 1)
    {
        n--;

        for (loop = 0; loop < n; loop++)
        {
            tot_comp++;

            if (list[loop] > list[loop + 1])
            {
                temp = list[loop];
                tot_step++;
                list[loop] = list[loop + 1];
                tot_step++;
                list[loop + 1] = temp;
                tot_step++;
            }
        }
    }
}
