#include <iostream>
using namespace std;

//Задача 1: Напишете програма, която приема две естествеи числа и връща най - малкото общо кратно.
//Вход : 16 24, Изход : 48
//
//int main()
//{
//	unsigned a;
//	unsigned b;
//	cin >> a >> b;
//	unsigned result = a > b ? a : b;
//	while (result % a != 0 || result % b != 0) {
//		result++;
//	}
//	cout << result;
//}
//Задача 2 : Напишете програма, която приема две естествеи числа и връща най - големият им общ делител.
//Вход : 16 24, Изход : 8
//
//
//int main() {
//	unsigned a, b;
//	cin >> a >> b;
//	if (a < b) {
//		unsigned temp = a;
//		a = b;
//		b = temp;
//	}
//	while (b != 0) {
//		unsigned temp = b;
//		b = a % b;
//		a = temp;
//	}
//	cout << a;
//}
//Задача 3 : Напишете програма, която приема естествено число и връща дали числото е просто.
//Вход : 17, Изход : Prime
//Вход : 25, Изход : not prime
//
//int main() {
//	unsigned number;
//	cin >> number;
//	bool isPrime = true;
//	if (number <= 1) {
//		isPrime = false;
//	}
//	else {
//		unsigned sqrtOfNumber = sqrt(number);
//		for (int i = 2; i < sqrtOfNumber; i++) {
//			if (number % i == 0) {
//				isPrime = false;
//				break;
//			}
//		}
//	}
//	if (isPrime) {
//		cout << "Prime";
//	}
//	else {
//		cout << "Not prime";
//	}
//
//}
//Задача 4 : Напишете програма, която приема естествено число и отпечатва разбиването му на прости множители, сортирани низходящо.
//Вход : 50 Изход : 5 ^ 2 2 ^ 1
//
//int main() {
//	unsigned number;
//	cin >> number;
//	unsigned sqrtOfNumber = sqrt(number);
//	for (int i = 2; i < sqrtOfNumber; i++) {
//		unsigned count = 0;
//		while (number % i == 0) {
//			count++;
//			number /= i;
//		}
//		if (count != 0) {
//			cout << i << "^" << count << endl;
//		}
//	}
//}
//Задача 5 : Напишете програма, която приема цяло число и връща най - често срещаната цифра.
//Ако има няколко най - често срещани, то да се отпечата най - малката.
//Вход : 2881, Изход : 8
//Вход : 456, Изход : 4
//int main() {
//	unsigned number;
//	cin >> number;
//	int currNumber = 0;
//	int times = 0;
//	for (int i = 0; i < 10; i++) {
//		unsigned temp = number;
//		int tempCaunt = 0;
//		while (temp != 0) {
//			if (temp % 10 == i) {
//				tempCaunt++;
//			}
//			temp /= 10;
//		}
//		if (tempCaunt > times) {
//			currNumber = i;
//		}
//	}
//	cout << currNumber;
//}
//Задача 5: Да се напише програма, която приема цяло число и отпечатва дали е степен на 2 - ката.
//int main() {
//	unsigned number;
//	cin >> number;
//	bool isPowerOf2 = false;
//	for (int i = 0; i < 32; i++) {
//		if (1 << i == number) {
//			isPowerOf2 = true;
//		}
//		else if (1 << i > number) {
//			break;
//		}
//	}
//	cout << isPowerOf2;
//}

//Задача 2: Да се напише програма, която приема 2 числа.Да се отпечатат всички общи делители сортиран наобратно.
//Вход : 28 21, Изход : 7 1
//Вход : 60 30 Изход : 30 15 10 6 5 3 2 1

//int gcd(int a, int b) {
//	if (a < b) {
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	while (b != 0) {
//		int temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//int main() {
//	int a, b;
//	cin >> a >> b;
//	if (a < b) {
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	int curr = gcd(a, b);
//	for (int i = curr; i >= 1; i--) {
//		if (curr % i == 0) {
//			cout << i << " ";
//		}
//	}
//}

//Задача 3: Да се напише програма, която приема число и премахва среднaта цифра, ако числото има нечетен брой цифри или премахва средните две цифри,
//ако числото има четен брой цифри.След това да се отпечата числото увеличено с 1 - ца.
//int returnTheCountOfNumbers(int n) {
//	int count = 0;
//	while (n != 0) {
//		count++;
//		n /= 10;
//	}
//	return count;
//}
//int powerOfNumber(int number, int times) {
//	int result = 1;
//	while (times > 0) {
//		result *= number;
//		times--;
//	}
//	return result;
//}
//int reversedNumber(int num) {
//	int result = 0;
//	while (num != 0) {
//		(result *= 10) += num % 10;
//		num /= 10;
//	}
//	return result;
//}
//int main() {
//	int a;
//	cin >> a;
//	int countOfNumb = returnTheCountOfNumbers(a);
//	int n = countOfNumb / 2 - (countOfNumb + 1) % 2;
//	int currPower = powerOfNumber(10, n);
//	int result = (reversedNumber(reversedNumber(a) % currPower)) * currPower + a % currPower;
//	cout << result << " " << result + 1;
//}

//bulls and cows
//unsigned countOfBulls(unsigned number, unsigned guess) {
//	unsigned count = 0;
//	while (number) {
//		if (number % 10 == guess % 10) {
//			count++;
//		}
//		number /= 10;
//		guess /= 10;
//	}
//	return count;
//}
//unsigned countOfSameNumbers(unsigned number, unsigned guess) {
//	bool arr[10]{false};
//	unsigned count = 0;
//	while (number) {
//		arr[number % 10] = true;
//		number /= 10;
//	}
//	while (guess) {
//		if (arr[guess % 10] == true) {
//			count++;
//		}
//		guess /= 10;
//	}return count;
//}
//void countOfBullsAndCows(unsigned number, unsigned guess, unsigned& cows, unsigned& bulls) {
//	bulls = countOfBulls(number, guess);
//	cows = countOfSameNumbers(number, guess) - bulls;
//}
//int main() {
//	unsigned num;
//	cin >> num;
//	unsigned currGuess;
//	unsigned cows = 0, bulls = 0;
//	do {
//		cin >> currGuess;
//		countOfBullsAndCows(num, currGuess, cows, bulls);
//		cout << "bulls:" << bulls << " cows:" << cows;
//	} while (bulls != 4);
//}
