#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

char getComputerChoice() {
    char choices[3] = {'s', 'p', 'z'};
    return choices[rand() % 3];
}

string determineWinner(char user, char computer) {
    if (user == computer) {
        return "It's a tie!";
    } else if ((user == 's' && computer == 'z') ||
               (user == 'p' && computer == 's') ||
               (user == 'z' && computer == 'p')) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    cout << "Choose s for stone" << endl;
    cout << "Choose p for paper" << endl;
    cout << "Choose z for scissors" << endl;

    int userWins = 0;
    int computerWins = 0;

    for (int i = 0; i < 3; ++i) {
        char userChoice;
        cout << "Round " << (i + 1) << ": ";
        cin >> userChoice;

        // Validate user input
        if (userChoice != 's' && userChoice != 'p' && userChoice != 'z') {
            cout << "Invalid input. Please choose 's', 'p', or 'z'." << endl;
            --i; // Do not count this round
            continue;
        }

        char computerChoice = getComputerChoice();

        cout << "You chose: " << userChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;

        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        if (result == "🏆 You win!") {
            userWins++;
        } else if (result == "💻 Computer wins!") {
            computerWins++;
        }
    }

    cout << "Final Result:" << endl;
    if (userWins > computerWins) {
        cout << "You are the winner!" << endl;
    } else if (computerWins > userWins) {
        cout << "Computer is the winner!" << endl;
    } else {
        cout << "It's a tie overall!" << endl;
    }

    return 0;
}