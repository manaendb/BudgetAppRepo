#include "AdditionalMethods.h"

string AdditionalMethods::readLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

string AdditionalMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AdditionalMethods::changeFirstLetterToCapitalAndOthersToSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AdditionalMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int AdditionalMethods::stringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char AdditionalMethods::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. User registration" << endl;
    cout << "2. Login User" << endl;
    cout << "3. Write down all User's passwords and logins >>Testing<<" << endl;
    cout << "9. End of the program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}

char AdditionalMethods::chooseOptionFromLoggedUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl; //Dodaj przychod
    cout << "2. Add expense" << endl; //Dodaj wydatek
    cout << "3. Current month's balance sheet" << endl; //Bilans z bie¿¹cego miesi¹ca
    cout << "4. Previous month's balance sheet" << endl; //Bilans z poprzedniego miesi¹ca
    cout << "5. Balance sheet from the selected period" << endl; //Bilans z wybranego okresu
    cout << "---------------------------" << endl;
    cout << "8. Change password" << endl; //Zmien haslo
    cout << "9. Log out" << endl; //Wyloguj sie
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = readChar();

    return choice;
}

char AdditionalMethods::readChar()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        cout << "That is not a single character. Please enter again." << endl;
    }
    return sign;
}

bool AdditionalMethods::checkingAmountInput(string isProperAmountString)
{
    int howManyDotsInString = 0;
    int lengthOfTheString = isProperAmountString.length();
    if (lengthOfTheString == 0)
        return false;
    int whereInTheStringDotAccured = lengthOfTheString;

    for (int i = 0; i < lengthOfTheString; i++)
    {
        if ((isdigit(isProperAmountString[i]) == false) && (isProperAmountString[i] != '.'))
            return false;
        else if ((isProperAmountString[i] == '.') && (howManyDotsInString < 1) && (lengthOfTheString - whereInTheStringDotAccured <= 2))
        {
            howManyDotsInString += 1;
            whereInTheStringDotAccured = i + 1;
        }
        else if (howManyDotsInString > 1)
            return false;
        else if (lengthOfTheString - whereInTheStringDotAccured > 2)
            return false;
    }
    return true;
}

bool AdditionalMethods::isThereOneCommaInTheString(string amountString)
{
    int howManyDotsInString = 0;
    int lengthOfTheString = amountString.length();
    for (int i = 0; i < lengthOfTheString; i++)
    {
        if ((amountString[i] == ','))
        {
            howManyDotsInString += 1;
        }
        else if (howManyDotsInString > 1)
            return false;
    }
    return true;
}

string AdditionalMethods::changeCommaToDot(string amountWithComma)
{
    int lengthOfTheString = amountWithComma.length();
    for (int i = 0; i < lengthOfTheString; i++)
    {
        if (amountWithComma[i] == ',')
        {
            amountWithComma[i] = '.';
        }
    }
    return amountWithComma;
}

double AdditionalMethods::readDouble()
{
    string entry = "";
    double number = 0.0;

    while (true)
    {
        getline(cin, entry);

        if (isThereOneCommaInTheString(entry))
            entry = changeCommaToDot(entry);
        if (!checkingAmountInput(entry))
            cout << "That is not correct double number with up to 2 decimal places. Please enter again. " << endl;
        else
        {
            stringstream myStream(entry);
            myStream >> number;
            break;
        }
    }
    return number;
}
