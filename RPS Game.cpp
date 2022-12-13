#include <cstdlib>
#include <iostream>

std::string toLower(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}

int main() {
  int roundNum = 0;
  int loopNum = 0;
  int plr1Wins = 0;
  int plr2Wins = 0;
  int botWins = 0;
  std::string playing = "yes";
  std::string gameMode;
  std::string botElements[] = {"rock", "paper", "scissors"};
  std::string botChoice;
  std::string plr1Name, plr1Choice;
  std::string plr2Name, plr2Choice;
  std::string lastWinner;

  std::cout << "Welcome to Rock Paper Scissors. ";

  // Game loop
  while (playing == "yes") {
    std::cout << "Which gamemode would you like to play ? Enter \"Help\" for "
                 "available modes."
              << "\n"
              << "\n";
    std::cin >> gameMode;
    gameMode = toLower(gameMode);

    while (gameMode != "singleplayer" && gameMode != "multiplayer") {
      if (gameMode == "help") {
        std::cout << "\n";
        std::cout << "Enter \"Singleplayer\" for a game against a bot."
                  << "\n";
        std::cout << "Enter \"Multiplayer\" for a game against a friend."
                  << "\n";
        std::cout << "\n";
        std::cin >> gameMode;
        gameMode = toLower(gameMode);
      } else {
        std::cout << "\n";
        std::cout << "You have entered an invalid gamemode. Please try again."
                  << "\n";
        std::cout << "\n";
        std::cin >> gameMode;
        gameMode = toLower(gameMode);
      }
    }

    std::cout << "\n";
    std::cout << "How many rounds would you like to play?"
              << "\n";
    std::cout << "\n";
    std::cin >> roundNum;
    loopNum = 0;

    if (gameMode == "singleplayer") {
      // SINGLEPLAYER
      while (loopNum < roundNum) {
        std::cout << "Round number " << loopNum + 1 << ". What do you choose?"
                  << "\n";
        std::cin >> plr1Choice;
        plr1Choice = toLower(plr1Choice);
        botChoice = botElements[(rand() % (3 - 1))];

        if (botChoice == plr1Choice) {
          // Draw
          std::cout << "It's a draw! Your opponent has also chosen "
                    << botChoice << "."
                    << "\n";
          botWins++;
          plr1Wins++;
        } else if (toLower(plr1Choice) == "rock") {
          if (botChoice == "scissors") {
            // Player Win
            std::cout << "You win! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            plr1Wins++;
          } else if (botChoice == "paper") {
            // Bot Win
            std::cout << "You lose! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            botWins++;
          }
        } else if (toLower(plr1Choice) == "paper") {
          if (botChoice == "rock") {
            // Player Win
            std::cout << "You win! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            plr1Wins++;
          } else if (botChoice == "scissors") {
            // Bot Win
            std::cout << "You lose! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            botWins++;
          }
        } else if (toLower(plr1Choice) == "scissors") {
          if (botChoice == "paper") {
            // Player Win
            std::cout << "You win! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            plr1Wins++;
          } else if (botChoice == "rock") {
            // Bot Win
            std::cout << "You lose! You have selected " << plr1Choice
                      << " while your opponent chose " << botChoice << "."
                      << "\n";
            botWins++;
          }
        } else {
          std::cout << "You lose. You have not chosen a valid element. You may "
                       "only use \"Rock\", \"Paper\" or \"Scissors\".";
        }
        loopNum++;

        std::cout << "\n";
      }

      std::cout << "\n";
      std::cout << "Game has ended. Score is " << plr1Wins << "-" << botWins
                << "."
                << " ";

      if (plr1Wins > botWins) {
        std::cout << "You have won the game! Congratulations!"
                  << "\n";
      } else if (plr1Wins < botWins) {
        std::cout << "You have lost the game... Better luck next time!!"
                  << "\n";
      } else {
        std::cout << "You are perfectly tied with your opponent!"
                  << "\n";
      }
    } else if (gameMode == "multiplayer") {
      // MULTIPLAYER
      std::cout << "Enter Player 1's Name: ";
      std::cin >> plr1Name;

      std::cout << "Enter Player 2's Name: ";
      std::cin >> plr2Name;
      while (loopNum < roundNum) {
        std::cout << "Round number " << loopNum + 1 << ". " << plr1Name
                  << ", what do you choose ? "
                  << "\n";
        std::cin >> plr1Choice;
        system("clear");
        plr1Choice = toLower(plr1Choice);
        std::cout << plr2Name << ", what do you choose ? "
                  << "\n";
        std::cin >> plr2Choice;
        system("clear");
        plr2Choice = toLower(plr2Choice);

        if (plr1Choice == plr2Choice) {
          // Draw
          std::cout << "You both chose " << plr1Choice << "."
                    << "\n";
          plr2Wins++;
          plr1Wins++;
        } else if (toLower(plr1Choice) == "rock") {
          if (plr2Choice == "scissors") {
            // P1 Win
            lastWinner = plr1Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr1Wins++;
          } else if (plr2Choice == "paper") {
            // P2 Win
            lastWinner = plr2Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr2Wins++;
          }
        } else if (toLower(plr1Choice) == "paper") {
          if (plr2Choice == "rock") {
            // P1 Win
            lastWinner = plr1Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr1Wins++;
          } else if (plr2Choice == "scissors") {
            // P2 Win
            lastWinner = plr2Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr2Wins++;
          }
        } else if (toLower(plr1Choice) == "scissors") {
          if (plr2Choice == "paper") {
            // P1 Win
            lastWinner = plr1Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr1Wins++;
          } else if (plr2Choice == "rock") {
            // P2 Win
            lastWinner = plr2Name;
            std::cout << lastWinner << " wins! " << plr1Name << " has selected "
                      << plr1Choice << " while " << plr2Name << " chose "
                      << plr2Choice << "."
                      << "\n";
            plr2Wins++;
          }
        }
        loopNum++;

        std::cout << "\n";
      }

      std::cout << "\n";
      std::cout << "Game has ended. Score is " << plr1Wins << "-" << plr2Wins
                << " as ";

      if (plr1Wins > plr2Wins) {
        std::cout << plr1Name << " has won the game!Congratulations!"
                  << "\n";
      } else if (plr1Wins < plr2Wins) {
        std::cout << plr2Name << " has won the game! Congratulations!"
                  << "\n";
      } else {
        std::cout << "Both of you are perfectly tied! What a game!"
                  << "\n";
      }
    } else {
      // ERROR
      std::cout
          << "It seems like something wrong happened... Please restart the App."
          << "\n";
    }

    std::cout << "Would you like to play again?"
              << "\n";
    std::cin >> playing;
    playing = toLower(playing);

    while (playing != "yes" && playing != "no") {
      std::cout << "Please enter \"Yes\" or \"No\"."
                << "\n";
    }
  }
}