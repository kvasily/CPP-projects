#include <iostream>
#include <string>
#include <vector>
using namespace std;

int initialFunc(int m ,int x, int b)
{
    
    int y = (m*x)-(b*b);
    return y;
}   

int averageSpeed(int y, int t1, int t2)
{
    int speeeed = (y* (t2)) - (y * (t1)) / (t2 - t1);
    return speeeed;
}

int main()
{
    int m;
    int x;
    int b;

    cout << "\nwhat is m: ";
    cin >> m;
    cout << "\nwhat is x: ";
    cin >> x;
    cout << "\nwhat is b: ";
    cin >> b;
    cout << initialFunc(m,x,b);
}