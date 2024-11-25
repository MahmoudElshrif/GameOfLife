#pragma once
class Board {
private:
	int width;
	int height;
	bool** cells;
	int mod(int x,int y) { return (y + (x % y)) % y; };
	int count_neighbors(int x, int y);
public:
	Board(int width,int height);
	void setCell(int x, int y, bool val) { cells[mod(x,width)][mod(y,height)] = val; };
	bool getCell(int x, int y) { return cells[mod(x,width)][mod(y,height)]; }
	int getWidth() { return width; };
	int getHeight() { return height; };
	void reset();
	void run();
};