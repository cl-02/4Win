//
// Created by Clemens Hanselmann on 17.05.23.
//

#ifndef DUMMY_FOURWINSSETUP_HPP
#define DUMMY_FOURWINSSETUP_HPP
class FourWinsSetup
{
public:

    void initField();
    void printField();
    void printEnterPlayersColumn();
    void setPlayersColumn();
    void setGameCoins(int column);
    void switchPlayer();

    /* win conditions */
    void checkRowWin(int row);
    void checkLeftBottomToTopDiagWin();     /* checks from top left to right down, if there is a diagonal win */
    void checkLeftTopToBottomDiagWin();     /* checks from bottom left to right top, if there is a diagonal win */
    void checkVerticalWin();                   /* todo */
    void checkHorizontalWin();                       /* todo */

    void checkAllWinConditions();
    void getWinner();                       /* print winner */

    bool isPlaceEmpty(int column);
    bool isInputValid(int column);
    char getFieldAtPosition(int row,int column);
    bool isBoardFull();

    bool isPlayerXWin() const;
    bool isPlayerOWin() const;
    int getPlayersTurn() const;            /* 1 = player X
                                            * 0 = player O */

    int getNextFreeRow(int column);       /* this function returns the next free row as an int*/
    void CountRowVariableDown(int column);

private:

    /* variables for player */
    int m_playersTurn{0};          // 1 = player X , 0 = player O
    const char m_symbolPlayerX = 'X';
    const char m_symbolPlayerO = 'O';
    bool m_playerXWin{false};
    bool m_playerOWin{false};
    int m_playersColumn{0};

    /* variables for field */
    const static int m_columnLenght {7};
    const static int m_rowLenght {6};
    char m_field[m_rowLenght][m_columnLenght];

    /* variables to count row positions of columns */
    int m_rowPosition0{m_rowLenght};
    int m_rowPosition1{m_rowLenght};
    int m_rowPosition2{m_rowLenght};
    int m_rowPosition3{m_rowLenght};
    int m_rowPosition4{m_rowLenght};
    int m_rowPosition5{m_rowLenght};
    int m_rowPosition6{m_rowLenght};

    /* variables for visualization */
    const static char EMPTY_PLACE = '-';
    const static char GRID = '|';
};
#endif // DUMMY_FOURWINSSETUP_HPP
