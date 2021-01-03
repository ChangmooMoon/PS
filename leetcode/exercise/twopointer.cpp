#include <iostream>
using namespace std;

int isPairSum(int A[], int N, int X) {
    int i = 0;
    int j = N - 1;

    while (i < j) {
        if (A[i] + A[j] == X)
            return 1;
        else if (A[i] + A[j] < X)
            i++;
        else
            j--;
    }
    return 0;
}

int main() {
    int arr[] = {10, 20, 35, 50, 75, 80};
    int val = 70;
    int arrSize = *(&arr + 1) - arr;
    cout << isPairSum(arr, arrSize, val) << endl;
    return 0;
}