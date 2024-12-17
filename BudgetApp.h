#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "IncomeExpenseManager.h"

using namespace std;

class BudgetApp
{
    UserManager userManager;
    IncomeExpenseManager *incomeExpenseManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    BudgetApp(string fileWithUsers, string fileNameWithIncomes, string fileNameWithExpenses) : userManager(fileWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
        incomeExpenseManager = NULL;
    };
    ~BudgetApp()
    {
        delete incomeExpenseManager;
        incomeExpenseManager = NULL;
    };

    void registerUser();
    void writeDownAllTheUsers();
    void loginUser();
    void logoutUser();

    void addIncome();
    void addExpense();
    void showIncomesOfTheLoggedUser();
    void showExpensesOfTheLoggedUser();
    void currentMonthBalance();
    void previousMonthBalance();
    void balanceFromSelectedPeriod();

    void changePasswordOfTheLoggedUser();

    bool isUserLoggedIn();
};

#endif // BUDGETAPP_H
