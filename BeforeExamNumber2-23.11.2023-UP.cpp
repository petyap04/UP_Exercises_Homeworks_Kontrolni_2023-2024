#include <iostream>
using namespace std;
constexpr int SIZE =32;
void print(const int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void print(const unsigned int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
int getIndexFromSymbol(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z') {
		return 10 + (ch - 'A');
	}
	else
		return -1;
}
char getSymbolFromIndex(int number) {
	if (number >= 0 && number <= 9) {
		return number + '0';
	}
	else if (number >= 10) {
		return number + 'A' - 10;
	}
	else
		return 0;
}
bool validationOfInput(const int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		if (arr[i] > 1) {
			return 0;
		}
	}
	return 1;
}
void readArray(int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		unsigned number;
		cin >> number;
		arr[i] = number;
	} 
}
void readArray(unsigned int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		unsigned number;
		cin >> number;
		arr[i] = number;
	}
}
void reverseOfArray(int arr[], size_t size) {
	for (unsigned i = 0; i < size; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
		}
		else
			arr[i] = 0;
	}
}
void negativeNumber(int arr[], size_t size) {
	reverseOfArray(arr, size);
	for (unsigned i = size; i >0; i--) {
		arr[i]++;
		if (arr[i] == 2) {
			arr[i] = 0;
		}
		else
			break;
	}
	print(arr, size);
}
bool isPermotationOfA(unsigned int a, unsigned int b) {
	for (unsigned int i = a; i > 0; i--) {
		if (b % i != 0) {
			return 0;
		}
		b /= i;
	}
	return 1;
}
unsigned int sumOfDividersOfNumber(unsigned number) {
	unsigned int sum = 0;
	for (unsigned i = 1; i <= number; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}
	return sum;
}
unsigned int sumOfDivisorsOfNumbersBefore(unsigned int number) {
	unsigned int sum = 0;
	for (unsigned i = 1; i <= number; i++) {
		sum += sumOfDividersOfNumber(i);
	}
	return sum;
}
bool nIsValid(unsigned int number) {
	if (number < 3 || number>16) {
		return 0;
	}
	return 1;
}
bool validationOfFirstThreeNumbers(int num1, int num2, int num3) {
	if (num1 == num2 || num2 == num3) {
		return 0;
	}
	if ((num1 > num2 && num2 > num3) || (num1 < num2 && num2 < num3)) {
		return 0;
	}
}
bool isTrion(unsigned int number,int num1,int num2,int num3) {
	for (unsigned int count = number-3; count > 0; count--) {
		num1 = num2;
		num2 = num3;
		cin >> num3;
		if ((num1 > num2 && num2 >= num3) || (num1 < num2 && num2 <= num3)) {
			return 0;
		}
	}
	return 1;
}
bool validationOfNumberForTriangles( unsigned int number) {
	if (number < 99) {
		return 0;
	}
	return 1;
}
bool isTriagle(unsigned int a, unsigned int b, unsigned int c) {
	if (a + b <= c || a + c <= b || b + c <= a) {
		return 0;
	}
	else
		return 1;
}
void sideC(unsigned int number, unsigned int a, unsigned b,unsigned int& count) {
	while (number != 0) {
		unsigned int c = number % 10;
		if (isTriagle(a, b, c)) {
			count++;
		}
		number /= 10;
	}
}
void sideB(unsigned int number,unsigned int a, unsigned int& count) {
	while (number != 0) {
		unsigned int b = number % 10;
		unsigned int copyOfN = number / 10;
		sideC(copyOfN, a, b, count);
		number /= 10;
	}
}
void sideA(unsigned int number,unsigned int& count) {
	while (number != 0) {
		unsigned int a = number % 10;
		unsigned int copyOfN = number / 10;
		sideB(copyOfN, a, count);
		number /= 10;
	}
}
unsigned int countOfTriangles(unsigned int number) {
	unsigned int count = 0;
	sideA(number,count);
	return count;
}
void readArray12(const int arr[], int arr1[],int arr2[],size_t size) {
	for (unsigned int i = 0; i < size; i++) {
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}
}
bool isPalindrome(const int arr[],size_t size) {
	if (size == 1) {
		return 1;
	}
	for (unsigned i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - 1]) {
			return 0;
		}
		size--;
	}
	return 1;
}
bool isTwoPalindromes(const int arr[], size_t size) {
	int arr1[SIZE];
	int arr2[SIZE];
	readArray12(arr, arr1, arr2, size);
	unsigned int sizeOfArr1 = 1;
	unsigned int sizeOfArr2 = size - sizeOfArr1;
	while (sizeOfArr1 < size) {
		if (isPalindrome(arr1,sizeOfArr1) && isPalindrome(arr2, sizeOfArr2)) {
			return 1;
		}
		sizeOfArr1++;
	}
	return 0;
}
int fromDecimalToK(unsigned int arr[], size_t size, unsigned number, unsigned k) {
	while (number != 0) {
		arr[size-1] = number % k;
		size--;
		number /= 10;
	}
	return (size - 1);
}
bool numberIsPalindrome(unsigned int number, unsigned k) {
	constexpr int size = 32;
	unsigned arr[size];
	int startOfNumberInArray = fromDecimalToK(arr, size, number, k);
	print(arr, size);
	for (int i = startOfNumberInArray; i < size; i++) {
		if (arr[i] != arr[size - 1]) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	//Задача 5: Да се напише функция, която приема осем битово число в двоична бройна система,
	//представено като int и връща числото, умножено по -1.
	/*constexpr int SIZE = 8;
	int arr[SIZE];
	readArray(arr, SIZE);
	if (validationOfInput(arr, SIZE)) {
		negativeNumber(arr, SIZE);
	}*/
	//Задача 1A: Да се вкарат две числа и да се провери дали второто е пермотация на първото.(без масив)
	/*unsigned a, b;
	cin >> a >> b;
	cout<<isPermotationOfA(a, b);*/
	//Задача 1Б: Да се въведе естествено число и да се намери сборът на делителите на предходните числа.
	/*unsigned int n;
	cin >> n;
	cout<<sumOfDivisorsOfNumbersBefore(n);*/
	//Zadacha 3
	/*unsigned int n;
    int num1, num2, num3;
	cin >> n >> num1 >> num2 >> num3;
	if (nIsValid(n) && validationOfFirstThreeNumbers(num1, num2, num3)) {
		cout << isTrion(n, num1, num2, num3);
	}
	else
		cout << "Invalid input";*/
	//Zadacha 4
	/*unsigned int n;
	cin >> n;
	if (validationOfNumberForTriangles(n) == 0) {
		cout << "Invalid input";
	}
	else{
		unsigned int count = countOfTriangles(n);
		cout << count;
    }*/
	//Задача 2 Контролно: Да се напише фунскция, която приема масив и големината му и връща дали масивът е 
	//конкатенция на два масива от палиндроми.
	/*int arr[SIZE];
	readArray(arr, SIZE);
	cout << isTwoPalindromes(arr, SIZE);*/
	//Задача 6: Да се напише функция, която приема число от тип unsigned int (32 бита) и K - бройна система(<= 16-ична). 
	//Функцията да връща дали числото е палиндром в дадената бройна система.
	unsigned int number;
	unsigned int k;
	cin >> number >> k;
	if (k < 1 || k > 16) {
		cout << "error";
	}
	else
		cout << numberIsPalindrome(number, k);
}
