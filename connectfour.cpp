//
//  connectfour.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <string>
using namespace std;
#include <iostream>

#include "GameState.h"
#include "globals.h"

// Function prototypes

// The main function
int main() {
  /**********************************************************************************/
  /* Create three initialized game state objects in an array */
  /**********************************************************************************/
  const int numOfRounds = 3;
  GameState game_state[numOfRounds];
  int count_winner_R = 0;
  int count_winner_Y = 0;
  // Read one integer from the user that represents the column
  // the player would like to place their piece (R or Y) in
  // You can assume there will be no formatting errors in the input

  int col;
  int round = 0;
  for (round; round < numOfRounds; round++) {
    cout << "Game " << round + 1 << "\n";
    while (!game_state[round].get_gameOver()) {
      cout << "Enter column to place piece: ";
      cin >> col;

      if (cin.eof()) {
        cerr << endl << "Game ended by user." << endl;
        exit(0);
      }
      if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        col = -1;  // giving col invalid value so it will be handled as invalid
                   // input below
      }

      // Check validity of input and if not valid, handle accordingly
      // Check validity of input and if not valid, handle accordingly
      if (col < 0 || col >= boardSize) {
        cout << "Invalid column!";
        //  return;
        // break;
        continue;
      }
      int count = 0;
      for (int i = 0; i < boardSize; i++) {
        if (game_state[round].get_gameBoard(i, col) == Empty) {
          count++;
        }
      };
      if (count == 0) {
        cout << "Invalid column!";
        // return;
        continue;
      } else {
        cout << "column chosen: " << col << "\n";
      }

      // The coordinates are valid; set the selectedRow and selectedColumn
      game_state[round].set_selectedColumn(col);
      // break
      for (int i = 0; i < boardSize; i++) {
        if (game_state[round].get_gameBoard(i, col) == Empty) {
          game_state[round].set_selectedRow(i);
          break;
        }
      };
      // members of the game state to the read values
      // Note that the corresponding mutators of GameState must be first
      // implemented before this works
      /* if (game_state[round].get_turn())
        {
          game_state[round].set_gameBoard(game_state[round].get_selectedRow(),
        game_state[round].get_selectedColumn(), R);
        }
        else
        {
          game_state[round].set_gameBoard(game_state[round].get_selectedRow(),
        game_state[round].get_selectedColumn(), Y);
        }; */
      // Call playMove
      playMove(game_state[round]);
      // Print the GameState object, as prescribed in the handout
      // int g =
      // game_state[round].get_gameBoard(game_state[round].get_selectedRow(),
      // game_state[round].get_selectedColumn());
      for (int i = boardSize - 1; i >= 0; i--) {
        for (int j = 0; j < boardSize; j++) {
          if (game_state[round].get_gameBoard(i, j) == Empty) {
            cout << "_";
          };
          if (game_state[round].get_gameBoard(i, j) == 1) {
            cout << "R";
          };
          if (game_state[round].get_gameBoard(i, j) == -1) {
            cout << "Y";
          }
        }
        cout << "\n";
      }
      cout << "\n";

      // void printboard(int g);
      //  Check if a player won this round and if so handle accordingly

      if (game_state[round].get_winner() == 1) {
        cout << "R won this round!"
             << "\n";
        count_winner_R++;
      } else if (game_state[round].get_winner() == -1) {
        cout << "Y won the round!"
             << "\n";
        count_winner_Y++;
      }
      // Check if a player won this match and if so handle accordingly
      if (count_winner_R == 2) {
        cout << "R won the match!";
        return 0;
        // break;
      }
      if (count_winner_Y == 2) {
        cout << "Y won the match!";
        return 0;
        break;
      }
    }
  }
}