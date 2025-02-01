#include <iostream>
using namespace std;
int** createintMatrix(int rows, unsigned int colls)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[colls + 2] {0};
		matrix[i][0] = colls;
	}
	return matrix;
}
//char** createcharMatrix(int rows, unsigned int colls)
//{
//	char** matrix = new char* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i] = new char[colls + 2] {0};
//		matrix[i][0] = colls;
//	}
//	return matrix;
//}
void freeintMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}
//void freecharMatrix(char** matrix, int rows)
//{
//	for (int i = 0; i < rows; i++)
//		delete[] matrix[i];
//	delete[] matrix;
//}
//void print(char** mtx, int rows, int colls)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < colls; j++)
//			cout << mtx[i][j] << ' ';
//		cout << endl;
//	}
//}
void print(int** mtx, int rows, int colls)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
			cout << mtx[i][j] << ' ';
		cout << endl;
	}
}
void readintMatrix(int** matrix, unsigned int rows, unsigned int colls) {
	int i = 0;
	int r = 0;
	while (r < rows) {
		for (unsigned int t = 0; t < colls; t++) {
			cin >> i;
			matrix[r][t] = i;
		}
		r++;
	}
}
//void readcharMatrix(char** matrix, unsigned int rows, unsigned int colls) {
//	char i = 0;
//	int r = 0;
//	while(r < rows){
//	  for (unsigned int t = 0; t < colls; t++) {
//		  cin >> i;
//		  matrix[r][t] = i;
//	  }
//	  r++;
//	}
//}
void codedMatrix(char** matrix, unsigned int rows, unsigned int colls) {
	int r = 0;
	while (r < rows) {
		for (int t = 0; t < colls; t++) {
			if (matrix[r][t] % 2 == 0) {
				matrix[r][t] = '*';
			}
		}
		r++;
	}
}
unsigned int sumOfnumbersAboveMainDiagonal(int** matrix, unsigned int rows, unsigned int colls) {
	unsigned int sum = 0;
	int r = 0;
	while (r < rows) {
		for (int t = r + 1; t < colls; t++) {
			if (matrix[r][t] % 2 == 0) {
				sum += matrix[r][t];
			}
		}
		r++;
	}
	return sum;
}
unsigned int sumOfnumbersUnderMainDiagonal(int** matrix, unsigned int rows, unsigned int colls) {
	unsigned int sum = 0;
	int r = colls - 1;
	while (r >= 0) {
		for (int t = r; t >= 0; t--) {
			if (matrix[r][t] % 2 != 0) {
				sum += matrix[r][t];
			}
		}
		r--;
	}
	return sum;
}
void poweredNumbers(int** matrix, unsigned int rows, unsigned int colls) {
	int r = 1;
	while (r < rows) {
		for (int t = colls - 1; t >= 0; t--) {
			cout << (matrix[r][t] * matrix[r][t]) << endl;
		}
		r--;
	}
}
void summedMatrix1andMatrix2(int** summedMatrix, int** matrix1, int** matrix2, unsigned int n) {
	int r = 0;
	while (r < n) {
		for (int t = 0; t < n; t++) {
			summedMatrix[r][t] = matrix1[r][t] + matrix2[r][t];
		}
		r++;
	}
}

int main()
{
  /*  unsigned int n, m;
    cin >> n >> m;
	char** matrix = createMatrix(n,m);
	readcharMatrix(matrix, n, m);
	codedMatrix(matrix, n, m);
	print(matrix, n, m);
	freeMatrix(matrix, n);*/
	/*unsigned int n;
	cin >> n;
	int** matrix = createintMatrix(n, n);
	readintMatrix(matrix, n, n);
	cout << sumOfnumbersAboveMainDiagonal(matrix, n, n) << endl << sumOfnumbersUnderMainDiagonal(matrix, n, n);
	poweredNumbers(matrix, n, n);
	freeintMatrix(matrix, n);*/
	unsigned int n;
	cin >> n;
	int** matrix1 = createintMatrix(n, n);
	readintMatrix(matrix1, n, n);
	int** matrix2 = createintMatrix(n, n);
	readintMatrix(matrix2, n, n);
	int** summedMatrix = createintMatrix(n, n);
	summedMatrix1andMatrix2(summedMatrix, matrix1, matrix2, n);
	print(summedMatrix, n, n);
	freeintMatrix(matrix1, n);
	freeintMatrix(matrix2, n);
	freeintMatrix(summedMatrix, n);

}

//Задача 1: От стандартния вход се приемат две естествени числа N и M и се чете матрица NxM. 
//Да се напише функция, принтира матрицата, но на мястото на всяко четно число извежда *.
//Задача 2: От стандартния вход се чете число N и се въвежда матрица NxN от цели числа. Да се изведе сумата на
//Всички четни елементи над главния диагонал(без него).
//Всички нечетни елементи под главния диагонал(с него).
//Всички елементи на вторичния диагонал повдигнати на квадрат.
//Задача 3: От стандартния вход се чете естествено число N и две матрици NxN. Напишете функция, събира двете матрици и връща резултата като нова матрица.
//Задача 4: От стандартния вход се въвеждат две числа N и M.След това от стандартния вход се четат две матрици с размери NxM и MxN.Напишете функция, 
//която връща произведението на двете матрици.