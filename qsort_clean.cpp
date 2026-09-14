#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DATA_FILE "DATA.txt"
#define CORRECTION_CANARY 1

void quick_sort (int* data, int num_array);
void swap (int* one, int* two);
int compare_up (const void* one, const void* two);

int main ()
{
    FILE* data_elem = NULL;
    int num_array = 0;
    int* data = NULL;

    if ((data_elem = fopen (DATA_FILE, "r")) == NULL)
    {
        printf ("\e[31m" "Your file doesn't open\n" "\e[0m");
        return -1;
    }
    fscanf (data_elem, "%d", &num_array);

    if ((data = (int *)calloc (num_array, sizeof(int))) == NULL)
    {
        printf ("\e[31m" "calloc doesn't work\n" "\e[0m");
        return -1;
    }

    for (int i = 0; i < num_array; i++)
    {
        fscanf (data_elem, "%d", &data [i]);
        printf ("%d ", data[i]);
    }
    printf ("\n");

    quick_sort (data, num_array);

    for (int i = 0; i < num_array; i++)
    {
        printf ("%d ", data[i]);
    }
    printf ("\n");

    if (fclose (data_elem) != 0)
    {
        printf ("\e[32m" "Warning! The file was not closed correctly!\n" "\e[0m");
        return -1;
    }

    free (data);

    return 0;
}

void quick_sort (int* data, int num_array)      //void* data, int num_array, size_t size, int (*func_compare)(const void* one, const void* two)
{
    assert (data);

    if (num_array < 1) return;

    int low = 0, high = 0;
    int pivot = num_array - 1;

        while (high < num_array - 1)
        {
            if (data[high] < data[pivot])
            {
                swap (&data[high], &data[low]);
                low++;
            }
            high++;
        }

        swap (&data[low], &data[pivot]);

        quick_sort (data, low);
        quick_sort (data + low + 1, num_array - (low + 1));
    return;
}

void swap (int* one, int* two)  //void* big, void* small
{
    assert (one);
    assert (two);

    int temp = *one;
    *one = *two;
    *two = temp;
    }
