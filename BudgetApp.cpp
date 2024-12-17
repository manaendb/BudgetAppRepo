#include "BudgetApp.h"

void BudgetApp::registerUser()
{
    userManager.registerUser();
}

void BudgetApp::writeDownAllTheUsers()
{
    userManager.writeDownAllTheUsers();
}

void BudgetApp::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
        incomeExpenseManager = new IncomeExpenseManager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getIdOfTheLoggedUser());
}

void BudgetApp::logoutUser()
{
    userManager.logoutUser();
    delete incomeExpenseManager;
    incomeExpenseManager = NULL;
}

void BudgetApp::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        incomeExpenseManager->addIncome();
    }
    else
    {
        cout << "Please log in first to add new income!";
        system("pause");
    }
}

void BudgetApp::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        incomeExpenseManager->addExpense();
    }
    else
    {
        cout << "Please log in first to add new expense!";
        system("pause");
    }
}

void BudgetApp::showIncomesOfTheLoggedUser()
{
    incomeExpenseManager->showAllIncomesOfTheLoggedUser();
}

void BudgetApp::showExpensesOfTheLoggedUser()
{
    incomeExpenseManager->showAllExpensesOfTheLoggedUser();
}

void BudgetApp::currentMonthBalance()
{
    if (userManager.isUserLoggedIn())
    {
        incomeExpenseManager->currentMonthBalance();
    }
    else
    {
        cout << "Please log in first to show balance!";
        system("pause");
    }
}

 void BudgetApp::previousMonthBalance()
 {
    if (userManager.isUserLoggedIn())
    {
        incomeExpenseManager->previousMonthBalance();
    }
    else
    {
        cout << "Please log in first to show balance!";
        system("pause");
    }
 }

 void BudgetApp::balanceFromSelectedPeriod()
 {
        if (userManager.isUserLoggedIn())
    {
        incomeExpenseManager->balanceFromSelectedPeriod();
    }
    else
    {
        cout << "Please log in first to show balance!";
        system("pause");
    }
 }

void BudgetApp::changePasswordOfTheLoggedUser()
{
    userManager.changePasswordOfTheLoggedUser();
}

bool BudgetApp::isUserLoggedIn()
{
    if (userManager.getIdOfTheLoggedUser() > 0)
        return true;
    else
        return false;
}
