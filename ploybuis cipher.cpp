//FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: ploybuis square cipher.cpp
// Program Description: This program converts letter of english into numbers and the opposite
// Last Modification Date: 22/3/2022
//AUther : Dalia Ibrahim sayed Ali  , 20210586  , group A  ,s26
#include <iostream>
#include <string>
#include <list>
#include <tuple>
using namespace std;
tuple<int, int> input(char word, char table[5][5])
{
    if (word == 'J')//check if letter  equal "j" convert to "i".
    {
        word = 'I';
    }
    if (islower(word)) //check if input equal small convert to capital.
    {
        word = toupper(word);
    }
    for (int i = 0; i < 5; i++) {//looping in each coloum in 2 dimention array.
        for (int j = 0; j < 5; j++) {//looping in each row in 2 dimention array.
            if (table[i][j] == word) {//check number of indexes of letter in 2 dimention array
                return { i , j };//return number of indexes.
            }
        }
    }
}
int index(char lst[5], char index) {//knowing number of indexes in list of number.
    for (int i = 0; i < 5; i++) {
        if (lst[i] == index) {
            return i;
        }
    }
}
int main()
{//decleration and initialization for  variables and 2 dimention array.
    string sentence, nsen, cstr;
    char lst1[5];
    char word;
    int choice;
    int x, y;
    char table[5][5];
    string nstr;
    table[0][0] = 'A';
    table[0][1] = 'B';
    table[0][2] = 'C';
    table[0][3] = 'D';
    table[0][4] = 'E';
    table[1][0] = 'F';
    table[1][1] = 'G';
    table[1][2] = 'H';
    table[1][3] = 'I';
    table[1][4] = 'K';
    table[2][0] = 'L';
    table[2][1] = 'M';
    table[2][2] = 'N';
    table[2][3] = 'O';
    table[2][4] = 'P';
    table[3][0] = 'Q';
    table[3][1] = 'R';
    table[3][2] = 'S';
    table[3][3] = 'T';
    table[3][4] = 'U';
    table[4][0] = 'V';
    table[4][1] = 'W';
    table[4][2] = 'X';
    table[4][3] = 'Y';
    table[4][4] = 'Z';
    cout << "please enter the list of number :  ";// Ask user to input numbers.
    for (int i = 0; i < 5; i++) {// looping in each item in list.
        cin >> lst1[i];
    }
    cout << "please enter you want to do :\n";//Ask user to choose coding or decoding.
    cout << "1- is cipher\n ";
    cout << "2- is decipher\n ";
    cout << "please enter your choice:";
    cin >> choice;

    if (choice == 1)//check of choice cippher or decipher.
    {
        cout << "please enter the sentence (plaintext) : ";
        cin.clear();
        cin.ignore();
        getline(cin, sentence);//get sentence with getline.
        cout << sentence;
        for (int i = 0; i < sentence.length(); i++)//looping in each letter in sentence.
        {
            if (sentence[i] != ' ')//check if each letter in sentence  not equal space.
            {
                tie(x, y) = input(sentence[i], table);
                nstr += lst1[x];
                nstr += lst1[y];
                nstr += " ";
            }
        }
        cout << "encrypt text is :" << nstr << "\n";//print encryption text.
    }
    else if(choice==2) {// if choice equal decipher.
        cout << "please enter the encrypt text : ";
        cin.clear();
        cin.ignore();
        getline(cin, nstr);//get encrypted text with getline

        for (int i = 0; i < nstr.length(); i++)//looping for each item in encrypted text.
        {
            if (nstr[i] == ' ') {// check if item in encrypted text equal space.
                if (nsen.length() == 2) {
                    x = index(lst1, nsen[0]);
                    y = index(lst1, nsen[1]);
                    cstr += table[x][y];
                    nsen = "";
                }
            }
            else {
                nsen += nstr[i];
            }
        }
        x = index(lst1, nsen[0]);
        y = index(lst1, nsen[1]);
        cstr += table[x][y];
        cout << "Decrypt text is : " << cstr;
    }
}