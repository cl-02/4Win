//
// Created by Clemens Hanselmann on 17.05.23.
//
#include <iostream>
using namespace std;
#include "dummy/Player.hpp"
#include "dummy/FourWinsSetup.hpp"


void Player::setGamePoints(int rowNumb, int columnNumb)
{

}

void Player::enterRowAndColumn()
{
    FourWinsSetup board;
    int row = 0;
    int column = 0;
    cout <<"Player" << m_name << "enter row please" << endl;
    cin >> row;
    cout <<"Player" << m_name << "enter column please" << endl;
    cin >> column;
    if(board.isInputValid(row,column))
    {
        m_row = row;
        m_column = column;

    }
    else
    {
        cout <<"ERROR enter row and column again...."<< endl;

    }

}
int Player::getRow() const
{
    return m_row;
}
int Player::getColumn() const
{
    return m_column;
}
