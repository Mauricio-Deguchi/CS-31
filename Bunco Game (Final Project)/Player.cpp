//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"



namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    
    // TODO: randomly roll the die and adjust the score for the current round accordingly
    //  increase the score if the amount matches this round's value
    int Player::roll( )
    {
        mDie.roll();                    // rolls the player's die
        int result = mDie.getValue();   // stores the value locally for the result of the roll
        if (result == mRound)           // compares the die roll to the current round
        {
            mScore++;                   // if they match, the player's round score will increase
        }
        // stubbed out for now...
        return(result);
    }

    // TODO: allow for cheating
    // use the amount argument as this Player's roll
    // adjust the score for the current round accordingly
    // increase the score if the amount matches this round's value
    int Player::roll( int amount )
    {
        if (amount == mRound)       // if the given die roll is the same as the round number,
        { 
            mScore++;               // we will increment the player's round score
        }
        // stubbed out for now...
        return(amount);
    }
    
    // TODO: set the current round and reset the player's score to 0
    void Player::setRound( int round )
    {
        mRound = round;         // this will declare the round
        mScore = 0;             // this will reset the player's round score
        // stubbed out for now...
    }
    
    // TODO: return the score member variable
    int  Player::getScore( ) const
    {
        // stubbed out for now...
        return( mScore );       // getter for the score of the current round
    }
    
    
}
