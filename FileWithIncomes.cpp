#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    stringstream ss;
    ss << fixed << setprecision(2) << income.getAmount();
    string str = ss.str();
    xml.AddElem("Amount", str);

    xml.Save("incomes.xml");
}

vector <Income> FileWithIncomes::loadLoggedUserIncomesFromFile (int loggedUserId)
{
    CMarkup xml;

    vector <Income> loadedUserIncomes;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        return loadedUserIncomes;
    }

    xml.FindElem();
    xml.IntoElem();

    int incomeId = 0;

    while (xml.FindElem("Income"))
    {
        Income income;
        xml.FindChildElem("IncomeId");
        incomeId = stoi(xml.GetChildData());
        income.setIncomeId(incomeId);
        xml.FindChildElem("UserId");
        income.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Date");
        income.setDate(stoi(xml.GetChildData()));
        xml.FindChildElem("Item");
        income.setItem(xml.GetChildData());
        xml.FindChildElem("Amount");
        income.setAmount(stod(xml.GetChildData()));
        if (income.getUserId() == loggedUserId)
            loadedUserIncomes.push_back(income);
    }

    lastIncomeId = incomeId;

    return loadedUserIncomes;
}

 int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
