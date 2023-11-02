#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// List of words for Hangman

const char* wordList[] = {"programming", "hangman", "computer", "language", "openai"};
vector<string> words(wordList, wordList + sizeof(wordList) / sizeof(wordList[0]));


// Function to choose a random word from the list
string getRandomWord() {
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

// Function to display the word with guessed letters
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the word has been guessed completely

bool isWordGuessed(const vector<bool>& guessed) 
{
    for (size_t i = 0; i < guessed.size(); i++) 
    {
        if (!guessed[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Welcome to Hangman!" << endl;
// potential for word selection, using if else as well as system clear to prevent cheating once the word is chosen
    string wordToGuess = getRandomWord();

    vector<bool> guessedLetters(wordToGuess.length(), false);
    int incorrectGuesses = 0;
    int maxIncorrectGuesses = 6;

    while (incorrectGuesses < maxIncorrectGuesses) {
        cout << "\nWord to guess: ";
        displayWord(wordToGuess, guessedLetters);

        char guess;
        cout << "Enter a letter: "; cin >> guess;

        bool found = false;

        for (size_t i = 0; i < wordToGuess.length(); ++i) {
            if (wordToGuess[i] == guess && !guessedLetters[i]) {
                guessedLetters[i] = true;
                found = true;
            }
        }

        if (!found) {
            cout << "Incorrect guess!" << endl;
            incorrectGuesses++;
        }

        if (isWordGuessed(guessedLetters)) {
            cout << "\nCongratulations! You guessed the word: " << wordToGuess << endl;
            break;
        }
    }

    if (incorrectGuesses >= maxIncorrectGuesses) {
        cout << "\nYou ran out of attempts. The word was: " << wordToGuess << endl;
    }

    return 0;
}
