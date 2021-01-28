#include <iostream>

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

void countingSort(int* arr, int n) {
    int count[10] = {0};
    int output[10];
    int max = arr[0];

    for (int i = 1; i < n; ++i)  // 배열의 최대값을 찾는다, 최소값은 0이라 가정
        if (arr[i] > max) max = arr[i];

    for (int i = 0; i < n; ++i)  // 모든 원소의 갯수를 센다
        count[arr[i]]++;

    for (int i = 1; i <= max; ++i)  // 모든 원소 갯수의 누적합을 저장한다
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {  // 카운트 배열에서 원래 배열의 각 요소의 인덱스를 찾아서 output에 배치한다
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;  // output에 배치했으면 그만큼 감소
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int* arr, int size, int div) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixSort(int* arr, int size) {
    int m = getMax(arr, size);
    for (int div = 1; m / div > 0; div *= 10)
        countingSort(arr, size, div);
}

int main() {
    // int arr[] = {1, 3, 2, 5, 4, 7, 5, 0};
    int arr[] = {487, 519, 403, 274, 115, 24, 987, 315};
    // bubbleSort(arr, 8);
    // selectionSort(arr, 8);
    // insertionSort(arr, 8);
    // mergeSort(arr, 0, 8);
    // quickSort(arr, 0, 8);
    // heapSort(arr, 8);
    // countingSort(arr, 8);
    radixSort(arr, 8);

    for (int i : arr) {
        cout << i << ' ';
    }
    return 0;
}