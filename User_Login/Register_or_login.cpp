#include <iostream>
#include <fstream>
using namespace std;


bool isLoggedIn () 
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username + ".txt");

    if (!read) 
    {
        cout << "User not found\n";
        cin.get();
        return false;
    }

    getline(read, un);
    getline(read, pw);
    
    if (un == username && pw == password) 
    {
        return true;
    } 
    else 
    {
        cout << "Incorrect username or password\n";
        return false;
    }

}

int main () 
{
    system("clear");

    int choice;
    cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;

    if (choice == 1) 
    {
        string username, password;

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file(username + ".txt");

        if (!file) 
        {
            cout << "Error creating the file";
            return 1;
        }
        cout << "Registration succeful." << endl;
        file << username << endl << password;


    }
    else if (choice == 2) 
    {
        bool status = isLoggedIn();

        if (!status)
        {
            cout << "False login!\nPress enter to continue... ";
            cin.get();
            return 1;
        }
        else 
        {
            cout << "Succefully logged in!\nPress enter to continue... ";
            cin.ignore();
            cin.get();
            return 0;
        }
    }

}


