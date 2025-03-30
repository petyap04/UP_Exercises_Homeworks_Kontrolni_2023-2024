/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Petya Petrova
* @idnumber 1MI0600311
* @task 2
*
*/
#include <iostream>
using namespace std;
constexpr int MAX_SIZE = 1000;
unsigned myStrlen(const char* str){
	if (!str)
		return 0;
	unsigned result = 0;
	while (*str) {
		result++;
		str++;
	}
	return result;
}
bool isNumber(char ch) {
	return ch >= '0' && ch <= '9';
}
bool isLower(char ch){
	return ch >= 'a' && ch <= 'z';
}
bool isUpper(char ch){
	return ch >= 'A' && ch <= 'Z';
}
void myStrcpy(const char* source, char* dest){
	if (!source || !dest)
		return;
	while (*source){
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}
int myStrcmp(const char* first, const char* second) {
	if (!first || !second)
		return 0; 
	while ((*first) && (*second) && ((*first) == (*second))) {
		first++;
		second++;
	}
	return (*first - *second);
}
unsigned int powerOfTwo(unsigned int n){
	if (n > 31)
		return 0; 
	return 1 << n;
}
char** createMatrix(int rows, int colls){
	char** matrix = new char* [rows];
	for (int i = 0; i < rows; i++){
		matrix[i] = new char[colls];
	}
	return matrix;
}
void freeMatrix(char** matrix, int rows){
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void readStr(const char* pattern, char** strWithAllpossibilities, int allCombinations) {
	if (!pattern && !strWithAllpossibilities) {
		return;
	}
	while (allCombinations != 0) {
		myStrcpy(pattern, *strWithAllpossibilities);
		strWithAllpossibilities++;
		allCombinations--;
	}
}
int numberOfPercents(const char* pattern) {
	if (!pattern) {
		return -1;
	}
	unsigned int count = 0;
	while (*pattern) {
		if(*pattern=='%'){
			count++;
		}
		pattern++;
	}
	return count;
}
void fillSymbolInMask(char** strWithAllpossibilities, int rows, unsigned int* arrWithCountOfSymbols, unsigned int& step) {
	unsigned parts = rows / step;// 8/4 = 2
	unsigned indexOfColls;
	for (int i = 0; i < rows; i++) {
		indexOfColls = arrWithCountOfSymbols[i];
		strWithAllpossibilities[i][indexOfColls] = '$';
		arrWithCountOfSymbols[i]++;
	}
	for (int i = 0; i < parts; i++) {
		for (int j = 0; j < step; j++) {
			if (i % 2 != 0) {
				unsigned indexRow = i * step + j;
				unsigned indexOfColls = arrWithCountOfSymbols[indexRow];
				strWithAllpossibilities[indexRow][indexOfColls] = '$';
				arrWithCountOfSymbols[indexRow]++;
			}
		}
	}
	step /= 2;
}
void fillStrWithZiros(char* strWithAllpossibilities) {
	if (!strWithAllpossibilities) {
		return;
	}
	while (*strWithAllpossibilities) {
		*strWithAllpossibilities = '\0';
		strWithAllpossibilities++;
	}
}
void revomeDuplicates(char** strWithAllpossibilities, int rows) {
	if (!strWithAllpossibilities) {
		return;
	}
	for (int i = 0; i < rows - 1; i++) {
		for(int j = i + 1; j < rows; j++){
			if (myStrcmp(strWithAllpossibilities[i], strWithAllpossibilities[j]) == 0) {
				fillStrWithZiros(strWithAllpossibilities[j]);
			}
		}
	}
}
void isPartOfTheMask(const char* text, const char* strWithAllpossibilities, int indexOfText, int indexOfPoss, int& count) {
	if (!text && !strWithAllpossibilities) {
		return;
	}
	if (!(strWithAllpossibilities[indexOfPoss])) {
		count++;
	}
	else if (strWithAllpossibilities[indexOfPoss] == '*') {
		indexOfText++;
		indexOfPoss++;
		isPartOfTheMask(text, strWithAllpossibilities, indexOfText, indexOfPoss, count);
	}
	else if (strWithAllpossibilities[indexOfPoss] == '@') {
		if (isLower(text[indexOfText]) || isUpper(text[indexOfText])) {
			indexOfText++;
			indexOfPoss++;
			isPartOfTheMask(text, strWithAllpossibilities, indexOfText, indexOfPoss, count);
		}
	}
	else if (strWithAllpossibilities[indexOfPoss] == text[indexOfText]) {
		indexOfText++;
		indexOfPoss++;
		isPartOfTheMask(text, strWithAllpossibilities, indexOfText, indexOfPoss, count);
	}
	else if (text[indexOfText] != '\0' && strWithAllpossibilities[indexOfPoss] == '$') {
		if (isNumber(text[indexOfText])) {
			indexOfText++;
			indexOfPoss++;
			isPartOfTheMask(text, strWithAllpossibilities, indexOfText, indexOfPoss, count);
		}
	}
	else
		indexOfText++;
}
void countOfAllTruePatterns(const char* text, char** strWithAllpossibilities, unsigned int* arrWithCountOfSymbols, int rows, int& count, unsigned int lenOfText) {
	if (!strWithAllpossibilities) {
		return;
	}
	int indexOfText = 0;
	int indexOfPoss = 0;
	for (int i = 0; i < rows; i++) {
		indexOfText = 0;
		if (strWithAllpossibilities[i][0] == '\0')continue;
		while (indexOfText < lenOfText) {
			indexOfPoss = 0;
			isPartOfTheMask(text, strWithAllpossibilities[i], indexOfText, indexOfPoss, count); 
			indexOfText++;
		}
	}
}
void makeMasks(const char* text, const char* pattern, int numberOfPercents, int& count, unsigned int lenOfText) {
	if (!pattern) {
		return;
	}
	int rows = powerOfTwo(numberOfPercents);
	char** strWithAllpossibilities = createMatrix(rows, MAX_SIZE);
	unsigned int step = rows / 2;
	unsigned int* arrWithCountOfSymbols = new unsigned int[rows] {0};
	int index = 0;
	int indexOfColls;
	while (pattern[index] != '\0') {
		if (pattern[index] != '%') {
			for (int i = 0; i < rows; i++) {
				indexOfColls = arrWithCountOfSymbols[i];
				strWithAllpossibilities[i][indexOfColls] = pattern[index];
				arrWithCountOfSymbols[i]++;
			}
			index++;
		}
		else {
			fillSymbolInMask(strWithAllpossibilities, rows, arrWithCountOfSymbols, step);
			numberOfPercents--;
			index++;
		}
	}
	for (int i = 0; i < rows; i++) {
		indexOfColls = arrWithCountOfSymbols[i];
		strWithAllpossibilities[i][indexOfColls] = '\0';
	}
	revomeDuplicates(strWithAllpossibilities, rows);
	countOfAllTruePatterns(text, strWithAllpossibilities, arrWithCountOfSymbols, rows, count, lenOfText);
	freeMatrix(strWithAllpossibilities, rows);
	delete[]arrWithCountOfSymbols;
}
void isPartOfThePattern(const char* text, const char* pattern, int& count) {
	if (!text && !pattern) {
		return;
	}
	if (!(*pattern)) {
		count++;
	}
	else if (*pattern == '*') {
		pattern++;
		text++;
		isPartOfThePattern(text, pattern, count);
	}
	else if (*pattern == '@') {
		if (isLower(*text) || isUpper(*text)) {
			pattern++;
			text++;
			isPartOfThePattern(text, pattern, count);
		}
	}
	else if (*pattern == *text) {
		pattern++;
		text++;
		isPartOfThePattern(text, pattern, count);
	}
}
unsigned int timesPatternSeen(const char* text, const char* pattern) {
	if (!text && !pattern) {
		return -1;
	}
	unsigned int lenOfText = myStrlen(text);
	unsigned int lenOfPattern = myStrlen(pattern);
	if (lenOfText < lenOfPattern)
		return 0;
	int count = 0;
	int percents = numberOfPercents(pattern);
	if (percents) {
		makeMasks(text, pattern, percents, count, lenOfText);
	}
	else {
		while (*text) {
			isPartOfThePattern(text, pattern, count);
			text++;
		}
	}
	return count;
}
int main()
{
	char text[MAX_SIZE];
	char pattern[MAX_SIZE];
	cin.getline(text, MAX_SIZE, '\n');
	cin.getline(pattern, MAX_SIZE, '\n');
	cout << timesPatternSeen(text, pattern);
}