#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class AdditionalMethods
{
    static bool checkingAmountInput(string isProperAmountString);
    static bool isThereOneCommaInTheString(string amountString);
    static string changeCommaToDot(string amountWithComma);

public:
    static string readLine();
    static string intToStringConversion(int number);
    static string changeFirstLetterToCapitalAndOthersToSmall(string text);
    static string getNumber(string text, int charPosition);
    static int stringToIntConversion(string number);
    static char chooseOptionFromMainMenu();
    static char chooseOptionFromLoggedUserMenu();
    static char readChar();
    static double readDouble();
};

#endif // ADDITIONALMETHODS_H
