#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/*******************************************
* Program Name: Tic-Tac-Toe
* Created Date: 05-08-2008
* Created By: Timothy Mulvey
* Purpose: One or Two player Tic-Tac-Toe game
* Version: 1.0
*******************************************/

const int MAX = 3;

//This class was provided.  Inhearance was used to fill in the functions.
class Game {
protected:
	char Board[MAX][MAX]; //Store the actually board for the game
	int iTotalMoves; //How many moves have happened in the game

public:
	Game() : iTotalMoves(0)
	{
		ResetBoard();
	}

	void DrawRow(char cRow[]) {
		//This member function will print out one row of the 3 row tic-tac-toe board
	}

	void DrawGame() {
		//This member function will print the entire tic-tac-toe board. This member function calls the
		//DrawRow() function which will draw the rows of the board
	}

	void ResetBoard() {
		//This member function will reset the board to all blank to start the tic-tac-toe game
		for (int iRow = 0; iRow < MAX; iRow++) {
			for (int iCol = 0; iCol < MAX; iCol++) {
				Board[iRow][iCol] = ' ';
			}
		}
	}

	void UserInput(char cPlayerSymbol) {
		//This member function will print to the user who's turn it is and ask the player for a column and row coordiante to put
		//their symbol on the tic-tac-toe board. This member function will also check to see if the user's position was
		//a valid place on the board to go to. In other words it checks to see if it is a space on the board and also makes
		//sure to check if another X or O is already in that position.
	}

	bool CheckMove(int iRow, int iColumn) {
		//This member function checks to see if the move was a valid move or not. This is called from UserInput.
	}

	void ComputerMove(char cPlayer, char cComputer) {
		//This is the code for the computers strategy on how it will make its next move. Ideally you will check all
		//positions on the board and make sure that you block any human player win attempts. Then if there are no
		//human win attempts, make the best move possible.
	}

	bool CheckWin(char cPlayer) {
		//This member function will check all winning combinations on the board to see if anyone won or if it is a
		//"Cats" game (A tie). Also remember that there is a member variable that keeps track of how many moves
		//have already taken place. There are only 9 moves in the entire game so once the moves are more than 9
		//the game is over (Cats game).
	}
};

//My code starts here.
/*******************************************
* Class Name: GAME
* Purpose: Tic-Tac-Toe game
*******************************************/

class GAME : public Game {
	bool end;        //is game over?
	int players;    //how many players
	int x, y;        //Board index
	int log[9];        //track moves
public:
	//initilize variables
	GAME() : Game(), end(false), players(0), x(0), y(0) {
		for (int c = 0; c < 9; c++) {
			log[c] = 0;
		}
	}
	//play tic-tac-toe
	void play() {
		char cont;    //play again?

					  //main loop
		do {
			//reset variables
			end = false;
			iTotalMoves = 0;
			ResetBoard();
			for (int c = 0; c < 9; c++) {
				log[c] = 0;
			}

			cout << "Tic-Tac-Toe" << endl;
			//loop for good input
			do {
				cout << "How many players? (1 or 2): ";
				cin >> players;
				if (players != 1 && players != 2) {
					cout << "Invalid input!" << endl;
				}
			} while (players != 1 && players != 2);
			system("cls");

			DrawGame();
			//loop for 9 turns or until game ends
			while (iTotalMoves < 9 && !end) {
				turn('X');
				if (iTotalMoves < 9 && !end) {
					turn('O');
				}
			}
			//Tie game message
			if (!end) cout << "Tie Game!" << endl << endl;
			//play again?
			cout << "Play again?(y/n): ";
			cin >> cont;
			cin.ignore();
			system("cls");
		} while (cont == 'y' || cont == 'Y');
	}

	//resets board
	void ResetBoard() {
		Board[0][0] = '1'; Board[0][1] = '2'; Board[0][2] = '3';
		Board[1][0] = '4'; Board[1][1] = '5'; Board[1][2] = '6';
		Board[2][0] = '7'; Board[2][1] = '8'; Board[2][2] = '9';
	}

	//shows board
	void DrawGame() {
		cout << "Tic-Tac-Toe" << endl << endl
			<< "  " << Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << endl
			<< " ---|---|---" << endl
			<< "  " << Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << endl
			<< " ---|---|---" << endl
			<< "  " << Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << endl << endl;
	}

	//turn for 1 or 2 player and computer
	void turn(char player) {
		int inp;    //move input

					//run for user input player 1 or 2
		if (players == 2 || player == 'X') {
			//loop for valid input
			do {
				cout << player << " pick a space: ";
				cin >> inp;
				switch (inp) {
				case 1: x = 0; y = 0; break;
				case 2: x = 0; y = 1; break;
				case 3: x = 0; y = 2; break;
				case 4: x = 1; y = 0; break;
				case 5: x = 1; y = 1; break;
				case 6: x = 1; y = 2; break;
				case 7: x = 2; y = 0; break;
				case 8: x = 2; y = 1; break;
				case 9: x = 2; y = 2; break;
				default: cout << "Invalid Input" << endl;
				}
				//check if space is taken
				if (Board[x][y] < '1' || Board[x][y] > '9') {
					cout << "Space Taken!!" << endl;
				}
			} while ((inp < 1 || inp > 9) || (Board[x][y] < '1' || Board[x][y] > '9'));

			//log move, increment total moves
			log[iTotalMoves++] = inp;
		}

		//run for computer player
		if (players == 1 && player == 'O') {

			//check for winning move
			if (canwin('O')) {
			}
			//check to block
			else if (canwin('X')) {
			}
			//computer strategy
			else strategy();

			//increment total moves
			iTotalMoves++;
		}

		//save move, clear screen, draw board
		Board[x][y] = player;
		system("cls");
		DrawGame();

		//check for winner
		if ((Board[0][0] == player && Board[0][1] == player && Board[0][2] == player)
			|| (Board[1][0] == player && Board[1][1] == player && Board[1][2] == player)
			|| (Board[2][0] == player && Board[2][1] == player && Board[2][2] == player)
			|| (Board[0][0] == player && Board[1][0] == player && Board[2][0] == player)
			|| (Board[0][1] == player && Board[1][1] == player && Board[2][1] == player)
			|| (Board[0][2] == player && Board[1][2] == player && Board[2][2] == player)
			|| (Board[0][0] == player && Board[1][1] == player && Board[2][2] == player)
			|| (Board[2][0] == player && Board[1][1] == player && Board[0][2] == player)) {
			cout << "  " << player << " WINS!!!" << endl << endl;
			end = true;
		}
	}

	//computer strategy
	void strategy();

	//Checks every possibility for a winning move
	bool canwin(char);

	//moves to first open spot
	void cleaner();
};

/*******************************************
* Fuction Name: main()
* Parameters: None
* Return Value: int
* Purpose: Create GAME object and call play()
*******************************************/

int main() {
	GAME game;        //Tic-Tac-Toe

	game.play();    //play

	return 0;
}

//computer strategy
//makes specific moves based on player moves
//unfinished
void GAME::strategy() {
	//strategy if first move is a corner
	if (log[0] == 1 || log[0] == 3 || log[0] == 7 || log[0] == 9) {
		if (iTotalMoves == 1) {
			x = 1; y = 1; //5
		}
		//************
		else if (log[0] == 1 && log[2] == 6) {
			if (iTotalMoves == 3) {
				x = 0; y = 1;
			}
			if (log[4] == 8) {
				if (iTotalMoves == 5) {
					x = 2; y = 0;
				}
			}
		}
		else if (log[0] == 1 && log[2] == 8) {
			if (iTotalMoves == 3) {
				x = 1; y = 0;
			}
			if (log[4] == 6) {
				if (iTotalMoves == 5) {
					x = 0; y = 2;
				}
			}
		}
		else if (log[0] == 1 && log[2] == 9) {
			if (iTotalMoves == 3) {
				x = 0; y = 1;
			}
		}
		//************
		else if (log[0] == 3 && log[2] == 4) {
			if (iTotalMoves == 3) {
				x = 0; y = 1;
			}
			if (log[4] == 8) {
				if (iTotalMoves == 5) {
					x = 2; y = 2;
				}
			}
		}
		else if (log[0] == 3 && log[2] == 7) {
			if (iTotalMoves == 3) {
				x = 1; y = 0;
			}
		}
		else if (log[0] == 3 && log[2] == 8) {
			if (iTotalMoves == 3) {
				x = 1; y = 2;
			}
			if (log[4] == 4) {
				if (iTotalMoves == 5) {
					x = 0; y = 0;
				}
			}
		}
		else cleaner();
	}
	else if (log[0] == 2 || log[0] == 4) {
		if (iTotalMoves == 1) {
			x = 2; y = 2;
		}
		else cleaner();
	}
	else if (log[0] == 6 || log[0] == 8) {
		if (iTotalMoves == 1) {
			x = 0; y = 0;
		}
		else cleaner();
	}
	else if (log[0] == 5) { //done
		if (iTotalMoves == 1) {
			x = 0; y = 0;
		}
		else if (log[2] == 9) {
			if (iTotalMoves == 3) {
				x = 0; y = 2;
			}
		}
		else cleaner();
	}
}

//Move to first open spot
void GAME::cleaner() {
	if (Board[0][0] == '1') {
		x = 0; y = 0;
	}
	else if (Board[0][1] == '2') {
		x = 0; y = 1;
	}
	else if (Board[0][2] == '3') {
		x = 0; y = 2;
	}
	else if (Board[1][0] == '4') {
		x = 1; y = 0;
	}
	else if (Board[1][1] == '5') {
		x = 1; y = 1;
	}
	else if (Board[1][2] == '6') {
		x = 1; y = 2;
	}
	else if (Board[2][0] == '7') {
		x = 2; y = 0;
	}
	else if (Board[2][1] == '8') {
		x = 2; y = 1;
	}
	else if (Board[2][2] == '9') {
		x = 2; y = 2;
	}
	else {
		cout << "Cleaner failed!!" << endl;
		system("pause");
	}
}

//Checks every possibility for a winning move
bool GAME::canwin(char ch) {
	if (Board[0][0] == '1' && Board[0][1] == ch && Board[0][2] == ch) {
		x = 0; y = 0;
		return true;
	}
	if (Board[0][0] == ch && Board[0][1] == '2' && Board[0][2] == ch) {
		x = 0; y = 1;
		return true;
	}
	if (Board[0][0] == ch && Board[0][1] == ch && Board[0][2] == '3') {
		x = 0; y = 2;
		return true;
	}
	//*****
	if (Board[1][0] == '4' && Board[1][1] == ch && Board[1][2] == ch) {
		x = 1; y = 0;
		return true;
	}
	if (Board[1][0] == ch && Board[1][1] == '5' && Board[1][2] == ch) {
		x = 1; y = 1;
		return true;
	}
	if (Board[1][0] == ch && Board[1][1] == ch && Board[1][2] == '6') {
		x = 1; y = 2;
		return true;
	}
	//*******
	if (Board[2][0] == '7' && Board[2][1] == ch && Board[2][2] == ch) {
		x = 2; y = 0;
		return true;
	}
	if (Board[2][0] == ch && Board[2][1] == '8' &&  Board[2][2] == ch) {
		x = 2; y = 1;
		return true;
	}
	if (Board[2][0] == ch && Board[2][1] == ch && Board[2][2] == '9') {
		x = 2; y = 2;
		return true;
	}
	//*******************
	if (Board[0][0] == '1' && Board[1][0] == ch && Board[2][0] == ch) {
		x = 0; y = 0;
		return true;
	}
	if (Board[0][0] == ch && Board[1][0] == '4' && Board[2][0] == ch) {
		x = 1; y = 0;
		return true;
	}
	if (Board[0][0] == ch && Board[1][0] == ch && Board[2][0] == '7') {
		x = 2; y = 0;
		return true;
	}
	//****************
	if (Board[0][1] == '2' && Board[1][1] == ch && Board[2][1] == ch) {
		x = 0; y = 1;
		return true;
	}
	if (Board[0][1] == ch && Board[1][1] == '5' && Board[2][1] == ch) {
		x = 1; y = 1;
		return true;
	}
	if (Board[0][1] == ch && Board[1][1] == ch && Board[2][1] == '8') {
		x = 2; y = 1;
		return true;
	}
	//***************
	if (Board[0][2] == '3' && Board[1][2] == ch && Board[2][2] == ch) {
		x = 0; y = 2;
		return true;
	}
	if (Board[0][2] == ch && Board[1][2] == '6' && Board[2][2] == ch) {
		x = 1; y = 2;
		return true;
	}
	if (Board[0][2] == ch && Board[1][2] == ch && Board[2][2] == '9') {
		x = 2; y = 2;
		return true;
	}
	//************
	if (Board[0][0] == '1' && Board[1][1] == ch && Board[2][2] == ch) {
		x = 0; y = 0;
		return true;
	}
	if (Board[0][0] == ch && Board[1][1] == '5' && Board[2][2] == ch) {
		x = 1; y = 1;
		return true;
	}
	if (Board[0][0] == ch && Board[1][1] == ch && Board[2][2] == '9') {
		x = 2; y = 2;
		return true;
	}
	//************
	if (Board[0][2] == '3' && Board[1][1] == ch && Board[2][0] == ch) {
		x = 0; y = 2;
		return true;
	}
	if (Board[0][2] == ch && Board[1][1] == '5' && Board[2][0] == ch) {
		x = 1; y = 1;
		return true;
	}
	if (Board[0][2] == ch && Board[1][1] == ch && Board[2][0] == '7') {
		x = 2; y = 0;
		return true;
	}
	return false;
}
