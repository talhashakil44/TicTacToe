#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "ttt.hh"


int main(int argc, char** argv) {


  //Initiating tictactoe object, displaying board and start of game statement
  tictactoe tictac;
  std::vector<std::vector<char> > board = tictac.get_board();
  tictac.display_board(board);
  tictac.start_game(); 
  bool end = tictac.end_game(board); 


  //While loop - players consecutively take turns until there is a winner or tie, in which case end_game will return true and terminate the loop.
  while (end == false) {

    board = tictac.player1_turn(board);
    tictac.set_board(board);
    tictac.display_board(board);
    end = tictac.end_game(board);
    if (end == true) {
      break;
    }

    board = tictac.player2_turn(board);
    tictac.set_board(board);
    tictac.display_board(board);
    end = tictac.end_game(board);
  }

  return 0;

}