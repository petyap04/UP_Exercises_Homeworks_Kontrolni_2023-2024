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
    while (times > 0) {
        result *= numberToPower;
        times--;
    }
    return result;
}
int numberWithoutDigit(int& a, int& b) {
    int result = a;
    int numberLength =length(a);
    int numberOfDigitsSaved= numberLength- b; 
    int dividerforNumbersAfterDigit = power(10, numberOfDigitsSaved);
    result %= dividerforNumbersAfterDigit;
    int dividerforNumbersBeforeDigit = 10 * dividerforNumbersAfterDigit;
    int numberBeforeDigits = a / dividerforNumbersBeforeDigit;
    result += (numberBeforeDigits * dividerforNumbersAfterDigit);
    return result;
}
int numbersThroughOne(int number,int length){//234 3//1234 4
    int newNumber = 0;
    while (length > 0) {//ok
        int divider = power(10, length - 1);//100  //1000
        newNumber = number / divider;//newnumbernoteven=234/100=2   //newnumber=1234/1000=1
        newNumber *= divider;//2/100  //1*1000
        number %= power(10,length-2);//number=234%10=4  //number=1234%100 //34%1
        length -= 2;//1
    }
}
int newNumberNotEven(int number) {//1234
    int lengthOfNumber = length(number);//4
    return numbersThroughOne(number,lengthOfNumber);
}
int newNumberEven(int number) {//1234
    int lengthOfNumber = length(number) - 1;//3
    number %= power(10, lengthOfNumber);//number=1234%1000=234
    return numbersThroughOne(number,lengthOfNumber);
}

int main()
{
    //zad3
    /*int number, digit;
    cin >> number >> digit;
    cout << numberWithoutDigit(number, digit);*/

    int number;//1234
    cin >> number;
    cout << newNumberNotEven(number) << " " << newNumberEven(number);//13 24
}