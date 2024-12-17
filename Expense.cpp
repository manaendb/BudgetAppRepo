#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId >= 0)
        expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId)
{
    if (userId >= 0)
        userId = newUserId;
}

void Expense::setDate (int newDate)
{
    if (newDate >= 0)
        date = newDate;
}

void Expense::setItem (string newItem)
{
    item = newItem;
}

void Expense::setAmount (double newAmount)
{
    if (newAmount >= 0.0)
        amount = newAmount;
}

int Expense::getExpenseId()
{
    return expenseId;
}

int Expense::getUserId()
{
    return userId;
}

int Expense::getDate()
{
    return date;
}

string Expense::getItem()
{
    return item;
}

double Expense::getAmount()
{
    return amount;
}
