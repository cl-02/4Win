#include "dummy/FourWinsSetup.hpp"
#include <iostream>
using namespace std;

void FourWinsSetup::switchPlayer()
{
    m_playersTurn ^= 1;
}

int FourWinsSetup::getPlayersTurn() const
{
    return m_playersTurn;
}

void FourWinsSetup::initField()
{
    for(int i=0; i<m_rowLenght;i++)
    {
        for(int j=0; j<m_columnLenght;j++)
        {
            m_field[i][j] = '-';
        }
    }
}

char FourWinsSetup::getFieldAtPosition(int row, int column)
{
    return m_field[row][column];
}

void FourWinsSetup::setGameCoins(int column)
{
    if(isPlaceEmpty(column))
    {
        switch(m_playersTurn)
        {
        case 0:
            m_field[getNextFreeRow(column)][column] = m_symbolPlayerO;
            CountRowVariableDown(column);
            break ;
        case 1:
            m_field[getNextFreeRow(column)][column] = m_symbolPlayerX;
            CountRowVariableDown(column);
            break ;
        default:
            break ;
        }
        switchPlayer();
    }
}

bool FourWinsSetup::isBoardFull()
{
    bool isBoardFull = false;
    int cntGamePoints = 0;
    for(int i=0; i<(m_rowLenght); i++)
    {
        if((getFieldAtPosition(0,i)!= EMPTY_PLACE)&&(getFieldAtPosition(1,i)!= EMPTY_PLACE)&&(getFieldAtPosition(2,i)!= EMPTY_PLACE)&&(getFieldAtPosition(3,i)!= EMPTY_PLACE)&&(getFieldAtPosition(4,i)!= EMPTY_PLACE)&&(getFieldAtPosition(5,i)!= EMPTY_PLACE)&&(getFieldAtPosition(6,i)!= EMPTY_PLACE))
        {
            cntGamePoints++;
        }
    }
    if(cntGamePoints==5)
    {
        isBoardFull = true;
    }
    return isBoardFull;
}

void FourWinsSetup::checkRowWin(int row)
{
    if(row < m_rowLenght)
    {
        for(int i=0; i < m_columnLenght; i++)
        {
            if(m_field[row][i] == m_symbolPlayerO &&
                m_field[row][i+1] == m_symbolPlayerO &&
                m_field[row][i+2] == m_symbolPlayerO &&
                m_field[row][i+3] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[row][i] == m_symbolPlayerX &&
                m_field[row][i+1] == m_symbolPlayerX &&
                m_field[row][i+2] == m_symbolPlayerX &&
                m_field[row][i+3] == m_symbolPlayerX )
            {
                m_playerXWin = true;
            }
        }
    }
}

void FourWinsSetup::checkLeftBottomToTopDiagWin()
{
    for(int i= m_rowLenght-1; i >= 3;i--)
    {
        for(int j = 0;j <= m_columnLenght-4;j++)
        {
            if(m_field[i][j] == m_symbolPlayerO &&
                m_field[i-1][j+1] == m_symbolPlayerO &&
                m_field[i-2][j+2] == m_symbolPlayerO &&
                m_field[i-3][j+3] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[i][j] == m_playerXWin &&
                m_field[i-1][j+1] == m_playerXWin &&
                m_field[i-2][j+2] == m_playerXWin &&
                m_field[i-3][j+3] == m_playerXWin )
            {
                m_playerXWin = true;
            }
        }
    }
}

void FourWinsSetup::checkLeftTopToBottomDiagWin()
{
    for(int i=0;i <=m_rowLenght-4;i++)
    {
        for(int j =0; j<=m_columnLenght-4;j++)
        {
            if(m_field[i][j] == m_symbolPlayerO &&
                m_field[i+1][j+1] == m_symbolPlayerO &&
                m_field[i+2][j+2] == m_symbolPlayerO &&
                m_field[i+3][j+3] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[i][j] == m_playerXWin &&
                m_field[i+1][j+1] == m_playerXWin &&
                m_field[i+2][j+2] == m_playerXWin &&
                m_field[i+3][j+3] == m_playerXWin )
            {
                m_playerXWin = true;
            }
        }
    }
}

void FourWinsSetup::checkVerticalWin()
{
    for(int i= 0;i<m_rowLenght;i++)
    {
        for(int j=0;j<m_columnLenght;j++)
        {
            if(m_field[i][j] == m_symbolPlayerO &&
                m_field[i+1][j] == m_symbolPlayerO &&
                m_field[i+2][j] == m_symbolPlayerO &&
                m_field[i+3][j] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[i][j] == m_playerXWin &&
                m_field[i+1][j] == m_playerXWin &&
                m_field[i+2][j] == m_playerXWin &&
                m_field[i+3][j] == m_playerXWin )
            {
                m_playerXWin = true;
            }
        }
    }
}

void FourWinsSetup::checkHorizontalWin()
{
    for(int i= 0;i < m_rowLenght;i++)
    {
        for(int j=0;j<m_columnLenght;j++)
        {
            if(m_field[i][j] == m_symbolPlayerO &&
                m_field[i][j+1] == m_symbolPlayerO &&
                m_field[i][j+2] == m_symbolPlayerO &&
                m_field[i][j+3] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[i][j] == m_playerXWin &&
                m_field[i][j+1] == m_playerXWin &&
                m_field[i][j+2] == m_playerXWin &&
                m_field[i][j+3] == m_playerXWin )
            {
                m_playerXWin = true;
            }
        }
    }
}

void FourWinsSetup::CountRowVariableDown(int column)
{
    switch (column)
    {
    case 0:
        m_rowPosition0 --;
        break ;
    case 1:
        m_rowPosition1 --;
        break ;
    case 2:
        m_rowPosition2 --;
        break ;
    case 3:
        m_rowPosition3 --;
        break ;
    case 4:
        m_rowPosition4 --;
        break ;
    case 5:
        m_rowPosition5 --;
        break ;
    case 6:
        m_rowPosition6 --;
        break ;
    }
}

int FourWinsSetup::getNextFreeRow(int column)
{
    int rowCntr =0;
    switch (column)
    {
    case 0:
        rowCntr = m_rowPosition0 -1;
        break ;
    case 1:
        rowCntr = m_rowPosition1 -1;
        break ;
    case 2:
        rowCntr = m_rowPosition2 -1;
        break ;
    case 3:
        rowCntr = m_rowPosition3 -1;
        break ;
    case 4:
        rowCntr = m_rowPosition4 -1;
        break ;
    case 5:
        rowCntr = m_rowPosition5 -1;
        break ;
    case 6:
        rowCntr = m_rowPosition6 -1;
        break ;
    }
    return rowCntr;
}

bool FourWinsSetup::isPlaceEmpty(int column)
{
    bool isPlaceEmpty = false;

    if(m_field[getNextFreeRow(column)][column]== EMPTY_PLACE)
    {
        isPlaceEmpty = true;
    }
    return isPlaceEmpty;
}

void FourWinsSetup::printField()
{
    cout <<' '<<' '<<0<<' '<<1<<' '<<2<<' '<<3<<' '<<4<<' '<<5<<' '<<6<<' '<<endl;
    for(int i = 0; i<m_rowLenght; i++)
    {
        cout<< i<< GRID << m_field[i][0] << GRID << m_field[i][1] << GRID <<  m_field[i][2] << GRID <<  m_field[i][3] << GRID <<  m_field[i][4] << GRID <<  m_field[i][5] << GRID <<  m_field[i][6] << GRID <<endl;
    }
    cout<<endl;
}

bool FourWinsSetup::isInputValid( int column)
{
    bool isInputValid = false;
    if((column < m_columnLenght) && isPlaceEmpty(column))
    {
        isInputValid = true;
    }
    return isInputValid;
}

void FourWinsSetup::setPlayersColumn()
{
    printEnterPlayersColumn();
    if(isInputValid(m_playersColumn))
    {
        setGameCoins(m_playersColumn);
    }
    else
    {
        cout <<"ERROR: enter column again...."<< endl;
       setPlayersColumn();
    }
}

void FourWinsSetup::printEnterPlayersColumn()
{
    char name = 'E';
    if(m_playersTurn == 0)
    {
        name = m_symbolPlayerO;
    }
    if(m_playersTurn == 1)
    {
        name = m_symbolPlayerX;
    }

    cout <<"Player " << name << " enter column please" << endl;
    cin >> m_playersColumn;
}

void FourWinsSetup::checkAllWinConditions()
{
    for(int i=0; i<m_rowLenght;i++)
    {
        checkRowWin(i);
    }
    checkLeftBottomToTopDiagWin();
    checkLeftTopToBottomDiagWin();
    checkVerticalWin();
    checkHorizontalWin();
}

void FourWinsSetup::getWinner()
{
    checkAllWinConditions();
    if(m_playerOWin)
    {
        std::cout <<"Player with symbol O is winner"<<std::endl;
    }
    if(m_playerXWin)
    {
        std::cout <<"Player with symbol X is winner"<<std::endl;
    }
    if(isBoardFull())
    {
        std::cout <<"draw: no one wins"<<std::endl;
    }
}

bool FourWinsSetup::isPlayerXWin() const
{
    return m_playerXWin;
}

bool FourWinsSetup::isPlayerOWin() const
{
    return m_playerOWin;
}
