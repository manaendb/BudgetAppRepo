#include "UserManager.h"

void UserManager::registerUser()
{
    User user = enterNewUserData();

    users.push_back(user);
    fileWithUsers.saveUserToFile(user);

    cout << endl << "The new user registration was succesfull - The new account has been created succesfully" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Enter login: ";
        user.setLogin(AdditionalMethods::readLine());
    } while (doesTheLoginExists(user.getLogin()) == true);

    cout << "Enter password: ";
    user.setPassword(AdditionalMethods::readLine());
    cout << "Enter first name: ";
    user.setFirstName(AdditionalMethods::readLine());
    cout << "Enter last name: ";
    user.setLastName(AdditionalMethods::readLine());

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesTheLoginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::writeDownAllTheUsers()
{
    system("cls");
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getFirstName() << endl;
        cout << users[i].getLastName() << endl;
    }
    system("pause");
}

void UserManager::changePasswordOfTheLoggedUser()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AdditionalMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPassword(newPassword);
            cout << "The password has been changed." << endl << endl;
            fileWithUsers.saveNewUserPasswordToXMLFile(loggedUserId, newPassword);
            system("pause");
        }
    }
}

void UserManager::loginUser()
{
    string login = "", password = "";
    cout << endl << "Enter login: ";
    login = AdditionalMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password. Remaining attempts: " << numberOfAttempts << ": ";
                password = AdditionalMethods::readLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return;
                }
            }
            cout << "You have entered wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
}

void UserManager::logoutUser()
{
    loggedUserId = 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getIdOfTheLoggedUser()
{
    return loggedUserId;
}

void UserManager::setIdOfTheLoggedUser(int number)
{
    loggedUserId = number;
}
