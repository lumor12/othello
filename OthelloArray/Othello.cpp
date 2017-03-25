#include <iostream>
#include "Othello.h"
using namespace std;

Othello::Othello()
{
    cout << "\n---------Othello Game---------" << endl << endl;
	cout << "Instructions : \n\n"
		<< "1 - If you want to quit the game type 'quit' and then press enter.\n\n"
		<< "2 - To place your piece, enter the column character followed by the row number   (For Example = a5)\n\n*Note* column character is not case sensitive\n\n"
		<< "3 - visit the game rules and intro at :\n'http://www.site-constructor.com/othello/othellorules.html' \n\n"
		<< endl ;
    cout << "Would you like a play a game?\n" << endl;
}

void Othello::searchChar(char othello[][8], char var){
    int i = 0;
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            i++;
            if(othello[row][column]== var){
                cout << "first " << var <<" at " << i-1 << endl;
            }
        }
        cout << endl;
    }
}

void Othello::printArray(char othello[][8]){
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            cout << othello[row][column] << " ";
        }
        cout << endl;
    }

}

void Othello::buildArray(char othello[][8]){
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            if((row == 3 && column == 3) || (row==4 && column==4)){
                othello[row][column] = 'X';
            }
            else if((row == 3 && column == 4) || (row==4 && column == 3)){
                othello[row][column] = 'O';
            }
            else{
                othello[row][column] = '|';
            }
        //cout << endl;
        }
     }

    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            cout << othello[row][column] << " ";
        }
        cout << endl;
    }
}

Othello::~Othello()
{
    //dtor
}
