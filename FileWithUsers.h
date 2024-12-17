#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    const string FILE_NAME_WITH_USERS;

public:
    FileWithUsers(string fileNameWithUsers) : FILE_NAME_WITH_USERS(fileNameWithUsers) {};
    void saveUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveNewUserPasswordToXMLFile(int userId, string newPassword);
    string getFileNameWithUSers();
};

#endif // FILEWITHUSERS_H
