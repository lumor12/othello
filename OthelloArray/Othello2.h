#pragma once
#include <vector>
#include "Point.h"

class Othello2
{
	private:
		char board[8][8];
		//int x_pieces[8][2];
		//int o_pieces[8][2];
		char currentPlayer;
		int XNumPieces = 0;
		int ONumPieces = 0;
		//int X_movesAvail[20][2];
		//int O_movesAvail[20][2];
		int X_moves = 0;
		int O_moves = 0;
		int X_flips = 2;
		int O_flips = 2;

		//	using Point class to hold the row and column. Made it easier to use the vectors to store and access the data we need
		std::vector<Point> Xpieces;
		//std::vector<Point> *pXpieces = &Xpieces;
		std::vector<Point> Opieces;

		std::vector<Point> XmovesAvail;
		//std::vector<Point> *pXmovesAvail = &XmovesAvail;
		std::vector<Point> OmovesAvail;



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
		static std::vector<Point> availableMovesLA(char player, char board[8][8], std::vector<Point> pieces);
		static std::vector<Point> findPiecesLA(char player, char board[8][8]);
		void findPieces();
		void printGameBoard();
		void printXPieces();
		void printOPieces();
		bool printXMoves();
		void printOMoves();
		static bool positionInBounds(int x, int y);
		void xMove();
		static void simMove(char player, Point move, char board[8][8]);
		void flips(int frow, int fcol);
		static void flipsLA(int frow, int fcol, char player, char board[8][8]);
		bool findPieces2();
		static double eval_func(char board[8][8]);
		static int numValidMoves(char player, char opp, char currentBoard[8][8]);
		std::vector<double> lookAhead(int n, char player, std::vector<Point> availMoves, char board[8][8]);
		void makeMove();
};
