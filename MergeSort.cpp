#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

int* RandomArray(int n) { // to generate Random Array
    int* arr = new int[n];
    srand(time(nullptr));

    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;// to Generate random numbers between 0 and 99
    }

    return arr;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void ascendingInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

void bestCase(int arr[], int n) {
    int* sortedArr = new int[n];
    copy(arr, arr + n, sortedArr);
    ascendingInsertionSort(sortedArr, n);
    clock_t start, end;
    double duration;

    start = clock();
    mergeSort(sortedArr, 0, n - 1);
    end = clock();

    duration = ((double)end - start) / CLOCKS_PER_SEC * 1000000; // Convert duration to microseconds
    cout << "Best case in Microsecond "  << ": " << duration << endl;

    delete[] sortedArr;
}

void descendingInsertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
    }
}

void worstCase(int arr[], int n) {
    int* sortedArr = new int[n];
    copy(arr, arr + n, sortedArr);

    clock_t start, end;
    double duration;

    descendingInsertionSort(sortedArr, n);
    start = clock();
    mergeSort(sortedArr, 0, n - 1);
    end = clock();

    duration = ((double)end - start) / CLOCKS_PER_SEC * 1000000; // Convert duration to microseconds
    cout << "Worst case in Microseconds "<<": " << duration << endl;

    delete[] sortedArr;
}

void averageCase(int arr[], int n) {
    int* sortedArr = new int[n];
    copy(arr, arr + n, sortedArr);

    clock_t start, end;
    double duration;
    start = clock();
    mergeSort(sortedArr, 0, n - 1);
    end = clock();

    duration = ((double)end - start) / CLOCKS_PER_SEC * 1000000; // Convert duration to microseconds
    cout << "worst Case in Microseconds "<< duration << endl;

    delete[] sortedArr;
}

int main() {
    const int inputSizes[] = {200,400,600,800,1000};
    const int numInputSizes = sizeof(inputSizes) / sizeof(inputSizes[0]);

    for (int i = 0; i < numInputSizes; ++i) {
        int n = inputSizes[i];
        int* arr =RandomArray(n);

        cout << "==========================" << endl;
        cout << "Input Size: " << n << endl;
       
        bestCase(arr, n);
        worstCase(arr, n);
        averageCase(arr, n);

        delete[] arr;

        cout << "\n\n";
    }

    return 0;
}


