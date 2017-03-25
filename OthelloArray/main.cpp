#include <iostream>
#include "Othello.h"
using namespace std;

char get_player();
int get_order(char cplayer);
void testing();

int main()
{
   char player;
    int order;
    char othello[8][8];

    Othello o;

    //show_start_game(othello);
    cout << "\n for testing\n "  <<endl;
    o.buildArray(othello);
    cout << endl;

    // To search for the instance of character passed
    int cords[8][2];
    o.searchChar(othello, cords, 'X');
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

    return 0;
}

void testing(){
    int test[8][8];
    int i = 0;
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            test[row][column] = i++;
        }
        //cout << endl;
    }


    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            cout << test[row][column] << " ";
        }
        cout << endl;
    }
   // return 0;
}


int get_order(char cplayer){
    int cint;
    while(true){
        cout << "OK player " << cplayer << ", enter 1 or 2 for order. " << endl;
        cin >> cint;
        if(cint == 1 or cint == 2){
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
