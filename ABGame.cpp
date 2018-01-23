#include "game_rules.h"

int posEvaluated = 0;


Estimator AlphaBetaGame(Board board, int depth, bool isWhite, int alpha, int beta)
{
	Generator geo;
    Estimator estim;

    if (depth == 0)
    {
    	int estiVal = estim.estimateMidEnd(board);
    	estim.setEstimate(estiVal);
    	estim.setBoard(board);
    	posEvaluated++;

        return estim;
    }

    vector<Board> List;
    if (isWhite)							//White move, takes MaxMin()
    {
        List = geo.GenerateMovesMidgameEndgame(board);
        Estimator temp;

        estim.setEstimate(-99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = AlphaBetaGame(List.at(i), depth - 1, false, alpha, beta);

            if (temp.getEstimate_value() > estim.getEstimate_value())
            {
                estim.setEstimate(temp.getEstimate_value());
                estim.setBoard(List.at(i));
            }
            if (estim.getEstimate_value() > alpha)
            {
                alpha = estim.getEstimate_value();
            }
            if(beta <= alpha)
            	break;
        }

        posEvaluated++;
        return estim;
    }
    else
    {
        List = geo.GenerateMovesMidEnd_Black(board);
        Estimator temp;

        estim.setEstimate(99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = AlphaBetaGame(List.at(i), depth - 1, true, alpha, beta);

            if (temp.getEstimate_value() < estim.getEstimate_value())
            {
                estim.setEstimate(temp.getEstimate_value());
                estim.setBoard(List.at(i));
            }
            if (estim.getEstimate_value() < beta)
            {
                beta = estim.getEstimate_value();
            }
            if (beta <= alpha)
                break;
        }

        posEvaluated++;
        return estim;
    }
}



int main(int argc, char* argv[]) {
    if (argc != 4)
    {
        cout << "Missing argument!" << endl;
        exit(1);
    }

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);
    int depth = atoi(argv[3]);

    char input[BOARD_SIZE];
    int i = 0;
    if (ifs.is_open())
    {
        while (!ifs.eof())
        {
            ifs >> input[i];
            i++;
        }
        ifs.close();
    }
    else
    {
        cout << "Unable to Open the file" << endl;
    }
    //cout << "Input Board: " << board << endl;

    Board board(input);
    Estimator out=AlphaBetaGame(board, depth, true, -99999, 99999);

    cout << "Board Position: " << out.getBoard().display() << endl;
    cout << "Position evaluated by static estimation: " << posEvaluated << endl;
    cout << "MiniMax Estimate: " << out.getEstimate_value() << endl;

    //write to file
    ofs << out.getBoard().display();

    return 0;
}
