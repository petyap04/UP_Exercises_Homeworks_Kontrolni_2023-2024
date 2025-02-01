//binary search
#include <iostream>

int binarySearch(const int arr[], size_t size, int searched) {
	unsigned left = 0;
	unsigned right = size - 1;

	while (left <= right) {
		unsigned mid = (left + right) / 2;
		if (arr[mid] == searched) {
			return mid;
		}
		else if (arr[mid] < searched) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}


unsigned binaryToDecimal(unsigned int number) {
	unsigned result = 0;
	unsigned mult = 0;
	while (number) {
		if (number % 10 == 1) {
			result += 1 << mult;
		}
		mult++;
		number /= 10;
	}
	return result;
}

unsigned decimalToBinary(unsigned number) {
	unsigned result = 1;
	while (number > 1) {
		(result *= 10) += number % 2;
		number /= 2;
	}
	return result;
}
int charToInt(char ch) {
	if (ch >= '0' && ch < '9') {
		return ch - '0';
	}
	else if(ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 10;
	}
	return -1;
}
unsigned fromKToDecimal(const char arr[],size_t size, unsigned k) {
	unsigned result = 0;
	for (int i = size - 1, mult = 1; i >= 0; i--, mult*=k) {
		int curr = charToInt(arr[i]);
		result += (mult * curr);
	}
	return result;
}

char intToChar(int i) {
	if (i >= 0 && i <= 9) {
		return '0' + i;
	}
	else {
		return 'A' + i - 10;
	}
}
void fromDecimalToK(unsigned number, char arr[], size_t size, unsigned k) {
	unsigned result = 0;
	for (int i = size - 1; i >= 0, number != 0; i--) {
		char ch = intToChar(number % k);
		arr[i] = ch;
		number /= k;
	}
}

//Задача 1: Да се напише функция, която приема масив, в който всяко число се среща 2 пъти с изключение на едно число, което се среща веднъж.
//Напишете функция, която приема такъв масив и връща кое е това число. (Подсказка: използвайте побитови операции, за да постигнете линейно решение)


int whichDoesNotHavePair(const int arr[], size_t size) {
	int result = 0;
	for (int i = 0; i < size; i++) {
		result ^= arr[i];
	}
	return result;
}

//Задача 2: Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.

unsigned countOfOnes(int number) {
	unsigned count = 0;
	while (number) {
		if (number & 1 == 1) {
			count++;
		}
		number = number >> 1;
	}
	return count;
}

//Задача 3 : Напишете функция, която приема цяло число и обръща най-десния бит в него, който е единица.

void reverseFirstZero(int& number) {
	if (number == 0) {
		return;
	}
	int curr = 0;
	while (true) {
		if ((number | 1<<curr) == number) {
			number ^= 1 << curr;
			break;
		}
		curr++;
	}
}



int main() {
	constexpr size_t size = 5;
	char matrix[size];
}