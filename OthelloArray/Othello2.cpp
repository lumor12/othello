#include <iostream>
#include "Othello2.h"
using namespace std;

Othello2::Othello2() {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if ((row == 3 && column == 3) || (row == 4 && column == 4)) {
				board[row][column] = 'X';
			}
			else if ((row == 3 && column == 4) || (row == 4 && column == 3)) {
				board[row][column] = 'O';
			}
			else {
				board[row][column] = '|';
			}
		}
	}
}

void Othello2::setCurrentPlayer(char p) {
	currentPlayer = p;
}

void Othello2::getX_pieces(int cords[][2]) {
	for (int row = 0; row < XNumPieces; row++) {
		cords[row][0] = x_pieces[row][0];
		cords[row][1] = x_pieces[row][1];
	}
}

void Othello2::getO_pieces(int cords[][2]) {
	for (int row = 0; row < ONumPieces; row++) {
		cords[row][0] = o_pieces[row][0];
		cords[row][1] = o_pieces[row][1];
	}
}

char Othello2::getCurrentPlayer() {
	return currentPlayer;
}

int Othello2::getXNumMoves() {
	return X_moves;
}

int Othello2::getONumMoves() {
	return O_moves;
}

void Othello2::getMovesAvail(int cords[][2]) {
	if (currentPlayer == 'X') {
		for (int row = 0; row < X_moves; row++) {
			cords[row][0] = X_movesAvail[row][0];
			cords[row][1] = X_movesAvail[row][1];
		}
	}
	if (currentPlayer == 'O') {
		for (int row = 0; row < O_moves; row++) {
			cords[row][0] = O_movesAvail[row][0];
			cords[row][1] = O_movesAvail[row][1];
		}
	}
}
//gets the available moves for current player
void Othello2::availableMoves() {
	int deltaX = 0;
	int deltaY = 0;
	int tempX;
	int tempY;
	int i = 0;

	if (currentPlayer == 'X') {
		for (int row = 0; row < XNumPieces; row++) {
			for (deltaX = -1; deltaX < 2; deltaX++) {
				for (deltaY = -1; deltaY < 2; deltaY++) {
					if (deltaX != 0 || deltaY != 0) {
						tempX = x_pieces[row][0] + deltaX;
						tempY = x_pieces[row][1] + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O') {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O') {
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;
							}
							if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
								X_movesAvail[i][0] = tempX;
								X_movesAvail[i][1] = tempY;
								i++;
								X_moves++;
							}
						}
						if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == 'X')) {
							continue;
						}
					}
				}
			}
		}
		//X_moves = i;
	}
	if (currentPlayer == 'O') {
		for (int row = 0; row < ONumPieces; row++) {
			for (deltaX = -1; deltaX < 2; deltaX++) {
				for (deltaY = -1; deltaY < 2; deltaY++) {
					if (deltaX != 0 || deltaY != 0) {
						tempX = o_pieces[row][0] + deltaX;
						tempY = o_pieces[row][1] + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X') {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X') {
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;
							}
							if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
								O_movesAvail[i][0] = tempX;
								O_movesAvail[i][1] = tempY;
								i++;
								O_moves++;
							}
						}
						if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == 'O')) {
							continue;
						}
					}
				}
			}
		}
		//O_moves = i;
	}
}
//saves the position of the pieces for player p in an array to be access later by availableMoves()
void Othello2::findPieces(char p) {
	int i = 0;  //tally position var was found. Will change to cordinates
	int j = 0; // tally # of vars found
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			i++;
			if (board[row][column] == p) {
				//cout << "first " << var <<" at " << i-1 << " X and Y cordinates ("
				//<< row << ", " << column << ")" << endl;
				if (p == 'X') {
					x_pieces[j][0] = row;
					x_pieces[j][1] = column;
					j++;
					XNumPieces++;
				}
				else if (p == 'O') {
					o_pieces[j][0] = row;
					o_pieces[j][1] = column;
					j++;
					ONumPieces++;
				}
			}
		}
	}std::cout << endl;
}

void Othello2::printGameBoard() {
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			cout << board[row][column] << " ";
		}
		cout << endl;
	}
}

void Othello2::printXPieces() {
	cout << "\nThe pieces for X are in" << endl;
	for (int row = 0; row < XNumPieces; row++) {
		cout << "(" << x_pieces[row][0] << ", " << x_pieces[row][1] << ")" << endl;
	}
}

void Othello2::printOPieces() {
	cout << "The pieces for O are in" << endl;
	for (int row = 0; row < ONumPieces; row++) {
		cout << "(" << o_pieces[row][0] << ", " << o_pieces[row][1] << ")" << endl;
	}
}

void Othello2::flips(int frow, int fcol) {
	int deltaX = 0;
	int deltaY = 0;
	int tempX = 0;
	int tempY = 0;
	int i = 0;
    if (currentPlayer == 'X') {
            cout << "did anything happen X? " << currentPlayer <<endl;
			for (deltaX = -1; deltaX < 2; deltaX++) {
                cout << " first loop? " << currentPlayer <<endl;
                int testi = 0;
                int temparray[8][2];
				for (deltaY = -1; deltaY < 2; deltaY++) {
					if (deltaX != 0 || deltaY != 0) {
						tempX = frow + deltaX;
						tempY = fcol + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O') {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O' && board[tempX][tempY] != 'X') {
								cout << " x what is tempX and temp Y " << tempX << " , " << tempY << endl;
								temparray[testi][0] = tempX;
								temparray[testi][1] = tempY;
								testi++;
								if(board[tempX+deltaX][tempY+deltaY] == 'X'){
                                    cout << " O if tempX and temp Y " << tempX+deltaX << " , " << tempY+deltaY << endl;
                                    cout << " test is " << testi << endl;
                                    for(int j=0; j<testi;j++){
                                        board[temparray[j][0]][temparray[j][1]] = 'X';
                                        cout << " with j " << tempX+j << " , " << tempY+j << endl;
                                    }
								}
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;

							}
						}
						if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == 'X')) {
							continue;
						}
					}
				}
			}
		//X_moves = i;
	}
	if (currentPlayer == 'O') {
            cout << " O did anything happen X? " << currentPlayer <<endl;
			for (deltaX = -1; deltaX < 2; deltaX++) {
                   cout << " first loop? " << currentPlayer <<endl;
                   int testi = 0;
                   int temparray[8][2];
				for (deltaY = -1; deltaY < 2; deltaY++) {
					if (deltaX != 0 || deltaY != 0) {
						tempX = frow + deltaX;
						tempY = fcol + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X' ) {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X') {
								cout << " O what is tempX and temp Y " << tempX << " , " << tempY << endl;
								temparray[testi][0] = tempX;
								temparray[testi][1] = tempY;
								testi++;
								if(board[tempX+deltaX][tempY+deltaY] == 'O'){
                                    cout << " O if tempX and temp Y " << tempX+deltaX << " , " << tempY+deltaY << endl;
                                    cout << " test is " << testi << endl;
                                    for(int j=0; j<testi;j++){
                                        board[temparray[j][0]][temparray[j][1]] = 'O';
                                        cout << " with j " << tempX+j << " , " << tempY+j << endl;
                                    }
								}
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;
							}
						}
						if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == 'X')) {
							continue;
						}
					}
				}
			}
		//X_moves = i;
	}
}

void Othello2::oMove(){
    int orow;
    int ocol;
    int in=0;
    cout << "which row? " ;
    cin >> orow;
    cout << "which column? " ;
    cin >> ocol;
    cout << "you chose row -" << orow << " col-" << ocol << endl;
    while(in ==0){
        for(int row = 0; row < O_moves; row++){
            if(O_movesAvail[row][0]==orow && O_movesAvail[row][1]==ocol){
                cout << "That is a legal move, store and update " << getCurrentPlayer()<< endl;
                board[orow][ocol] = 'O';
                //printGameBoard();
                flips(orow, ocol);
                ONumPieces =0;
                O_moves=0;
                printGameBoard();
                in++;
                break;
            }/*else{
                cout << "not a legal move, try again" << endl;
                //break;
            }*/
        }
        if(in==0){cout << "not a legal move, try again" << endl;}
    }
}

void Othello2::xMove(){
    int xrow;
    int xcol;
    int in=0;
    cout << "which row? " ;
    cin >> xrow;
    cout << "which column? " ;
    cin >> xcol;
    cout << "you chose row -" << xrow << " col-" << xcol << endl;
    while(in ==0){
        for(int row = 0; row < X_moves; row++){
            if(X_movesAvail[row][0]==xrow && X_movesAvail[row][1]==xcol){
                cout << "That is a legal move, store and update " << currentPlayer << endl;
                board[xrow][xcol] = 'X';
                flips(xrow, xcol);
                XNumPieces =0;
                X_moves = 0;
                printGameBoard();
                in++;
                break;
            }/*else{
                cout << "not a legal move, try again" << endl;
                //break;
            }*/
        }
        if(in==0){cout << "not a legal move, try again" << endl;}
    }

}
void Othello2::printXMoves() {
	cout << "\nThe legal moves for X" << endl;
	for (int row = 0; row < X_moves; row++) {
		cout << "(" << X_movesAvail[row][0] << ", " << X_movesAvail[row][1] << ")" << endl;
	}
}

void Othello2::printOMoves() {
	cout << "\nThe legal moves for O" << endl;
	for (int row = 0; row < O_moves; row++) {
		cout << "(" << O_movesAvail[row][0] << ", " << O_movesAvail[row][1] << ")" << endl;
	}
}

bool Othello2::positionInBounds(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	else
		return false;
}
