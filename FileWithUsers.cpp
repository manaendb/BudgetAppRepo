#include "FileWithUsers.h"

void FileWithUsers::saveUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());

    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    vector <User> users;

    if (!fileExists)
    {
        return users;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        User user;
        xml.FindChildElem("UserId");
        user.setId(stoi(xml.GetChildData()));
        xml.FindChildElem("Login");
        user.setLogin(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setPassword(xml.GetChildData());
        xml.FindChildElem("FirstName");
        user.setFirstName(xml.GetChildData());
        xml.FindChildElem("LastName");
        user.setLastName(xml.GetChildData());
        users.push_back(user);
    }

    return users;
}

void FileWithUsers::saveNewUserPasswordToXMLFile(int userId, string newPassword)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        cout << "Could not open User's file";
        system("pause");
        return;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        User user;
        xml.FindChildElem("UserId");
        if (stoi(xml.GetChildData()) == userId)
        {
            xml.FindChildElem("Password");
            xml.SetChildData(newPassword);
        }
    }
    xml.Save("users.xml");
}

string FileWithUsers::getFileNameWithUSers()
{
    return FILE_NAME_WITH_USERS;
}
