#include <iostream>
#include "Othello.h"
#include "Othello2.h"
#include <queue>
using namespace std;

char get_player();
int get_order(char cplayer);
void testing();
void test2();

int main()
{
   char player;
    int order;
    char othello[8][8];

    //player = get_player();

    //char opponent = (player == 'O')? 'X' : 'O';

    //cout << "Opponet = " << opponent << " player = " << player << endl;

   	cout << "\nthis is the test of Othello2" << endl;
	test2();
	//system("PAUSE");
    return 0;
}

void test2() {

	char player1 = 'X';
	char player2 = 'O';

	//create a new game
	Othello2 game = Othello2();

	//display game board
	game.printGameBoard();
    while(1){
    //for(int maini = 0; maini < 20 ; maini ++){
	//find the position of each players pieces on the board and print them
        //int score[3];
        //game.printXPieces();
        //game.findPieces(player2);
        //game.printOPieces();

        //set the current player to X and get the available moves and print them
        game.setCurrentPlayer(player1);
        //game.findPieces(player1);
        game.findPieces();
        game.availableMoves();
        if(game.printXMoves()){
           game.makeMove(); // why is this not working
        }else { cout << "no moves available, moving on " << endl;}
        if(!game.findPieces2()){break;}

        //set the current player to O and get the available moves and print them
        //game.findPieces(player2);
        game.setCurrentPlayer(player2);
        game.findPieces();
        game.availableMoves();
        //game.printOMoves();
        //game.printGameBoard();
        if(game.printXMoves()){
           //game.xMove();
            game.makeMove();
        }else { cout << "no moves available, moving on " << endl;}
        if(!game.findPieces2()){break;}

    }
    cout << "stop here " << endl;
}

int get_order(char cplayer){
    int cint;
    while(true){
        cout << "OK player " << cplayer << ", enter 1 or 2 for order. " << endl;
        cin >> cint;
        if(cint == 1 || cint == 2){
            if(cint == 1){
                cout << "Player " << cplayer << " you are first!" << endl;
            }else{
                cout << "Player " << cplayer << " you will go second!" << endl;
            }
            return cint;
            break;
        }else{
            cout << "That was not a valid respond, please try again" << endl;
        }
    }
}

char get_player(){
    char c;
    while(true){
        cout << "\nWhich would you like to be X or O?\n" << endl;
        cin >> c;
        if(toupper(c)== 88){
            c = 'X';
            return c;
            break;
        }else if(toupper(c)== 79){
            c = 'O';
            return c;
            break;
        }else {
            cout << " you entered an invalid response, try again " << endl;
        }
    }
}


void testing(){
    int test[2];
    //queue<int, int> testqueue;
    int i = 0;
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
           // test[row][column] = i++;
        }
        //cout << endl;
    }


    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            //cout << test[row][column] << " ";
        }
        cout << endl;
    }
   // return 0;
}

    /*for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            cout << othello[row][column] << " ";
        }
        cout << endl;
    }*/
    //o.printGameBoard(othello);
    //testing();
    //testing2(othello);

    //player = get_player();

    //order = get_order(player);
