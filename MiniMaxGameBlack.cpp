#include "game_rules.h"

int posEvaluated = 0;


Estimator MiniMaxGameBlack(Board board, int depth, bool isBlack)
{
	Generator geo;
    Estimator estim;

    if (depth == 0)
    {
    	int estiVal = estim.estimateMidEnd_Black(board);
    	estim.setEstimate(estiVal);
       	estim.setBoard(board);
  	   	posEvaluated++;

        return estim;
    }

    vector<Board> List;
    if (isBlack)							//Black move, takes MaxMin()
    {
        List = geo.GenerateMovesMidEnd_Black(board);
        Estimator temp;

        estim.setEstimate(-99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = MiniMaxGameBlack(List.at(i), depth - 1, false);

            if (temp.getEstimate_value() > estim.getEstimate_value())
            {
                estim.setEstimate(temp.getEstimate_value());
                estim.setBoard(List.at(i));
            }
        }

        posEvaluated++;
        return estim;
    }
    else									//White move, takes MinMax()
    {
        List = geo.GenerateMovesMidgameEndgame(board);
        Estimator temp;

        estim.setEstimate(99999);
        for (int i = 0; i < List.size(); i++)
        {
            temp = MiniMaxGameBlack(List.at(i), depth - 1, true);

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

    char input[BOARD_SIZE+1];
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
    Estimator out = MiniMaxGameBlack(board, depth, true);

    cout << "Board Position: " << out.getBoard().display() << endl;
    cout << "Position evaluated by static estimation: " << posEvaluated << endl;
    cout << "MiniMax Estimate: " << out.getEstimate_value() << endl;

    //write to file
    ofs << out.getBoard().display();

    return 0;
}

