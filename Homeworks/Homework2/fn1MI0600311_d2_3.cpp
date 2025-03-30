/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Petya Petrova
* @idnumber 1MI0600311
* @task 3
*
*/
#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 64;
void swap(char* str, int index1, int index2) {
	if (!str) {
		return;
	}
	char temp = str[index1];
	str[index1] = str[index2];
	str[index2] = temp;
}
unsigned myStrlen(const char* str) {
	if (!str)
		return 0;
	unsigned result = 0;
	while (*str) {
		result++;
		str++;
	}
	return result;
}
void makeItLexicographic(char* str, size_t size) {
	if (!str) {
		return;
	}
	unsigned int index = 0;
	while (*str) {
		char smallestElement = *str;
		unsigned int indexOfSmallerElement = 0;
		for (unsigned int i = 0; i < size; i++) {
			if (str[i] < smallestElement) {
				smallestElement = str[i];
				indexOfSmallerElement = i;
			}
		}
		swap(str, index, indexOfSmallerElement);
		str++;
		size--;
	}
}
void myReverse(char* str, int start, int end) {
	while (start < end) {
		swap(str, start++, end--);
	}
}
bool nextPerm(char* str, size_t size) {
	int current = size - 1;
	while (current > 0 && str[current] <= str[current - 1])
		current--;
	current--;
	if (current == -1)
		return false;
	int other = size - 1;
	while (str[other] <= str[current])
		other--;
	swap(str, other, current);
	myReverse(str, current + 1, size - 1);
	return true;
}
int main()
{
	char str[MAX_SIZE];
	cin >> str;
	int n;
	cin >> n;
	size_t size = myStrlen(str);
	makeItLexicographic(str, size);
	if (n > 0) {
		cout << str << endl;
		n--;
		while (n > 0 && nextPerm(str, size)) {
			cout << str << endl;
			n--;
		}
	}
}