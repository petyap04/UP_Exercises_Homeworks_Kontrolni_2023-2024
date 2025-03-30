/**

*

* Solution to homework assignment 1

* Introduction to programming course

* Faculty of Mathematics and Informatics of Sofia University

* Winter semester 2023/2024

*

* @author Petya Petrova

* @idnumber 1MI0600311

* @task 2

*

*/
#include <iostream>
using namespace std;
constexpr int SIZE = 1000;
bool validationOfN(unsigned int n) {
    if (n < 1 || n > 1000) {
        cout << "Incorrect input";
        return 0;
    }
    return 1;
}
void readArray(int arr[], size_t size) {
    for (unsigned int i = 0; i < size; i++) {
        unsigned int a;
        cin >> a;
        arr[i] = a;
    }
}
int countOfNumber(int arr[], size_t size, int& numberCounted, int position) {
    int count = 0;
    while (position < size) {
        if (arr[position] == numberCounted) {
            count++;
            arr[position] = -1;
        }
        position++;

    }
    return count;
}
void groupingOfNumbers(int arr[], size_t size, int& minPeople, int position) {
    if (arr[position] != -1) {
        int groups = 0;
        int numberCounted = arr[position];
        int count = countOfNumber(arr, size, numberCounted, position);
        groups = count / (numberCounted + 1);
        if (count % (numberCounted + 1) != 0) {
            groups++;
        }
        minPeople += groups * (numberCounted + 1);
    }
}

int minNumberOfPeopleInUpland(int arr[], size_t size) {
    int minPeople = 0;
    for (int i = 0; i < size; i++) {
        groupingOfNumbers(arr, size, minPeople, i);
    }
    return minPeople;
}

int main()
{
    unsigned int n;
    cin >> n;
    if (validationOfN(n)) {
        int arr[SIZE];
        readArray(arr, n);
        cout << minNumberOfPeopleInUpland(arr, n);
    }
}
