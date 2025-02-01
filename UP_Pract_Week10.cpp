#include <iostream>
using namespace std;

int myStrlen(const char* str) {
	if (!str) {
		return 0;
	}
	unsigned int result = 0;
	while (*str) {
		result++;
		str++;
	}
	return result;
 }
bool isPalindrome(const char* str, unsigned int len, char* first, char* last) {
	if (!str) {
		return 0;
	}
	for (unsigned int i = 0; i < len / 2; i++) {
		if (*first != *last) {
			return 0;
		}
		first++;
		last++;
	}
	return 1;
}
void changeTheSizeOfSymbol(char* str, unsigned int len) {//защо не бачка 
	if (!str) {
		return;
	}

	while (*str) {
		if (*str >= 'a' && *str <= 'z') {
			*str -= 32;
		}
		else if (*str >= 'A' && *str <= 'Z') {
			*str += 32;
		}
		str++;
	}
}
void fillArr(bool* arr, size_t size, bool defaultValue) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = defaultValue;
	}
}
int toDigit(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	{
		return symbol - 'a';
	}

	return -1;
}
bool checkUniqueLetters(char* str) {
	bool charCheckArr[26];
	fillArr(charCheckArr, 26, 0);
	while (*str) {
		int currLetterIndex = toDigit(*str);

		if (charCheckArr[currLetterIndex] == true) {
			return false;
		}

		charCheckArr[currLetterIndex] = true;
		str++;
	}

	return true;
}
void functionWithTheNewIndex(const char* text, char* result, char symbol, unsigned int index) {
	if (!text && !result) {
		return;
	}
	int len = myStrlen(text) + 1;
	for (size_t i = 0; i < len; i++) {
		if (i == index) {
			*result = symbol;
		}
		else {
			*result = *text;
			text++;
		}
	result++;
	}
	*result = '\0';
}
int fromSymbolToDigit(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		return symbol - '0';
	}
}
char fromIndexToSymbol(int index) {
	if (index >= 0 && index <= 9) {
		return index + '0';
	}
}
void fillArrWithValue(bool* arr) {
	if (!arr) {
		return;
	}
	while (*arr) {
		*arr = false;
		arr++;
	}
}
void fillingOfResult(const char* text, char* result, int lencopy, int index) {
	if (!text || !result) {
		return;
	}
	unsigned int count = 0;
	while (lencopy != 0)
	{
		if (fromSymbolToDigit(*text) == index) {
			count++;
		}
		lencopy--;
		text++;
	}
	*result = fromIndexToSymbol(count);
}
void timesNumberUsed(char* text, char* result) {
	if (!text || !result) {
		return;
	}
	
	bool arr[10];
	fillArrWithValue(arr);
	int len = myStrlen(text);
	
	while (*text) {
		int lencopy = len;
		char symbol = *text;
		int index = fromSymbolToDigit(symbol);
		if(!arr[index]) {
			fillingOfResult(text, result, lencopy, index);
			arr[index] = true;
		}
		
		len--;
		text++;
		result++;
	}
}


int main()
{

	char text[] = { "1616546449" };
	char result[10];
	timesNumberUsed(text, result);
	for (int i = 0; i < 10; i++) {
		cout << result[i] << "x" << i;
	}
		
}

//Задача 1: Да се напипе функция, която приема симовлен низ и провеява дали низът е палиндром.
//Задача 2: Да се напише функция, която приема символен низ и превръща всички негови главни букви в малки и всички малки в главни.
//Задача 3: Напишете функция, която проверява дали всички букви в символен низ са уникални. За улеснение работим само с малките букви от английската азбука.
//Задача 4: Да се напише функция, която приема стрингове text и result, символ symbol и индекс i и обработва така result, че да представлява стринг,
//в който е вмъкнат symbol в text на позиция i.
//Задача 5: Да се напише функция, която приема стринг с произволна дължина от цифри, и стринг result. Функцията да обработва result така, че да предтсавлява стринг,
//в който пише коя цифра колко пъти се среща.

