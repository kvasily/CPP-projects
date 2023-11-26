#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int wins;
};

bool compareTeams(const Team& a, const Team& b) {
    return a.wins > b.wins;
}

int main() {
    const int numTeams = 5;
    vector<Team> teams(numTeams);

    // Ask the user to enter team names and win amounts
    for (int i = 0; i < numTeams; ++i) {
        cout << "Enter team #" << i + 1 << ": ";
        cin.ignore();  // Ignore any leftover newline character
        getline(cin, teams[i].name);
        cout << "Enter the wins for " << teams[i].name << ": ";
        cin >> teams[i].wins;
    }

    // Sort the teams by wins in descending order
    sort(teams.begin(), teams.end(), compareTeams);

    // Display the league standings
    cout << "\nLeague Standings:" << endl;
    for (const Team& team : teams) {
        cout << team.name << ": " << team.wins << endl;
    }

    return 0;
}
