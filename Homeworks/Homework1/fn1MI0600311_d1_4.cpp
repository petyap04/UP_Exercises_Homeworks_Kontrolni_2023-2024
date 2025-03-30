/**

*

* Solution to homework assignment 1

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

bool verificationOfInput(unsigned int yearBefore, unsigned int monthBefore, unsigned int dateBefore,
    unsigned int yearAfter, unsigned int monthAfter, unsigned int dateAfter,
    unsigned int interval) {
    if (interval < 1 || interval>365) {
        return 0;
    }
    if (yearBefore > yearAfter || yearBefore < 1600 || yearAfter>2100) {
        return 0;
    }
    if (monthBefore > 12 || monthBefore < 1 || monthAfter>12 || monthAfter < 1) {
        return 0;
    }
    if (dateBefore > 31 || dateAfter > 31 || dateBefore < 1 || dateAfter < 1) {
        return 0;
    }
    if (yearBefore == 1916 && monthBefore == 4 && dateBefore >= 1 && dateBefore <= 13) {
        return 0;
    }
    if (yearAfter == 1916 && monthAfter == 4 && dateAfter >= 1 && dateAfter <= 13) {
        return 0;
    }
    return 1;
}
void newStyle(unsigned int& year, unsigned int& month, unsigned int& date) {
    if (year % 4 == 0 && year % 100 != 0) {
        if (date >= 30) {
            date -= 29;
            month++;
        }
    }
    else if (year % 400 == 0) {
        if (date >= 30) {
            date -= 29;
            month++;
        }
    }
    else if (date >= 29) {
        date -= 28;
        month++;
    }

}
void oldStyle(unsigned int& year, unsigned int& month, unsigned int& date) {
    if (year % 4 == 0) {
        if (date >= 30) {
            date -= 29;
            month++;
        }
    }
    else {
        date -= 28;
        month++;
    }
}
void february(unsigned int& year, unsigned int& month, unsigned int& date) {
    if (year <= 1916) {
        oldStyle(year, month, date);
    }
    else
        newStyle(year, month, date);
}
void April1916(unsigned int currentYear, unsigned int currentMonth, unsigned int& currentDate, unsigned int yBefore, unsigned int mBefore, unsigned int dBefore) {
    bool hasNotPassedYet = true;
    if (currentYear == 1916 && mBefore < 4) {
        currentDate += 13;
        hasNotPassedYet = false;
    }
}
void dateBiggerThenTheMonth(unsigned int& currentYear, unsigned int& currentMonth, unsigned int& currentDate, unsigned int yBefore, unsigned int mBefore, unsigned int dBefore) {
    while (currentDate > 31) {
        switch (currentMonth) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:currentDate -= 31;
            currentMonth++; break;
        case 4:April1916(currentYear, currentMonth, currentDate, yBefore, mBefore, dBefore);
        case 6:
        case 9:
        case 11:currentDate -= 30;
            currentMonth++; break;
        case 2:
            february(currentYear, currentMonth, currentDate); continue;
        case 12:currentDate -= 31;
            currentMonth = 1;
            currentYear++; break;
        }
    }
}
void validationOfCurrentDate(unsigned int currentYear, unsigned int currentMonth, unsigned int& currentDate) {
    if (currentYear == 1916 && currentMonth == 4 && currentDate == 1) {
        currentDate = 14;
    }
}

void calendar(unsigned int yBefore, unsigned int mBefore, unsigned int dBefore, unsigned int yAfter,
    unsigned int mAfter, unsigned int dAfter, unsigned int i) {
    unsigned int currentYear = yBefore;
    unsigned int currentMonth = mBefore;
    unsigned int currentDate = dBefore;
    while (!(currentYear >= yAfter && currentMonth >= mAfter && currentDate >= dAfter)) {
        validationOfCurrentDate(currentYear, currentMonth, currentDate);
        cout << currentYear << " " << currentMonth << " " << currentDate << " - ";
        currentDate += i - 1;
        if (currentYear == yAfter && currentMonth == mAfter && currentDate > dAfter) break;
        dateBiggerThenTheMonth(currentYear, currentMonth, currentDate, yBefore, mBefore, dBefore);
        switch (currentMonth) {
        case 4:April1916(currentYear, currentMonth, currentDate, yBefore, mBefore, dBefore);
        case 6:
        case 9:
        case 11:
            if (currentDate == 31) {
                currentDate -= 30;
                currentMonth++;
            }break;
        case 2:
            february(currentYear, currentMonth, currentDate);
            break;
        }
        if (currentYear >= yAfter && currentMonth >= mAfter && currentDate >= dAfter) {
            break;
        }
        else {
            cout << " " << currentYear << " " << currentMonth << " " << currentDate << endl;
        }
        currentDate++;
        dateBiggerThenTheMonth(currentYear, currentMonth, currentDate, yBefore, mBefore, dBefore);
    }
    if (currentYear == yAfter && currentMonth == mAfter && currentDate == dAfter) {
        cout << currentYear << " " << currentMonth << " " << currentDate << " - " << yAfter << " " << mAfter << " " << dAfter;
    }
    else
        cout << yAfter << " " << mAfter << " " << dAfter;
}

int main()
{
    unsigned int yearBefore, monthBefore, dateBefore;
    unsigned int yearAfter, monthAfter, dateAfter;
    unsigned int interval;
    cin >> yearBefore >> monthBefore >> dateBefore >> yearAfter >> monthAfter >> dateAfter >> interval;
    if (!verificationOfInput(yearBefore, monthBefore, dateBefore, yearAfter, monthAfter, dateAfter, interval)) {
        cout << "Incorrect input";
    }
    calendar(yearBefore, monthBefore, dateBefore, yearAfter, monthAfter, dateAfter, interval);
}