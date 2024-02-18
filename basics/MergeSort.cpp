#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[size];

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        merge(arr, l, m, r, size);
    }
}

int main()
{
    int exampleArray[] = {1, 20, 332, 1, 2, 100, 14, 37, 99, 15, 1};
    int size = sizeof(exampleArray) / sizeof(exampleArray[0]);

    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << exampleArray[i] << " ";
    }
    cout << endl;

    mergeSort(exampleArray, 0, (size - 1), size);

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << exampleArray[i] << " ";
    }

    return 0;
}