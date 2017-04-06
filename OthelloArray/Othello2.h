#pragma once

class Othello2
{
	private:
		char board[8][8];
		int x_pieces[8][2];
		int o_pieces[8][2];
		char currentPlayer;
		int XNumPieces = 0;
		int ONumPieces = 0;
		int X_movesAvail[8][2];
		int O_movesAvail[8][2];
		int X_moves = 0;
		int O_moves = 0;
		int X_flips = 2;
		int O_flips = 2;

	public:
		Othello2();
		~Othello2() { };
		void setCurrentPlayer(char p);
		void getX_pieces(int cords[][2]);
		void getO_pieces(int cords[][2]);
		char getCurrentPlayer();
		int getXNumMoves();
		int getONumMoves();
		void getMovesAvail(int cords[][2]);
		void availableMoves();
		void findPieces(char player);
		void printGameBoard();
		void printXPieces();
		void printOPieces();
		void printXMoves();
		void printOMoves();
		bool positionInBounds(int x, int y);
		void xMove();
		void oMove();
		void flips(int frow, int fcol);
};
