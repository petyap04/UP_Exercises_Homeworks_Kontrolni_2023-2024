#include <iostream>
using namespace std;
unsigned reverse(unsigned number) {
    unsigned result = 0;
    while (number) {
        (result *= 10) += number % 10;
        number /= 10;
    }
    return result;
}
unsigned concat(unsigned a, unsigned b) {
    if (a == 0) {
        return 0;
    }
    unsigned result = a;
    unsigned temp = reverse(b);
    while (temp) {
        (result *= 10) += temp % 10;
        temp /= 10;
    }
    while (b % 10 == 0) {
        result *= 10;
        b /= 10;
        if (b == 0) {
            break;
        }
    }
    return result;
}
long findSeq(const char* arr, char s) {
    if (!arr) {
        return 0;
    }
    unsigned count = 0;
    unsigned currCount = 0;
    while (*arr) {
        if (*arr == s) {
            currCount++;
        }
        else {
            if (count < currCount) {
                count = currCount;
            }
            currCount = 0;
        }
        arr++;
    }
    return count;
}
unsigned myStrLen(const char* word) {
    if (!word) {
        return 0;
    }
    unsigned len = 0;
    while (*word) {
        len++;
        word++;
    }
    return len;
}
bool findWordInStr(const char* str, const char* word) {
    if (!word) {
        return false;
    }
    unsigned len = myStrLen(word);
    unsigned currInd = 0;
    while (*str) {
        
        if (*str == word[currInd]) {
            currInd++;
            if (len - currInd == 0) {
            return true;
            }
        }
        else {
            currInd = 0;
        }
        str++;
    }
    return false;
}
bool findThatVert(const char* const* grid, size_t M, size_t N, const char* word, size_t col) {
    if (!word) {
        return false;
    }
    unsigned len = myStrLen(word);
    unsigned currInd = 0;
    for (size_t i = 0; i < M; i++) {
        if (len - currInd == 0) {
            return true;
        }
        if (grid[i][col] == word[currInd]) {
            currInd++;
        }
        else {
            currInd = 0;
        }
    }
    return false;
}
bool findVertical(const char* const* grid, size_t M, size_t N, const char* word) {
    unsigned len = myStrLen(word);
    if (len > M) {
        return false;
    }
    for (size_t i = 0; i < N; i++) {
        findThatVert(grid, M, N, word, i);
    }
}
bool findHorriz(const char* const* grid, size_t M, size_t N, const char* word) {
    unsigned len = myStrLen(word);
    if (len > N) {
        return false;
    }
    for (size_t i = 0; i < M; i++) {
        findWordInStr(grid[i], word);
    }
}
bool findWord(const char* const* grid, size_t red, size_t col, const char* word) {
    return findHorriz(grid, red, col, word) || findVertical(grid, red, col, word);
}
void mask(const int arr[], size_t size, int* newArr, int& currIndex, int mask) {
    for (int i = 0; i < size; i++) {
        if (mask % 2 != 0) {
            newArr[currIndex++] = arr[i];
        }
        mask /= 2;
    }
    newArr[currIndex++] = 0;
}
int* findSets(const int arr[], size_t size) {
    int pt = (1 << size) - 1;
    int newSize = pt * size + pt - 1 + 2;
    int* newArr = new int[newSize];
    int currInd = 0;
    for (int i = 1; i <= pt; i++) {
        mask(arr, size, newArr, currInd, i);
    }
    newArr[currInd] = 0;
    return newArr;
}

void ins(int* arr, size_t size) {
    for (int i = 1; i < size; i++) {
        int currInd = i;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[currInd]) {
                std::swap(arr[j], arr[currInd]);
                currInd--;
            }
            else {
                break;
            }
        }
    }
}

int main()
{
    /*const char* grid1 = "onn";
    const char* grid2 = "bwo";
    const char* grid3 = "ehnee";
    const char* grid4 = "foer";
    const char* grid5 = "five";
    const char* grid[5];
    grid[0] = grid1;
    grid[1] = grid2;
    grid[2] = grid3;
    grid[3] = grid4;
    grid[4] = grid5;
    cout<<findWord(grid, 5, 6, "one");*/
    int arr[] = { 5,12,3,7,26,8 };
    ins(arr, 6);
    for (int i = 0; i < 6; i++) {
        cout << arr[i]<<" ";
    }
    
}
