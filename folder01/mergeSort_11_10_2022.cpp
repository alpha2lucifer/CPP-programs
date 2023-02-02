#include <iostream>
using namespace std;
void merge(int a[], int b, int c, int e) {
    int i, j, k;
    int n1 = c - b + 1;
    int n2 = e - c;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
    LeftArray[i] = a[b + i];
    for (int j = 0; j < n2; j++)
    RightArray[j] = a[c + 1 + j];
    i = 0;
    j = 0;
    k = b;
    while (i < n1 && j < n2) {
        if(LeftArray[i] <= RightArray[j]) {
            a[k] = LeftArray[i];
            i++;
        }
        else {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j<n2) {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int b, int e) {
    if (b < e) {
        int c = (b + e) / 2;
        mergeSort(a, b, c);
        mergeSort(a, c + 1, e);
        merge(a, b, c, e);
    }
}
void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}
int main() {
    int a[] = { 11, 30, 24, 7, 31, 16, 39, 41 };
    int n = sizeof(a) / sizeof(a[0]);
    cout<<"Before sorting array elements are - \n";
    printArray(a, n);
    mergeSort(a, 0, n - 1);
    cout<<"\nAfter sorting array elements are - \n";
    printArray(a, n);
    return 0;
}