#include <iostream>
using namespace std;


//Задача 2 : Напишете функция, която приема цяло число и връща броя на цифрите му.
//Вход : 4, Изход : 1
//Вход : -4, Изход : 1
//Вход : 5430 Изход : 4
//
unsigned countOfDigits(int number) {
	int count = 0;
	while (number) {
		count++;
		number /= 10;
	}
	return count;
}
//Задача 3 : Напишете функция, която приема 6 целочислени координати(3 точки) и връща обиколката на триъгълника по тези точки.
//Вход : 1 1 4 7 0 10, Изход : 20.764
//
double getDist(int x1, int y1, int x2, int y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx * dx + dy * dy);
}
double getPer(int x1, int y1, int x2, int y2, int x3, int y3) {
	return getDist(x1, y1, x2, y2) + getDist(x1, y1, x3, y3) + getDist(x3, y3, x2, y2);
}
//Задача 4 : Да се напише функция, която приема две естествени числа и връща ново число, което е тяхната конкатенация.
//Вход : 19 32, Изход : 1932
//
unsigned reverse(unsigned num) {
	unsigned result = 0;
	while (num) {
		(result *= 10) += num % 10;
		num /= 10;
	}
	return result;
}
unsigned concat(unsigned num1, unsigned num2) {
	unsigned result = num1;
	num2 = reverse(num2);
	while (num2) {
		(result *= 10) += num2 % 10;
		num2 /= 10;
	}
	return result;
}

//Задача 5 : Напишете функция, която дадено по подадено естествено число N, връща число, което е резултат от конкатенацията на обърнатото число на N
//с подаденото N.
//Вход : 1234 Изход : 43211234
//
unsigned concatrealnumb(unsigned numb) {
	unsigned result = reverse(numb);
	unsigned reversed = result;
	while (reversed!=0) {
		(result *= 10) += reversed % 10;
		reversed /= 10;
	}
	return result;
}

unsigned countOfDigitsInNumber(int number, int i) {
	unsigned count = 0;
	while (number) {
		if (number % 10 == i) {
			count++;
		}
		number /= 10;
	}
	return count;
}

void concatDigitsToNumber(int& result, int i, unsigned count) {
	while (count) {
		(result *= 10) += i;
		count--;
	}
}

unsigned sortNumber(int number) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		unsigned count = countOfDigitsInNumber(number, i);
		concatDigitsToNumber(result, i, count);
	}
	return result;
}


