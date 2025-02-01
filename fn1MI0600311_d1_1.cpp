/**

*

* Solution to homework assignment 1

* Introduction to programming course

* Faculty of Mathematics and Informatics of Sofia University

* Winter semester 2023/2024

*

* @author Petya Petrova

* @idnumber 1MI0600311

* @task 1

*

*/
#include <iostream>
using namespace std;

bool validationOfNumbers(int n, int k) {
	if (n < k) {
		return 0;
	}
	return 1;
}

unsigned int divisorsOfNumber(int number) {
	if (number == 1) {
		return 1;
	}
	int count = 0;
	for (int i = 1; i <= number; i++) {
		if (number % i == 0) {
			count++;
		}
	}
	return count;
}
void satisfyTheEquality(unsigned int k, unsigned int x, unsigned int y, int dx, int dy, unsigned int& count) {
	if (k * dx * dy == x * y) {
		count++;
	}
}
void yNumber(unsigned int n, unsigned int k, unsigned int x, unsigned int y, int dx, unsigned int& count) {
	while (y <= n && x <= y) {
		int dy = divisorsOfNumber(y);
		satisfyTheEquality(k, x, y, dx, dy, count);
		y++;
	}
}

unsigned int countOfPairs(unsigned int n, unsigned int k) {
	unsigned int x = 1, y = 1;
	unsigned int count = 0;
	while (x <= n && x <= y) {
		int dx = divisorsOfNumber(x);
		yNumber(n, k, x, y, dx, count);
		x++;
		y = x;
	}
	return count;
}

int main()
{
	unsigned int n, k;
	cin >> n >> k;
	if (validationOfNumbers(n, k)) {
		cout << countOfPairs(n, k);
	}
	else
		cout << "Incorrect input";
}
