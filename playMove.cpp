//
//  playMove.cpp
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
//  ECE244 Student: write your code for playMove in this file

#include "GameState.h"
#include "globals.h"

// Function prototypes (if you need)

void playMove(GameState &game_state) {
  // Change turn if move is valid,
  // Change gameOver
  // Change winner
  int selectedRow = game_state.get_selectedRow();
  int selectedColumn = game_state.get_selectedColumn();
  // game_state.set_turn(false);
  bool turn = game_state.get_turn();
  // cout << "turn = " << turn << endl;
  int check_R_or_Y;
  if (game_state.get_moveValid()) {
    // getting value of what needs to be checked
    //  int value;
    if (turn) {
      check_R_or_Y = R;
    } else {
      check_R_or_Y = Y;
    }
    // setting the board
    game_state.set_gameBoard(selectedRow, selectedColumn, check_R_or_Y);

    // checking for game over
    int count = 0;  // south-east FOR LOOP1
    for (int i = 0, j = 0;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize));
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    // cout << "southeast count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // int
    count = 0;  // north-east FOR LOOP2
    for (int i = 0, j = 0;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize));
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    // cout << "northeast count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // int
    count = 0;  // south-west FOR LOOP3
    for (int i = 0, j = 0;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize));
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    // cout << "southwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // int
    count = 0;  // north-west FOR LOOP4
    for (int i = 0, j = 0;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize));
         i++, j++) {
      // int count = 0;
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    // cout << "northwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // int
    count = 0;  // south FOR LOOP5
    for (int i = 0;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn) >= 0) && ((selectedColumn) < boardSize));
         i++) {
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    //  cout << "south count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    //   int
    count = 0;  // east FOR LOOP6
    for (int j = 0;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize));
         j++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count == 0;
        break;
      }
    };
    //  cout << "east count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // int
    count = 0;  // west FOR LOOP7
    for (int j = 0;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize));
         j++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        // count = 0;
        break;
      }
    };
    //  cout << "west count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // CHECKING FOR EDGE CASES- START HERE
    count = 0;  // edge case 1 horizontal: -1 +2
    for (int j = 0;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         j <= 2;
         j++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int i = 1;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn - i) >= 0) && ((selectedColumn - i) < boardSize)) &&
         i <= 1;
         i++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn - i)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    }
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    count = 0;  // edge case 2 horizontal: -2 +1
    for (int j = 0;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize)) &&
         j <= 2;
         j++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int j = 1;
         (((selectedRow) >= 0) && ((selectedRow) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         j <= 1;
         j++) {
      if (game_state.get_gameBoard((selectedRow), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    }
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    count = 0;  // edge case 3 south west -north east: +2 -1
    for (int i = 0, j = 0;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         i <= 2 && j <= 2;
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int i = 1, j = 1;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize)) &&
         j <= 1 && i <= 1;
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    // cout << "southwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    count = 0;  // edge case 4 south west-north east: +1 -2
    for (int i = 0, j = 0;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         i <= 1 && j <= 1;
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int i = 1, j = 1;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize)) &&
         j <= 2 && i <= 2;
         i++, j++) {
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    // cout << "southwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    count = 0;  // edge case 5 south east- north west: +-2 -+1
    for (int i = 0, j = 0;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         i <= 2 && j <= 2;
         i++, j++) {
      // int count = 0;
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int i = 1, j = 1;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize)) &&
         i <= 1 && j <= 1;
         i++, j++) {
      // int count = 0;
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    // cout << "northwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    count = 0;  // edge case 6 south east- north west: +-2 -+1
    for (int i = 0, j = 0;
         (((selectedRow + i) >= 0) && ((selectedRow + i) < boardSize)) &&
         (((selectedColumn - j) >= 0) && ((selectedColumn - j) < boardSize)) &&
         i <= 2 && j <= 2;
         i++, j++) {
      // int count = 0;
      if (game_state.get_gameBoard((selectedRow + i), (selectedColumn - j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    for (int i = 1, j = 1;
         (((selectedRow - i) >= 0) && ((selectedRow - i) < boardSize)) &&
         (((selectedColumn + j) >= 0) && ((selectedColumn + j) < boardSize)) &&
         i <= 1 && j <= 1;
         i++, j++) {
      // int count = 0;
      if (game_state.get_gameBoard((selectedRow - i), (selectedColumn + j)) ==
          check_R_or_Y) {
        count++;
      } else {
        count = 0;
        break;
      }
    };
    // cout << "northwest count : " << count << endl;
    if (count == 4) {
      game_state.set_gameOver(true);
      game_state.set_winner(check_R_or_Y);
      // game_state.set_turn(!game_state.get_turn());
      return;
    };
    // changing the turn
    // cout << "gamestate turn" << game_state.get_turn() << endl;
    game_state.set_turn(!turn);
    // cout << "gamestate turn" << game_state.get_turn() << endl;
  };
  return;
}