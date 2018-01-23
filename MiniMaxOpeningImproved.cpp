#include "game_rules.h"

int posEvaluated = 0;


Estimator MiniMaxOpeningImproved(Board board, int depth, bool isWhite)
{
	Generator geo;
	Estimator estim;

    if (depth == 0)
    {
    	int estiVal = estim.estimateOpening_Improved(board, isWhite);
    	estim.setEstimate(estiVal);
        estim.setBoard(board);
        posEvaluated++;

    	return estim;
    }

    vector<Board> List;
    if (isWhite)						//White move, takes MaxMin()
    {
        List=geo.GenerateMovesOpening(board);
        Estimator temp;

        estim.setEstimate(-99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = MiniMaxOpeningImproved(List.at(i), depth - 1, false);

            if(temp.getEstimate_value() > estim.getEstimate_value())
            {
                estim.setEstimate(temp.getEstimate_value());
                estim.setBoard(List.at(i));
            }
        }

        posEvaluated++;
        return estim;
    }
    else								//Black move, takes MinMax()
    {
        List = geo.GenerateMovesOpening_Black(board);
        Estimator temp;

        estim.setEstimate(99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = MiniMaxOpeningImproved(List.at(i), depth - 1, true);

            if (temp.getEstimate_value() < estim.getEstimate_value())
            {
                estim.setEstimate(temp.getEstimate_value());
                estim.setBoard(List.at(i));
            }
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
    //cout << "Input Board: " << input << endl;

    Board board(input);
    Estimator out = MiniMaxOpeningImproved(board, depth, true);

    cout << "Board Position: " << out.getBoard().display() << endl;
    cout << "Position evaluated by static estimation: " << posEvaluated << endl;
    cout << "MiniMax Estimate: " << out.getEstimate_value() << endl;

    //write to file
    ofs << out.getBoard().display();

    return 0;
}

