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


        board.setGamePoints(0);
        board.setGamePoints(0);
        board.setGamePoints(1);
        board.setGamePoints(1);
        board.setGamePoints(2);
        board.setGamePoints(2);
        board.setGamePoints(3);
        board.setGamePoints(2);


    // THEN
    board.checkRowWin(5);
    EXPECT_EQ(true, board.isPlayerOWin());
}
TEST(TestingTestClass, TestColumnWin)
{
    // WHEN
    FourWinsSetup board;
    board.initField();

    board.setGamePoints(1);
    board.setGamePoints(0);

    board.setGamePoints(1);
    board.setGamePoints(2);

    board.setGamePoints(1);
    board.setGamePoints(0);

    board.setGamePoints(1);
    board.setGamePoints(0);

    // THEN
    board.checkColumnWin(1);
    EXPECT_EQ(true,board.isPlayerOWin());
}

TEST(TestingTestClass, TestLeftDiagWin)
{
    // WHEN
    FourWinsSetup board;
    board.initField();
    board.setGamePoints(0);
    board.setGamePoints(1);

    board.setGamePoints(1);
    board.setGamePoints(2);

    board.setGamePoints(2);
    board.setGamePoints(3);

    board.setGamePoints(2);
    board.setGamePoints(3);

    board.setGamePoints(1);
    board.setGamePoints(3);

    board.setGamePoints(3);
    board.setGamePoints(3);

    // THEN
    board.checkLeftBottomToTopDiagWin();
    EXPECT_EQ(true,board.isPlayerOWin());
}

TEST(TestingTestClass, TestRightDiagWin)
{
    // WHEN
    FourWinsSetup board;
    board.initField();

    board.setGamePoints(4);
    board.setGamePoints(3);
    board.setGamePoints(2);
    board.setGamePoints(1);

    // THEN
    board.checkLeftTopToBottomDiagWin();
    EXPECT_EQ(true,board.isPlayerOWin());
}

TEST(TestingTestClass, TestIsPlaceEmpty)
{
    // WHEN
    FourWinsSetup board;
    board.initField();
    board.setGamePoints(4);

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

   board.setGamePoints(2);
    EXPECT_EQ(false,   board.isInputValid(2));
}