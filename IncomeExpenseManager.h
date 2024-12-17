#ifndef INCOMEEXPENSEMANAGER_H
#define INCOMEEXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "DateMethods.h"

using namespace std;

class IncomeExpenseManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    Income enterNewIncomeData();
    Expense enterNewExpenseData();
    void showIncomeData(Income income);
    void showExpenseData(Expense expense);
    void showBalance(int startDate, int endDate);
    void sortIncomesByDate();
    void sortExpensesByDate();

public:

    IncomeExpenseManager(string fileNameWithIncomes, string fileNameWithExpenses, int loggedUserId) : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), LOGGED_USER_ID(loggedUserId)
    {
        incomes = fileWithIncomes.loadLoggedUserIncomesFromFile(LOGGED_USER_ID);
        expenses = fileWithExpenses.loadLoggedUserExpensesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void addExpense();
    void showAllIncomesOfTheLoggedUser();
    void showAllExpensesOfTheLoggedUser();
    void showDateNameAndAmountOfTheIncome(Income income);
    void showDateNameAndAmountOfTheExpense(Expense expense);

    void currentMonthBalance();
    void previousMonthBalance();
    void balanceFromSelectedPeriod();

    int getLoggedUserId();

};

#endif // INCOMEEXPENSEMANAGER_H
