/* Project 4 functions */
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Project 4 function implementations go here...
int locateMinimum(const string array[], int n);

int countCommonElements(const string array1[], int n1, const string array2[], int n2);

int countVowels(const string array[], int n);

bool hasThreeOfX(const string array[], int n, string x);

string majorityElement(const string array[], int n);

bool shiftRight(string array[], int n, int amount, string placeholder);

bool rotateLeft(string array[], int n, int amount);

int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

void print(const string array[], int n);







int main()
{
    string a[6] = { "136", "135", "135", "gamma", "bEta", "delta" };
    string b[4] = { "" , "", "", "uU iI"};
    string c[11] = { "samwell", "jon", "margaery", "daenerys", "daenerys", "jon", "jon", "jon", "jOn", "jon", "jon"};
    string d[4] = { "aa", "bb", "bb", "cc" };
    string e[4] = { "bb", "bb", "dd", "ee" };
    string f[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    string g[7] = { "AA", "BB", "BB", "BB", "cc", "dd", "ee" };
    string h[4] = { " ", "  ", "hello", "h i" };
    string folks[8] = { "samwell", "jon", "mArgaEry", "daenerys", "tYriOn", "sansa", "magdalena", "jon" };
    string data[5] = { "mama", "mama", "12,", "sansa", "mama" };

    // locating minimum tests
    assert(locateMinimum(a, 6) == 1);
    assert(locateMinimum(b, 4) == 0);
    assert(locateMinimum(c, 6) == 3);
    assert(locateMinimum(c, 0) == -1);
    assert(locateMinimum(data, 5) == 2);

    // common element tests
    assert(countCommonElements(folks, 8, data, 5) == 1);
    assert(countCommonElements(folks, 3, data, 3) == 0);
    assert(countCommonElements(folks, 8, c, 8) == 11);
    assert(countCommonElements(d, 4, e, 4) == 4);
    assert(countCommonElements(d, 0, e, 1) == -1);
    assert(countCommonElements(d, 4, e, 0) == -1);
    assert(countCommonElements(d, -1, e, 0) == -1);
    assert(countCommonElements(f, 7, g, 7) == 7);

    // counting vowels test
    assert(countVowels(data, 5) == 8);
    assert(countVowels(folks, 8) == 21);
    assert(countVowels(folks, 4) == 11);
    assert(countVowels(a, 3) == 0);
    assert(countVowels(b, 4) == 4);
    assert(countVowels(a, 6) == 6);
    assert(countVowels(a, 0) == -1);

    // has three of given element test
    assert(hasThreeOfX(c, 8, "jon") == false);
    assert(hasThreeOfX(c, 7, "jon") == true);
    assert(hasThreeOfX(folks, 8, "jon") == false);
    assert(hasThreeOfX(b, 3, "") == true);
    assert(hasThreeOfX(a, 6, "a") == false);
    assert(hasThreeOfX(b, 0, "") == false);

    // majority element test
    assert(majorityElement(a, 6) == "");
    assert(majorityElement(b, 4) == "");
    assert(majorityElement(c, 8) == "");
    assert(majorityElement(c, 9) == "");
    assert(majorityElement(c, 11) == "jon");
    assert(majorityElement(data, 5) == "mama");
    assert(majorityElement(folks, 8) == "");
    assert(majorityElement(folks, 0) == "");
    assert(majorityElement(folks, -5) == "");

    //shift right test
    assert(shiftRight(data, -5, 10, "foobar") == false);
    assert(shiftRight(data, 5, -5, "foobar") == false);
    assert(shiftRight(data, 5, 0, "foobar") == false);
    assert(shiftRight(data, 0, 0, "foobar") == false);
    assert(shiftRight(data, 0, 5, "foobar") == false);
    assert(shiftRight(data, 5, 2, "foo") == true);
    assert(data[0] == "foo"); data[0] = "mama";
    assert(data[1] == "foo"); data[1] = "mama";

    assert(shiftRight(data, 5, 10, "bar") == true);
    assert(data[0] == "bar"); data[0] = "mama";
    assert(data[1] == "bar"); data[1] = "mama";
    assert(data[2] == "bar"); data[2] = "12,";
    assert(data[3] == "bar"); data[3] = "sansa";
    assert(data[4] == "bar"); data[4] = "mama";

    assert(shiftRight(b, 4, 1, "") == true);
    assert(b[3] == ""); b[3] = "uU iI";

    assert(shiftRight(d, 2, 2, "hi") == true);
    assert(d[0] == "hi"); d[0] = "aa";
    assert(d[1] == "hi"); d[1] = "bb";

    

    // rotate left tests
    assert(rotateLeft(d, 2, 3) == true);
    assert(d[0] == "bb");   d[0] = "aa";
    assert(d[1] == "aa");   d[1] = "bb";
    assert(d[2] == "bb");
    assert(d[3] == "cc");

    assert(rotateLeft(c, 3, 3) == false);
    assert(rotateLeft(c, 3, 0) == false);
    assert(rotateLeft(b, -1, 0) == false);

    assert(rotateLeft(b, 4, 3) == true);
    assert(b[0] == "uU iI"); b[0] = "";
    assert(b[1] == "");
    assert(b[2] == "");
    assert(b[3] == "");     b[3] = "uU iI";


    // replace all tests
    assert(replaceAll(b, 0, ' ', 'a') == -1);
    assert(replaceAll(b, -5, ' ', 'a') == -1);

    cout << "Printing folks: " << endl;
    print(folks, 8);
    assert(replaceAll(folks, 8, 'a', 'Z') == 8);
    print(folks, 8);
    cout << endl;

    cout << "printing b: " << endl;
    print(b, 4);
    assert(replaceAll(b,4, ' ', 'a') == 1);
    print(b, 4);
    cout << endl;

    cout << "printing h: " << endl;
    print(h, 4);
    assert(replaceAll(h, 4, ' ', 'a') == 4);
    print(h, 4);
    cout << endl;

    cerr << "All tests succeeded" << endl;
    return (0);
}




void print(const string array_inspec[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array_inspec[i]<< " ";
    }
    cout << endl;
}

int locateMinimum(const string array[], int n)
{
    string minValue = "0";      // let's initiate a minimum value string which will store our smallet string according to the ascii table
    int minIdx = -1;             // let's initialize an integer to store the location of our minium value
    if(n>0)                     // if we are given a valid length or an array, we will start taking it apart
    {
        for (int i = 0; i < n; i++)     // we will loop through all of the postions of the array
        {
            string analyze = array[i];      // let's extract one elements from the array one at a time
            if (i == 0)                     // if this is the first element of the array, let's set this as our mind value and min index
            {
                minValue = analyze;
                minIdx = i;
            }
            else if (minValue > analyze)    // for any other spot in the array, we will only reassign our min value and index if the value is smaller than our stored minimum
            {
                minValue = analyze;
                minIdx = i;
            }
        }
    }
    return minIdx;
}

int countCommonElements(const string array1[], int n1, const string array2[], int n2)
{
    int common = 0;                 // let's start a counter to count all of the common elements
    if ((n1 <= 0) || (n2 <= 0))     // if an invalid size is given for either array,
    {
        common = -1;                // our error value will be -1
    }
    else
    {
        for (int i = 0; i < n1; i++)    // let's start looping through the first array
        {
            string string1 = array1[i];     // let's extract one element from the first array at a time
            for (int j = 0; j < n2; j++)    // now, for each element of the first array, let's loop through the second array and compare them
            {
                string string2 = array2[j];     // let's extract one element from the second array
                if (string1 == string2)         // if they are the same
                {
                    common++;                   // we have found a common value
                }
            }
        }
    }
    return common;
}

int countVowels(const string array[], int n)
{
    int vowels = 0;             // lets start a counter
    if (n <= 0)                 // if we are given an invalid array length, we will return -1 as our error
    {
        vowels = -1;
    }
    else
    {                                   // if not,
        for (int i = 0; i < n; i++)     // let's start analyzing our array
        {   
            string string1 = array[i];      // let's extract one element from the array at a time
            for (size_t pos = 0;pos < string1.length(); pos++ )         // let's loop through all the characters in the array one at a time
            {
                char character = string1.at(pos);                       // we will start by extracting only 1 char
                switch(character)                                       // if that char is a vowel (caps or lower case)
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    vowels++; break;                                    // we will add it to our counter
                default: break;                                         // if not, move on to the next character
                }
            }
        }
    }
    return vowels;
}

bool hasThreeOfX(const string array[], int n, string x)
{
    bool flag = false;          // let's initialize a flag which we will return to the user
    int counter = 0;            // let's also initialize a counter
    if (n > 0)                  // if we are given a valid size of an array
    {
        for (int i = 0; i < n; i++)     // let's start analyzing our array elements
        {   
            string string1 = array[i];  // let's pull out one string at a time
            if (string1 == x)           // if our string is the same as the one we are searching for
            {
                counter++;              // let's add one to our counter
            }
        }
    }
    if (counter == 3)           // if after we search through the whole array our counter is exactly 3
    {
        flag = true;            // we will have had exactly 3 of the element we were searching for in the array
    }
    return flag;
}

string majorityElement(const string array[], int n)
{
    int counter = 0, idx = -1;      // let's initialize a counter and index variable
    string common = "";             // let's also initialize the stirng which we will return to the user, if there is not majority element, then the empty string will be sent to the user
    for (int i = 0; i < n; i++)     // let's loop through the array   (for greater efficiency, (int i = 0; i < (n/2+1); i++) could be used since after the half way mark, it's not possible to have a majority element
    {
        counter = 0;                // for each index in the array, we will compare it to every other index
        string element = array[i];  // let's extract that element
        for (int j = i; j < n; j++)     // we will now loop throug the remaining elements in the array
        {
            string nextElement = array[j];      // we will extarct all the remaining strings one at a time
            if (nextElement == element)
            {
                counter++;                      // if they match, let's update our counter
            }
        }
        if (counter > n / 2)                    // if the counter is more than half the size of the array, we have found a majority element
        {
            idx = i;
        }
    }
    if (idx != -1)          // if we hae found a majority element, the idx value would have been updated
    {
        common = array[idx];        // we will extract the string which contains the majority value
    }

    return common;
}

bool shiftRight(string array[], int n, int amount, string placeholder)
{
    bool isChanged = true;      // lets initialize our flag
    if ((n <= 0)||(amount<=0))  // if we are not given reasonable sizes or amounts, we will not alter the array
    {
        isChanged = false;
    }
    else        // let's begin inspecting the array
    {
        for (int i = 0; i < amount; i++)        // this outside function will repeat for however many times we must shift the array
        {                                       // the inside function will shift the array right by 1
            for (int j = n - 1; j >= 0; j--)    // starting from the rightmost element, we will shift everything up and loose the rightmost element
            {
                if (j == 0)                     // if we are at the first index, we will set the slot e
                {
                    array[j] = placeholder;
                }
                else                            // if not, set each upper element equal to the one below it
                {
                    array[j] = array[j - 1];
                }
            }
        }
    }
    return isChanged;
}

bool rotateLeft(string array[], int n, int amount)
{
    bool flag = false;                          // let's initialize a flag which we will return to the user
    if ((n > 0)&&(amount>0)&&(amount%n != 0))   // if we are fed an invalid size our amount, we will not alter the array
    {                                           // we will also not alter the array if we rotate the an integer multiple of the array
        flag = true;                            // if we make it here, we will be altering the array
        for (int i = 0; i < amount; i++)        // this will shift the array by the number of times
        {
            string first = array[0];            // we will extract one element from the array
            for (int j = 0; j < n; j++)         // let's loop from the starting index of the array (this will only shift by 1)     
            {
                if (j == n-1)                   // if we are at the last element of the array, let's set it to the first element
                {
                    array[j] = first;
                }
                else
                {                               // otherwise, lets set the current element to the element immediately to the right of it
                    array[j] = array[j + 1];
                }
            }
        }
    }
    return flag;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
    int counter = 0;        // let's initialize a counter to count the amount of changes we make
    if (n <= 0)             // if we are given an invalid size, our error will return -1 to the user
    {
        counter = -1;
    }
    else
    {
        for (int i = 0; i < n; i++)         // if not, let's start analyzing the elements of the array
        {
            string element = array[i];      // let's extract one array at a time
            for (size_t pos = 0; pos < element.length(); pos++)     // then, we will analyze each of the characters in that string
            {
                char c = element.at(pos);               // so let's extract one character at a time
                if (c == letterToReplace)               // if that character is the one we are searching for
                {
                    element.at(pos) = letterToFill;     // let's replace that character with the given character
                    counter++;                          // let's update our counter
                }
            }
            array[i] = element;                     // let's update the array element with the new string
        }
    }
    return counter;
}
