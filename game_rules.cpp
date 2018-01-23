#include "game_rules.h"


/*
 * Get locations corresponding to j's neighbors on the board
 */
vector<int> neighbors(int j)
{
    vector<int> nbs;

    if (j < 0 || j > 22) {
    	cout << "Error: location " << j << " not exist on the board" << endl;
    	return nbs;
    }

    switch (j) {
    case 0:
        nbs.push_back(1);
        nbs.push_back(3);
        nbs.push_back(8);
        break;
    case 1:
        nbs.push_back(0);
        nbs.push_back(2);
        nbs.push_back(4);
        break;
    case 2:
        nbs.push_back(1);
        nbs.push_back(5);
        nbs.push_back(13);
        break;
    case 3:
        nbs.push_back(0);
        nbs.push_back(4);
        nbs.push_back(6);
        nbs.push_back(9);
        break;
    case 4:
        nbs.push_back(1);
        nbs.push_back(3);
        nbs.push_back(5);
        break;
    case 5:
        nbs.push_back(2);
        nbs.push_back(4);
        nbs.push_back(7);
        nbs.push_back(12);
        break;
    case 6:
        nbs.push_back(3);
        nbs.push_back(7);
        nbs.push_back(10);
        break;
    case 7:
        nbs.push_back(5);
        nbs.push_back(6);
        nbs.push_back(11);
        break;
    case 8:
        nbs.push_back(0);
        nbs.push_back(9);
        nbs.push_back(20);
        break;
    case 9:
        nbs.push_back(3);
        nbs.push_back(8);
        nbs.push_back(10);
        nbs.push_back(17);
        break;
    case 10:
        nbs.push_back(6);
        nbs.push_back(9);
        nbs.push_back(14);
        break;
    case 11:
        nbs.push_back(7);
        nbs.push_back(12);
        nbs.push_back(16);
        break;
    case 12:
        nbs.push_back(5);
        nbs.push_back(11);
        nbs.push_back(13);
        nbs.push_back(19);
        break;
    case 13:
        nbs.push_back(2);
        nbs.push_back(12);
        nbs.push_back(22);
        break;
    case 14:
        nbs.push_back(10);
        nbs.push_back(15);
        nbs.push_back(17);
        break;
    case 15:
        nbs.push_back(14);
        nbs.push_back(16);
        nbs.push_back(18);
        break;
    case 16:
        nbs.push_back(11);
        nbs.push_back(15);
        nbs.push_back(19);
        break;
    case 17:
        nbs.push_back(9);
        nbs.push_back(14);
        nbs.push_back(18);
        nbs.push_back(20);
        break;
    case 18:
        nbs.push_back(15);
        nbs.push_back(17);
        nbs.push_back(19);
        nbs.push_back(21);
        break;
    case 19:
        nbs.push_back(12);
        nbs.push_back(16);
        nbs.push_back(18);
        nbs.push_back(22);
        break;
    case 20:
        nbs.push_back(8);
        nbs.push_back(17);
        nbs.push_back(21);
        break;
    case 21:
        nbs.push_back(18);
        nbs.push_back(20);
        nbs.push_back(22);
        break;
    case 22:
        nbs.push_back(13);
        nbs.push_back(19);
        nbs.push_back(21);
        break;
    }

    return nbs;
}

/*
 * Check whether a move to location j will close a mill
 */
bool closeMill(int j, Board board)
{
	if (j < 0 || j > 22) {
		cout << "Error: location " << j << " not exist on the board" << endl;
		return false;
	}

    char C = board.getLocationValue(j);
    if (C!='W' && C!='B') {
    	cout << "Error: value at location " << j << "must be either White or Black!" << endl;
    	return false;
    }

    switch (j) {
    case 0:
    	if ((board.getLocationValue(1)==C && board.getLocationValue(2)==C)
    			|| (board.getLocationValue(3)==C && board.getLocationValue(6)==C)
				|| (board.getLocationValue(8)==C && board.getLocationValue(20)==C))
    		return true;
    	else
    		return false;
    case 1:
    	if (board.getLocationValue(0)==C && board.getLocationValue(2)==C)
            return true;
        else
        	return false;
    case 2:
        if ((board.getLocationValue(0)==C && board.getLocationValue(1)==C)
        		|| (board.getLocationValue(5)==C && board.getLocationValue(7)==C)
				|| (board.getLocationValue(13)==C && board.getLocationValue(22)==C))
            return true;
        else
        	return false;
    case 3:
        if ((board.getLocationValue(0)==C && board.getLocationValue(6)==C)
        		|| (board.getLocationValue(4)==C && board.getLocationValue(5)==C)
				|| (board.getLocationValue(9)==C && board.getLocationValue(17)==C))
            return true;
        else
        	return false;
    case 4:
        if (board.getLocationValue(3)==C && board.getLocationValue(5)==C)
            return true;
        else
        	return false;
    case 5:
        if ((board.getLocationValue(4)==C && board.getLocationValue(3)==C)
        		|| (board.getLocationValue(12)==C && board.getLocationValue(19)==C)
				|| (board.getLocationValue(2)==C && board.getLocationValue(7)==C))
            return true;
        else
        	return false;
    case 6:
        if ((board.getLocationValue(3)==C && board.getLocationValue(0)==C)
        		|| (board.getLocationValue(10)==C && board.getLocationValue(14)==C))
            return true;
        else
        	return false;
    case 7:
        if ((board.getLocationValue(11)==C && board.getLocationValue(16)==C)
        		|| (board.getLocationValue(5)==C && board.getLocationValue(2)==C))
            return true;
        else
        	return false;
    case 8:
        if ((board.getLocationValue(0)==C && board.getLocationValue(20)==C)
        		|| (board.getLocationValue(9)==C && board.getLocationValue(10)==C))
            return true;
        else
        	return false;
    case 9:
        if ((board.getLocationValue(17)==C && board.getLocationValue(3)==C)
        		|| (board.getLocationValue(8)==C && board.getLocationValue(10)==C))
            return true;
        else
        	return false;
    case 10:
        if ((board.getLocationValue(8)==C && board.getLocationValue(9)==C)
        		|| (board.getLocationValue(6)==C && board.getLocationValue(14)==C))
            return true;
        else
        	return false;
    case 11:
        if ((board.getLocationValue(16)==C && board.getLocationValue(7)==C)
        		|| (board.getLocationValue(12)==C && board.getLocationValue(13)==C))
            return true;
        else
        	return false;
    case 12:
        if ((board.getLocationValue(19)==C && board.getLocationValue(5)==C)
        		|| (board.getLocationValue(11)==C && board.getLocationValue(13)==C))
            return true;
        else
        	return false;
    case 13:
        if ((board.getLocationValue(11)==C && board.getLocationValue(12)==C)
        		|| (board.getLocationValue(22)==C && board.getLocationValue(2)==C))
            return true;
        else
        	return false;
    case 14:
        if ((board.getLocationValue(10)==C && board.getLocationValue(6)==C)
        		|| (board.getLocationValue(17)==C && board.getLocationValue(20)==C)
				|| (board.getLocationValue(15)==C && board.getLocationValue(16)==C))
            return true;
        else
        	return false;
    case 15:
        if ((board.getLocationValue(18)==C && board.getLocationValue(21)==C)
        		|| (board.getLocationValue(14)==C && board.getLocationValue(16)==C))
            return true;
        else
        	return false;
    case 16:
        if ((board.getLocationValue(14)==C && board.getLocationValue(15)==C)
        		|| (board.getLocationValue(11)==C && board.getLocationValue(7)==C)
				|| (board.getLocationValue(19)==C && board.getLocationValue(22)==C))
            return true;
        else
        	return false;
    case 17:
        if ((board.getLocationValue(20)==C && board.getLocationValue(14)==C)
        		|| (board.getLocationValue(18)==C && board.getLocationValue(19)==C)
				|| (board.getLocationValue(9)==C && board.getLocationValue(3)==C))
            return true;
        else
        	return false;
    case 18:
        if ((board.getLocationValue(21)==C && board.getLocationValue(15)==C)
        		|| (board.getLocationValue(17)==C && board.getLocationValue(19)==C))
            return true;
        else
        	return false;
    case 19:
        if ((board.getLocationValue(16)==C && board.getLocationValue(22)==C)
        		|| (board.getLocationValue(12)==C && board.getLocationValue(5)==C)
				|| (board.getLocationValue(17)==C && board.getLocationValue(18)==C))
            return true;
        else
        	return false;
    case 20:
        if ((board.getLocationValue(8)==C && board.getLocationValue(0)==C)
        		|| (board.getLocationValue(17)==C && board.getLocationValue(14)==C)
				|| (board.getLocationValue(21)==C && board.getLocationValue(22)==C))
            return true;
        else
        	return false;
    case 21:
        if ((board.getLocationValue(18)==C && board.getLocationValue(15)==C)
        		|| (board.getLocationValue(22)==C && board.getLocationValue(20)==C))
            return true;
        else
        	return false;
    case 22:
        if ((board.getLocationValue(19)==C && board.getLocationValue(16)==C)
        		|| (board.getLocationValue(13)==C && board.getLocationValue(2)==C)
				|| (board.getLocationValue(21)==C && board.getLocationValue(20)==C))
            return true;
        else
            return false;

    default:
        return false;
    }
}




Board::Board()
{
    int i;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        board_position.push_back('x');
    }
}

Board::Board(char values[])
{
    int i;
    if (strlen(values) == BOARD_SIZE)
    {
        for(i = 0; i < BOARD_SIZE; i++)
        {
            board_position.push_back(values[i]);
        }
    }
    else
    {
    	cout << "Error: number of locations not match" << endl;
    	exit(1);
    }
}

char Board::getLocationValue(int index)
{
    return board_position.at(index);
}

void Board::setLocationValue(int index, char val)
{
    board_position.at(index) = val;
}

vector<char> Board::getBoardPosition()
{
    return board_position;
}

int Board::getPieceNum(char color)
{
    int count = 0;

    for (int i = 0; i < board_position.size(); i++)
    {
        if (board_position.at(i) == color)
        {
            count++;
        }
    }
    return count;
}

void Board::swapColor()
{
	for (int i = 0; i < board_position.size(); i++)
	{
	    if (board_position.at(i) == 'W')
	    {
	    	board_position.at(i) = 'B';
	    }
	    else if (board_position.at(i) == 'B')
	    {
	    	board_position.at(i) = 'W';
	    }
	}
}

string Board::display()
{
    char temp[BOARD_SIZE + 1];
    string output;
    for (int i = 0; i < BOARD_SIZE; i++) {
        temp[i] = board_position.at(i);
    }
    output = (string)temp;
    return output;
}




vector<Board> Generator::GenerateMovesOpening(Board board)
{
    /* Return the list of board positions produced by GenerateAdd */
    return GenerateAdd(board);
}

vector<Board> Generator::GenerateMovesMidgameEndgame(Board board)
{
    if (board.getPieceNum('W') == 3)
    {
        return GenerateHopping(board);
    }
    else
    {
    	return GenerateMove(board);
    }
}

vector<Board> Generator::GenerateAdd(Board board)
{
    vector<Board> List;

    for (int i = 0; i < board.getBoardPosition().size(); i++)
    {
        if (board.getLocationValue(i) == 'x')
        {
            Board boardCopy = board;
            boardCopy.setLocationValue(i, 'W');
            if (closeMill(i, boardCopy))
            {
                List = GenerateRemove(boardCopy, List);
            }
            else
            {
                List.push_back(boardCopy);
            }
        }
    }

    return List;
}

vector<Board> Generator::GenerateMove(Board board)
{
    vector<Board> List;

    for (int i = 0; i < board.getBoardPosition().size(); i++)
    {
        if (board.getLocationValue(i) == 'W')
        {
            vector<int> nbs = neighbors(i);
            for (int j = 0; j < nbs.size(); j++) {
                int k = nbs.at(j);
                if (board.getLocationValue(k) == 'x')
                {
                    Board boardCopy = board;
                    boardCopy.setLocationValue(i, 'x');
                    boardCopy.setLocationValue(k, 'W');
                    if (closeMill(k, boardCopy))
                    {
                        List = GenerateRemove(boardCopy, List);
                    }
                    else
                    {
                        List.push_back(boardCopy);
                    }
                }
            }
        }
    }

    return List;
}

vector<Board> Generator::GenerateHopping(Board board)
{
    vector<Board> List;

    for (int i = 0; i < board.getBoardPosition().size(); i++)
    {
        if (board.getLocationValue(i) == 'W')
        {
            for (int j = 0; j < board.getBoardPosition().size(); j++)
            {
                if (board.getLocationValue(j) == 'x')
                {
                    Board board_copy = board;
                    board_copy.setLocationValue(i, 'x');
                    board_copy.setLocationValue(j, 'W');
                    if (closeMill(j, board_copy))
                    {
                        List = GenerateRemove(board_copy, List);
                    }
                    else
                    {
                        List.push_back(board_copy);
                    }
                }
            }
        }
    }

    return List;
}

vector<Board> Generator::GenerateRemove(Board board, vector<Board> List)
{
	bool noPosAdded = true;

    for (int i = 0; i < board.getBoardPosition().size(); i++)
    {
        if (board.getLocationValue(i) == 'B')
        {
            if (!closeMill(i, board))
            {
                Board boardCopy = board;
                boardCopy.setLocationValue(i, 'x');
                List.push_back(boardCopy);
                noPosAdded = false;
            }
        }
    }
    if (noPosAdded)								//If no positions added, add board to List
    {
    	List.push_back(board);
    }

    return List;
}

vector<Board> Generator::GenerateMovesOpening_Black(Board board)
{
    vector<Board> List;

    board.swapColor();
    List = GenerateMovesOpening(board);
    for (int i = 0; i < List.size(); i++)
    {
        List.at(i).swapColor();
    }

    return List;
}

vector<Board> Generator::GenerateMovesMidEnd_Black(Board board)
{
    vector<Board> List;

    board.swapColor();
    List =GenerateMovesMidgameEndgame(board);
    for (int i = 0; i < List.size(); i++)
    {
        List.at(i).swapColor();
    }

    return List;
}




int Estimator::estimateOpening(Board board)
{
	int numWhitePieces, numBlackPieces;

	numWhitePieces = board.getPieceNum('W');
	numBlackPieces = board.getPieceNum('B');

	return (numWhitePieces - numBlackPieces);
}

int Estimator::estimateMidEnd(Board board)
{
    Generator gen;
    int numWhitePieces, numBlackPieces;
    int numBlackMoves;

    numWhitePieces = board.getPieceNum('W');
    numBlackPieces = board.getPieceNum('B');

    vector<Board> List = gen.GenerateMovesMidEnd_Black(board);
    numBlackMoves = static_cast<int>(List.size());

    if (numBlackPieces <= 2)
    {
        return 10000;
    }
    else if (numWhitePieces <= 2)
    {
        return -10000;
    }
    else if (numBlackMoves == 0)
    {
        return 10000;
    }
    else
    {
    	return (1000 * (numWhitePieces - numBlackPieces) - numBlackMoves);
    }
}

int Estimator::estimateOpening_Black(Board board)
{
	int numWhitePieces, numBlackPieces;

	numWhitePieces = board.getPieceNum('W');
	numBlackPieces = board.getPieceNum('B');

	return (numBlackPieces - numWhitePieces);
}

int Estimator::estimateMidEnd_Black(Board board)
{
	Generator gen;
	int numWhitePieces, numBlackPieces;
	int numWhiteMoves;

	numWhitePieces = board.getPieceNum('W');
	numBlackPieces = board.getPieceNum('B');

	vector<Board> List = gen.GenerateMovesMidgameEndgame(board);
	numWhiteMoves = static_cast<int>(List.size());

    if (numWhitePieces <= 2)
    {
        return 10000;
    }
    else if (numBlackPieces <= 2)
    {
        return -10000;
    }
    else if (numWhiteMoves == 0)
    {
        return 10000;
    }
    else
    {
    	return (1000 * (numBlackPieces - numWhitePieces) - numWhiteMoves);
    }
}

int Estimator::estimateOpening_Improved(Board board, bool isWhite)
{
    int number_mills = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board.getLocationValue(i) == 'x') {
            Board tmp = board;
            if (isWhite) {
            	tmp.setLocationValue(i, 'W');
            	if (closeMill(i, tmp))
            		number_mills++;
            } else {
            	tmp.setLocationValue(i, 'B');
            	if (closeMill(i, tmp))
            		number_mills--;
            }
        }
    }
    return estimateOpening(board) + number_mills;
}

int Estimator::estimateMidEnd_Improved(Board board, bool isWhite)
{
    Generator gen;
    int numWhitePieces, numBlackPieces;
    int numBlackMoves, numWhiteMoves;

    numWhitePieces = board.getPieceNum('W');
    numBlackPieces = board.getPieceNum('B');

    vector<Board> List = gen.GenerateMovesMidEnd_Black(board);
    numBlackMoves = static_cast<int>(List.size());

    List = gen.GenerateMovesMidgameEndgame(board);
    numWhiteMoves = static_cast<int>(List.size());

    if (numBlackPieces <= 2)
    {
        return 10000;
    }
    else if (numWhitePieces <= 2)
    {
        return -10000;
    }
    else if(numBlackMoves == 0)
    {
        return 10000;
    }
    else
    {
    	if (isWhite)
    	    return (1000 * (numWhitePieces - numBlackPieces) + numWhiteMoves - numBlackMoves);
    	else
    		return (1000 * (numWhitePieces - numBlackPieces) - numBlackMoves);
    }
}

int Estimator::getEstimate_value()
{
    return estimate_value;
}


Board Estimator::getBoard()
{
    return board_out;
}

void Estimator::setEstimate(int estimate)
{
    estimate_value = estimate;
}


void Estimator::setBoard(Board board)
{
    board_out = board;
}

