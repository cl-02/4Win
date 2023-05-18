//
// Created by Clemens Hanselmann on 17.05.23.
//
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

void FourWinsSetup::setGamePoints(int column)
{
    if(isPlaceEmpty(column))
    {
        switch(m_playersTurn)
        {
        case 0:
            m_field[getNextFreeRow(column)][column] = m_symbolPlayerO;
            setRow(column);
            break ;
        case 1:
            m_field[getNextFreeRow(column)][column] = m_symbolPlayerX;
            setRow(column);
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
        if((getFieldAtPosition(0,i)!= emptyPlace)&&(getFieldAtPosition(1,i)!= emptyPlace)&&(getFieldAtPosition(2,i)!= emptyPlace)&&(getFieldAtPosition(3,i)!= emptyPlace)&&(getFieldAtPosition(4,i)!= emptyPlace)&&(getFieldAtPosition(5,i)!= emptyPlace)&&(getFieldAtPosition(6,i)!= emptyPlace))
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

void FourWinsSetup::checkColumnWin(int column)
{
    if(column < m_columnLenght)
    {
        for(int i=0; i < m_rowLenght; i++)
        {
            if(m_field[i][column] == m_symbolPlayerO &&
                m_field[i+1][column] == m_symbolPlayerO &&
                m_field[i+2][column] == m_symbolPlayerO &&
                m_field[i+3][column] == m_symbolPlayerO )
            {
                m_playerOWin = true;
            }
            if(m_field[i][column] == m_symbolPlayerX &&
                m_field[i+1][column] == m_symbolPlayerX &&
                m_field[i+2][column] == m_symbolPlayerX &&
                m_field[i+3][column] == m_symbolPlayerX )
            {
                m_playerXWin = true;
            }
        }


    }
}
void FourWinsSetup::checkLeftBottomToTopDiagWin()
{
    for(int i= m_rowLenght-1;i >= 3;i--)
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

void FourWinsSetup::checkVertical()
{
    for(int i= 0;i<=m_rowLenght-4;i++)
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
void FourWinsSetup::checkHori()
{
    for(int i= 0;i < m_rowLenght;i++)
    {
        for(int j=0;j<m_columnLenght-4;j++)
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

void FourWinsSetup::setRow(int column)
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

    if(m_field[getNextFreeRow(column)][column]== emptyPlace)
    {
        isPlaceEmpty = true;
    }
    return isPlaceEmpty;
}

void FourWinsSetup::printField()
{
    cout <<' '<<' '<<0<<' '<<1<<' '<<2<<' '<<3<<' '<<4<<' '<<5<<' '<<6<<' '<<endl;
    for(int i=0; i<m_rowLenght;i++)
    {
        cout<< i<<grid << m_field[i][0] << grid << m_field[i][1] << grid <<  m_field[i][2] << grid <<  m_field[i][3] << grid <<  m_field[i][4] <<grid <<  m_field[i][5] << grid <<  m_field[i][6] << grid <<endl;
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

void FourWinsSetup::enterColumn()
{
    int name = 0;
    if(m_playersTurn==0)
    {
        name = 1;
    }
    if(m_playersTurn==1)
    {
        name = 2;
    }


    cout <<"Player:" << name << " enter column please" << endl;
    cin >> m_playersColumn;
    if(isInputValid(m_playersColumn))
    {
        setGamePoints(m_playersColumn);

    }
    else
    {
        cout <<"ERROR enter row and column again...."<< endl;
        enterColumn();

    }
}

void FourWinsSetup::checkAllWinConditions()
{
    for(int i=0; i<m_columnLenght;i++)
    {
        checkColumnWin(i);
    }
    for(int i=0; i<m_rowLenght;i++)
    {
        checkRowWin(i);
    }
    checkLeftBottomToTopDiagWin();
    checkLeftTopToBottomDiagWin();
    checkVertical();
    checkHori();
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
int FourWinsSetup::getPlayersColumn() const
{
    return m_playersColumn;
}

