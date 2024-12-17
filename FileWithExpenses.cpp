#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    stringstream ss;
    ss << fixed << setprecision(2) << expense.getAmount();
    string str = ss.str();

    xml.AddElem("Amount", str);

    xml.Save("expenses.xml");
}

vector <Expense> FileWithExpenses::loadLoggedUserExpensesFromFile(int loggedUserId)
{
    CMarkup xml;

    vector <Expense> loadedUserExpenses;

    bool fileExists = xml.Load( "expenses.xml" );

    if (!fileExists)
    {
        return loadedUserExpenses;
    }

    xml.FindElem();
    xml.IntoElem();

    int expenseId = 0;

    while (xml.FindElem("Expense"))
    {
        Expense expense;
        xml.FindChildElem("ExpenseId");
        expenseId = stoi(xml.GetChildData());
        expense.setExpenseId(expenseId);
        xml.FindChildElem("UserId");
        expense.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Date");
        expense.setDate(stoi(xml.GetChildData()));
        xml.FindChildElem("Item");
        expense.setItem(xml.GetChildData());
        xml.FindChildElem("Amount");
        expense.setAmount(stod(xml.GetChildData()));
        if (expense.getUserId() == loggedUserId)
            loadedUserExpenses.push_back(expense);
    }

    lastExpenseId = expenseId;

    return loadedUserExpenses;
}

 int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}

