#include <iostream>
#include <string>
#include <vector>
#include <cctype>
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
        string getUsername()
        {
            return username;
        }
        string getPassword()
        {
            return password;
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
            cout << "\t\tEnter Username: ";
            cin >> username;
            cout << "\t\tEnter Password: ";
            cin >> password;

            User newUser(username, password);
            users.push_back(newUser);

            cout <<"\t\tUser Register Successfully \n";
        }
        bool LoginUser(string name, string password)
        {
            for(int i = 0; i<users.size(); i++)
            {
                if(users[i].getUsername()==name && users[i].getPassword() == password)
                {
                    cout << "\t\tLogin Succesfull \n";
                    return true;
                }
            }
            cout << "\t\tInvalid Username or Password \n";
            return false;
        }



};

int main ()
{
    UserManager usermanage;

    int input;
    char choice;
    do
    {
        system("clear");
        cout << "\n\n\t\t1. Register User \n";
        cout << "\t\t2. Login \n";
        cout << "\t\t3. Show User List \n";
        cout << "\t\t4. Search User \n";
        cout << "\t\t5. Delete User \n";
        cout << "\t\t6. Exit \n";
        cout << "\t\tEnter Your Choice: \n";
        cin >> input;
        switch(input)
        {
            case 1:
            {
                usermanage.registerUser();
                break;
            }
            case 2:
            {
                string username,password;
                cout<<"\t\tEnter Username: \n";
                cin >> username;
                cout << "\t\tEnter Password: \n";
                cin >> password;
                usermanage.LoginUser(username, password);
                break;
            }
        }
    cout << "\n\t\tDo You Want To Continue? [Y/N]: ";
    cin >> choice;
    } while(choice == 'Y' || choice == 'y');
    
    
    
}

// credit to https://www.youtube.com/watch?v=BuEtmctac3o&list=PLduM7bkxBdOeolIybZs6IibVIoXaEVQL0&ab_channel=SafdarDogar