#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "ttt.hh"

//Turning inputs (A0, B1, and C2 etc.) into valid indices ([0][0], [1][1] and [2][2] etc)
std::tuple <int,int> tictactoe::input_to_entry(std::string &player) {
  int row;
  int column;
  if (player[0] == 'A' || player[0]== 'a') {
    row = 0;
    column = player[1] - '0';
    } else if (player[0]=='B' || player[0]=='b')
    {row = 1;
    column = player[1] - '0';
    } else if (player[0] == 'C' || player[0] == 'c')
    {row = 2;
    column = player[1] - '0';
    }
    return std::make_tuple(row, column);
}

//Displaying the tictac toe board 
void tictactoe::display_board(std::vector<std::vector<char> > &board) {
  
  std::cout << "Tic Tac Toe Board: \n" << std::endl;
  std::cout << "   0 1 2" << std::endl;

  for (int i = 0; i < board.size(); i++) {
    switch(i) {
      case 0: 
        std::cout << "A: ";
        break;
      case 1:
        std::cout << "\nB: ";
        break;
      case 2:
        std::cout << "\nC: ";
        break;
      default:
        std::cout << "invalid out of range \n";
    }

    for (int j=0; j < board[i].size(); j++) {
      std::cout << board[i][j] << " ";
    }
  }
  std::cout << "\n";
}

//Checking for Winner or Tie (3 X's or 3 O's across columns rows and diagonals)
bool tictactoe::end_game(std::vector<std::vector<char> > &board) {
  bool endgame = false; 
  int counter_tie = 0;
  //Traverse through Rows of Board to Check Winner or Tie
  for (int i = 0; i < board.size() ; i++) {
    int counter_x = 0;
    int counter_y = 0;
    for (int j = 0; j < board[i].size(); j++) {
      if(board[i][j] == 'X') {
        counter_x += 1;
        counter_tie +=1;
        if (counter_x == 3) {
          std::cout << "Player 1 (X) has won!\n";
          endgame = true;
          return endgame;
        } else if (counter_tie == 9) {
          std::cout << "The Game is a tie!\n";
          endgame = true;
          return endgame;
        }
      } else if (board[i][j] == 'O') {
          counter_y +=1; 
          counter_tie +=1;
          if (counter_y == 3) { 
            std::cout << "Player 2 (O) has won! \n";
            endgame = true;
            return endgame;
          } else if (counter_tie == 9) {
            std::cout << "The Game is a tie!\n";
            endgame = true;
            return endgame;
          }
      }
    }
  }
  //Traverse through Columns of Board to Check Winner or Tie. 
  for (int i = 0; i < board.size(); i++) {
    int counter_x = 0;
    int counter_y = 0; 
    for (int j =0; j<board.size(); j++) {
      if (board[j][i] == 'X') {
        counter_x += 1; 
        if(counter_x == 3) {
          std::cout << "Player 1 (X) has won! \n";
          endgame = true;
          return endgame;
        }
      } else if (board[j][i] == 'O') {
          counter_y += 1;
          if (counter_y == 3) {
            std::cout << "Player 2 (O) has won! \n";
            endgame = true;
            return endgame;
        }
      }
    }
  }
  //Checking if Diagonals of Board to Determine Winner. 
  if (board[0][0] == board [1][1] && board[2][2] == board[1][1] ) {
    if (board[0][0] == 'X') {
      std::cout << "Player 1 (X) has won! \n";
      endgame = true;
      return endgame;
    } else if (board[0][0] == 'O'){
        std::cout << "Player 2 (O) has won! \n";
        endgame = true;
        return endgame;
    }
  }
  if (board[2][0] == board[1][1] && board[0][2] == board[1][1]) {
    if (board[2][0] == 'X') {
      std::cout << "Player 1 (X) has won! \n";
      endgame = true;
      return endgame; 
    } else if (board[2][0] == 'O') {
      std::cout << "Player 2 (O) has won! \n";
      endgame = true; 
      return endgame;
    }
  }
  return endgame;
}

//Game Instructions at Start of Game
void tictactoe::start_game() {
   std::cout << "\n\nPlayer1 is X and Player 2 is O. Please pick your entries according to the corresponding ROW LETTER (A, B, C) and COLUMN NUMBER (0,1,2). Examples of Valid Entries are as follows: A0, B2, C0 and A2 etc. \n";
}

//Inputting the Entry Player 1 onto the board
std::vector<std::vector<char> > tictactoe::player1_turn(std::vector<std::vector<char> > &board) {
  int row;
  int column;
  bool valid_entry = true; 
  do {
    std::cout << "\nPlayer1 (X) - Please choose your entry _ _:" << "\n";
    std::cin >> player1;
    std::cout << player1 << "\n";
    entry = input_to_entry(player1);
    row = std::get<0>(entry);
    column = std::get<1>(entry);
    if (board[row][column] == '-') {
      board[row][column] = 'X';
    } else {
      valid_entry = false;
      std::cout << "Invalid Entry.\n";
      }
  } while (valid_entry == false);
  return board;
}

//Inputting the Entry of Player 2 onto the board
std::vector<std::vector<char> > tictactoe::player2_turn(std::vector<std::vector<char> > &board) {
  int row;
  int column;
  bool valid_entry = true; 
  do {
    std::cout << "\nPlayer2 (O) - Please choose your entry _ _:" << "\n";
    std::cin >> player2;
    std::cout << player2 << "\n";
    entry = input_to_entry(player2);
    row = std::get<0>(entry);
    column = std::get<1>(entry);
    if (board[row][column] == '-') {
      board[row][column] = 'O';
    } else {
      valid_entry = false;
      std::cout << "Invalid Entry.\n";
      }
  } while (valid_entry == false);
  return board; 
}


 