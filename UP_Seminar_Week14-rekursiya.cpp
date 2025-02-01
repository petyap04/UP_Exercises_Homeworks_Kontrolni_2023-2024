#include <iostream>
using namespace std;

int factoriel(int number) {
	if (number == 0) {
		return 1;
	}
	return number * factoriel(number - 1);
}
int fibonachi(int number) {
	if (number == 0 || number == 1) {
		return 1;
	}
	return fibonachi(number - 1) + fibonachi(number - 2);
}
int power(int number, int k) {
	if (k == 0) {
		return 1;
	}
	return number * power(number, k - 1);
}
int fastpower(int number, int k) {
	if (k == 0) {
		return 1;
	}
	if (k % 2 != 0) {
		return number * power(number, k - 1);
	}
	else
		return power(number * number, k / 2);
}
int sum(int* arr, size_t size) {
	if (size == 0) {
		return 0;
	}
	return *arr + sum(arr + 1, size - 1);
}
bool isNumberPartOfArray(int* arr, size_t size, int number) {
	if (size == 0) {
		return false;
	}
	return *arr == number || isNumberPartOfArray(arr + 1, size - 1, number);
}
bool binarySearch(int* arr, size_t size, int number) {
	if (size == 0) { 
		return false; 
	}
	int mid = size / 2;
	if (arr[mid] == number)return true;
	if (arr[mid] > number) {
		return binarySearch(arr, mid, number);
	}
	else
		return(arr + mid, size- mid -1, number);
}
bool isCapital(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}
void bigAndSmall(const char* str, int& small, int& big) {
	if (*str == '\0')
		return;
	if (isCapital(str[0]))big++;
	else if (isLower(str[0]))small++;
	bigAndSmall(++str, small, big);
}
int main()
{
	int small = 0;
	int big = 0;
	bigAndSmall("deJFisJHo5", small, big);
	cout << small << endl << big;
}