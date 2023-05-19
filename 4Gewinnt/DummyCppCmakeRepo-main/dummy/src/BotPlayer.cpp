#include "dummy/BotPlayer.hpp"

int BotPlayer::getBotsColumn() const
{
    return m_setBotsColumn;
}

void BotPlayer::setPoints()
{
    m_setBotsColumn++;

    if(m_setBotsColumn >= 6)
    {
        m_setBotsColumn = 0;
    }
}

