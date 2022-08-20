#include <iostream>
#include <fstream>
#include <string.h>
#include <process.h>
using namespace std;

void login();
void registration();
void forget();

int main()
{
    system("cls");
    system("color a");
    int c;
    cout << "\t\t\t_____________________________________________________________" << endl
         << endl
         << endl;
    cout << "\t\t\t                Welcome to the login page                    " << endl
         << endl
         << endl;
    cout << "\t\t\t___________________   MENU   ________________________________" << endl
         << endl
         << endl;
    cout << "                                                                   " << endl
         << endl
         << endl;
    cout << "\t| Press 1 to LOGIN                       |" << endl;
    cout << "\t| Press 2 to REGISTER                    |" << endl;
    cout << "\t| Press 3 to if you forget the PASSWORD  |" << endl;
    cout << "\t| Press 4 to EXIT                        |" << endl;

    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
    {
        login();
        break;
    }
    case 2:
    {
        registration();
        break;
    }
    case 3:
    {
        forget();
        break;
    }
    case 4:
    {
        cout << "\t\t\t Thankyou !  \n\n";
        break;
    }
    default:
    {
        system("cls");
        cout << "\t\t\t Please select from the option given above \n\n";
        main();
        break;
    }
    }
    return 0;
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password : \n";
    cout << "\t\t\t USERNAME : ";
    cin >> userId;
    cout << "\t\t\t PASSWORD : ";
    cin >> password;
    ifstream input("record .txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successful \n Thanks for logging in !\n";
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password ";
        main();
    }
}

void registration()
{
    string ruserid, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the username  : ";
    cin >> ruserid;
    cout << "\t\t\t Enter the password : ";
    cin >> rpassword;

    ofstream f1("record.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration is successful!\n";
    main();
}

void forget()
{
    int option;
    system("cls");
    cout << "\t\t\t You forget the password? No Worries \n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to main menu";
    cout << "\t\t\tEnter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sId, spass;
        cout << "\n\t\t\t Enter the username which you remembered : ";
        cin >> suserid;

        ifstream f2("record.txt");

        while (f2 >> sId >> spass)
        {
            if (sId == suserid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your password is " << spass;
            main();
        }
        else
        {
            cout << "\n\t Sorry your acccount is not found! \n";
            main();
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
    {
        cout << "\t\t\t Wrong choice ! Please Try Again \n";
        forget();
    }
    }
}
