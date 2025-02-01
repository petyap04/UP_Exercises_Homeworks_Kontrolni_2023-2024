#include <iostream>
using namespace std;

bool isPrimeNumber(int number, unsigned int& divider) {
	if (divider >= number-1) {
		return true;
	}
	if (number % divider != 0) {
		isPrimeNumber(number, ++divider);
	}
	else return false;
}
void printArr(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void fibb(int* arr, size_t size, int& index) {
	if (size <= index) {
		return;
	}
	if (index == 0 || index == 1) {
		arr[index] = 1;
	}
	else
		arr[index] = arr[index - 1] + arr[index - 2];
	fibb(arr, size, ++index);
}

bool isThereWayToZero(int* arr, size_t size, int index) {
	if (arr[index] == 0) {
		return true;
	}
	if (arr[index - arr[index]] >= 0) {
		if (isThereWayToZero(arr, size, (index - arr[index]))) {
			return true;
		}
	}
	if (arr[index + arr[index]] < size) {
		if (isThereWayToZero(arr, size, (index + arr[index]))) {
			return true;
		}
	}
	return false;
}
bool isThereWay(int arr[][7], size_t sizeRow, size_t sizeColl, int& indexOfR, int& indexOfC) {
	if (indexOfR == sizeRow && indexOfC == sizeColl) {
		return true;
	}
	for (int x = indexOfR - 1; x <= indexOfR + 1; x++) {
		if (x >= 0 && x < sizeRow) {
			for (int y = indexOfC - 1; y <= indexOfC + 1; y++) {
				if (y >= 0 && y < sizeColl)
				{
					if (x == indexOfR && y == indexOfC)
						continue;
					if (arr[x][y] == 1)
						isThereWay(arr, sizeRow, sizeColl, x, y);
				}
			}
		}
	}
	return false;
}
int countOfSymbol(char* str, char symbol, int& count) {
	if (!str) {
		return count;
	}
	while (*str) {
		if (*str == symbol) {
			countOfSymbol(str++, symbol, ++count);
		}
		str++;
	}
	return count;
}
int main()
{
	/*int index = 4;
	size_t size = 6;
	int arr[] = { 5,6,2,8,3,0 };
	cout << isThereWayToZero(arr, size, index);*/
	/*int start = 1;
	int arr[6][7] = { {1,1,0,0,0,0,0},
				      {0,1,0,0,0,0,0},
				      {0,1,1,1,0,0,0},
				      {0,0,0,1,0,0,0},
				      {0,0,0,1,1,1,1},
				      {0,0,0,0,0,0,1}};
	cout << isThereWay(arr, 6, 7, start, start);*/
	char str[] = { "alabala" };
	char symbol = 'a';
	int count = 0;
	cout << countOfSymbol(str, symbol, count);
}

//Задача 1. Напишете рекурсивна функция, която приема цяло число n и връща масив от първите n числа на Фибоначи.
//Задача 2. Напишете рекурсивна функция, която пресмята дали едно число е просто.
//Задача 3. Напишете функция, която проверява дали при подаден масив от цели положителни числа, стартов индекс има път от стартовия до клетка
//със стойност 0 предвижвайки се според стойностите в клетките (Можете да се придвижвате както наляво, така и надясно).
//Задача 4. Даден е лабиринт под формата на матрица с размер n x m, където свободно квадратче се отбелязва с 1, а стена – с 0.
//Намерете има ли път от позиция (0,0) до позиция (n-1, m-1), движейки се в четирите основни посоки и само през свободни квадратчета.
//Задача 5. Напишете рекурсивна функция, която пресмята броя срещания на символ c в низ str.