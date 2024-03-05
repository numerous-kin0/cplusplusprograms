//Interface file
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>

const int ROWS = 7;
const int COLUMNS = 7;

class ticTacToe
{
public:
    void get_name_of_players();
    //Precondition: The input must not be empty or else the program will
    //encounter an error loop.
    //Postcondition: The function enters the input into the reference variables
    void print_board();
    //Precondition: The tic-tac-toe two dimensional must already be populated with the initial
    //values necessary to display the board.
    //Postcondition: Prints the tic-tac-toe board.
    void begin_game();
    //Begins the tic-tac toe game
    ticTacToe();
    //Default Constructor
private:
    char board[ROWS][COLUMNS];
    std::string player1;
    std::string player2;
    void populate_board();
    //Precondition: The two-dimensional array must be of 7 x 7 dimensions.
    //Postcondition: The function enters the values necessary to display
    //the tic-tac-toe board using the two-dimensional array.
    std::string check_if_a_player_has_won();
    //Precondition: The tic-tac-toe board must be populated with
    //necessary X or O values to win.
    //Postcondition: Returns a string indicating which player has won.
    void reflect_move_on_board(char move, int turn);
    //Postcondition: The move entered by a player is reflected on the board as either
    //the character 'X' or 'O'.
    bool check_if_space_is_already_played(char move);
    //Precondition:
    //Postcondition: Checks if the space entered
    //by the user does not already have a X or O symbol.
    //Returns true if that is the case.
    bool check_if_play_is_valid(char move);
    //Precondition: The 'play' from the user must be a single character and a
    //choice between the characters A, B, C, D, E, F, G, H, I.
    //Postcondition: Returns a boolean whose truth depends on whether the 
    //character input from the user if between the letters A, B, C, D, E, F, G,
    //H, I or not. Returns true if it is between the letters.
    int check_win_scenario_1();
    int check_win_scenario_2();
    int check_win_scenario_3();
    int check_win_scenario_4();
    int check_win_scenario_5();
    int check_win_scenario_6();
    int check_win_scenario_7();
    int check_win_scenario_8();
};

#endif
