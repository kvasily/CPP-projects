#include<iostream>
#include<string>
using namespace std;

void reverse(int ar[], int start, int end)
{
 
  if (start <= end)
  {
    // I was having trouble modifying my reverse function
    // the end+1 part was only usefull if I was printing the last int
    // It would trigger the if statement too soon leading to the cout only printing half of the list
    // So I realized this could be done by removng the end+1 from the original statement
    // This would let my recursive function to be called enough times for my cout statement to make the start parameter high enough to cout in the right order
    reverse(ar, start+1, end);
    cout << ar[start] << " ";
  }
}

int main() 
{
  int myAr[] = {1,2,3,4,5};
  reverse(myAr, 0, 4);

  return 0;
}