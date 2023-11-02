#include <iostream>
#include <string>
#include <vector>
using namespace std;



void displayWord(const string& word) 
{
    // 1. Print increasing substrings from the start
    for (size_t i = 1; i <= word.length(); ++i) 
    {
        cout << word.substr(0, i) << endl;
    }

    // 2. Print decreasing substrings from the end, with leading spaces
    for (size_t i = 1; i < word.length(); ++i) 
    {
        for (size_t j = 0; j < word.length() - i; ++j)
        {
            cout << " ";
        }
        cout << word.substr(word.length() - i) << endl;
    }

    // 3. Print the entire string
    cout << word << endl;
}








int main() 
{

    vector<string> words;

    string input;
    cout << "Input a string:\n"; cin >> input;
    
    words.push_back(input);
    displayWord(words[0]);



    return 0;
}