//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include <iostream>

namespace cs31
{
    Bunco::Bunco() : mRound( 1 )
    {
        setRound( mRound );
    }
    
    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::nextRound( )
    {
        // prevent walking off the edge of the Board...
       if (mRound <= 5)
       {
          mRound = mRound + 1;
          setRound( mRound );
       }
    }


    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }
    
    // TODO: let the human player randomly play
    // randomly roll the human player's die and return what was rolled
    int Bunco::humanPlay( )
    {
        // stubbed out for now...
        int amountrolled = 0;           // initializes a variable to store the value fo the dice roll
        amountrolled = mHuman.roll();   // saves the dice roll
        return( amountrolled );         // returns the result of the dice roll to the user
    }

    // TODO: let the human player cheat
    // force a specific roll amount for the human plyaer
    int Bunco::humanPlay( const Die & d )
    {
        // stubbed out for now...
        int amountrolled = 0;           // initializes a variable to store the value fo the dice roll
        amountrolled = d.getValue();    // saves the dice roll
        mHuman.roll(amountrolled);      // forces a dice roll with the value given to update the player's score
        return( amountrolled );
    }
    
    // TODO: let the computer player play
    // randomly roll the computer player's die and return what was rolled
    int Bunco::computerPlay( )
    {
        // stubbed out for now...
        int amountrolled = 0;               // initializes a variable to store the value fo the dice roll
        amountrolled = mComputer.roll();    // simulates and saves the dice roll
        return( amountrolled );    
    }
    
    // TODO: let the computer player cheat
    // force a specific roll amount for the computer player
    int Bunco::computerPlay( const Die & d )
    {
        // stubbed out for now...
        int amountrolled = 0;
        amountrolled = d.getValue();        // saves the dice roll
        mComputer.roll(amountrolled);       // forces a dice roll with the value given to update the player's score
        return( amountrolled );             
    }

    // TODO: update the Board now that a turn of play has ended
    // if appropriate, mark the Human or Computer player as the winner on the board
    void Bunco::endTurn()
    {
        if (mHuman.getScore() > mComputer.getScore())       // if at the end of a turn, the player has a higher score
        {
            mBoard.markHumanAsWinner();                     // the player has won that round
        }
        else if (mComputer.getScore() > mHuman.getScore())  // if the computer has a higher score    
        {
            mBoard.markComputerAsWinner();                  // the computer has won the round
        }
        // stubbed out for now...
    }

    // TODO: considering each player's score,
    //       determine the winner of this round of play
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome( ) 
    {
        // stubbed out for now...
        ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
        if (mHuman.getScore() > mComputer.getScore())       // if the player has a higher score than the computer
        {
            result = ROUNDOUTCOME::HUMANWON;                // the human won that specific round
        }
        else if (mComputer.getScore() > mHuman.getScore())  // if the computer has a higher score than the player
        {
            result = ROUNDOUTCOME::COMPUTERWON;             // the computer has won that specific round
        }
        return( result );
    }
    
    // TODO: count up the number of won rounds by each player
    //       to determine the game's outcome
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        // stubbed out for now...
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        int compWins = mBoard.countUpComputerRoundWins(), humWins = mBoard.countUpHumanRoundWins();     //obtains the number of rounds won by the computer and human respectively
        if (compWins + humWins == 6)                        // if there have been a total of 6 rounds played
        {
            if (compWins > humWins)                         // then, if the computer won more round
            {
                result = GAMEOUTCOME::COMPUTERWONGAME;      // the computer won the game
            }
            else if (humWins > compWins)                    // or, if the human won more rounds
            {
                result = GAMEOUTCOME::HUMANWONGAME;         // the human won the game
            }
            else if (humWins == compWins)                   // or, if they won the same number of rounds
            {
                result = GAMEOUTCOME::TIEDGAME;             // the game ends in a tie
            }
        }
        return( result );
    }
    
    // is the game over?
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

    Player Bunco::getHuman() const
    {
        return( mHuman );
    }

    Player Bunco::getComputer() const
    {
        return( mComputer );
    }

    Board  Bunco::getBoard() const
    {
        return( mBoard );
    }

}
