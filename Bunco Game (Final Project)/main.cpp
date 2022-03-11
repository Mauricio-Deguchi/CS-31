//
//  main.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include "Die.h"
#include "Player.h"
#include "Bunco.h"
#include <cassert>


void clearScreen( );



//int main()
//{
//    using namespace cs31;
//    using namespace std;
//    
//    clearScreen();
//    
//    Bunco game;
//    int human, computer;
//    std::string action, message = "(r)oll (q)uit: ";
//    cout << game.display( message ) << endl;
//
//    
//    do
//    {
//        getline( cin, action );
//        while (action.size() == 0)
//        {
//            getline( cin, action );  // no blank entries allowed....
//        }
//        switch (action[0])
//        {
//            default:   // if bad move, nobody moves
//                cout << '\a' << endl;  // beep
//                continue;
//            case 'Q':
//            case 'q':
//                return 0;
//            case 'r':
//            case 'R':
//                human = game.humanPlay();
//                computer = game.computerPlay();
//                cout << "human rolled:" << human;
//                cout << "\tcomputer rolled:" << computer << endl;
//                game.endTurn();
//                if (game.determineRoundOutcome() != Bunco::NOTDECIDED)
//                {
//                    game.nextRound();
//                    cout << game.display( message ) << endl;
//                }
//                if (game.gameIsOver())
//                {
//                    cout << game.display( ) << endl;
//                }
//                break;
//        }
//        
//    } while( !game.gameIsOver() );
//    
//    return( 0 );
//}

int main()
{
    using namespace std;
    using namespace cs31;
    std::string action, message = "(r)oll (q)uit: ";
    // test code
    Die d;
    for (int i = 1; i <= 100; i++)
    {
        d.roll();
        int value = d.getValue();
        assert(value >= 1 && value <= 6);
    }

    // player testing
    Player p;
    assert(p.getScore() == 0);
    p.setRound(1);
    assert(p.getScore() == 0);
    for (int i = 2; i <= 6; i++)
    {
        assert(p.roll(i) == i);
        assert(p.getScore() == 0);
    }
    
    assert(p.roll(1) == 1);
    assert(p.getScore() == 1);
    assert(p.roll(1) == 1);
    assert(p.getScore() == 2);
    assert(p.roll(1) == 1);
    assert(p.getScore() == 3);
    p.setRound(6);
    assert(p.getScore() == 0);
    assert(p.roll(6) == 6);
    assert(p.getScore() == 1);

    //board testing

    Board game;
    game.setCurrentRound(1);
    assert(game.countUpComputerRoundWins() == 0);
    assert(game.countUpHumanRoundWins() == 0);
    game.markComputerAsWinner();
    assert(game.countUpComputerRoundWins() == 1);
    assert(game.countUpHumanRoundWins() == 0);
    game.setCurrentRound(2);
    game.markHumanAsWinner();
    assert(game.countUpComputerRoundWins() == 1);
    assert(game.countUpHumanRoundWins() == 1);
    
    Bunco bunc;


    Die d1;
    d1.setValue(1);
    Die d2;
    d2.setValue(2);
    Die d3;
    d3.setValue(3);
    Die d4;
    d4.setValue(4);
    Die d5;
    d5.setValue(5);
    Die d6;
    d6.setValue(6);

    Bunco b;
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d5);
    b.humanPlay(d5);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d1);
    b.humanPlay(d1);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d1);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::COMPUTERWON);
    b.nextRound();

    b.computerPlay(d2);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d2);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d2);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::NOTDECIDED);
    b.computerPlay(d1);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::HUMANWON);
    b.nextRound();
    assert(b.determineGameOutcome() == Bunco::GAMENOTOVER);

    b.computerPlay(d3);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::COMPUTERWON);
    b.nextRound();
    b.computerPlay(d3);
    b.humanPlay(d4);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::HUMANWON);
    b.nextRound();
    b.computerPlay(d5);
    b.humanPlay(d2);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::COMPUTERWON);
    b.nextRound();
    b.computerPlay(d3);
    b.humanPlay(d6);
    b.endTurn();
    assert(b.determineRoundOutcome() == Bunco::HUMANWON);
    b.nextRound();
    assert(b.determineGameOutcome() == Bunco::TIEDGAME);


    cout << "all tests passed!" << endl;
    return 0;

}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

