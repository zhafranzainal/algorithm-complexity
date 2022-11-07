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

    for (int i = 1; i <= 6; i++)
    {
        srand(time(0));
        tot_comp = 0, tot_step = 0;

        for (int j = 0; j < n; j++)
        {
            array[j] = rand() % n;
        }

        bubble_sort(array, n);

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
}
