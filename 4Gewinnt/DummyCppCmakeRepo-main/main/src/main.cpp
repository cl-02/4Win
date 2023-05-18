#include <iostream>

#include "dummy/testClass.hpp"
#include "dummy/FourWinsSetup.hpp"
#include "dummy/BotPlayer.hpp"

int main()
{
    const int humanPlayer =1;
    const int botPlayer =2;
    int humanOrBot = 0;

    std::cout <<"Lets start Connect Four"<< std::endl;
    std::cout <<"Press "<<humanPlayer<<" to play against another player and " <<botPlayer<<" to play against bot" <<std::endl;
    std::cin >> humanOrBot;

    FourWinsSetup board;
    board.initField();

    BotPlayer bot;
    if(humanOrBot == humanPlayer)
    {
        while ((!board.isPlayerOWin()) && (!board.isPlayerXWin()) && (!board.isBoardFull()))
        {
            board.printField();
            board.enterRowAndColumn();
            board.isBoardFull();
            board.getWinner();
        }
        board.printField();

    }
    else if(humanOrBot == botPlayer)
    {
        while ((!board.isPlayerOWin()) && (!board.isPlayerXWin()) && (!board.isBoardFull()))
        {
            board.printField();
            if(board.getPlayersTurn() == 0)
            {
                board.enterRowAndColumn();
                bot.copyField(board.getPlayersRow(),board.getPlayersColumn());
            }
            else if(board.getPlayersTurn() == 1)
            {
                bot.setPoints();
                board.setGamePoints(bot.getBotsRow(),bot.getBotsColumn());

            }
            board.isBoardFull();
            board.getWinner();
        }
        board.printField();
    }



    return 0;
}