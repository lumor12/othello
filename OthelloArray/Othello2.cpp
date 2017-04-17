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
// gets the available moves in a given board for a player. called by lookAhead()
vector<Point> Othello2::availableMovesLA(char player, char board[8][8], vector<Point> pieces) {
	int deltaX = 0;
	int deltaY = 0;
	int tempX;
	int tempY;
	int i = 0;

	vector<Point> movesAvail;
	char opponent = (player == 'O') ? 'X' : 'O';
	for (int row = 0; row < pieces.size(); row++) {
		for (deltaX = -1; deltaX < 2; deltaX++) {
			for (deltaY = -1; deltaY < 2; deltaY++) {
				if (deltaX != 0 || deltaY != 0) {
					tempX = pieces[row].getRow() + deltaX;
					tempY = pieces[row].getCol() + deltaY;

					if (positionInBounds(tempX, tempY) && board[tempX][tempY] == opponent) {
						while (positionInBounds(tempX, tempY) && board[tempX][tempY] == opponent) {
							tempX = tempX + deltaX;
							tempY = tempY + deltaY;
						}
						if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
							int dupe = 0;
							for (int row = 0; row < movesAvail.size(); row++) {
								if (movesAvail[row].getRow() == tempX && movesAvail[row].getCol() == tempY) {
									dupe++;
								}
							}
							if (dupe == 0) {
								movesAvail.push_back(Point(tempX, tempY));
								//i++;
								//X_moves++;
								//cout << "vector size " << XmovesAvail.size() << endl;
							}
						}
					}
					if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == player)) {
						continue;
					}
				}
			}
		}
	}
	return movesAvail;
}

void Othello2::availableMoves() {
	int deltaX = 0;
	int deltaY = 0;
	int tempX;
	int tempY;
	int i = 0;

	XmovesAvail.clear();
	OmovesAvail.clear();
    char opponent = (currentPlayer == 'O')? 'X' : 'O';
    for (int row = 0; row < XNumPieces; row++) {
        for (deltaX = -1; deltaX < 2; deltaX++) {
            for (deltaY = -1; deltaY < 2; deltaY++) {
                if (deltaX != 0 || deltaY != 0) {
                    tempX = Xpieces[row].getRow() + deltaX;
                    tempY = Xpieces[row].getCol() + deltaY;

                    if (positionInBounds(tempX, tempY) && board[tempX][tempY] == opponent) {
                        while (positionInBounds(tempX, tempY) && board[tempX][tempY] == opponent) {
                            tempX = tempX + deltaX;
                            tempY = tempY + deltaY;
                        }
                        if (positionInBounds(tempX, tempY) && board[tempX][tempY] == '|') {
                            int dupe = 0;
                            for (int row = 0; row < XmovesAvail.size(); row++) {
                                if( XmovesAvail[row].getRow() == tempX && XmovesAvail[row].getCol() == tempY){
                                    dupe++;
                                }
                            }
                            if(dupe == 0){
                                    XmovesAvail.push_back(Point(tempX, tempY));
                                    //i++;
                                    X_moves++;
                                    //cout << "vector size " << XmovesAvail.size() << endl;
                            }
                        }
                    }
                    if (positionInBounds(tempX, tempY) && (board[tempX][tempY] == '|' || board[tempX][tempY] == currentPlayer)) {
                        continue;
                    }
                }
            }
        }
    }
}

void Othello2::findPieces() {
	//int i = 0;  //tally position var was found. Will change to cordinates
	//int j = 0; // tally # of vars found
	Xpieces.clear();
	Opieces.clear();
    //char opponent = (currentPlayer == 'O')? 'X' : 'O';
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			//i++;
			if (board[row][column] == currentPlayer) {
				//cout << "first " << var <<" at " << i-1 << " X and Y cordinates ("
				//<< row << ", " << column << ")" << endl;
                Xpieces.push_back(Point(row, column));
                //j++;
                XNumPieces++;
			}
		}
	}std::cout << endl;
}

//	find the pieces for the given player in the given board. called by lookAhead() to find the pieces in a temp board
vector<Point> Othello2::findPiecesLA(char p, char board[8][8]) {

	vector<Point> pieces;

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			if (board[row][column] == p) {
				pieces.push_back(Point(row, column));
			}
		}
	}
	return pieces;
}

//saves the position of the pieces for player p in an array to be access later by availableMoves()
bool Othello2::findPieces2() {
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
	if(x == 0 || o == 0 || x+o >= 64){
        return false;
	} else {
        return true;
	}
}

void Othello2::printGameBoard() {
            cout << "   0 1 2 3 4 5 6 7" << endl;
            cout << "  -----------------" << endl;
	for (int row = 0; row < 8; row++) {
            cout << row << "| ";
		for (int column = 0; column < 8; column++) {
			cout << board[row][column] << " ";
			if(column == 7){ cout << "|" ;}
		}
		cout << endl;
	}
	cout << "  -----------------" << endl;
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

// does the flips for a simulated move. called by simMove()
void Othello2::flipsLA(int frow, int fcol, char player, char board[8][8]) {
	int deltaX = 0;
	int deltaY = 0;
	int tempX = 0;
	int tempY = 0;
	//int i = 0;
	// used to define player and opponent for each move
	char opponent = (player == 'O') ? 'X' : 'O';
	//cout << "Opponet = " << opponent << " CurrentPlayer = " << currentPlayer << endl;
	/*if (currentPlayer == 'X') {*/
	//cout << "did anything happen X? " << currentPlayer <<endl;
	for (deltaX = -1; deltaX < 2; deltaX++) {
		//cout << " first loop? " << currentPlayer <<endl;
		for (deltaY = -1; deltaY < 2; deltaY++) {
			if (frow + deltaX < 0 || frow + deltaX >= 8 ||
				fcol + deltaY < 0 || fcol + deltaY >= 8 ||
				(deltaX == 0 && deltaY == 0)) {
				continue;
			}
			//cout << " should be here a few times " << tempX << " " << tempY <<endl;
			if (board[frow + deltaX][fcol + deltaY] == opponent) {
				tempX = frow + deltaX;
				tempY = fcol + deltaY;
				for (;;) {
					tempX += deltaX;
					tempY += deltaY;
					if (tempX < 0 || tempX >= 8 || tempY < 0 || tempY >= 8) {
						break;
					}
					if (board[tempX][tempY] == ' ') {
						break;
					}
					if (board[tempX][tempY] == player) {
						while (board[tempX -= deltaX][tempY -= deltaY] == opponent) {
							board[tempX][tempY] = player;
						}
						break;
					}
				}
			}
		}
	}
	//}
}

// makes a move for the given player in the given board. Called by lookAhead() to simulate a move in a temp board
void Othello2::simMove(char player, Point move, char board[8][8]){
	board[move.getRow()][move.getCol()] = player;
	flipsLA(move.getRow(), move.getCol(), player, board);
}

void Othello2::xMove(){
    int xrow;
    int xcol;
    //char entry;
    int in=0;
    while(in ==0){
    cout << "which row? " ;
    cin >> xrow;
    //if(entry == 'q'){exit(0);}
    //else {xrow = stoi(entry);}
    cout << "which column? " ;
    cin >> xcol;
    //cout << "you chose row -" << xrow << " col-" << xcol << endl;
    char opponent = (currentPlayer == 'O')? 'X' : 'O';
        for(int row = 0; row < X_moves; row++){
            if(XmovesAvail[row].getRow()==xrow && XmovesAvail[row].getCol()==xcol){
                //cout << "That is a legal move, store and update " << currentPlayer << endl;
                board[xrow][xcol] = currentPlayer;
                flips(xrow, xcol);
                XNumPieces =0;
                X_moves = 0;
                printGameBoard();
                in++;
                break;
            }
        }
        if(in== 0){
            cout << "not a valid move, try again" << endl;
        }
    }

}

bool Othello2::printXMoves() {
    if(X_moves == 0){
        return false;
    } else {
        cout << "\nThe legal moves for currentPlayer " << currentPlayer << endl;
        for (int row = 0; row < X_moves; row++) {
            cout << "(" << XmovesAvail[row].getRow() << ", " << XmovesAvail[row].getCol() << ")" << endl;
        }
        return true;
    }
}

void Othello2::printOMoves() {
	cout << "\nThe legal moves for O" << endl;
	for (int row = 0; row < O_moves; row++) {
		cout << "(" << OmovesAvail[row].getRow() << ", " << OmovesAvail[row].getCol() << ")" << endl;
	}
}

bool Othello2::positionInBounds(int x, int y) {
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	else
		return false;
}

double Othello2::eval_func(char board[8][8]) {
	double score = 0.0;
	double hCorners = 0.0, hMovesAvail = 0.0, hCurrentPieces = 0.0, hFuturePieces = 0.0, hCornerCloseness = 0.0, hPieceValue = 0.0;
	int ai_pieces = 0, opp_pieces = 0, ai_futPieces = 0, opp_futPieces = 0;

	char tempBoard[8][8];
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			tempBoard[row][col] = board[row][col];
		}
	}

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
			if (tempBoard[row][col] == 'O') {
				hPieceValue += pValues[row][col];
				ai_pieces++;
				for (int i = 0; i < 8; i++) {
					int x = row + deltaX[i];
					int y = col + deltaY[i];
					if (positionInBounds(x, y) && tempBoard[x][y] == 'X') {
						while (positionInBounds(x, y) && tempBoard[x][y] == 'X') {
							x = x + deltaX[i];
							y = y + deltaY[i];
						}
						if (positionInBounds(x, y) && tempBoard[x][y] == '|') {
							ai_futPieces++;
						}
					}
				}
			}
			else if (tempBoard[row][col] == 'X') {
				hPieceValue -= pValues[row][col];
				opp_pieces++;
				for (int i = 0; i < 8; i++) {
					int x = row + deltaX[i];
					int y = col + deltaY[i];
					if (positionInBounds(x, y) && tempBoard[x][y] == 'O') {
						while (positionInBounds(x, y) && tempBoard[x][y] == 'O') {
							x = x + deltaX[i];
							y = y + deltaY[i];
						}
						if (positionInBounds(x, y) && tempBoard[x][y] == '|') {
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

	if (tempBoard[0][0] == 'O')
		ai_pieces++;
	else if (tempBoard[0][0] == 'X')
		opp_pieces++;
	if (tempBoard[7][0] == 'O')
		ai_pieces++;
	else if (tempBoard[7][0] == 'X')
		opp_pieces++;
	if (tempBoard[0][7] == 'O')
		ai_pieces++;
	else if (tempBoard[0][7] == 'X')
		opp_pieces++;
	if (tempBoard[7][7] == 'O')
		ai_pieces++;
	else if (tempBoard[7][7] == 'X')
		opp_pieces++;

	hCorners = 25.0 * (ai_pieces - opp_pieces);

	// evaluate hCornerCloseness
	ai_pieces = 0;
	opp_pieces = 0;

	if (tempBoard[0][0] == '|') {
		if (tempBoard[0][1] == 'O')
			ai_pieces++;
		else if (tempBoard[0][1] == 'X')
			opp_pieces++;
		if (tempBoard[1][1] == 'O')
			ai_pieces++;
		else if (tempBoard[1][1] == 'X')
			opp_pieces++;
		if (tempBoard[1][0] == 'O')
			ai_pieces++;
		else if (tempBoard[1][0] == 'X')
			opp_pieces++;
	}
	if (tempBoard[7][0] == '|') {
		if (tempBoard[7][1] == 'O')
			ai_pieces++;
		else if (tempBoard[7][1] == 'X')
			opp_pieces++;
		if (tempBoard[6][1] == 'O')
			ai_pieces++;
		else if (tempBoard[6][1] == 'X')
			opp_pieces++;
		if (tempBoard[6][0] == 'O')
			ai_pieces++;
		else if (tempBoard[6][0] == 'X')
			opp_pieces++;
	}
	if (tempBoard[0][7] == '|') {
		if (tempBoard[0][6] == 'O')
			ai_pieces++;
		else if (tempBoard[0][6] == 'X')
			opp_pieces++;
		if (tempBoard[1][6] == 'O')
			ai_pieces++;
		else if (tempBoard[1][6] == 'X')
			opp_pieces++;
		if (tempBoard[1][7] == 'O')
			ai_pieces++;
		else if (tempBoard[1][7] == 'X')
			opp_pieces++;
	}
	if (tempBoard[7][7] == '|') {
		if (tempBoard[6][7] == 'O')
			ai_pieces++;
		else if (tempBoard[6][7] == 'X')
			opp_pieces++;
		if (tempBoard[6][6] == 'O')
			ai_pieces++;
		else if (tempBoard[6][6] == 'X')
			opp_pieces++;
		if (tempBoard[7][6] == 'O')
			ai_pieces++;
		else if (tempBoard[7][6] == 'X')
			opp_pieces++;
	}

	hCornerCloseness = -12.5 * (ai_pieces - opp_pieces);

	// evaluate hMovesAvail
	ai_pieces = numValidMoves('O', 'X', tempBoard);
	opp_pieces = numValidMoves('X', 'O', tempBoard);

	if (ai_pieces > opp_pieces)
		hMovesAvail = (100.0 * ai_pieces) / (ai_pieces + opp_pieces);
	else if (ai_pieces < opp_pieces)
		hMovesAvail = -(100.0 * opp_pieces) / (ai_pieces + opp_pieces);
	else
		hMovesAvail = 0;

	// evaluate final score for current board. Still need to figure out the weight of each heuristic
	score = (10.0 * hCurrentPieces) + (801.724 * hCorners) + (382.026 * hCornerCloseness) + (78.922 * hMovesAvail) + (74.396 * hFuturePieces) + (10.0 * hPieceValue);
	return score;
}

// counts the valid moves for the given player in the current board
int Othello2::numValidMoves(char player, char opp, char currentBoard[8][8]) {
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

// does the look ahead and evaluates the available moves. Called by makeMove(). could use some ideas on how to make this work. Getting stack overflow errors, need to keep looking at this.
vector<double> Othello2::lookAhead(int n, char player, vector<Point> availMoves, char board[8][8]) {
	//cout << "for some reason dies here " << endl;
	vector<double> moveValues (availMoves.size(), 0.0);
	char opponent = (player == 'O') ? 'X' : 'O';
	if (n > 0) {
		if (n % 2 == 0) {
			for (int i = 0; i < availMoves.size(); i++) {
				char tempBoard[8][8];
				for (int row = 0; row < 8; row++) {
					for (int col = 0; col < 8; col++) {
						tempBoard[row][col] = board[row][col];
					}
				}
				tempBoard[availMoves[i].getRow()][availMoves[i].getCol()] = player;
				flipsLA(availMoves[i].getRow(), availMoves[i].getCol(), player, tempBoard);
				moveValues[i] += eval_func(tempBoard);
				vector<Point> nPieces = findPiecesLA(opponent, tempBoard);
				vector<Point> nAvailMovs = availableMovesLA(opponent, tempBoard, nPieces);
				//n--;
				lookAhead(n-1, opponent, nAvailMovs, tempBoard);
			}
			//n--;
		}
		else {
			for (int i = 0; i < availMoves.size(); i++) {
				char tempBoard[8][8];
				for (int row = 0; row < 8; row++) {
					for (int col = 0; col < 8; col++) {
						tempBoard[row][col] = board[row][col];
					}
				}
				tempBoard[availMoves[i].getRow()][availMoves[i].getCol()] = opponent;
				flipsLA(availMoves[i].getRow(), availMoves[i].getCol(), opponent, tempBoard);
				moveValues[i] += eval_func(tempBoard);
				vector<Point> nPieces = findPiecesLA(player, tempBoard);
				vector<Point> nAvailMovs = availableMovesLA(player, tempBoard, nPieces);
				//n--;
				lookAhead(n-1, player, nAvailMovs,tempBoard);
			}
			//n--;
		}
	}
	return moveValues;
}

// plays the move for the AI
void Othello2::makeMove() {
	vector<double> moveVals = lookAhead(4, currentPlayer, XmovesAvail, board);
	int bestMove = 0;
	for (int i = 1; i < moveVals.size(); i++) {
		if (moveVals[bestMove] < moveVals[i])
			bestMove = i;
	}
	int xrow = XmovesAvail[bestMove].getRow();
	int xcol = XmovesAvail[bestMove].getCol();

	board[xrow][xcol] = currentPlayer;
	flips(xrow, xcol);
	cout << "Player " << currentPlayer << " move: (" << xrow << ", " << xcol << ")" << endl;
	XNumPieces = 0;
	X_moves = 0;
	printGameBoard();
}
