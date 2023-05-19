//
// Created by Clemens Hanselmann on 17.05.23.
//
#include <gtest/gtest.h>
#include <sstream> // for testing of function print()
#include "dummy/FourWinsSetup.hpp"
TEST(TestingTestClass, TestBoardInit)
{
    // WHEN
    FourWinsSetup board;
    board.initField();

    // THEN
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            EXPECT_EQ('-', board.getFieldAtPosition(i,j));
        }
    }
}
TEST(TestingTestClass, TestRowWin)
{
    // WHEN
    FourWinsSetup board;
    board.initField();

    board.setGameCoins(0);
        board.setGameCoins(0);
        board.setGameCoins(1);
        board.setGameCoins(1);
        board.setGameCoins(2);
        board.setGameCoins(2);
        board.setGameCoins(3);
        board.setGameCoins(2);


    // THEN
    board.checkRowWin(5);
    EXPECT_EQ(true, board.isPlayerOWin());
}

TEST(TestingTestClass, TestLeftDiagWin)
{
    // WHEN
    FourWinsSetup board;
    board.initField();
    board.setGameCoins(0);
    board.setGameCoins(1);

    board.setGameCoins(1);
    board.setGameCoins(2);

    board.setGameCoins(2);
    board.setGameCoins(3);

    board.setGameCoins(2);
    board.setGameCoins(3);

    board.setGameCoins(1);
    board.setGameCoins(3);

    board.setGameCoins(3);
    board.setGameCoins(3);

    // THEN
    board.checkLeftBottomToTopDiagWin();
    EXPECT_EQ(true,board.isPlayerOWin());
}

TEST(TestingTestClass, TestRightDiagWinLeftTopToBottom)
{
    // WHEN
    FourWinsSetup board;
    board.initField();

    board.setGameCoins(4);
    board.setGameCoins(3);
    board.setGameCoins(2);
    board.setGameCoins(1);

    // THEN
    board.checkLeftTopToBottomDiagWin();
    EXPECT_EQ(true,board.isPlayerOWin());
}

TEST(TestingTestClass, TestIsPlaceEmpty)
{
    // WHEN
    FourWinsSetup board;
    board.initField();
    board.setGameCoins(4);

    // THEN
    EXPECT_EQ(false,   board.isPlaceEmpty(4));
    EXPECT_EQ(true,   board.isPlaceEmpty(4));
}

TEST(TestingTestClass, TestIsInputValid)
{
    // WHEN
    FourWinsSetup board;
    board.initField();
    // THEN
    EXPECT_EQ(true,   board.isInputValid(4));

    board.setGameCoins(2);
    EXPECT_EQ(false,   board.isInputValid(2));
}