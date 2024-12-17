#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "User.h"
#include "AdditionalMethods.h"

#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User enterNewUserData();
    int getNewUserId();
    bool doesTheLoginExists(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        users = fileWithUsers.loadUsersFromFile();
        loggedUserId = 0;
    };

    void registerUser();
    void writeDownAllTheUsers();
    void loginUser();
    void logoutUser();

    void changePasswordOfTheLoggedUser();

    bool isUserLoggedIn();

    int getIdOfTheLoggedUser();
    void setIdOfTheLoggedUser(int number);
};

#endif // USERMANAGER_H
