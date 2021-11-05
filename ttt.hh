#include <iostream>
#include <vector>
#include <tuple>
#include <string>

//Tictactoe Class 
class tictactoe {
    std::vector<std::vector<char> > board {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    std::string player1;
    std::string player2;
    std::tuple <int,int> entry;
    bool end;

public:
    std::vector<std::vector<char> > get_board() {
        return board; 
    }
    void set_board(std::vector<std::vector<char> > new_board){
        board = new_board;
    }
    std::string get_player1() {
        return player1;
    }
    void set_player1(std::string new_player1) {
        player1 = new_player1;
    }
    std::string get_player2() {
        return player2;
    }
    void set_player2(std::string new_player2) {
        player2 = new_player2; 
    }
    std::tuple <int,int> get_entry() {
        return entry;
    }
    void set_entry(std::tuple <int,int> new_entry) {
        entry = new_entry;
    }
    bool get_end() {
        return end;
    }
    void set_end(bool new_end) {
        end = new_end;
    }

    void display_board(std::vector<std::vector<char> > &board);

    std::tuple <int,int> input_to_entry(std::string &player);

    bool end_game(std::vector<std::vector<char> > &board);

    void start_game();

    std::vector<std::vector<char> > player1_turn(std::vector<std::vector<char> > &board);

    std::vector<std::vector<char> > player2_turn(std::vector<std::vector<char> > &board);

};