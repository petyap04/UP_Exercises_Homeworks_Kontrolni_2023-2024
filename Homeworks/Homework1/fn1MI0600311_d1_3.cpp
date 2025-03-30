/**

*

* Solution to homework assignment 1

* Introduction to programming course

* Faculty of Mathematics and Informatics of Sofia University

* Winter semester 2023/2024

*

* @author Petya Petrova

* @idnumber 1MI0600311

* @task 3

*

*/
#include <iostream>
using namespace std;
constexpr int SIZE = 256;
void printArray(const char arr[], size_t size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
void readArray(char arr[], size_t size) {
    for (unsigned int i = 0; i < size; i++) {
        char a;
        cin >> a;
        arr[i] = a;
    }
}
void removeAnElementsFromArray(char arr[], size_t& size, unsigned int count, unsigned int indexGoingLeft, unsigned int indexGoingRight) {

    indexGoingRight += 1;
    for (unsigned int i = indexGoingLeft; indexGoingRight < size; i++, indexGoingRight++) {
        arr[i] = arr[indexGoingRight];
    }
    size -= count;
}
bool checkIfThereIsRowBiggerThanThree(char arr[], size_t& size, unsigned int count, unsigned int indexGoingLeft,
    unsigned int indexGoingRight) {
    if (count >= 3) {
        removeAnElementsFromArray(arr, size, count, indexGoingLeft, indexGoingRight);
        return 1;
    }
    return 0;
}
void countOfSymbol(char arr[], size_t size, unsigned int& count, int index, int& indexLeft, int& indexRight) {
    char symbol = arr[index];

    count = 1;
    indexLeft = index;
    while (indexLeft != 0 && arr[indexLeft - 1] == arr[indexLeft])
    {
        indexLeft--;
        count++;
    }
    indexRight = index;
    while (indexRight != size - 1 && arr[indexRight + 1] == arr[indexRight])
    {
        indexRight++;
        count++;
    }
}

void checkForARow(char arr[], size_t& size, unsigned int index) {
    bool thereIsRowBiggerThanThree = false;
    do {
        int indexRight = index;
        int indexLeft = index;
        unsigned int count = 0;
        countOfSymbol(arr, size, count, index, indexLeft, indexRight);
        if (size == 0) break;

        thereIsRowBiggerThanThree = checkIfThereIsRowBiggerThanThree(arr, size, count, indexLeft, indexRight);
        index = indexLeft;
        if (indexLeft > 0 && arr[indexLeft] != arr[indexLeft - 1]) break;
    } while (thereIsRowBiggerThanThree);
}
void addingAnElementToTheArray(char arr[], size_t& size, unsigned int index, char colour) {
    arr[size] = colour;
    for (unsigned int i = size - 1; i > index; i--) {
        char temp = arr[i + 1];
        arr[i + 1] = arr[i];
        arr[i] = temp;
    }
    checkForARow(arr, size, index + 1);
}
void shoot(char arr[], size_t& size, unsigned int shoots) {
    unsigned int index;
    char colour;
    while (shoots != 0) {
        cin >> index >> colour;
        if (index <= size && size != 0) {
            size++;
            addingAnElementToTheArray(arr, size, index, colour);
        }
        shoots--;
    }
}

int main()
{
    size_t numberOfBalls;
    cin >> numberOfBalls;
    char arr[SIZE];
    readArray(arr, numberOfBalls);
    unsigned int shoots;
    cin >> shoots;
    shoot(arr, numberOfBalls, shoots);
    if (numberOfBalls == 0)
        cout << -1;
    else
        printArray(arr, numberOfBalls);
}
