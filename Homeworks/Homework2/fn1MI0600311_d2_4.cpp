/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Petya Petrova
* @idnumber 1MI0600311
* @task 4
*
*/
#include <iostream>
using namespace std;
void readMatrix(int** matrix, int rows, unsigned int colls) {
	for (unsigned int j = 1; j < colls; j++) {
		int number;
		cin >> number;
		matrix[rows][j] = number;
	}
}
int** createMatrix(int rows){
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++){
		unsigned int colls;
		cin >> colls;
		matrix[i] = new int[colls + 1];
		readMatrix(matrix, i, colls + 1);
		matrix[i][0] = colls;
	}
	return matrix;
}
void freeMatrix(int** matrix, unsigned int rows){
	for (unsigned int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void print(int** matrix, unsigned int rows){
	for (unsigned int i = 0; i < rows; i++){
		unsigned int sizeOfRow = matrix[i][0];
		for (unsigned int j = 1; j < sizeOfRow + 1; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
}
void increasingWay(int** matrix, int rows, unsigned int& length, unsigned int& currentLength, int priviousDigit, int x, int y) {

	priviousDigit = matrix[x][y];
	for (int i = x - 1; i <= x + 1; i++) {
		if (i >= 0 && i < rows){
		    for (int j = y - 1; j <= y + 1; j++) {
			    if (j >= 1 && j <= matrix[i][0]) {
				    if (matrix[i][j] > priviousDigit) {
					    currentLength++;
                        if (currentLength > length) {
					  	    length = currentLength;
                        }
					    increasingWay(matrix, rows, length, currentLength, priviousDigit, i, j);
				    }
			    }
		    }
		}
	}
	currentLength--;
}
void longestIncreasingWay(int** matrix, int rows, unsigned int& length) {
	int priviousDigit;
	for (int x = 0; x < rows ; x++){
		for (int y = 1; y <= matrix[x][0]; y++){
			priviousDigit = matrix[x][y];
			unsigned int currentLength = 1;
			increasingWay(matrix, rows, length, currentLength, priviousDigit, x, y);
		}
	}
}
int main(){
    int rows;
    cin >> rows;
	int** matrix = createMatrix(rows);
	unsigned int lengthOfTheWay = 0;
	longestIncreasingWay(matrix, rows, lengthOfTheWay);
	cout << lengthOfTheWay;
	freeMatrix(matrix, rows);
}


