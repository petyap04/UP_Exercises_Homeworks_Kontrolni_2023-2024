#include <iostream>
using namespace std;
constexpr int SIZE = 2;

void readArray(char* arr, size_t size) {
	for (int i = 0; i < size; i++) {
	  cin >> arr[i];
	}
}

int symbolToIndex(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return symbol - '0';
	}
	if (symbol >= 'A' && symbol <= 'Z') {
		return symbol - '0' + 10;
	}
	if (symbol >= 'a' && symbol <= 'z') {
		return symbol - '0' + 10;
	}
	return -1;
}
int fromKtoDecimal(char* arr, size_t size, int k) {
	if (!arr)
		return -1;
	int result = 0;
	while (size!=0) {
		int index = symbolToIndex(*arr);
		result += index * k;
		result *= 10;
		arr++;
		size--;
	}
	return result;
}

int main()
{
	char arr[SIZE];
	readArray(arr, SIZE);
	int k;
	cin >> k;
	cout << fromKtoDecimal(arr, SIZE, k);
	
}