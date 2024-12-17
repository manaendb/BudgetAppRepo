#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    int date;
    string item;
    double amount;

public:
    Expense(int expenseId = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0)
    {
        this->expenseId = expenseId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif // EXPENSE_H
