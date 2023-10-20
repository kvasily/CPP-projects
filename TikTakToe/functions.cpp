#include <string>
#include "functions.hpp"
using namespace std;

//function for character choice
char character_choice(char &player1, char &player2) {

    while (true) {
        // prompts player1 to chose their character
        cout << "player 1 choose your character, X or O: ";
        cin >> player1;
        
        // makes the choice uppercases
        player1 = toupper(player1);

        // checks if user input was valid
        if (player1 == 'O' || player1 == 'X') {
            cout << "\nplayer 1 chose: " << player1 << "\n";

            // assigns player 2 based on player 1 choice
            player2 = (player1 == 'X') ? 'O' : 'X';
            cout << "player 2 chose: " << player2 << "\n";

            return player1;
        } else {
            cout << "Invalid choice, please choose either X or O.\n"; 
        }
    }
}

//function to initialize array
string* initializeArray() {
    static string static_array[] = {
        "   |   |   ",
        "---+---+---",
        "   |   |   ",
        "---+---+---",
        "   |   |   "
    };

int array_size = sizeof(static_array) / sizeof(static_array[0]);

    // Allocate a new array on the heap and copy the content
    string* dynamicArray = new string[array_size];
    for (int i = 0; i < array_size; i++) {
        dynamicArray[i] = static_array[i];
    }
    return dynamicArray;
}

void rules(string array1[5]) {
    if ((array1[0][1] == 'X' && array1[2][1] == 'X' && array1[4][1] == 'X') ||
        (array1[0][1] == 'X' && array1[0][5] == 'X' && array1[0][9] == 'X') ||
        (array1[0][1] == 'X' && array1[2][5] == 'X' && array1[4][9] == 'X') ||
        (array1[4][1] == 'X' && array1[4][5] == 'X' && array1[4][9] == 'X') ||
        (array1[0][9] == 'X' && array1[2][9] == 'X' && array1[4][9] == 'X') ||
        (array1[0][5] == 'X' && array1[2][5] == 'X' && array1[4][5] == 'X') ||
        (array1[0][9] == 'X' && array1[2][5] == 'X' && array1[4][1] == 'X')) {
        cout << "Player 1 wins!";

        } else if ((array1[0][1] == 'O' && array1[2][1] == 'O' && array1[4][1] == 'O') ||
                   (array1[0][1] == 'O' && array1[0][5] == 'O' && array1[0][9] == 'O') ||
                   (array1[0][1] == 'O' && array1[2][5] == 'O' && array1[4][9] == 'O') ||
                   (array1[4][1] == 'O' && array1[4][5] == 'O' && array1[4][9] == 'O') ||
                   (array1[0][9] == 'O' && array1[2][9] == 'O' && array1[4][9] == 'O') ||
                   (array1[0][5] == 'O' && array1[2][5] == 'O' && array1[4][5] == 'O') ||
                   (array1[0][9] == 'O' && array1[2][5] == 'O' && array1[4][1] == 'O')){
                   cout << "Player 2 wins!";

        }
}