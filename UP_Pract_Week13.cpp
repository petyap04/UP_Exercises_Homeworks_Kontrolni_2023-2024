#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 10;
void printArr(const int* arr)
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void swap(int* arr, int index) {
	int temp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = temp;
}
void coctailShaker(int* arr, bool& isSorted) { 
	int times = 0;
	do {
		isSorted = true;
		for (int i = times; i < MAX_SIZE - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr, i);
				isSorted = false;
			}
		}
		times++;
		for (int i = MAX_SIZE - times; i >= 0; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(arr, i - 1);
				isSorted = false;
			}
		}
	} while (!isSorted);
}
int main()
{
	//bool isSorted = true;
	//int arr[MAX_SIZE] = { -1,6,8,-12,36,7,4,12,-4,6 };
	//coctailShaker(arr, isSorted);
	//printArr(arr);

}




//Да се напише функция, която приема двумерен масив arr[3][N] от числа.
//arr[0] наричаме първичен ключ.arr[1] наричаме вторичен ключ.arr[2] наричаме стойност.
//Тройката(arr[0][i], arr[1][i], arr[2][i]) е по - малка от тройката(arr[0][j], arr[1][j], arr[2][j]) ако
//arr[0][i] < arr[0][j] или arr[0][i] == arr[0][j] & arr[1][i] < arr[1][j].
//Сортирайте двумерния масив така, че за всяко i < j е вярно(arr[0][i], arr[1][i], arr[2][i]) < (arr[0][j], arr[1][j], arr[2][j]).