#include <iostream>
using namespace std;
long MAX_SIZE = 1000000000;
int myStrlen(const char* str) {
	if (!str) {
		return 0;
	}
	int count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}
void myStrCpy(const char* str1, char* str2) {
	if (!str1 || !str2) {
		return;
	}
	while (*str1) {
		*str2 = *str1;
		str1++;
		str2++;
	}
	*str2 = '\0';
}
void changeTheStr(char* str, int currIndex) {
	if (!str) {
		return;
	}
	while (str[currIndex] != '\0') {
		str[currIndex] = str[currIndex + 1];
		currIndex++;
	}
}
void eleminateSymbols(char* str, int index) {
	if (!str) {
		return;
	}
	int currIndex = index + 1;
	while (str[currIndex] != '\0') {
		if (str[index] == str[currIndex]) {
			changeTheStr(str, currIndex);
		}
		currIndex++;
	}
}
int analizeArr(char* str) {
	if (!str) {
		return -1;
	}
	int index = 0;
	while (str[index] != '\0') {
		eleminateSymbols(str, index);
		index++;
	}
	return myStrlen(str);
}
bool validationOfNumber(long N) {
	return N > (-MAX_SIZE) && N < MAX_SIZE;
}
void fillArrWithNumber(int* arr, size_t size, long N, int& index) {
	while (N != 0) {
		int number = N - (10 * (N / 10));
		arr[index] = number;
		N /= 10;
		index--;
	}
	index++;
}
bool newNumberCanBeDividedBy3(int* arr, int index) {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		if (i != index) {
			sum += arr[i];
		}
	}
	return sum - ((sum / 3) * 3) == 0;
}
int checkNum(long N) {
	if (!validationOfNumber(N))return -1;
	int arr[10]{ 0 };
	int index = 9;
	fillArrWithNumber(arr, 10, N, index);
	while (index < 10) {
		if (newNumberCanBeDividedBy3(arr, index)) {
			return arr[index];
		}
		index++;
	}
	return 0;
}
bool validationOfInput(const char* str, int N) {
	if (!str) {
		return 0;
	}
	while (*str) {
		if (*str < 32 && *str>128) {
			return 0;
		}
		str++;
	}
	return N >= 2 && N <= 49;
}
char indexToSymbol(int index) {
	return index;
}
int symbolToIndex(char ch) {
	return ch;
}
char* encodeWord(const char* str, int N) {
	int len = myStrlen(str);
	char* newStr = new char[len] {0};
	if (!validationOfInput(str, N))return newStr;
	myStrCpy(str, newStr);
	while (*newStr) {
		int index = symbolToIndex(*newStr);
		index += N;
		if (index < 32 || index > 126) {
			return newStr;
		}
		*newStr = indexToSymbol(index);
	}
	return newStr;
}
void swap(unsigned int& number1, unsigned int& number2) {
	unsigned int temp = number1;
	number1 = number2;
	number2 = temp;
}
unsigned int getGCDofTwoNumbers(unsigned int number1, unsigned int number2) {
	if (number1 < number2)swap(number1, number2);
	while (number2 != 0) {
		int temp = number1 % number2;
		number1 = number2;
		number2 = temp;
	}
	return number1;
}
unsigned int getGCD(const unsigned int* arr, size_t size) {
	int index = 1;
	unsigned int number1 = arr[0];
	int gcd = getGCDofTwoNumbers(number1, arr[index]);
	index++;
	while (index < size) {
		int newgcd = getGCDofTwoNumbers(number1, arr[index]);
		if (gcd != newgcd) {
			gcd = getGCDofTwoNumbers(gcd, newgcd);
		}
		if (gcd == 1)return gcd;
		index++;
	}
	return gcd;
}
bool itIsPartOfTheText(const char* symbols, const char* word, int lenOfWord) {
	if (!symbols || !word) {
		return 0;
	}
	while (lenOfWord != 0) {
		if (*symbols != word[lenOfWord - 1])return 0;
		symbols++;
		lenOfWord--;
	}
	return 1;
}
bool doExist(const char* symbols, const char* word) {
	if (!symbols || !word) {
		return 0;
	}
	int lenOfWord = myStrlen(word);
	while (*symbols) {
		if (itIsPartOfTheText(symbols, word, lenOfWord))return 1;
		symbols++;
	}
}
unsigned short int reverseBitwise(unsigned short int number) {
	unsigned short int newNumber = 0;
	int bits = 16;
	while (bits != 0) {
		(newNumber <<= 1) += (1 & number);
		number >>= 1;
		bits--;
	}
	return newNumber;
}
void squareArr(int* arr, size_t len) {
	for (int i = 0; i < len; i++) {
		arr[i] = arr[i] * arr[i];
	}
}
void printArr(int* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
bool binarySearch(int* arr, size_t size, int searchedNumber) {
	if (size == 0) {
		return false;
	}
	int mid = size / 2;
	if (arr[mid] == searchedNumber) {
		return true;
	}
	if (arr[mid] > searchedNumber) {
		binarySearch(arr, mid, searchedNumber);
	}
	else
		binarySearch(arr + mid + 1, size - mid - 1, searchedNumber);
}
int fact(int number) {
	if (number == 1) {
		return 1;
	}
	return number * fact(number-1);
}
int fastPower(int number, int k) {
	if (k == 0) {
		return 1;
	}
	if (k % 2 == 1) {
		fastPower(number, k - 1);
	}
	else
		fastPower(number * number, k / 2);
}
unsigned int fibbres(unsigned int* arr, int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	if (arr[n] != 0) {
		return arr[n];
	}
	int current = fibbres(arr, n - 1) + fibbres(arr, n - 2);
	arr[current] = current;
	return current;
}
unsigned int fibb(int n) {
	unsigned int* arr = new unsigned int[n + 1] {0};
	unsigned res = fibbres(arr, n);
	delete[]arr;
	return res;
}
bool isPalindromeRes(const char* str, size_t size) {
	if (size <= 1) {
		return true;
	}
	return str[0] == str[size - 1] && isPalindromeRes(str + 1, size - 2);
}
bool isPalinrome(const char* str) {
	return isPalindromeRes(str, myStrlen(str));
}
void bubbleSort(int* arr, size_t size) {
	if (size == 1) {
		return;
	}
	int index = 0;
	while (index < size - 1) {
		if (arr[index] > arr[index + 1]) {
			swap(arr[index], arr[index + 1]);
		}
		index++;
	}
	bubbleSort(arr, size - 1);
}
void printArr(const int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void insertionSort(int* arr, size_t size) {
	int index = 1;
	while (index < size) {
		int currentIndex = index - 1;
		int currentElement = arr[index];
		while(currentIndex >=0 && arr[currentIndex] > currentElement){
			swap(arr[currentIndex], arr[currentIndex + 1]);
			currentIndex--;
		}
		arr[currentIndex + 1] = currentElement;
		index++;
	}
}
int* newSortedArr(int* arr1, int* arr2, int size1, int size2) {
	int* newArr = new int[size1 + size2] {0};
	int index = 0;
	while (size1 != 0 || size2 != 0) {
		if (size1!=0 && *arr1 <= *arr2) {
			newArr[index] = *arr1;
			index++;
			arr1++;
			size1--;
		}
		else if(size2 != 0) {
			newArr[index] = *arr2;
			index++;
			arr2++;
			size2--;
		}
	}
	return newArr;
}
char** createMatrix(int rows, int colls, char symbol) {
	char** matrix = new char*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new char[colls];
        for (int j = 0; j < colls; j++) {
			matrix[i][j] = symbol;
	    }
	}
	return matrix;
}
void printMatrix(char** matrix, int rows, int colls) {
	int maxrows = 25;
	int maxcolls = 80;
	while (maxrows + 1 != rows && maxrows != rows) {
		cout << endl;
		maxrows -= 2;
	}
	int count = 0;
	while (maxcolls != colls && maxcolls + 1 != colls) {
		count++;
		maxcolls -= 2;
	}
	int countcpy = count;
	for (int i = 0; i < rows; i++) {
		countcpy = count;
		while (countcpy != 0) {
			cout << " ";
			countcpy--;
		}
		for (int j = 0; j < colls; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}
void deleteMatrix(char** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[]matrix[i];
	}
	delete[] matrix;
}
int sumOfNumbersOnDiagonal(int matrix[][4], int rows) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += matrix[i][i];
	}
	return sum;
}
void printMatrix(int arr[][4], size_t rows, size_t colls)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}
void transponingMatrix(int arr[][4], size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
}

int main() {

}