#include <iostream>
using namespace std;
constexpr int SIZE = 7;
int numberWithoutAPair(const int arr[], size_t size) {
    int result = 0;
    for (unsigned i = 0; i < size; i++)
        result ^= arr[i];
    return result;
}
int countOfOne(int number) {
    int count = 0;
    while (number != 0) {
        int binaryNum = number % 2;
        count += binaryNum;
        number /= 2;
    }
    return count;
}

int main()
{
    int number;
    cin >> number;
    cout << countOfOne(number);
}

//Задача 1: Да се напише функция, която приема масив, в който всяко число се среща 2 пъти с изключение на едно число, което се среща веднъж. 
// Напишете функция, която приема такъв масив и връща кое е това число. (Подсказка: използвайте побитови операции, за да постигнете линейно решение)
// Вход: [9 18 9 12 18 15 12] , Изход : 15
//Задача 2: Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.
//Вход: 189, Изход : 6