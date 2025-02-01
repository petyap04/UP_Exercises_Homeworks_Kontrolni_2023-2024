#include <iostream>
using namespace std;

void countOfTheSameDigit(int i, unsigned int number, int& count) {
    while (number != 0) {
        if (i == (number % 10)) {
            count++;
        }
        number /= 10;
    }
}
void myResult(int i, int count, unsigned int& result) {
    while (count != 0) {
        result *= 10;
        result += i;
        count--;
    }
}
unsigned int sortedNumber(unsigned int number) {
    unsigned int result = 0;
    for (int i = 0; i < 10; i++) {
        int count = 0;
        countOfTheSameDigit(i, number, count);
        myResult(i, count, result);
    }
    return result;
}
int main()
{
    unsigned int number;//1541684
    cin >> number;
    cout << sortedNumber(number);
}
