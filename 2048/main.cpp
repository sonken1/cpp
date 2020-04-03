#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class tile
{
public:
    int val = 0;
    bool occupied = false;
    bool moved = false;

    void printVal()
    {
        cout << val;
    }
};


class Game
{
    public:
        bool game_over = false;
        bool won = false;
        int score = 0;
        tile board[4][4];

    void displayBoard()
    {
        for (int row = 0; row < 4; row ++)
        {
            cout << "+------+------+------+------+" << endl << "| ";
            for (int col = 0; col < 4; col ++)
            {
                if (board[row][col].val != 0)
                {
                    cout << setw(4);
                    board[row][col].printVal();
                }
                else
                {
                    cout << setw(4) << " ";
                }
                cout << " | ";
            }
            cout << endl;
        }
        cout << "+------+------+------+------+" << endl << endl;
	}

    void addTile(bool isFirst=false)
    {
        int val, percent, row, col;

        if (isFirst)
        {
            srand (time(NULL));
            percent = rand()% 100;
            row = rand()% 4;
            col = rand()% 4;
            if (percent < 65)
            {
                val = 2;
            }
            else
            {
                val = 4;
            }
            board[row][col].val = val;
            board[row][col].occupied = true;
        }

        else
        {
            srand (time(NULL));
            percent = rand()% 100;
            if (percent < 75)
            {
                srand (time(NULL));
                row = rand()% 4;
                col = rand()% 4;
                if (percent < 60)
                {
                    val = 2;
                }
                else
                {
                    val = 4;
                }
                board[row][col].val = val;
                board[row][col].occupied = true;
            }
        }
        
    }

    void resetMoved()
    {
        for (int row = 0; row < 4; row ++)
        {
            for (int col = 0; col < 4; col ++)
            {
                board[row][col].moved = false;
            }
        }
    }

    void moveUp()
    {
        for (int row = 1; row < 4; row ++)
        {
            for (int col = 0; col < 4; col ++)
            {
                if (board[row][col].occupied)
                {
                    if (board[row - 1][col].occupied)
                    {
                        if (board[row - 1][col].val == board[row][col].val && !board[row][col].moved && !board[row-1][col].moved)
                        {
                        board[row - 1][col].val = board[row - 1][col].val + board[row][col].val;
                        board[row - 1][col].moved = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        }
                    }
                    else
                    {
                        board[row - 1][col].val = board[row][col].val;
                        board[row - 1][col].occupied = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        moveUp();
                    }
                }
            }
        }        
    }

    void moveDown()
    {
        for (int row = 2; row > -1; row --)
        {
            for (int col = 0; col < 4; col ++)
            {
                if (board[row][col].occupied)
                {
                    if (board[row + 1][col].occupied)
                    {
                        if (board[row + 1][col].val == board[row][col].val && !board[row][col].moved && !board[row + 1][col].moved)
                        {
                        board[row + 1][col].val = board[row + 1][col].val + board[row][col].val;
                        board[row + 1][col].moved = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        }
                    }
                    else
                    {
                        board[row + 1][col].val = board[row][col].val;
                        board[row + 1][col].occupied = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        moveDown();
                    }
                }
            }
        }        
    }

    void moveLeft()
    {
        for (int row = 0; row < 4; row ++)
        {
            for (int col = 1; col < 4; col ++)
            {
                if (board[row][col].occupied)
                {
                    if (board[row][col - 1].occupied)
                    {
                        if (board[row][col - 1].val == board[row][col].val && !board[row][col].moved && !board[row][col-1].moved)
                        {
                        board[row][col - 1].val = board[row][col - 1].val + board[row][col].val;
                        board[row][col - 1].moved = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        }
                    }
                    else
                    {
                        board[row][col - 1].val = board[row][col].val;
                        board[row][col - 1].occupied = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        moveLeft();
                    }
                }
            }
        }        
    }

    void moveRight()
    {
        for (int row = 0; row < 4; row ++)
        {
            for (int col = 2; col > -1; col --)
            {
                if (board[row][col].occupied)
                {
                    if (board[row][col + 1].occupied)
                    {
                        if (board[row][col + 1].val == board[row][col].val && !board[row][col].moved && !board[row][col + 1].moved)
                        {
                        board[row][col + 1].val = board[row][col + 1].val + board[row][col].val;
                        board[row][col + 1].moved = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        }
                    }
                    else
                    {
                        board[row][col + 1].val = board[row][col].val;
                        board[row][col + 1].occupied = true;
                        board[row][col].val = 0;
                        board[row][col].occupied = false;
                        moveRight();
                    }
                }
            }
        }        
    }

    void moveTiles(char direction)
    {
        switch (direction)
        {
        case 'W':
            moveUp();
            resetMoved();
            break;

        case 'S':
            moveDown();
            resetMoved();
            break;

        case 'A':
            moveLeft();
            resetMoved();
            break;

        case 'D':
            moveRight();
            resetMoved();
            break;

        default:
            break;
        }
    }
};


int main()
{
    Game G;
    //G.addTile(true);
    //G.addTile();
    G.board[0][0].val = 4;
    G.board[0][0].occupied = true;
    G.board[1][0].val = 4;
    G.board[1][0].occupied = true;
    G.board[2][0].val = 8;
    G.board[2][0].occupied = true;
    G.board[3][0].val = 4;
    G.board[3][0].occupied = true;
    G.board[0][1].val = 2;
    G.board[0][1].occupied = true;
    G.board[1][1].val = 4;
    G.board[1][1].occupied = true;
    G.board[2][1].val = 4;
    G.board[2][1].occupied = true;
    G.board[3][1].val = 8;
    G.board[3][1].occupied = true;
    G.board[3][2].val = 4;
    G.board[3][2].occupied = true;
    G.board[3][3].val = 4;
    G.board[3][3].occupied = true;
    G.displayBoard();
    G.moveTiles('D');
    G.displayBoard();
    G.moveTiles('D');
    G.displayBoard();
    return 0;
}