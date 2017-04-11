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
		cords[row][0] = Xpieces[row].getRow();
		cords[row][1] = Xpieces[row].getCol();
	}
}

void Othello2::getO_pieces(int cords[][2]) {
	for (int row = 0; row < ONumPieces; row++) {
		cords[row][0] = Opieces[row].getRow();
		cords[row][1] = Opieces[row].getCol();
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
			cords[row][0] = XmovesAvail[row].getRow();
			cords[row][1] = XmovesAvail[row].getCol();
		}
	}
	if (currentPlayer == 'O') {
		for (int row = 0; row < O_moves; row++) {
			cords[row][0] = OmovesAvail[row].getRow();
			cords[row][1] = OmovesAvail[row].getCol();
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

	XmovesAvail.clear();
	OmovesAvail.clear();

	if (currentPlayer == 'X') {
		for (int row = 0; row < XNumPieces; row++) {
			for (deltaX = -1; deltaX < 2; deltaX++) {
				for (deltaY = -1; deltaY < 2; deltaY++) {
					if (deltaX != 0 || deltaY != 0) {
						tempX = Xpieces[row].getRow() + deltaX;
						tempY = Xpieces[row].getCol() + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O') {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'O') {
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;
							}
							if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
								XmovesAvail.push_back(Point(tempX, tempY));
								//i++;
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
						tempX = Opieces[row].getRow() + deltaX;
						tempY = Opieces[row].getCol() + deltaY;

						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X') {
							while (positionInBounds(tempX, tempY) && board[tempX][tempY] == 'X') {
								tempX = tempX + deltaX;
								tempY = tempY + deltaY;
							}
							if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
								OmovesAvail.push_back(Point(tempX, tempY));
								//i++;
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
	Xpieces.clear();
	Opieces.clear();
	
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			i++;
			if (board[row][column] == p) {
				//cout << "first " << var <<" at " << i-1 << " X and Y cordinates ("
				//<< row << ", " << column << ")" << endl;
				if (p == 'X') {
					Xpieces.push_back(Point(row, column));
					j++;
					XNumPieces++;
				}
				else if (p == 'O') {
					Opieces.push_back(Point(row, column));
					j++;
					ONumPieces++;
				}
			}
		}
	}std::cout << endl;
}

//saves the position of the pieces for player p in an array to be access later by availableMoves()
void Othello2::findPieces2() {
	int x = 0;  //tally position var was found. Will change to cordinates
	int o = 0; // tally # of vars found
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if (board[row][column] == 'X') {
				x++;
			}
			if (board[row][column] == 'O'){
                o++;
			}
		}
	}
	cout << " X = " << x << " O = " << o << endl;
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
		cout << "(" << Xpieces[row].getRow() << ", " << Xpieces[row].getCol() << ")" << endl;
	}
}

void Othello2::printOPieces() {
	cout << "The pieces for O are in" << endl;
	for (int row = 0; row < ONumPieces; row++) {
		cout << "(" << Opieces[row].getRow() << ", " << Opieces[row].getCol() << ")" << endl;
	}
}

void Othello2::flips(int frow, int fcol) {
	int deltaX = 0;
	int deltaY = 0;
	int tempX = 0;
	int tempY = 0;
	int i = 0;
	// used to define player and opponent for each move
	char opponent = (currentPlayer == 'O')? 'X' : 'O';
	//cout << "Opponet = " << opponent << " CurrentPlayer = " << currentPlayer << endl;
    /*if (currentPlayer == 'X') {*/
            //cout << "did anything happen X? " << currentPlayer <<endl;
        for (deltaX = -1; deltaX < 2; deltaX++) {
            //cout << " first loop? " << currentPlayer <<endl;
            for (deltaY = -1; deltaY < 2; deltaY++) {
                if (frow + deltaX < 0 || frow + deltaX >= 8 ||
                    fcol + deltaY < 0 || fcol + deltaY >= 8 ||
                        (deltaX == 0 && deltaY == 0))  {
                            continue;
                        }
                //cout << " should be here a few times " << tempX << " " << tempY <<endl;
                if (board[frow + deltaX][fcol + deltaY] == opponent) {
                    tempX = frow + deltaX;
                    tempY = fcol + deltaY;
                    for(;;){
                        tempX += deltaX;
                        tempY += deltaY;
                        if(tempX < 0 || tempX >= 8 || tempY < 0 || tempY >= 8){
                            break;
                        }
                        if(board[tempX][tempY] == ' '){
                            break;
                        }
                        if(board[tempX][tempY] == currentPlayer){
                            while(board[tempX -= deltaX][tempY -= deltaY] == opponent){
                                board[tempX][tempY] = currentPlayer;
                            }
                            break;
                        }
                    }
                }
            }
        }
	//}
}

void Othello2::oMove(){
    int orow;
    int ocol;
    int in=0;
    cout << "which row? " ;
    cin >> orow;
    cout << "which column? " ;
    cin >> ocol;
    //cout << "you chose row -" << orow << " col-" << ocol << endl;
    while(in ==0){
        for(int row = 0; row < O_moves; row++){
            if(OmovesAvail[row].getRow()==orow && OmovesAvail[row].getCol()==ocol){
                //cout << "That is a legal move, store and update " << getCurrentPlayer()<< endl;
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
    //cout << "you chose row -" << xrow << " col-" << xcol << endl;
    while(in ==0){
        for(int row = 0; row < X_moves; row++){
            if(XmovesAvail[row].getRow()==xrow && XmovesAvail[row].getCol()==xcol){
                //cout << "That is a legal move, store and update " << currentPlayer << endl;
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
		cout << "(" << XmovesAvail[row].getRow() << ", " << XmovesAvail[row].getCol() << ")" << endl;
	}
}

void Othello2::printOMoves() {
	cout << "\nThe legal moves for O" << endl;
	for (int row = 0; row < O_moves; row++) {
		cout << "(" << OmovesAvail[row].getRow() << ", " << OmovesAvail[row].getCol() << ")" << endl;
	}
}

bool positionInBounds(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	else
		return false;
}

double Othello2::eval_func(char currentBoard[8][8]) {
	double score = 0;
	double hCorners, hMovesAvail, hCurrentPieces, hFuturePieces, hCornerCloseness, hPieceValue;
	int ai_pieces = 0, opp_pieces = 0, ai_futPieces = 0, opp_futPieces = 0;

	int deltaX[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	int deltaY[] = {-1, 0, 1, 1, 1, 0, -1, -1};

	int pValues[8][8] = {{ 20, -3, 11, 8, 8, 11, -3, 20 },
						{ -3, -7, -4, 1, 1, -4, -7, -3 },
						{ 11, -4, 2, 2, 2, 2, -4, 11 },
						{ 8, 1, 2, -3, -3, 2, 1, 8 },
						{ 8, 1, 2, -3, -3, 2, 1, 8 },
						{ 11, -4, 2, 2, 2, 2, -4, 11 },
						{ -3, -7, -4, 1, 1, -4, -7, -3 },
						{ 20, -3, 11, 8, 8, 11, -3, 20 }};

	// evaluate hPieceValue, hCurrentPieces, and hFuturePieces
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (currentBoard[row][col] == 'O') {
				hPieceValue += pValues[row][col];
				ai_pieces++;
				for (int i = 0; i < 8; i++) {
					int x = row + deltaX[i];
					int y = col + deltaY[i];
					if (positionInBounds(x, y) && currentBoard[x][y] == 'X') {
						while (positionInBounds(x, y) && currentBoard[x][y] == 'X') {
							x = x + deltaX[i];
							y = y + deltaY[i];
						}
						if (positionInBounds(x, y) && currentBoard[x][y] == '|') {
							ai_futPieces++;
						}
					}
				}
			}
			else if (currentBoard[row][col] == 'X') {
				hPieceValue -= pValues[row][col];
				opp_pieces++;
				for (int i = 0; i < 8; i++) {
					int x = row + deltaX[i];
					int y = col + deltaY[i];
					if (positionInBounds(x, y) && currentBoard[x][y] == 'O') {
						while (positionInBounds(x, y) && currentBoard[x][y] == 'O') {
							x = x + deltaX[i];
							y = y + deltaY[i];
						}
						if (positionInBounds(x, y) && currentBoard[x][y] == '|') {
							opp_futPieces++;
						}
					}
				}
			}
		}
	}

	if (ai_pieces > opp_pieces)
		hCurrentPieces = (100.0 * ai_pieces) / (ai_pieces + opp_pieces);
	else if (ai_pieces < opp_pieces)
		hCurrentPieces = (100.0 * opp_pieces) / (ai_pieces + opp_pieces);
	else
		hCurrentPieces = 0;

	if (ai_futPieces > opp_futPieces)
		hFuturePieces = (100.0 * ai_futPieces) / (ai_futPieces + opp_futPieces);
	else if (ai_futPieces < opp_futPieces)
		hFuturePieces = (100.0 * opp_futPieces) / (ai_futPieces + opp_futPieces);
	else
		hFuturePieces = 0;

	// evaluate hCorners
	ai_pieces = 0;
	opp_pieces = 0;

	if (currentBoard[0][0] == 'O')
		ai_pieces++;
	else if (currentBoard[0][0] == 'X')
		opp_pieces++;
	if (currentBoard[7][0] == 'O')
		ai_pieces++;
	else if (currentBoard[7][0] == 'X')
		opp_pieces++;
	if (currentBoard[0][7] == 'O')
		ai_pieces++;
	else if (currentBoard[0][7] == 'X')
		opp_pieces++;
	if (currentBoard[7][7] == 'O')
		ai_pieces++;
	else if (currentBoard[7][7] == 'X')
		opp_pieces++;

	hCorners = 25.0 * (ai_pieces - opp_pieces);

	// evaluate hCornerCloseness
	ai_pieces = 0;
	opp_pieces = 0;

	if (currentBoard[0][0] == '|') {
		if (currentBoard[0][1] == 'O')
			ai_pieces++;
		else if (currentBoard[0][1] == 'X')
			opp_pieces++;
		if (currentBoard[1][1] == 'O')
			ai_pieces++;
		else if (currentBoard[1][1] == 'X')
			opp_pieces++;
		if (currentBoard[1][0] == 'O')
			ai_pieces++;
		else if (currentBoard[1][0] == 'X')
			opp_pieces++;
	}
	if (currentBoard[7][0] == '|') {
		if (currentBoard[7][1] == 'O')
			ai_pieces++;
		else if (currentBoard[7][1] == 'X')
			opp_pieces++;
		if (currentBoard[6][1] == 'O')
			ai_pieces++;
		else if (currentBoard[6][1] == 'X')
			opp_pieces++;
		if (currentBoard[6][0] == 'O')
			ai_pieces++;
		else if (currentBoard[6][0] == 'X')
			opp_pieces++;
	}
	if (currentBoard[0][7] == '|') {
		if (currentBoard[0][6] == 'O')
			ai_pieces++;
		else if (currentBoard[0][6] == 'X')
			opp_pieces++;
		if (currentBoard[1][6] == 'O')
			ai_pieces++;
		else if (currentBoard[1][6] == 'X')
			opp_pieces++;
		if (currentBoard[1][7] == 'O')
			ai_pieces++;
		else if (currentBoard[1][7] == 'X')
			opp_pieces++;
	}
	if (currentBoard[7][7] == '|') {
		if (currentBoard[6][7] == 'O')
			ai_pieces++;
		else if (currentBoard[6][7] == 'X')
			opp_pieces++;
		if (currentBoard[6][6] == 'O')
			ai_pieces++;
		else if (currentBoard[6][6] == 'X')
			opp_pieces++;
		if (currentBoard[7][6] == 'O')
			ai_pieces++;
		else if (currentBoard[7][6] == 'X')
			opp_pieces++;
	}

	hCornerCloseness = -12.5 * (ai_pieces - opp_pieces);

	// evaluate hMovesAvail
	ai_pieces = numValidMoves('O', 'X', currentBoard);
	opp_pieces = numValidMoves('X', 'O', currentBoard);

	if (ai_pieces > opp_pieces)
		hMovesAvail = (100.0 * ai_pieces) / (ai_pieces + opp_pieces);
	else if (ai_pieces < opp_pieces)
		hMovesAvail = -(100.0 * opp_pieces) / (ai_pieces + opp_pieces);
	else
		hMovesAvail = 0;

	// evaluate final score for current board. Still need to figure out the weight of each heuristic
	score = hCurrentPieces + hCorners + hCornerCloseness + hMovesAvail + hFuturePieces + hPieceValue;
	return score;
}

// counts the valid moves for the given player in the current board
int numValidMoves(char player, char opp, char currentBoard[8][8]) {
	int count = 0;

	int deltaX[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int deltaY[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			if (currentBoard[row][col] == player) {
				for (int i = 0; i < 8; i++) {
					int x = row + deltaX[i];
					int y = col + deltaY[i];
					if (positionInBounds(x, y) && currentBoard[x][y] == opp) {
						while (positionInBounds(x, y) && currentBoard[x][y] == opp) {
							x = x + deltaX[i];
							y = y + deltaY[i];
						}
						if (positionInBounds(x, y) && currentBoard[x][y] == '|') {
							count++;
						}
					}
				}
			}
		}
	}
	return count;
}