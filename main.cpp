#include <iostream>

#include "BudgetApp.h"

using namespace std;


int main()
{
    char choice = '0';
    BudgetApp budgetApp("users.xml", "incomes.xml", "expenses.xml");

    while (true)
    {
        if (budgetApp.isUserLoggedIn() == false)
        {
            choice = AdditionalMethods::chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();
                break;
            case '3':
                budgetApp.writeDownAllTheUsers();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = AdditionalMethods::chooseOptionFromLoggedUserMenu();

            switch (choice)
            {
            case '1':
                budgetApp.addIncome();
                break;
            case '2':
                budgetApp.addExpense();

                break;
            case '3':
                budgetApp.currentMonthBalance();
                break;
            case '4':
                budgetApp.previousMonthBalance();
                break;
            case '5':
                budgetApp.balanceFromSelectedPeriod();
                break;
            case '6':
                budgetApp.showIncomesOfTheLoggedUser();
                break;
            case '7':
                budgetApp.showExpensesOfTheLoggedUser();
                break;
            case '8':
                budgetApp.changePasswordOfTheLoggedUser();
                break;
            case '9':
                budgetApp.logoutUser();
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
