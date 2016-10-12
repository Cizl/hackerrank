#include <iostream>
#include <map>
#include <string>
#include <queue>

#define MAX_BOARD 4

void switchTurn(char& turn) {
	if (turn == 'w') turn = 'b';
	else turn = 'w';
}

int bishopX[4] = {1, 1, -1, -1};
int bishopY[4] = {1, -1, 1, -1};

int rookX[4] = {1, 0, -1, 0};
int rookY[4] = {0, 1, 0, -1};

int knightX[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int knightY[8] = {2, -2, 1, -1, 2, -2, 1, -1};

std::vector<std::vector<std::string> > move(std::vector<std::vector<std::string> > board, int x, int y) {

	std::string piece = board[x][y];
	board[x][y] = "";

	if (piece[1] == 'B' || piece[1] == 'Q') {

		for (int i = 0; i < 4; i++) {

			int a = x + bishopX[i], b = y + bishopY[i];

			while (a < 4 && b < 4 && a >= 0 && b >= 0) {
				if (board[a][b][0] == piece[0]) break; // friendly piece
				if (board[a][b][0] != piece[0] && board[a][b] != "") { 
					board[a][b] = piece; // opponent piece
					break;
				}

				board[a][b] = piece; // empty
				a += bishopX[i];
				b += bishopY[i];
			}
		}
	}

	if (piece[1] == 'R' || piece[1] == 'Q') {

		for (int i = 0; i < 4; i++) {

			int a = x + rookX[i], b = y + rookY[i];

			while (a < 4 && b < 4 && a >= 0 && b >= 0) {
				if (board[a][b][0] == piece[0]) break; // friendly piece
				if (board[a][b][0] != piece[0] && board[a][b] != "") { 
					board[a][b] = piece; // opponent piece
					break;
				}

				board[a][b] = piece; // empty
				a += rookX[i];
				b += rookY[i];
			}
		}
	}

	if (piece[1] == 'N') {

		for (int i = 0; i < 8; i++) {

			int a = x + knightX[i], b = y + knightY[i];

			while (a < 4 && b < 4 && a >= 0 && b >= 0) {
				if (board[a][b][0] == piece[0]) break; // friendly piece
				if (board[a][b][0] != piece[0] && board[a][b] != "") { 
					board[a][b] = piece; // opponent piece
					break;
				}

				board[a][b] = piece; // empty
				a += knightX[i];
				b += knightY[i];
			}
		}
	}


	return board;
}

int main() {

	int g; // no of tests
	std::cin >> g;

	while (g--) {
		int w, b, m;
		std::cin >> w >> b >> m;

		std::vector<std::vector<std::string> > board;
		std::vector<std::string> v;
		v.insert(v.begin(), 4, "");
		board.insert(board.begin(), 4, v);

		std::map<char, int> countW;
		while (w--) {

			char c, a;
			int b;
			std::cin >> c >> a >> b;

			a -= 65;
			b--;

			countW[c]++;

			board[(int)a][b] += "w";
			board[(int)a][b] += c;
			board[(int)a][b] += (countW[c] + 48);

		}

		std::map<char, int> countB;
		while (b--) {

			char c, a;
			int b;
			std::cin >> c >> a >> b;

			a -= 65;
			b--;

			countB[c]++;

			board[(int)a][b] += "b";
			board[(int)a][b] += c;
			board[(int)a][b] += (countB[c] + 48);
		}

		char turn = 'w';

		bool foundSolution = false;

		std::queue<std::pair<std::vector<std::vector<std::string> >, int> > q;
		q.push(std::make_pair(board, 0));
		
		while (!q.empty() && !foundSolution) {

			board = q.front().first;
			int moveNum = q.front().second;
			q.pop();

			if (moveNum > m) { // finished
				
				foundSolution = true;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (board[i][j] == "bQ1") {
							foundSolution = false;
						}
					}
				}

				continue;
			}

			/*
			std::cout << std::endl << "\t move: " << moveNum << std::endl;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					std::cout << board[i][j] << " ";
					if (board[i][j] == "") std::cout << "---";
				}
				std::cout << std::endl;
			}
			*/

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (board[i][j] == "") continue;
					if (board[i][j][0] != turn) continue;

					std::vector<std::vector<std::string> > newBoard;
					newBoard = move(board, i, j);

					q.push(std::make_pair(newBoard, moveNum + 1));
				}
			}

			switchTurn(turn);

//			std::cout << std::endl;
		}


		if (foundSolution) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}

	}

	return 0;
}

