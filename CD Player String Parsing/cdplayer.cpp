#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// declaring our functions
bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);


// Starting our main
int main()
{
	// main copied from project instructions
	string s;
	cout.setf(ios::boolalpha); // prints bool values as "true" or "false"
	for (;;)
	{
		cout << "Enter a possible result string: ";
		getline(cin, s); if (s == "quit") break;
		cout << "isValidCDPlayerString returns ";
		cout << isValidCDPlayerString(s) << endl;
		cout << "isOpen(s) returns ";
		cout << isOpen(s) << endl;
		cout << "hasCD(s) returns ";
		cout << hasCD(s) << endl;
		cout << "totalTracksPlayed(s) returns ";
		cout << totalTracksPlayed(s) << endl;
		cout <<  "currentTrack(s) returns ";
		cout << currentTrack(s) << endl;
		cout << endl;
	}
	return(0);
}

bool isValidCDPlayerString(string cdstring) 
{
	// inititalizing flags which will be the main structure of the
	bool flag = true, isOpen = false, isCDin = false, isPlaying = false, NeedsStopped = false;
	int trackCounter = 0;		// this will keep count of which track the CD should be playing
	// length of string to determine how long we need to loop for
	size_t length = cdstring.size();

	// I ran into a bug when taking in an empty string so this ensure that we can adequately take in and read an empty string
	if (cdstring == "")
	{
		flag = false;
	}
	// we must ensure that our string starts by opening the CD player, if so we can proceed to interpret the string
	else if (cdstring.at(0) == 'O')
	{
		// here, we will loop through the string from start to end
		for (size_t position = 0; position < length; position++)
		{
			char c = cdstring.at(position);			// this will extract a single character which we are interested in analyzing for that step in the for loop
			switch (c)					// we will evaluate the character for various possible valid input cases.
			{							// each of these cases will be an if-else; for the if, we will check if the circumstances are valid to proceed with the given task, else our overall flag will be false and our string will be deemed invalid
			case 'O':					// O: we want to open the player
				if ((isOpen == false))	// to open the player, the player must be closed 
				{
					isOpen = true;
					isPlaying = false;
				}
				else
				{
					flag = false;
				}
				break;
			case 'I':					// I: we want to insert a disk
				if ((isOpen == true) && (isCDin == false))		// to insert a disk, the player must be open and there must not already be a disk
				{
					isCDin = true;
					trackCounter = 1;	// each time we insert the CD, we start the CD over from track 1
				}	
				else
				{
					flag = false;
				}
				break;
			case 'R':					// R: we want to remove the disk
				if ((isOpen == true) && (isCDin == true))		// to remove the disk, the player must be open and there must be a disk inside
				{
					isCDin = false;
				}
				else
				{
					flag = false;
				}
				break;
			case 'C':					// C: we want to close the player	
				if (isOpen == true)		// to close the player, the player must be open
				{
					isOpen = false;
				}
				else
				{
					flag = false;
				}
				break;
			case 'P':					// P: we want to press play
				if ((isOpen == false) && (isCDin == true))		// to play the player, it must be close and there must be a CD inside
				{
					isPlaying = true;
					NeedsStopped = true;
				}
				else
				{
					flag = false;
				}
				break;	
			case 'S':					// S: we want to stop the player
				if (isPlaying == true)		// to stop the player, it must have been playing
				{
					isPlaying = false;
					NeedsStopped = false;
				}
				else if (NeedsStopped == true)
				{
					isPlaying = false;
					NeedsStopped = false;
				}
				else
				{
					flag = false;
				}
				break;
			case '1':					// we want to play track 1
				if ((trackCounter == 1) && (isPlaying == true))	// if we have inserted a disk, we will be on the first track
				{
					trackCounter++;		// once we play track 1, we will move to the next track
				}
				else
				{
					flag = false;
				}
				break;
			case '2':					// we want to play track 2
				if ((trackCounter == 2) && (isPlaying == true))	// the counter must have increased to 2, before we can play track 2
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '3':					// we want to play track 3
				if ((trackCounter == 3) && (isPlaying == true))	// the counter must have increased to 3, before we can play track 3
				{						// the rest of these cases will follow the same format, except for 9 so no new comments will be detailed
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '4':					// we want to play track 4
				if ((trackCounter == 4) && (isPlaying == true))
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '5':					// we want to play track 5
				if ((trackCounter == 5) && (isPlaying == true))
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '6':					// we want to play track 6
				if ((trackCounter == 6) && (isPlaying == true))
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '7':					// we want to play track 7
				if ((trackCounter == 7) && (isPlaying == true))
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '8':					// we want to play track 8
				if ((trackCounter == 8) && (isPlaying == true))
				{
					trackCounter++;
				}
				else
				{
					flag = false;
				}
				break;
			case '9':					// we want to play track 9
				if ((trackCounter == 9) && (isPlaying == true))	// if we play track 9, we end our CD so the track resets automatically to track 1.
				{
					trackCounter ++;
				}
				else
				{
					flag = false;
				}
				break;
			default:
				flag = false;
			}
		}
	}
	else
	{									// if we did not start our string by opening the player, the string is invalid so our flag will be false				
	flag = false;
	}
	return(flag);						// at the end, we return our flag, if it passed all the if cases in our switch, the flag will remain true and be deemmed a valid string
}

// this function will check if at the end of the commands of a valid string, whether the player will be open
bool isOpen(string cdstring) 
{
	bool validCD = isValidCDPlayerString(cdstring);		// let's see if the string is valid
	bool isOpen = false;								// the player's initial state is close
	size_t length = cdstring.size();
	if (validCD == true)								// if our string is valid, let's see what state it ends with
	{	
		for (size_t position = 0; position < length; position++)
		{
			char c = cdstring.at(position);
			switch (c)									// here, we only care about two chars, the open and close commands
			{
			case 'O':									// we open the player	
				if (isOpen == false)
				{
					isOpen = true;
				}
				break;
			case 'C':									// we close the player
				if (isOpen == true)
				{
					isOpen = false;
				}
				break;
			default: break;
			}
		}
	}
	return(isOpen);										// at the end of our loop, the last O or C char which is read in will determine which state we are in
}

// this function follows a near identical format to the previous function, except now our varibale of interest is whether a CD is inserted at the end of a string or not
bool hasCD(string cdstring) 
{
	bool validCD = isValidCDPlayerString(cdstring);
	bool hasCD = false;
	size_t length = cdstring.size();
	if (validCD == true)
	{
		for (size_t position = 0; position < length; position++)
		{
			char c = cdstring.at(position);
			switch (c)
			{
			case 'I':
				if (hasCD == false)
				{
					hasCD = true;
				}
				break;
			case 'R':
				if (hasCD == true)
				{
					hasCD = false;
				}
				break;
			default: break;
			}
		}
	}
	return(hasCD);
}

// here, we want to count the total number of tracks played by a string
int totalTracksPlayed(string cdstring) 
{
	bool validCD = isValidCDPlayerString(cdstring);		// let's check if the string is valid
	size_t length = cdstring.size();				
	int trackCounter = 0;								// starts a counter 
	if (validCD == true)								// if our string is valid, let's start looping
	{
		for (size_t position = 0; position < length; position++)
		{
			char c = cdstring.at(position);
			switch (c)
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				trackCounter++; break;					// for any of the numerical cases, we will play a track so we want to add 1 to our counter each time we enounter these
			default: break;
			}
		}
	}
	else
	{													// if our string is not valid, we want to return -1 as our number of tracks to signal an error
		trackCounter = -1;
	}
	return(trackCounter);
}

// here, we want to see what the next track to play would be
int currentTrack(string cdstring) 
{
	bool validCD = isValidCDPlayerString(cdstring);		// let's check if the string is valid
	size_t length = cdstring.size();
	int track = -1;										// this value will be reassigned depending on which case we last leave off on
	if (validCD == true)
	{
		for (size_t position = 0; position < length; position++)	// we will loop through the entire string reassigning the value, the last value we assign is what we left off on
		{
			char c = cdstring.at(position);
			switch (c)
			{
			case 'I': track = 1; break;					// if our last action is inserting, our next track will be 1
			case 'R': track = -1; break;				// if we remove the CD, we do not have a next track so -1 will be our stand in value
			case '1': track = 2; break;					// if we played the first track, our next track will be track 2
			case '2': track = 3; break;					// ...
			case '3': track = 4; break;					// ...
			case '4': track = 5; break;					// ...
			case '5': track = 6; break;					// ...
			case '6': track = 7; break;					// ...
			case '7': track = 8; break;					// ...
			case '8': track = 9; break;					// ...
			case '9': track = 10; break;					// if we play the last track, our next track will be 1
			default: break;
			}
		}
	}
	return(track);										// we return the final value of our track after all the reassignments
}