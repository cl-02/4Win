//
// Created by Clemens Hanselmann on 17.05.23.
//

#ifndef DUMMY_PLAYER_HPP
#define DUMMY_PLAYER_HPP
class Player
{
public:
    void setGamePoints(int rowNumb, int columnNumb);
    void enterRowAndColumn();
    int getRow() const;
    int getColumn() const;

private:
    char m_name;
    int m_row{0};
    int m_column{0};
};

#endif // DUMMY_PLAYER_HPP
