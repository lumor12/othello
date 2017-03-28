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