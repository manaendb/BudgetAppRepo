#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

class DateMethods
{
    static bool isTheYearALeapYear(int year);
    static int howManyDaysTheCurrentMonthHas();
    static bool hasInputStringCorrectConstruction(string isProperDateString);
public:

    static Date currentDate();
    static int currentMonthFirstDayDate();
    static int currentMonthLastDayDate();
    static int previousMonthFirstDayDate();
    static int previousMonthLastDayDate();
    static int howManyDaysAMonthHasFromTheGivenDate(int year, int month, int day);
    static string dateIntToStringWithDashes(int dateInt);
    static bool isTheDateCorrect(string dateString);
    static Date stringToDateConversion(string dateString);
    static int dateStringToInt(string dateString);
    static int dateToInt(Date date);
};

#endif // DATEMETHODS
