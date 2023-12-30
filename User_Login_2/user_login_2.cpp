#include <iostream>
#include <string>
#include <vector>
using namespace std;

 

class User
{
    private:
        string username,password;

    public:
        User(string name, string pass)
        {
            username = name;
            password = pass;
        }
};  


class UserManager
{
    private:
        vector<User> users; //create object of vector

    public:
        void registerUser()
        {
            string username, password;
            cout << "Enter User Name: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            User newUser(username, password);
            users.push_back(newUser);

            cout <<"\t\t User Register Successfully \n";
        }



};

int main ()
{
    UserManager usermanage;

    int op;
    cout << "\n\n\t\t1. Register User \n";
    cout << "\t\t2. Login \n";
    cout << "\t\t3. Show User List \n";
    cout << "\t\t4. Search User \n";
    cout << "\t\t5. Delete User \n";
    cout << "\t\t6. Exit \n";
    cout << "\t\tEnter Your Choice: \n";
    cin >> op;
    switch(op){
        case 1:
            usermanage.registerUser();
            break;
    }
}

// credit to https://www.youtube.com/watch?v=BuEtmctac3o&list=PLduM7bkxBdOeolIybZs6IibVIoXaEVQL0&ab_channel=SafdarDogar