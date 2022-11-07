#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(long[], long, int);
void heap_sort(long[], long);
void display(long[], long);

clock_t start, end;
double cpu_time_used;
int tot_comp, tot_step;

void main()
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
        // display(array, n);

        // start timer
        start = clock() * CLK_TCK;

        heap_sort(array, n);

        // printf("\n\nAFTER SORTING:\n\n");

        // // Sorted list
        // display(array, n);

        // stop timer
        end = clock() * CLK_TCK;
        elapseMsec = end / 1000;
        cpu_time_used = elapseMsec / 1000;

        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n += 5000;
    }
}

void heap_sort(long heap[], long no)
{

    int temp;

    // Build max heap
    for (int i = no / 2 - 1; i >= 0; i--)
    {
        heapify(heap, no, i);
    }

    // Heap sort
    for (int i = no - 1; i >= 0; i--)
    {
        temp = heap[0];
        tot_step++;

        heap[0] = heap[i];
        tot_step++;

        heap[i] = temp;
        tot_step++;

        // Heapify root element to get highest element at root again
        heapify(heap, i, 0);
    }
}

void heapify(long heap[], long n, int i)
{
    int temp;
    tot_comp++;

    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i)
    {
        temp = heap[i];
        tot_step++;

        heap[i] = heap[largest];
        tot_step++;

        heap[largest] = temp;
        tot_step++;

        // Recursively heapify the affected sub-tree
        heapify(heap, n, largest);
    }
}

void display(long heap[], long no)
{
    for (int i = 0; i < no; i++)
    {
        printf("%d\t", heap[i]);
    }

    printf("\n");
}
