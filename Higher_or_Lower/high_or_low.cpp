#include <iostream>

class NumberGuesser {

private:
    int lowerBound;
    int upperBound;
    int originalLowerBound;
    int originalUpperBound;

public:
    // Constructors
    NumberGuesser() : lowerBound(0), upperBound(0), originalLowerBound(0), originalUpperBound(0) {}
    NumberGuesser(int lower, int upper);

    // Member Functions
    void higher();
    void lower();
    int getCurrentGuess();
    void reset();
};

// Constructor Implementation
NumberGuesser::NumberGuesser(int lower, int upper) : lowerBound(lower), upperBound(upper), originalLowerBound(lower), originalUpperBound(upper) {}

// Member Function Implementations
void NumberGuesser::higher() {
    lowerBound = getCurrentGuess() + 1;
}

void NumberGuesser::lower() {
    upperBound = getCurrentGuess() - 1;
}

int NumberGuesser::getCurrentGuess() {
    return (lowerBound + upperBound) / 2;
}

void NumberGuesser::reset() {
    lowerBound = originalLowerBound;
    upperBound = originalUpperBound;
}


void run() {
    NumberGuesser guesser1(1, 100);
    std::cout << "Think of a number between 1 and 100.\n";
    char response;

    do {
        int guess = guesser1.getCurrentGuess();
        std::cout << "Is the number " << guess << "? (h/l/c/r): " << "\n";
        std::cin >> response;

        if (response == 'h') {
            guesser1.higher();
        } else if (response == 'l') {
            guesser1.lower();
        } else if (response == 'r') {
            guesser1.reset();
        }

    } while (response != 'c');

    std::cout << "You picked " << guesser1.getCurrentGuess() << "? Great pick.\n";
}



int main() {
    run();
    run();
    run();
    run();
    run();
    NumberGuesser first, second, third, fourth, fifth;
    first.getCurrentGuess();
    second.getCurrentGuess();
    third.getCurrentGuess();
    fourth.getCurrentGuess();
    fifth.getCurrentGuess();
    return 0;
}
