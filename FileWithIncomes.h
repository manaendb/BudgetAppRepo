#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iomanip>

#include "Income.h"
#include "AdditionalMethods.h"
#include "Markup.h"


using namespace std;

class FileWithIncomes
{
    const string FILE_NAME_WITH_INCOMES;
    int lastIncomeId;

public:
    FileWithIncomes(string fileNameWithIncomes) : FILE_NAME_WITH_INCOMES(fileNameWithIncomes) {
        lastIncomeId = 0;
    };
    void addIncomeToFile(Income income);
    vector <Income> loadLoggedUserIncomesFromFile (int loggedUserId);

    int getLastIncomeId();
};

#endif // FILEWITHINCOMES_H
