#include <iostream>
#include "functions.hpp"
using namespace std;

int main() {

char pl1, pl2;
// char chosen_character = character_choice(pl1, pl2);





string* array1 = initializeArray(); // Call the initialization function and store the returned pointer

    for (int i = 0; i < 5; i++) {
        cout << array1[i] << endl; // Print each row of the game board
    }


delete[] array1; 


return 0;
}










