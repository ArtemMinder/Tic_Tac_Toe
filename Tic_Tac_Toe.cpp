#include "Tic_Tac_Toe.h"



struct InitGame :sc::simple_state<InitGame, GameSM> {
	InitGame() { std::cout << "\t\t\t\t*IN INIT STATE...*" << std::endl; }
	typedef sc::transition<game_menu, MenuGame>reactions;
};
struct MenuGame :sc::simple_state<MenuGame, GameSM> {
	MenuGame() { std::cout << "\t\t\t\t*IN MENU STATE...*" << std::endl; }
	typedef mpl::list< sc::transition<game_starting, StartingGame>,
		sc::transition<game_menu, MenuGame>,
		sc::transition<game_exit, ExitGame> > reactions;

};
struct StartingGame :sc::simple_state<StartingGame, GameSM> {
	StartingGame() { std::cout << "\t\t\t\t*IN STARTING STATE...*" << std::endl; }
	typedef sc::transition<game_run, RunGame>reactions;
};
struct RunGame :sc::simple_state<RunGame, GameSM> {
	RunGame() { std::cout << "\t\t\t\t*IN RUNNING STATE...*" << std::endl; }
	typedef mpl::list< sc::transition<game_restart, RestartGame>,
		sc::transition<game_run, RunGame> > reactions;
};
struct RestartGame :sc::simple_state<RestartGame, GameSM> {
	RestartGame() { std::cout << "\t\t\t\t*IN RESTARTING STATE...*" << std::endl; }
	typedef sc::transition<game_menu, MenuGame>reactions;
};
struct ExitGame :sc::simple_state<ExitGame, GameSM> {
	ExitGame() { std::cout << "\t\t\t\t*IN EXITING STATE...*" << std::endl; }
	typedef sc::transition<game_menu, MenuGame>reactions;
};



void Player::setName(std::string newName) {
	name = newName;
}
std::string Player::getName() {
	return name;
}
void Player::setSign(char newSign) {
	sign = newSign;
}
char Player::getSign() const {
	return sign;
}


void Board::setField(char newSign, int position) {
	field[position] = newSign;
}
std::vector<char> Board::getField() {
	return field;
}
void Board::showField() const {
	std::cout << "                     [" << field[0] << "]" << "[" << field[1] << "]" << "[" << field[2]
		<< "]" << "\n" << "                     [" << field[3] << "]" << "[" << field[4] << "]"
		<< "[" << field[5] << "]" << "\n" << "                     [" << field[6] << "]" << "[" << field[7]
		<< "]" << "[" << field[8] << "]" << std::endl;
}
void Board::clearField() {
	field = { a,a,a,a,a,a,a,a,a };
}

void Game::start() {
	int priority{};
	int answer{};

	sm.initiate();
	std::string first{};
	std::string second{};
	Player player1;
	players.push_back(player1);
	Player player2;
	players.push_back(player2);
	if (rst == 0) {
		sm.process_event(game_init());
	}
	else if (rst == 1) {
		sm.process_event(game_restart());
	}

	std::cout << "XXXXXXX       XXXXXXX                  OOOOOOOOO     " << '\n'
		<< "X:::::X       X:::::X                OO:::::::::OO   " << '\n'
		<< "X:::::X       X:::::X              OO:::::::::::::OO " << '\n'
		<< "X::::::X     X::::::X             O:::::::OOO:::::::O" << '\n'
		<< "XXX:::::X   X:::::XXX             O::::::O   O::::::O" << '\n'
		<< "   X:::::X X:::::X                O:::::O     O:::::O" << '\n'
		<< "    X:::::X:::::X                 O:::::O     O:::::O" << '\n'
		<< "     X:::::::::X                  O:::::O     O:::::O" << '\n'
		<< "     X:::::::::X                  O:::::O     O:::::O" << '\n'
		<< "    X:::::X:::::X                 O:::::O     O:::::O" << '\n'
		<< "   X:::::X X:::::X                O:::::O     O:::::O" << '\n'
		<< "XXX:::::X   X:::::XXX             O::::::O   O::::::O" << '\n'
		<< "X::::::X     X::::::X             O:::::::OOO:::::::O" << '\n'
		<< "X:::::X       X:::::X              OO:::::::::::::OO " << '\n'
		<< "X:::::X       X:::::X                OO:::::::::OO   " << '\n'
		<< "XXXXXXX       XXXXXXX                  OOOOOOOOO     " << '\n';
	std::cout << std::endl;
	std::cout << "                       Welcome to game" << std::endl;
	sm.process_event(game_menu());
	std::cout << "                         *GAME MENU*" << std::endl;
	std::cout << "               If You want to exit - press 2" << std::endl;
	if (rst == 0) {
		std::cout << "         Select game mode: For two(1)/With computer(0)" << std::endl;
		std::cin >> answer;
		//while (!(checkAnswer(1, answer)) || std::cin.fail()) { std::cin >> answer;}
	}
	else {
		std::cout << "         You have an unfinished game, do You want to continue? Yes(1)/No(0)" << std::endl;
		std::cin >> answer;
		//while (!(checkAnswer(1, answer))||std::cin.fail()) { std::cin >> answer; }
		if (answer) {
			if (answer == 2) {
				sm.process_event(game_exit());
				exit(0);
			}
			system("cls");
			play(priority);
		}
		else if (answer == 2) {
				sm.process_event(game_exit());
				exit(0);
			rst = 0;
			restart();
			if (answer == 0) {
				start();
			}
		}
		else if (answer == 0) {
			system("cls");
			rst = 0;
			start();
		}
	}
	if (answer == 2) {
		sm.process_event(game_exit());
		exit(0);
	}
	if (!answer) {
		std::cout << "         Enter your name: ";
		std::cin >> first;
		players[0].setName(first);
		players[1].setName("Computer");
		mode = true;
		answer = true;
		system("cls");
	}
	else {
		std::cout << "         Enter the name of 1st player: ";
		std::cin >> first;
		std::cout << "         Enter the name of 2nd player: ";
		std::cin >> second;
		players[0].setName(first);
		players[1].setName(second);
		std::random_device dev;
		std::mt19937 engine(dev());
		std::uniform_int_distribution<int> uid(0, 1);
		priority = uid(engine);

		std::cout << players[priority].getName() << ", you are lucky to pick a sign first, choose your sign.  X(1)/O(0):";
		std::cin >> answer;
		//while (!(checkAnswer(2, answer))) { std::cin >> answer; }
		system("cls");
		if (answer) {
			players[priority].setSign('X');

		}
		else {
			players[priority].setSign('O');

		}
		if (priority == 0) {
			priority = 1;

		}
		else if (priority == 1) {
			priority = 0;
		}
		if (answer) {
			players[priority].setSign('O');
		}
		else { players[priority].setSign('X'); }
	}

	play(priority);
}
void Game::play(int priority) {
	bool answer{};
	char sign{};
	int turn{};
	if (priority == 0) {
		priority = 1;
	}
	else if (priority == 1) { priority = 0; }
	sm.process_event(game_starting());
	std::cout << "XXXXXXX       XXXXXXX                  OOOOOOOOO     " << '\n'
		<< "X:::::X       X:::::X                OO:::::::::OO   " << '\n'
		<< "X:::::X       X:::::X              OO:::::::::::::OO " << '\n'
		<< "X::::::X     X::::::X             O:::::::OOO:::::::O" << '\n'
		<< "XXX:::::X   X:::::XXX             O::::::O   O::::::O" << '\n'
		<< "   X:::::X X:::::X                O:::::O     O:::::O" << '\n'
		<< "    X:::::X:::::X                 O:::::O     O:::::O" << '\n'
		<< "     X:::::::::X                  O:::::O     O:::::O" << '\n'
		<< "     X:::::::::X                  O:::::O     O:::::O" << '\n'
		<< "    X:::::X:::::X                 O:::::O     O:::::O" << '\n'
		<< "   X:::::X X:::::X                O:::::O     O:::::O" << '\n'
		<< "XXX:::::X   X:::::XXX             O::::::O   O::::::O" << '\n'
		<< "X::::::X     X::::::X             O:::::::OOO:::::::O" << '\n'
		<< "X:::::X       X:::::X              OO:::::::::::::OO " << '\n'
		<< "X:::::X       X:::::X                OO:::::::::OO   " << '\n'
		<< "XXXXXXX       XXXXXXX                  OOOOOOOOO     " << '\n';
	std::cout << std::endl;
	sm.process_event(game_run());
	std::cout << "                If You go to menu - press 9" << std::endl;
	board.showField();
	if (mode == false) {
		for (auto i = 0; i < 9; i++) {
			std::cout << "               " << players[priority].getName() << ", your turn: ";
			std::cin >> turn;
			//while (!(checkAnswer(3, turn))) { std::cin >> turn; }
			if (turn == 9)
			{
				system("cls");
				rst = 1;
				if (priority == 1) {
					priority = 0;
				}
				else if (priority == 0) {
					priority = 1;
				}

				restart();
			}
			sign = players[priority].getSign();
			if (sign == 'X') {

				makeMove('X', turn);
				board.showField();
				checkWin('X');
			}
			else {
				makeMove('O', turn);
				board.showField();
				checkWin('O');
			}
			if (priority == 1) {
				priority = 0;
			}
			else if (priority == 0) {
				priority = 1;
			}

		}
		std::cout << "                  No one won" << std::endl;
		std::cout << "         Do you want to play again? Yes(1)/No(0)";
		std::cin >> answer;
		//while (!(checkAnswer(4, answer))) { std::cin >> answer; }
		if (answer) {
			restart();
		}
		else {

			sm.process_event(game_exit());
			exit(0);
		}
	}
	else {

		for (auto i = 0; i < 4; i++) {
			std::cout << "      " << players[0].getName() << ", your turn: ";
			std::cin >> turn;
			//while (!(checkAnswer(3, turn))) { std::cin >> turn; }
			if (turn == 9) {
				system("cls");
				rst = 1;
				if (priority == 1) {
					priority = 0;
				}
				else if (priority == 0) {
					priority = 1;
				}
				restart();
			}
			sign = players[0].getSign();
			makeMove('X', turn);
			board.showField();
			checkWin('X');
			std::cout << "               " << players[1].getName() << "'s turn" << std::endl;
			std::vector<char> fields = board.getField();
			std::vector<char> free{};
			for (auto i = 0; i < 9; i++) {
				if (fields[i] != 'X' && fields[i] != 'O') {
					free.push_back(i);
				}
			}
			std::random_device dev;
			std::mt19937 engine(dev());
			std::uniform_int_distribution<size_t> uid(0, free.size());
			sign = players[1].getSign();
			makeMove('O', free[uid(engine)]);
			board.showField();
			checkWin('O');
		}
		std::cout << "                " << players[0].getName() << ", your turn" << std::endl;
		std::cin >> turn;
		sign = players[0].getSign();
		makeMove('X', turn);
		board.showField();
		checkWin('X');
	}
	std::cout << "                  No one won" << std::endl;
	std::cout << "         Do you want to play again? Yes(1)/No(0)";
	std::cin >> answer;
	//while (!(checkAnswer(4, answer))) { std::cin >> answer; }
	if (answer) {
		restart();
	}
	else {
		sm.process_event(game_exit());
		exit(0);
	}
}

void Game::makeMove(char sign, int move) {
	board.setField(sign, move);
}

void Game::restart() {
	if (rst == 0) {
		board.clearField();
	}
	rst = 1;
	system("cls");
	start();
}
void Game::checkWin(char sign) {
	auto moves = board.getField();
	if (moves[0] == moves[1] && moves[1] == moves[2] && moves[0, 1, 2] != ' ') {
		congratulation(sign);
	}
	else if (moves[3] == moves[4] && moves[4] == moves[5] && moves[3, 4, 5] != ' ') {
		congratulation(sign);
	}
	else if (moves[6] == moves[7] && moves[7] == moves[8] && moves[6, 7, 8] != ' ') {
		congratulation(sign);
	}
	else if (moves[0] == moves[3] && moves[3] == moves[6] && moves[0, 3, 6] != ' ') {
		congratulation(sign);
	}
	else if (moves[1] == moves[4] && moves[4] == moves[7] && moves[1, 4, 7] != ' ') {
		congratulation(sign);
	}
	else if (moves[2] == moves[5] && moves[5] == moves[8] && moves[2, 5, 8] != ' ') {
		congratulation(sign);
	}
	else if (moves[0] == moves[4] && moves[4] == moves[8] && moves[0, 4, 8] != ' ') {
		congratulation(sign);
	}
	else if (moves[2] == moves[4] && moves[4] == moves[6] && moves[2, 4, 6] != ' ') {
		congratulation(sign);
	}
}
void Game::congratulation(char sign) {
	bool answer{};
	if (sign == 'X') {
		std::cout << "         X - Wins!" << std::endl;
	}
	else {
		std::cout << "         O - Wins!" << std::endl;
	}
	std::cout << "         Do you want to play again? Yes(1)/No(0): ";
	std::cin >> answer;
	//while (!(checkAnswer(4, answer))) { std::cin >> answer; }
	if (answer) {
		restart();
	}
	else {
		sm.process_event(game_exit());
		exit(0);
	}
}
bool Game::checkAnswer(int var, std::string answer) {
	switch (var) {
	case 1: {
			const std::regex myRegex1("[0-2]");
			if (!(std::regex_match(answer, myRegex1))) {
				std::cout << "Incorrect answer\n";
				return false;
			}
			else return true;
			break;
		}
	case 2:  {
			const std::regex myRegex2("[0-1]");
			if (!(std::regex_match(answer, myRegex2))) {
				std::cout << "Incorrect answer\n";
				return false;
			}
			else return true;
			break;
		}
	case 3: {
			const std::regex myRegex3("[0-9]");
			if (!(std::regex_match(answer, myRegex3))) {
				std::cout << "Incorrect answer\n";
				return false;
			}
			else return true;
			break;
		}
	case 4:  {
			const std::regex myRegex4("[0,1,9]");
			if (!(std::regex_match(answer, myRegex4))) {
				std::cout << "Incorrect answer\n";
				break;
			}
			else return true;
			break;
		}
	}
	
}

