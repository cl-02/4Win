//
// Created by Clemens Hanselmann on 18.05.23.
//

#ifndef DUMMY_BOTPLAYER_HPP
#define DUMMY_BOTPLAYER_HPP

class BotPlayer
{
public:
    BotPlayer()=default;
    void setPoints();

    int getBotsColumn() const;

private:
    int m_setBotsColumn{0};

};
#endif // DUMMY_BOTPLAYER_HPP
