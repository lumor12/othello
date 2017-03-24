#include <iostream>

using namespace std;

void show_start_game();
char get_player();
int get_order(char cplayer);
void testing();
void testing2();
void PrintInstructions();

int main()
{
    char player;
    int order;
    PrintInstructions();
    char othello2[8][8];
    show_start_game();
    cout << "\n for testing\n " << endl;
    testing();
    testing2();

    //player = get_player();

    //order = get_order(player);

    return 0;
}

void testing2(){
    char othello[8][8];
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
        }
     }
    int i = 0;
    for(int row=0; row < 8; row++){
        for(int column=0; column < 8; column++){
            i++;
            if(othello[row][column]=='X'){
                cout << "first X at " << i-1 << endl;
            }
        }
        cout << endl;
    }
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

void show_start_game(){
    char othello[8][8];
     cout << "Would you like a play a game?\n" << endl;

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
   // return 0;
}

void PrintInstructions()
{
	cout << "\n---------Othello Game---------" << endl << endl;
	cout << "Instructions : \n\n"
		<< "1 - If you want to quit the game type 'quit' and then press enter.\n\n"
		<< "2 - To place your piece, enter the column character followed by the row number   (For Example = a5)\n\n*Note* column character is not case sensitive\n\n"
		<< "3 - visit the game rules and intro at :\n'http://www.site-constructor.com/othello/othellorules.html' \n\n"
		<< endl ;
}
