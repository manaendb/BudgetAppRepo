#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <iomanip>

#include "Expense.h"
#include "AdditionalMethods.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses
{
    const string FILE_NAME_WITH_EXPENSES;
    int lastExpenseId;

public:
    FileWithExpenses(string fileNameWithExpenses) : FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        lastExpenseId = 0;
    };
    void addExpenseToFile(Expense expense);
    vector <Expense> loadLoggedUserExpensesFromFile(int loggedUserId);

    int getLastExpenseId();
};

#endif // FILEWITHEXPENSES_H
