#include <iostream>
using namespace std;

int length(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
int power(int numberToPower, int times) {
    int result = 1;
    while (times != 0) {
        result *= numberToPower;
        times--;
    }
    return result;
}
int numberWithoutDigit(int& a, int& b) {
    int result = a;
    int numberLength = length(a);
    int numberOfDigitsSaved = numberLength - b;
    int dividerforNumbersAfterDigit = power(10, numberOfDigitsSaved);
    result %= dividerforNumbersAfterDigit;
    int dividerforNumbersBeforeDigit = 10 * dividerforNumbersAfterDigit;
    int numberBeforeDigits = a / dividerforNumbersBeforeDigit;
    result += (numberBeforeDigits * dividerforNumbersAfterDigit);
    return result;
}
unsigned int reverse(unsigned num) {
    unsigned reversedNumber = 0; 
    while (num != 0) {
        unsigned lastDigit = num % 10;
        (reversedNumber *= 10) += lastDigit;
        num /= 10;
    }
    return reversedNumber;
}
void funnumber(int number, int& oddNumber, int& evenNumber){
    oddNumber = 0;
    evenNumber = 0;
    number = reverse(number);//54321
    bool isCurrentPosOdd = true;
    while (number != 0)
    {
        unsigned digitToAdd = number % 10;//1  //2
        number /= 10;//5432 //543

        if (isCurrentPosOdd)//true  //false
        {
            oddNumber = oddNumber * 10 + digitToAdd;//1
            isCurrentPosOdd = false;
            continue;
        }

        evenNumber = evenNumber * 10 + digitToAdd;//2
        isCurrentPosOdd = true;
    }
 }
void numberWithoutTwoDigits(unsigned& num, unsigned digit1, unsigned digit2) {//43467867  3 5
     unsigned int copyOfNumber = reverse(num);//76876434
     int lengthofNumber = length(num);//8
     num = 0;
     unsigned int count = 1;
     while (copyOfNumber != 0) {
       if (count == digit1 || count == digit2) {
         count++;
         copyOfNumber /= 10;
         continue;
       }
     int lastDigit = copyOfNumber % 10;
     (num *= 10) += lastDigit;
     copyOfNumber /= 10;
     count++;
 } 
}
void numberInIntegral(unsigned& num, unsigned digit1, unsigned digit2) {//1234567  3 5
    int numLength = length(num);//7
    num /= power(10, numLength-digit2);//12345
    num = reverse(num);//54321
    num /= power(10, digit1 - 1);//543
    num = reverse(num);

}

int main()
{
    //zad3
    /*int number, digit;
    cin >> number >> digit;
    cout << numberWithoutDigit(number, digit);*/
    //zad4
    /*int number;//12345
    cin >> number;
    int odd=0;
    int even=0;
    funnumber(number, odd, even);
    cout << odd <<" "<< even;*/
    //zad5
    unsigned int number, digitStart, digitEnd;//1234567  3 5
    cin >> number >> digitStart >> digitEnd;
    if (digitStart > digitEnd) {
        int t = digitStart;
        digitStart = digitEnd;
        digitEnd = t;
    }
    /*numberWithoutTwoDigits(number, digitStart, digitEnd);*/
    numberInIntegral(number, digitStart, digitEnd);
    cout << number;


}

