#include "dummy/BotPlayer.hpp"
//
// Created by Clemens Hanselmann on 18.05.23.
//
int BotPlayer::getBotsRow() const
{
    return m_setBotsRow;
}
int BotPlayer::getBotsColumn() const
{
    return m_setBotsColumn;
}

void BotPlayer::setPoints()
{
    if(m_fieldCopy[m_setBotsRow+1][m_setBotsColumn+1]==0)
    {
        m_setBotsRow++;
        m_setBotsColumn++;
    }
    if(m_fieldCopy[m_setBotsRow+1][m_setBotsColumn] == 0)
    {
        m_setBotsRow++;

    }
    if(m_fieldCopy[m_setBotsRow][m_setBotsColumn+1] == 0)
    {
        m_setBotsColumn++;

    }


    if(m_setBotsColumn>=6)
    {
        m_setBotsColumn=0;
    }
    if(m_setBotsRow>=5)
    {
        m_setBotsRow=0;
    }


}

