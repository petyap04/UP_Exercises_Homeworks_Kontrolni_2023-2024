#include <iostream>
using namespace std;

void printArray(const int arr[][3], unsigned int rows, unsigned int colls) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int elementOfMatrix(const int arr[][4], unsigned int rows, unsigned int colls) {
	int biggestEl = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			if (arr[i][j] > biggestEl) {
				biggestEl = arr[i][j];
			}
		}
	}
	return biggestEl;
}
void diagonal1(const int arr[][4], unsigned int rows, unsigned int colls) {
	for (int i = 0; i < rows; i++) {
		cout << arr[i][i] << " ";
	}
}
void diagonal2(const int arr[][4], unsigned int rows, unsigned int colls) {
	for (int i = 0; i <rows; i++) {
		cout << arr[i][colls - i - 1] << " ";
	}
}
void zigzag(int arr[][4], unsigned int rows, unsigned int colls) {
	for (int i = 0; i < rows; i++) {
		if (i % 2 == 0) {
			continue;
		}
		else {
			for (int j = 0; j < colls/2; j++) {
				int temp = arr[i][j];
				arr[i][j] = arr[i][colls - 1];
				arr[i][colls - 1] = temp;
				colls--;
			}
		}
	}
}
bool isMatrixTriagonal(int arr[][4], unsigned int rows, unsigned int colls) {
	int i = 1;
	int j = 0;
	while (i < rows && j < colls) {
		if (arr[i][j] != 0) {
			return 0;
		}
		i++;
		j++;
	}
	return 1;
}
void transMatrix(int arr[][4], unsigned int rows, unsigned int colls) {
	int i = 0;
	int j = 1;
	while( i < rows) {
		while ( j < colls) {
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
			j++;
		}
		i++;
		j = i + 1;
	}
}
bool magicSquare(int arr[][4], unsigned int rows, unsigned int colls) {
	int sum = 0;
	int tempsum = 0;
	for (int j = 0; j < colls; j++) {
		sum += arr[0][j];
	}
	for (int i = 1; i < rows; i++) {
		tempsum = 0;
		for (int j = 0; j < colls; j++) {
			tempsum += arr[i][j];
		}
		if (tempsum != sum) {
			return 0;
		}
	}
    for (int j = 0; j < colls; j++) {
		tempsum = 0;
	    for (int i = 0; i < rows; i++) {
			tempsum += arr[i][j];
		}
		if (tempsum != sum) {
			return 0;
		}
	}
	tempsum = 0;
	for (int i = 0; i < rows; i++) {
			tempsum += arr[i][i];
	}
	if (tempsum != sum) {
			return 0;
	}
	tempsum = 0;
	for (int i = 0; i < rows; i++) {
		tempsum += arr[i][colls - i - 1];
	}
	if (tempsum != sum) {
			return 0;
	}
	return 1;
}
void sumOfTwoMatrix(int arr[][4], int arr1[][4], int arr2[][4], unsigned int rows, unsigned int colls) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
}
void multiplicatoinOfMatrixByNumber(int arr[][3], unsigned int rows, unsigned int colls, int number) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			arr[i][j] *= number;
		}
	}
}

int main()
{
	int number = 5;
	unsigned int rows = 4;
	unsigned int colls = 3;
	int arr[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	multiplicatoinOfMatrixByNumber(arr, rows, colls, number);
	printArray(arr, rows, colls);
}
//Задача 1: Да се напише функция, която приема матрица и връща най-малкия й елемент.
//Задача 2: Да се напише функция, която приема квадратна матрица с n на n елемента отпечатва главния диагонал, след това и второстепенния.
//Задача 3: Да се напише функция, която по даден матрица отпечатва елементите ѝ на зиг-заг (първи ред отляво надясно, втори ред отдясно наляво и т.н.)
//Задача 6: Да се напише функция, която приема квадратна матрица с n на n елемента и връща дали матрицата е триъгълна, т.е. под главния диагонал има само нули.
//Задача 7: Да се напише функция, която транспонира квадратна матрица с n на n елемента.
//Задача 8: Една квадратна матрица от числа се нарича магически квадрат, когато всички суми, получени поотделно от сбора на елементите по всеки ред/всеки 
//стълб/всеки от двата диагонала са равни. Да се състави функция, която приема квадратна матрица и определя дали образува магически квадрат.
//Задача 9: Да се напише функция, която: събира 2 матрици ; умножава матрица с число