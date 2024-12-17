#include "IncomeExpenseManager.h"


int IncomeExpenseManager::getLoggedUserId()
{
    return LOGGED_USER_ID;
}

void IncomeExpenseManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData();

    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
}

Income IncomeExpenseManager::enterNewIncomeData()
{
    Income newIncome;
    int lastIncomeId = fileWithIncomes.getLastIncomeId();

    newIncome.setIncomeId(++lastIncomeId);
    newIncome.setUserId(LOGGED_USER_ID);
    bool notCorrectDate = true;

    int correctIntDateOfNewIncome = 0;

    do
    {
        cout << "Adding new date for income (Remember the date must be between 2000-01-01 and maximum the last day of the current month)";
        cout << endl << "Enter the date of new income with yyyy-mm-dd format (enter 't' to get current date): ";
        string dateString = AdditionalMethods::readLine();

        if (dateString == "t" || dateString == "T")
        {
            notCorrectDate = false;
            correctIntDateOfNewIncome = DateMethods::dateToInt(DateMethods::currentDate());
        }
        else
        {
            if (DateMethods::isTheDateCorrect(dateString))
            {
                notCorrectDate = false;

                correctIntDateOfNewIncome = DateMethods::dateStringToInt(dateString);
            }
            else
            {
                cout << "You have entered wrong date. Please correct it. Remember that the format should be yyyy-mm-dd (for example 2024-10-10) and also the date must be between 2000-01-01 and maximum the last day of the current month";
                system("pause");
            }
        }
    }
    while (notCorrectDate);

    newIncome.setDate(correctIntDateOfNewIncome);

    cout << "Enter Item (for example: salary for work): ";
    newIncome.setItem(AdditionalMethods::readLine());

    cout << "Enter amount of Income: ";
    newIncome.setAmount(AdditionalMethods::readDouble());

    return newIncome;
}

void IncomeExpenseManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterNewExpenseData();

    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
}

Expense IncomeExpenseManager::enterNewExpenseData()
{
    Expense newExpense;
    int lastExpenseId = fileWithExpenses.getLastExpenseId();

    newExpense.setExpenseId(++lastExpenseId);
    newExpense.setUserId(LOGGED_USER_ID);
    bool notCorrectDate = true;

    int correctIntDateOfNewExpense = 0;

    do
    {
        cout << "Adding new date for expense (Remember the date must be between 2000-01-01 and maximum the last day of the current month)";
        cout << endl << "Enter the date of new expense with yyyy-mm-dd format (enter 't' to get current date): ";
        string dateString = AdditionalMethods::readLine();
        //date = stringToDateConversion(dateString);

        if (dateString == "t" || dateString == "T")
        {
            notCorrectDate = false;
            correctIntDateOfNewExpense = DateMethods::dateToInt(DateMethods::currentDate());
        }
        else
        {
            if (DateMethods::isTheDateCorrect(dateString))
            {
                notCorrectDate = false;

                correctIntDateOfNewExpense = DateMethods::dateStringToInt(dateString);
            }
            else
            {
                cout << "You have entered wrong date. Please correct it. Remember that the format should be yyyy-mm-dd (for example 2024-10-10) and also the date must be between 2000-01-01 and maximum the last day of the current month" << endl;
                system("pause");
            }
        }
    }
    while (notCorrectDate);

    newExpense.setDate(correctIntDateOfNewExpense);

    cout << "Enter Item (for example: food, restaurant, house etc.): ";
    newExpense.setItem(AdditionalMethods::readLine());

    cout << "Enter amount of Expense: ";
    newExpense.setAmount(AdditionalMethods::readDouble());

    return newExpense;
}

void IncomeExpenseManager::showAllIncomesOfTheLoggedUser()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> Incomes of the logged User <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            showIncomeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There are no incomes." << endl << endl;
    }
    system("pause");
}

void IncomeExpenseManager::showAllExpensesOfTheLoggedUser()
{
    system("cls");
    if (!expenses.empty())
    {
        cout << "             >>> Expenses of the logged User <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            showExpenseData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "There are no expenses." << endl << endl;
    }
    system("pause");
}

void IncomeExpenseManager::showIncomeData(Income income)
{
    cout << endl << "Income Id:     " << income.getIncomeId() << endl;
    cout << "User Id:               " << income.getUserId() << endl;
    cout << "Date of Income:        " << income.getDate() << endl;
    cout << "Name of Income:        " << income.getItem() << endl;
    cout << "Amount of Income:      " << income.getAmount() << endl;
}

void IncomeExpenseManager::showExpenseData(Expense expense)
{
    cout << endl << "Expense Id:     " << expense.getExpenseId() << endl;
    cout << "User Id:                " << expense.getUserId() << endl;
    cout << "Date of Expense:        " << expense.getDate() << endl;
    cout << "Name of Expense:        " << expense.getItem() << endl;
    cout << "Amount of Expense:      " << expense.getAmount() << endl;
}

void IncomeExpenseManager::showDateNameAndAmountOfTheIncome(Income income)
{
    cout << endl << "Date of Income:        " << DateMethods::dateIntToStringWithDashes(income.getDate()) << endl;
    cout << "Name of Income:        " << income.getItem() << endl;
    cout << "Amount of Income:      " << income.getAmount() << endl;
}

void IncomeExpenseManager::showDateNameAndAmountOfTheExpense(Expense expense)
{
    cout << endl << "Date of Expense:        " << DateMethods::dateIntToStringWithDashes(expense.getDate()) << endl;
    cout << "Name of Expense:        " << expense.getItem() << endl;
    cout << "Amount of Expense:      " << expense.getAmount() << endl;
}

void IncomeExpenseManager::sortIncomesByDate()
{
    sort(incomes.begin(), incomes.end(), [](Income income1, Income income2)
    {
        return income1.getDate() < income2.getDate();
    });
}

void IncomeExpenseManager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end(), [](Expense expense1, Expense expense2)
    {
        return expense1.getDate() < expense2.getDate();
    });
}

void IncomeExpenseManager::showBalance(int startDate, int endDate)
{
    system("cls");
    double sumOfTheIncomesFromDateToDate = 0;
    double sumOfTheExpensesFromDateToDate = 0;
    if (!incomes.empty())
    {
        sortIncomesByDate();

        cout << "             >>> Incomes of the logged User from " << DateMethods::dateIntToStringWithDashes(startDate) << " to " << DateMethods::dateIntToStringWithDashes(endDate) << " <<<" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if (itr->getDate() >= startDate && itr->getDate() <= endDate)
            {
                sumOfTheIncomesFromDateToDate += itr->getAmount();
                showDateNameAndAmountOfTheIncome(*itr);
            }
        }
        cout << endl;
        if (sumOfTheIncomesFromDateToDate == 0.0)
            cout << endl << "The User does not have incomes within specified range.";
    }
    else
    {
        cout << endl << "The User does not have any incomes." << endl << endl;
    }

    if (!expenses.empty())
    {
        sortExpensesByDate();

        cout << "             >>> Expenses of the logged User from " << DateMethods::dateIntToStringWithDashes(startDate) << " to " << DateMethods::dateIntToStringWithDashes(endDate) << " <<<" << endl;
        cout << "-----------------------------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if (itr->getDate() >= startDate && itr->getDate() <= endDate)
            {
                sumOfTheExpensesFromDateToDate += itr->getAmount();
                showDateNameAndAmountOfTheExpense(*itr);
            }
        }
        if (sumOfTheExpensesFromDateToDate == 0.0)
            cout << endl << "The User does not have expenses within specified range.";
        cout << endl;
    }
    else
    {
        cout << endl << "The User does not have any expenses." << endl << endl;
    }

    cout << endl << "Total of the incomes from " << DateMethods::dateIntToStringWithDashes(startDate) << " to " << DateMethods::dateIntToStringWithDashes(endDate) << ": " << fixed << setprecision(2) << sumOfTheIncomesFromDateToDate << endl;
    cout << "Total of the expenses " << DateMethods::dateIntToStringWithDashes(startDate) << " to " << DateMethods::dateIntToStringWithDashes(endDate) << ": " << fixed << setprecision(2) << sumOfTheExpensesFromDateToDate << endl;
    cout << endl << "Income end expense balance is: " << fixed << setprecision(2) << sumOfTheIncomesFromDateToDate - sumOfTheExpensesFromDateToDate << endl << endl;
    system("pause");
}

void IncomeExpenseManager::currentMonthBalance()
{
    showBalance(DateMethods::currentMonthFirstDayDate(), DateMethods::currentMonthLastDayDate());
}

void IncomeExpenseManager::previousMonthBalance()
{
    showBalance(DateMethods::previousMonthFirstDayDate(), DateMethods::previousMonthLastDayDate());
}

void IncomeExpenseManager::balanceFromSelectedPeriod()
{
    int correctIntStartPeriodDate = 0;
    int correctIntEndPeriodDate = 0;

    bool notCorrectStartDate = true;
    bool notCorrectEndDate = true;

    do
    {
        system("cls"); //Date date;
        cout << "Start date to calculate balance (Remember the date must be between 2000-01-01 and maximum the last day of the current month)";
        cout << endl << "Enter start Date with correct yyyy-mm-dd format : ";
        string dateString = AdditionalMethods::readLine();

        if (DateMethods::isTheDateCorrect(dateString))
        {
            notCorrectStartDate = false;

            correctIntStartPeriodDate = DateMethods::dateStringToInt(dateString);
        }
        else
        {
            cout << "You have entered wrong date. Please correct it. Remember that the format should be yyyy-mm-dd (for example 2024-10-10) and also the date must be between 2000-01-01 and maximum the last day of the current month";
            system("pause");
        }
    }

    while (notCorrectStartDate);

    do
    {
        system("cls"); //Date date;
        cout << "Start date to calculate balance (Remember the date must be between 2000-01-01 and maximum the last day of the current month)";
        cout << endl << "Enter end Date with correct yyyy-mm-dd format : ";
        string dateString = AdditionalMethods::readLine();

        if (DateMethods::isTheDateCorrect(dateString))
        {
            notCorrectEndDate = false;

            correctIntEndPeriodDate = DateMethods::dateStringToInt(dateString);
        }
        else
        {
            cout << "You have entered wrong date. Please correct it. Remember that the format should be yyyy-mm-dd (for example 2024-10-10) and also the date must be between 2000-01-01 and maximum the last day of the current month";
            system("pause");
        }
    }
    while (notCorrectEndDate);

    showBalance(correctIntStartPeriodDate, correctIntEndPeriodDate);
}
