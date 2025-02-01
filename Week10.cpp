#include <iostream>
using namespace std;


void myStrcpy(const char* income, char* outcome) {
    if (!income) {
        return;
    }
    while (*income) {
        *outcome = *income;
        income++;
        outcome++;
    }
    *outcome = '\0';
}

unsigned myStrlen(const char* str) {
    if (!str) {
        return 0;
    }
    unsigned count = 0;
    while (*str) {
        count++;
        str++;
    }
    return count;
}

int myStrcmp(const char* str1, const char* str2) {
    if (!str1 || !str2) {
        return 0;
    }
    while (*str1 && *str2 && *str1==*str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

void myStrcat(char* str1, const char* str2) {
    unsigned len = myStrlen(str1);
    str1 += len;
    myStrcpy(str2, str1);
}
void generateSubsetByMask(const int arr[], size_t size, unsigned mask) {
    for (int i = 0; i < size; i++) {
        if (mask % 2 == 1) {
            cout << arr[i] << " ";
        }
        mask /= 2;
    }
    cout << endl;
}
void generateSubsets(const int arr[], size_t size) {
    unsigned countOfSubsets = (1 << size);
    for (int i = 0; i < countOfSubsets; i++) {
        generateSubsetByMask(arr, size, i);
    }
}

//Напишете функция, която приема масив от цели числа и цяло число и елемент на масива. 
//Функцията да преподрежда елементите, така че всички по-малки елементи от подадения да са в ляво от него, а всички по-големи - в дясно. 


void sortByNumber(int arr[], size_t size, int number) {
    int* newArr = new int[size];
    unsigned begin = 0;
    unsigned end = size - 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > number) {
            newArr[end] = arr[i];
            end--;
        }
        else {
            newArr[begin] = arr[i];
            begin++;
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = newArr[i];
    }
    delete[]newArr;
}


char* censoreNumbers(const char* arr) {
    char* result = new char[myStrlen(arr)];
    unsigned i = 0;
    while (*arr) {
        if (*arr > '0' && *arr < '9') {
            result[i] = '*';
        }
        else {
            result[i] = *arr;
        }
        arr++;
        i++;
    }
    return result;
}

