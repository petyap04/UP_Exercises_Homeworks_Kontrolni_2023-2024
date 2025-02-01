#include <iostream>
using namespace std;
const int DIGIT_COUNT = 4;

bool valideInput(unsigned int number) {
    unsigned int digitsCount = 0;
    while (number != 0) {
        number /= 10;
        digitsCount++;
    }
    return digitsCount == DIGIT_COUNT;
}
unsigned int inputNumber() {
    unsigned int number;
    do {
        cin >> number;
    } while (!valideInput(number));
    return number;
}
unsigned int getBullsCount(unsigned int numberToBeGuessed, unsigned int myGuess) {
    unsigned int count = 0;
    while (myGuess != 0) {
        if ((myGuess % 10) == (numberToBeGuessed % 10)) {
            count++;
        }
        myGuess /= 10;
        numberToBeGuessed /= 10;
    }
    return count;
}
void compareOfDigits(int numberFromNumberToBeGuessed, unsigned int copyOfMyGuess, unsigned int& sum) {
    while (copyOfMyGuess != 0) {
        int numberFromMyGuessed = copyOfMyGuess % 10;
        if (numberFromMyGuessed == numberFromNumberToBeGuessed) {
            sum++;
        }
        copyOfMyGuess /= 10;
    }
}
unsigned int getBullsAndCowsSum(unsigned int numberToBeGuessed, unsigned int myGuess) {
    unsigned int sum = 0;
    while (numberToBeGuessed != 0) {
        int numberFromNumberToBeGuessed = numberToBeGuessed % 10;
        unsigned int copyOfMyGuess = myGuess;
        compareOfDigits(numberFromNumberToBeGuessed, copyOfMyGuess, sum);
        numberToBeGuessed /= 10;
    }
    return sum;
}
void getBullsAndCows(unsigned int numberToBeGuessed, unsigned int myGuess, unsigned int& bulls, unsigned int& cows) {
    bulls = getBullsCount(numberToBeGuessed, myGuess);
    cows = getBullsAndCowsSum(numberToBeGuessed, myGuess) - bulls;
}

int main()
{
    unsigned int numberToBeGuessed = inputNumber();
    unsigned int myGuess;
    do {
        myGuess = inputNumber();
        unsigned int bulls, cows;
        getBullsAndCows(numberToBeGuessed, myGuess, bulls, cows);
        cout << "Bulls:" << bulls << " " << "Cows:" << cows << endl;
    } while (myGuess != numberToBeGuessed);
    cout << "Congratulations! " << endl;
}
