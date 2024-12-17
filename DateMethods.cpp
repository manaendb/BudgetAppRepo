#include "DateMethods.h"

bool DateMethods::isTheYearALeapYear(int year) //isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    return false;
}

int DateMethods::howManyDaysAMonthHasFromTheGivenDate(int year, int month, int day) //how many days a month has from the given date; ileDniMaMiesiacZPodanejDaty
{
    int daysInTheMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //dniWMiesiacu

    if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31 || year > currentDate().year || (year == currentDate().year && month > currentDate().month))
        return 0;

    if (isTheYearALeapYear(year) && month == 2)
        daysInTheMonth[month - 1]++;

    return daysInTheMonth[month - 1];
}

string DateMethods::dateIntToStringWithDashes(int dateInt)
{
    stringstream ss;
    ss << dateInt;
    string dateString = ss.str();
    dateString.insert(4, 1, '-');
    dateString.insert(7, 1, '-');
    return dateString;
}

bool DateMethods::hasInputStringCorrectConstruction(string isProperDateString)
{
    int lenghtOfTheString = isProperDateString.length();
    if (lenghtOfTheString != 10)
        return false;
    for (int i = 0; i < lenghtOfTheString; i++)
    {
        if (i == 4 || i == 7)
        {
            if (isProperDateString[i] != '-')
                return false;
        }
        else
        {
            if (isdigit(isProperDateString[i]) == false)
                return false;
        }
    }
    return true;
}

bool DateMethods::isTheDateCorrect(string dateString) //czyDataJestPoprawna
{
    if (!hasInputStringCorrectConstruction(dateString))
        return false;
    Date date;
    date = stringToDateConversion(dateString);

    int numberOfDays = howManyDaysAMonthHasFromTheGivenDate(date.year, date.month, date.day);
    if (numberOfDays == 0) return false;

    return date.day <= numberOfDays;
}

int DateMethods::howManyDaysTheCurrentMonthHas()
{
    Date actualDate = currentDate();

    return howManyDaysAMonthHasFromTheGivenDate(actualDate.year, actualDate.month, actualDate.day);
}

Date DateMethods::currentDate()
{
    Date currentDate;
    time_t timeNow = time(0);
    tm* now = localtime(&timeNow);

    currentDate.year = now->tm_year + 1900;
    currentDate.month = now->tm_mon + 1;
    currentDate.day = now->tm_mday;

    return currentDate;
}

int DateMethods::currentMonthFirstDayDate()
{
    Date currentMonthFirstDayDate = currentDate();
    currentMonthFirstDayDate.day = 1;

    return dateToInt(currentMonthFirstDayDate);
}

int DateMethods::currentMonthLastDayDate()
{
    Date currentMonthLastDayDate = currentDate();
    currentMonthLastDayDate.day = howManyDaysTheCurrentMonthHas();

    return dateToInt(currentMonthLastDayDate);
}

int DateMethods::previousMonthFirstDayDate()
{
    Date actualDate = currentDate();
    Date previousMonthFirstDayDate;
    previousMonthFirstDayDate.year = actualDate.year;
    actualDate.month == 1 ? previousMonthFirstDayDate.month == 12 : previousMonthFirstDayDate.month = actualDate.month - 1;
    previousMonthFirstDayDate.day = 1;

    return dateToInt(previousMonthFirstDayDate);
}

int DateMethods::previousMonthLastDayDate()
{
    Date actualDate = currentDate();
    Date previousMonthLastDayDate;
    previousMonthLastDayDate.year = actualDate.year;
    actualDate.month == 1 ? previousMonthLastDayDate.month == 12 : previousMonthLastDayDate.month = actualDate.month - 1;
    previousMonthLastDayDate.day = howManyDaysAMonthHasFromTheGivenDate(previousMonthLastDayDate.year, previousMonthLastDayDate.month, 1);

    return dateToInt(previousMonthLastDayDate);
}

Date DateMethods::stringToDateConversion(string dateString)
{
    Date date;
    date.year = stoi(dateString.substr(0, 4));
    date.month = stoi(dateString.substr(5, 2));
    date.day = stoi(dateString.substr(8, 2));
    return date;
}

int DateMethods::dateStringToInt(string dateString)
{
    Date date;
    date = stringToDateConversion(dateString);

    int dateInt = dateToInt(date);
    return dateInt;
}

int DateMethods::dateToInt(Date date)
{
    stringstream ss;
    ss << date.year;
    if (date.month > 0 && date.month < 10)
        ss << "0" << date.month;
    else
        ss << date.month;
    if (date.day > 0 && date.day < 10)
        ss << "0" << date.day;
    else
        ss << date.day;
    string dateToString = ss.str();
    int dateInt = stoi(dateToString);
    return dateInt;
}
