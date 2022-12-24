#include <iostream>
using namespace std;

void Merge(int arr[], int L, int mid, int R)
{
    int L_size = mid - L + 1;
    int R_size = R - mid;

    int* L_arr = new int[L_size];
    int* R_arr = new int[R_size];

    for (int i = 0; i < L_size; i++)
    {
        L_arr[i] = arr[L + i];
    }

    for (int j = 0; j < R_size; j++)
    {
        R_arr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = L;


    while (i < L_size && j < R_size)
    {
        if (L_arr[i] <= R_arr[j])
        {
            arr[k++] = L_arr[i++];      
        }
        else
        {
            arr[k++] = R_arr[j++];
        }
    }


    while (i < L_size)
    {
        arr[k++] = L_arr[i++];
    }

    while (j < R_size)
    {
        arr[k++] = R_arr[j++];
    }
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}


int main()
{
    int arr[] = { 4, 3, 6, 5, 2, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Display(arr, size);

    MergeSort(arr, 0, size - 1);
    cout << "Sorted array: \n";
    Display(arr, size);


    return 0;
}