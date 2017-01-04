#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN(a) (sizeof(a) / sizeof(a[0]))
#define PRINTARRAY(a) do {                                       \
                        for (int i = 0; i < (int) LEN(a); i++) { \
                            printf("%d ", a[i]);                 \
                        }                                        \
                        printf("\n");                            \
                      } while (0);

void quicksort(int *array, int left, int right)
{
    if (left <= right) {
        int mid = left + (right - left) / 2;
        int pivot = array[mid];
        int i = left, j = right;

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
            }

            while (array[j] > pivot) {
                j--;
            }

            if (i <= j) {
                int tmp = array[i];

                array[i] = array[j];
                array[j] = tmp;

                i++;
                j--;
            }
        }
        
        if (i < right) {
            quicksort(array, i, right);
        }

        if (j > left) {
            quicksort(array, left, j);
        }
    }
}

int main()
{
    int array[100];

    /*
     * Decreasing sequential numbers
     */
    for (int i = 0; i < (int) LEN(array); i++) {
        array[i] = 100 - i;
    }
    quicksort(array, 0, LEN(array) - 1);
    PRINTARRAY(array);
    
    printf("\n");

    /*
     * Random numbers from 0 - 100
     */
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < (int) LEN(array); i++) {
        array[i] = rand() % 101;
    }
    quicksort(array, 0, LEN(array) - 1);
    PRINTARRAY(array);
    return 0;
}
