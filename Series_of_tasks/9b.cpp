#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct WinRecord {
    int wins;
    string name;
};

// Function to initialize data
void initializeData(WinRecord* standings, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Enter the name for team #" << i + 1 << ": ";
        cin >> standings[i].name;
        cout << "Enter the wins for team #" << i + 1 << ": ";
        cin >> standings[i].wins;
        cin.ignore(); // Consume the newline character
    }
}

// Comparison function for sorting by wins in descending order
bool compareTeams(const WinRecord& a, const WinRecord& b) {
    return a.wins > b.wins;
}

// Function to sort data
void sortData(WinRecord* standings, int size) {
    sort(standings, standings + size, compareTeams);
}

// Function to display data
void displayData(WinRecord* standings, int size) {
    cout << "\nLeague Standings:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << standings[i].name << ": " << standings[i].wins << endl;
    }
}

int main() {
    int numTeams;

    // Ask the user how many teams are in the league
    cout << "Enter the number of teams in the league: ";
    cin >> numTeams;

    // Dynamically allocate memory for the array of WinRecord structs
    WinRecord* standings = new WinRecord[numTeams];

    // Initialize the data
    initializeData(standings, numTeams);

    // Sort the data
    sortData(standings, numTeams);

    // Display the league standings
    displayData(standings, numTeams);

    // Deallocate the dynamically allocated memory
    delete[] standings;

    return 0;
}