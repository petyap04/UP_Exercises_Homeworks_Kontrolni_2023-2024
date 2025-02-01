#include <iostream>
using namespace std;
constexpr int SIZE = 5;
int binaryEvenSearch(const int* arr, int len)
{
	int left = 0;
	int right = len - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == 0) {
			return mid;
		}
		else if (arr[mid] % 2 == 0) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return -1;
}
int binaryWithTwoArr(const int* arr1, const int* arr2, size_t size) {
	int left = 0;
	int right = size;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (arr2[mid] == 0) {
			return mid;
		}
		else if (arr2[mid] == arr1[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}


int main()
{
	int arr1[SIZE] = { 2,6,7,5,3 };
	int arr2[SIZE + 1] = { 2,6,7,5,0,3 };
	cout << binaryWithTwoArr(arr1, arr2, SIZE);
}

//Задача 3:Да се напише функция, която приема два масива с цели числа.Масив 1 е с размер N и съдържа само уникални положителни числа.
//Масив 2 е с размер N + 1 и е копие на масив 1, но на някоя позиция е вмъкнато числото 0. 
//Функцията трябва за логаритмичен брой стъпки да намира къде е вмъкнато числото 0.