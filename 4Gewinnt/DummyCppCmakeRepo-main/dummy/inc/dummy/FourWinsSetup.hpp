//
// Created by Clemens Hanselmann on 17.05.23.
//

#ifndef DUMMY_FOURWINSSETUP_HPP
#define DUMMY_FOURWINSSETUP_HPP
class FourWinsSetup
{
public:
    char getFieldAtPosition(int row,int column);
    bool isBoardFull();
    void setGamePoints(int column);
    void initField();
    void printField();
    void enterRowAndColumn();
    void switchPlayer();

    void checkColumnWin(int column);
    void checkRowWin(int row);

    void checkLeftDiagWin();    /* checks from top left to right down, if there is a diagonal win */
    void checkRightDiagWin();   /* checks from bottom left to right top, if there is a diagonal win */

    void checkAllWinConditions();
    void getWinner();

    bool isPlaceEmpty(int column);
    bool isInputValid(int row,int column);
    bool isPlayerXWin() const;
    bool isPlayerOWin() const;
    int getPlayersTurn() const;

    const static char emptyPlace = '-';
    const static char grid = '|';

private:
    int m_playersTurn{0}; // 1 = player X , 0 = player O
    const static int m_columnLenght {7};
    const static int m_rowLenght {6};
    const char m_symbolPlayerX = 'X';
    const char m_symbolPlayerO = 'O';
    bool m_playerXWin{false};
    bool m_playerOWin{false};
    int m_playersRow{0};
    int m_playersColumn{0};
    char m_field[m_rowLenght][m_columnLenght];
    int m_rowPosition =0;

public:
    int getPlayersColumn() const;
    int getPlayersRow() const;
};
#endif // DUMMY_FOURWINSSETUP_HPP
