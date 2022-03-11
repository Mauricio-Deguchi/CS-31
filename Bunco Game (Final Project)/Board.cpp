//
//  Board.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mRound( 0 )
    {
        // initialize each BoardRow
        for (int i = 1; i <= 6; i++)
        {
            mBoardRow[ i ].setRound( i );
        }
    }
    
    void Board::setCurrentRound( int round )
    {
        // unset the current board row
        if (mRound >= 0 && mRound <= 6)
            mBoardRow[ mRound ].setCurrentRound( false );
        mRound = round;
        // set the current board row
        if (mRound >=0 && mRound <=6)
            mBoardRow[ mRound ].setCurrentRound(true);
    }
    
    // TODO: set the human player to have won this current BoardRow
    void Board::markHumanAsWinner()
    {
        mBoardRow[mRound].setHumanAsWinner();   // public access method from the row class to set the winner for the row
        // stubbed out for now...
    }
    
    // TODO: set the computer player to have won this current BoardRow
    void Board::markComputerAsWinner()
    {
        mBoardRow[mRound].setComputerAsWinner();   // public access method from the row class to set the winner for the row
        // stubbed out for now...
    }
    
    // stringify the Board
    std::string Board::display( ) const
    {
        std::string s = "\t\t  Bunco Game\n\tHuman\t\t\tComputer\n";
        
        for( int i = 1; i <= 6; i++)
        {
            s += mBoardRow[ i ].display() + "\n";
        }
        
        return( s );
    }
    
    // TODO: how many rounds has the human player won?
    int Board::countUpHumanRoundWins( ) const
    {
        int counter = 0;                // starts a counter for the number of human player wins
        for (int i = 1; i <= 6; i++)    // we will need to loop through each of the rows
        {
            if (mBoardRow[i].didHumanWin())     // if the human wins any given row, 
            {
                counter++;                      // we will increment the counter by 1
            }
        }
        // stubbed out for now...
        return( counter );                      // and we will return the final win counter to the user
    }
    
    // TODO: how many rounds has the computer player won?
    int Board::countUpComputerRoundWins( ) const
    {
        int counter = 0;                // starts a counter for the number of computer player wins
        for (int i = 1; i <= 6; i++)    // we will need to loop through each of the rows
        {
            if (mBoardRow[i].didComputerWin())     // if the computer wins any given row, 
            {
                counter++;                      // we will increment the counter by 1
            }
        }
        // stubbed out for now...
        return(counter);                      // and we will return the final win counter to the user
    }

    
}