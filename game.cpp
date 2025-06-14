#include <string>
#include <cstdlib>
#include <ctime>

extern "C" {

int userScore = 0;
int computerScore = 0;

const char* moveToString(int move) {
    switch (move) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "Invalid";
    }
}

const char* play(int userMove) {
    static std::string result;
    std::srand(std::time(0));
    int compMove = std::rand() % 3;

    if (userMove == compMove) {
        result = "Draw (" + std::string(moveToString(userMove)) + ")";
    } else if ((userMove == 0 && compMove == 2) ||
               (userMove == 1 && compMove == 0) ||
               (userMove == 2 && compMove == 1)) {
        userScore++;
        result = "Win (" + std::string(moveToString(userMove)) + " vs " + moveToString(compMove) + ")";
    } else {
        computerScore++;
        result = "Lose (" + std::string(moveToString(userMove)) + " vs " + moveToString(compMove) + ")";
    }

    result += " | Score: " + std::to_string(userScore) + "-" + std::to_string(computerScore);

    if (userScore == 2 || computerScore == 2) {
        result += userScore > computerScore ? " | 🏆 You win Best of 3!" : " | 💻 Computer wins Best of 3!";
        userScore = 0;
        computerScore = 0;
    }

    return result.c_str();
}

}
