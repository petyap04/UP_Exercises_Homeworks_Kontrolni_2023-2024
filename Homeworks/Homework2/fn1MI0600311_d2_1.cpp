/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Petya Petrova
* @idnumber 1MI0600311
* @task 1
*
*/
#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 65;
void printSymbols(char firstSymbol, char secondSymbol) {
    cout << firstSymbol << secondSymbol;
}
int symbolToIndex(char symbol) {
    if (symbol >= '!' || symbol <= 'Z') {
        return symbol - '!' + 33;
    }
    return -1;
}
bool checkBit(unsigned int n, unsigned ind)
{
    unsigned int mask = 1;
    mask <<= ind;
    return (mask & n) == mask;
}
void makeBitOne(int& number, unsigned int ind){
    unsigned int mask = 1;
    mask <<= ind;

    number = number | mask;
}
void fillingNumbers(const int indexOfSymbol, int& index ,int& newNumber) {
    int indexOfNumber = 7;
    while (indexOfNumber > 0) {
        if (checkBit(indexOfSymbol, index)) {
            makeBitOne(newNumber, indexOfNumber);
        }
        else {
            makeBitOne(newNumber, indexOfNumber - 1);
        }
        indexOfNumber -= 2;
        index--;
    }
}

void codedSymbol(int indexOfSymbol) {
    int indexOfFirstSymbol = 0;
    int indexOfSecondSymbol = 0;
    int index = 7;
    fillingNumbers(indexOfSymbol, index, indexOfFirstSymbol);
    fillingNumbers(indexOfSymbol, index, indexOfSecondSymbol);
    char firstSymbol = indexOfFirstSymbol;
    char secondSymbol = indexOfSecondSymbol;
    printSymbols(firstSymbol, secondSymbol);
}

void codedStr(const char* str) {
    if (!str) {
        return;
    }
    while (*str) {
        int indexOfSymbol = symbolToIndex(*str);
        codedSymbol(indexOfSymbol);
        str++;
    }
}
int main()
{
    char str[MAX_SIZE] = "abc";
    codedStr(str);
}