#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 전체에서 가장 작은 값을 찾아서 맨 첫번째 자리로 옮기는 것을 반복함
void bubbleSort(int* data, int n) {
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void selectionSort(int* arr, int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; ++i) {  // 0~n-2 까지 순회
        min_idx = i;
        for (j = i + 1; j < n; ++j) {  // i+1부터 n-1까지 비교할 값을 고른다
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

void insertionSort(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; ++i) {
        key = arr[i];  // 기존의 정렬된 리스트에 끼워 넣을 key를 선택
        j = i - 1;
        while (j >= 0 && arr[j] > key) {  // 기존의 정렬된 리스트에서 key값보다 작은 값이 나올 때까지
            arr[j + 1] = arr[j];          // 앞으로 한칸씩 당긴다
            j--;
        }
        arr[j + 1] = key;  // 정렬된 리스트에서 key값보다 작은 값 바로 앞에 key값을 넣는다
    }
}

void merge(int* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int* arr, int n, int i) {  // heap size, 노드 번호
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])  // left child가 root보다 크면
        largest = l;
    if (r < n && arr[r] > arr[largest])  // right child가 root보다 크면
        largest = r;

    if (largest != i) {  // largest가 root가 아니면
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)  // 힙 구조에 따라 배열 재배치
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {  // 힙에서 1개씩 extract
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {1, 3, 2, 5, 4, 7, 5, 0};
    // bubbleSort(arr, 8);
    // selectionSort(arr, 8);
    // insertionSort(arr, 8);
    // mergeSort(arr, 0, 8);
    // quickSort(arr, 0, 8);
    heapSort(arr, 8);

    for (int i : arr) {
        cout << i << ' ';
    }
    return 0;
}