#include <iostream>
using namespace std;
int poweredByTwo( int k) {
	return 1 << k;
}
int bitOnPossitionM( int n, int m) {
	unsigned int mask = 1;
	return (mask << m) & n;
}
int changeBitOnPossitionM( int n, int m) {
	unsigned int mask = 1;
	return (mask << m) ^ n;
}
int numberAfter(int x, int m, int n) {
	x = x >> (m - 1);
	unsigned mask = (1 << n) - 1;
	return x & mask;
}
void swopValue(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	/*int x, m, n;
	cin >> x >> m >> n;
	cout << numberAfter(x, m, n);*/

	int a, b;
	cin >> a >> b;
	swopValue(a, b);
	cout << a << " " << b;
}


//Задача 1: Да се напише функция, която приема число k, между 0 и 31 и връща 2^k.
//Задача 2: Да се напише функция, която приема 2 цели числа N и M и връща бита на позиция M в числото N (отзад напред, започвайки от 0).
//Задача 3: Да се напише функция, която приема 2 цели числа N и M и връща стойността на числото N
//с променена стойност на бита на позиция M (отзад напред, започвайки от 0).
//Задача 4: Да се напише функция, която приема 3 цели числа x, m и n и връща числото, което се получава, ако от x се вземат n бита, започвайки от позиция m.
//Задача 6: Да се напише функция, която приема 2 цели числа a и b и разменя стойностите им без допълнителна променлива с побитови операции.