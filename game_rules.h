#ifndef GAME_RULES_H
#define GAME_RULES_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>


#define BOARD_SIZE 23

using namespace std;


class Board
{
    vector<char> board_position;

public:
    Board();
    Board(char board_position_values[]);

    char getLocationValue(int index);				//get location index's value
    void setLocationValue(int index, char val);		//set location index's value
    vector<char> getBoardPosition();				//get board position values
    int getPieceNum(char color);					//obtain number of white or black pieces
    void swapColor();								//swap location value, replace 'W' with 'B', and 'B' with 'W'
    string display();
};


class Generator
{
public:
    /* Generate moves at opening phase */
    vector<Board> GenerateMovesOpening(Board board);
    /* Generate moves at midgame or endgame phase */
    vector<Board> GenerateMovesMidgameEndgame(Board board);
    /* Add a white piece on the board at opening phase */
    vector<Board> GenerateAdd (Board board);
    /* Move a white piece along a board line at midgame phase */
    vector<Board> GenerateMove(Board board);
    /* Move a white piece to any open spot at endgame phase */
    vector<Board> GenerateHopping (Board board);
    /* Remove an isolated black piece when create a mill */
    vector<Board> GenerateRemove(Board board, vector<Board> List);

    /* Generate moves for black piece at opening phase */
    vector<Board> GenerateMovesOpening_Black(Board board);
    /* Generate moves for black piece at midgame or endgame phase */
    vector<Board> GenerateMovesMidEnd_Black(Board board);
};


class Estimator
{
private:
    int estimate_value;
    Board board_out;

public:
    int estimateOpening(Board board);
    int estimateMidEnd(Board board);

    int estimateOpening_Black(Board board);
    int estimateMidEnd_Black(Board board);

    int estimateOpening_Improved(Board board, bool isWhite);
    int estimateMidEnd_Improved(Board board, bool isWhite);

    int getEstimate_value();
    void setEstimate(int estimate);
    Board getBoard();
    void setBoard(Board board);
};


#endif
