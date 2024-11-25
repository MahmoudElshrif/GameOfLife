#include "Board.h"
#include <vector>


Board::Board(int width,int height) : width(width),height(height) {
	cells = new bool* [width];
	for (int x = 0; x < width; x++) {
		cells[x] = new bool[height];
		for (int y = 0; y < height; y++) {
			cells[x][y] = 0;
		}
	}
}

void Board::reset() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			cells[x][y] = false;
		}
	}
}

int Board::count_neighbors(int x, int y) {
	int total = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (j == 0 && i == 0) {
				continue;
			}
			if (getCell(x + i, y + j)) total++;

		}
	}
	return total;
}

void Board::run() {
	bool** temp;
	temp = new bool* [width];
	for (int i = 0; i < width; i++) {
		temp[i] = new bool[height];
	}


	/*std::vector<std::vector<int>> sum;
	for (int x = 0; x < width; x++) {
		std::vector<int> v = { 0 };
		for (int y = 0; y < height; y++) {
			v.push_back(v.front() + getCell(x, y));
		}
		sum.push_back(v);
	}*/

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			int count = count_neighbors(x, y);
			
			if (getCell(x, y)) {
				if (count < 2 || count > 3) {
					temp[x][y] = false;
				}
				else {
					temp[x][y] = true;
				}
			}
			else {
				if (count == 3) {
					temp[x][y] = true;
				}
				else {
					temp[x][y] = false;
				}
			}
			//temp[x][y] = true;
		}
	}

	for (int i = 0; i < width; i++) {
		delete[] cells[i];
	}
	delete[] cells;
	cells = temp;
}