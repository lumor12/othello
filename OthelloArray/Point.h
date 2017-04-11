#pragma once

//	simple class to hold the coords on the board
class Point
{
	private:
		int row;
		int col;
	public:
		Point() {};
		~Point() {};
		Point(int r, int c) { row = r; col = c; };
		int getRow() { return row; };
		int getCol() { return col; };
		void setRow(int r) { row = r; };
		void setCol(int c) { col = c; };
};