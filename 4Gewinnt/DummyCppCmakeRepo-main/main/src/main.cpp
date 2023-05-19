#include <iostream>
#include "dummy/FourWinsSetup.hpp"
#include "dummy/BotPlayer.hpp"

int main()
{
    const int humanPlayer = 1;
    const int botPlayer = 2;
    int humanOrBot = 0;

    std::cout <<"Lets start Connect Four"<< std::endl;
    std::cout <<"Press "<<humanPlayer<<" to play against another player and " <<botPlayer<<" to play against bot" <<std::endl;
    std::cin >> humanOrBot;

    FourWinsSetup board;
    board.initField();

    if(humanOrBot == humanPlayer)
    {
        while ((!board.isPlayerOWin()) && (!board.isPlayerXWin()) && (!board.isBoardFull()))
        {
            board.printField();
            board.setPlayersColumn();
            board.isBoardFull();
            board.getWinner();
        }
    }

    else if(humanOrBot == botPlayer)
    {
        BotPlayer bot;

        while ((!board.isPlayerOWin()) && (!board.isPlayerXWin()) && (!board.isBoardFull()))
        {
            board.printField();
            if(board.getPlayersTurn() == 0)
            {
                board.setPlayersColumn();

            }
            else if(board.getPlayersTurn() == 1)
            {
                bot.setPoints();
                board.setGameCoins(bot.getBotsColumn());
            }
            board.isBoardFull();
            board.getWinner();
        }
    }

    board.printField();
    return 0;
}