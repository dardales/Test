#include <iostream>
#include <stdlib.h>
using namespace std;

void printBoard(char board[][3]) {
	int i, j;
	int let = 0;
	cout << "		    A   B   C\n";
	cout << "		  _____________\n";
	for (i = 0; i < 3; i++) {
		let++;
		cout << "		" <<let << " |";
		for (j = 0; j < 3; j++) {
			cout << " " << board[i][j] << " |";
		}
		cout << endl;
	}
	cout << "		  -------------\n";
}

char checkWin (char board[][3]) {
	int i;
	for (i = 0; i < 3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2])) {
			if (board[i][0] != ' ') {
				return board[i][0];
			}
		}
	}
	for (i = 0; i < 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i])) {
			if (board[0][i] != ' ') {
				return board[0][i];
			}
		}
	}
	if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))) {
		if (board[1][1] != ' ') {
			return board[1][1];
		}
	}
	return 'N';
}

int countSpace (char board[][3]) {
	int i, j;
	int ctr = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				ctr++;
			}
		}
	}
	return ctr;
}

int checkInput (char input[]) {
	char x = input[0];	
	char y = input[1];
	int z;
	if((input[2] == '\0') && ((x >= 'a' && x <= 'c') || (x >= 'A' && x <= 'C')) && (y >= '1' && y <= '3')) {
		z = ((int)(y) - 49) * 10;
		if (x == 'a' || x == 'A') {
			return z + 0;
		}
		if (x == 'b' || x == 'B') {
			return z + 1;
		}
		if (x == 'c' || x == 'C') {
			return z + 2;
		}
	}
	cout << "\nINVALID INPUT!\n";
	return -1;	
}

int main () {
	char board[3][3];
	bool turn = 1;
	int i, j;
	int i1, i2, cdn;
	char input[2];
	int gameover;
	
	while (gameover != 1) {
		system("cls");
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				board[i][j] = ' ';
			}
		}
		cout << "TIC TAC TOE! :>\n\nPlayer O's turn:\n" << endl;
		while (countSpace(board) != 0 && checkWin(board) == 'N') {
			printBoard(board);
			do {
				cout << "\nInput Coordinates: ";
				cin >> input;
			} while (checkInput(input) == -1);
		
			cdn = checkInput(input);
			i1 = cdn / 10;
			i2 = cdn % 10;
		
			if (board[i1][i2] == ' ') {
				system("cls");
				if (turn) {
					board[i1][i2] = 'O';
					turn = !turn;
					cout << "Player X's turn:\n" << endl;
				}
				else if (!turn) {
					board[i1][i2] = 'X';
					turn = !turn;
					cout << "Player O's turn:\n" << endl;
				}
			}
			else {
				system("cls");
				cout << "\n Position is Occupied! Please choose another position! \n";
			}
		}
		
		if (checkWin(board) == 'N') {
			printBoard(board);
			cout << "\n Tie Game! \n";
		}
		else {
			printBoard(board);
			cout << "Player " << checkWin(board) << " Wins the Game!" << endl;
		}
		
		do {
			cout << "\nWould you like to start another game (Y/N): ";
			cin >> input;
			if ((input[0] == 'N') || (input[0] == 'n')) {
				cout << "\nEnding Game. . ." << endl;
				gameover = 1;
			}
			else if ((input[0] == 'Y') || (input[0] == 'y')) {
				cout << "\nStarting New Game. . .\n\n";
			}
			else {
				cout << "\nInvalid Input!\n";
			}
		} while ((input[0] != 'N') && (input[0] != 'n') && (input[0] != 'Y') && (input[0] != 'y'));
	}
	return 0;
}
