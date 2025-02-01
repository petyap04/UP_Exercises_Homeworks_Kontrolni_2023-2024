#include <iostream>
using namespace std;
void print(const int arr[], size_t size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
}
void reverseArray(int arr[], size_t size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
		}
		else
			arr[i] = 0;
	}
}
void twosCompiment(int arr[], size_t size) {
	for (int i = size - 1; i >= 0; i--) {
		arr[i]++;
		if (arr[i] > 1) {
			arr[i] = 0;
		}
		else
			break;
	}
}
void fromDecimalToBinary(int arr[], size_t size, int number) {
	int copyOfNumber = number;
	while (number!=0) {
		arr[size-1] = number % 2;
		number /= 2;
		size--;
	}
	/*if (copyOfNumber < 0) {
		reverseArray(arr, size);
		twosCompiment(arr, size);
	}*/
	print(arr, size);
}
int main()
{
	//Задача 1: Да се направи функция, която извежда на екрана двоичната репрезентация на 32 битово число записано в десетична бройна система.
	constexpr int size = 32;
	int arr[size];
	int number;
	cin >> number;
	fromDecimalToBinary(arr, size, number);
}