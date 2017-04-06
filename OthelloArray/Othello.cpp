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
    cout << "Would you like to play a game?\n" << endl;
}

void Othello::searchChar(char othello[][8], int cords[][2], char var){
    int i = 0;  //tally position var was found. Will change to cordinates
    int j = 0; // tally # of vars found
    int movesAvail[8][2];
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            i++;
            if(othello[row][column]== var){
                //cout << "first " << var <<" at " << i-1 << " X and Y cordinates ("
                //<< row << ", " << column << ")" << endl;
                cords[j][0] = row;
                cords[j][1] = column;
                j++;
            }
        }
    }cout <<endl;
    //cout << "this is j " << j <<endl;
    for(int k = 0; k < j ; k++){
        cout << "Cordinate " << k+1 << " (" << cords[k][0] << ", " << cords[k][1]<< ") Available moves " ;
        int tempX = cords[k][0];
        int tempY = cords[k][1];
        int availMoves = 0;
        if(othello[tempX-1][tempY-1]=='O'){
            if(othello[tempX-2][tempY-2]=='|'){
                cout << "("<<tempX-2 << ", " << tempY-2 << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX-1][tempY]=='O'){
            if(othello[tempX-2][tempY]=='|'){
                cout << "("<<tempX-2 << ", " << tempY << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX-1][tempY+1]=='O'){
            if(othello[tempX-2][tempY+2]=='|'){
                cout << "("<<tempX-2 << ", " << tempY << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX][tempY-1]=='O'){
            if(othello[tempX][tempY-2]=='|'){
                cout << "("<<tempX << ", " << tempY-2 << ") " ;
            }availMoves++;
        }
        if(othello[tempX][tempY+1]=='O'){
            if(othello[tempX][tempY+2]=='|'){
                cout << "("<<tempX << ", " << tempY+2 << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX+1][tempY-1]=='O'){
            if(othello[tempX+2][tempY-2]=='|'){
                cout << "("<<tempX+2 << ", " << tempY-2 << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX+1][tempY]=='O'){
            if(othello[tempX+2][tempY]=='|'){
                cout << "("<<tempX+2 << ", " << tempY << ") " ;
            }
            availMoves++;
        }
        if(othello[tempX+1][tempY+1]=='O'){
            if(othello[tempX+2][tempY+2]=='|'){
                cout << "("<<tempX+2 << ", " << tempY+2 << " " ;
            }availMoves++;
        }
        if(availMoves == 0){
            cout << "No moves available " ;
        }
        cout <<endl;
    }
}

void Othello::printGameBoard(char othello[][8]){
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
