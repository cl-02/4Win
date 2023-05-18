//
// Created by Clemens Hanselmann on 18.05.23.
//

#ifndef DUMMY_BOTPLAYER_HPP
#define DUMMY_BOTPLAYER_HPP

class BotPlayer
{
public:
    BotPlayer()=default;
    void copyField(); /*todo: set do bot check, if field is empty */
    void setPoints();
    bool isColumnWinNear(int column);

    int getBotsRow() const;
    int getBotsColumn() const;

private:
    int m_setBotsColumn{0};
    int m_setBotsRow{0};
    int m_fieldCopy[6][7];
};
#endif // DUMMY_BOTPLAYER_HPP
