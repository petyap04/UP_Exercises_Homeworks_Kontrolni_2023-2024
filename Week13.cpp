#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int* arr, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int curr = i;
        for (int j = 0; j < size - i; j++) {
            if (arr[j] < arr[i]) {
                curr = j;
            }
        }
        swap(arr[i], arr[curr]);
    }
}
