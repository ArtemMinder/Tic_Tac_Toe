#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "Tic_Tac_Toe.h"
#include <iostream>
#include <vector>
#include <random>
#include <regex>
#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>


namespace sc = boost::statechart;
namespace mpl = boost::mpl;

struct game_init :sc::event<game_init> {};
struct game_menu :sc::event<game_menu> {};
struct game_starting :sc::event<game_starting> {};
struct game_run :sc::event<game_run> {};
struct game_restart :sc::event<game_restart> {};
struct game_exit :sc::event<game_exit> {};

struct InitGame;
struct MenuGame;
struct StartingGame;
struct RunGame;
struct RestartGame;
struct ExitGame;

struct GameSM : sc::state_machine<GameSM, InitGame> {};

class Player {
public:
	Player() = default;
	void setName(std::string newName);
	std::string getName();
	void setSign(char newSign);
	char getSign() const;
private:
	std::string name{};
	char sign{};
};

class Board {
public:
	void setField(char newSign, int position);
	std::vector<char> getField();
	void showField() const;
	void clearField();
private:
	char a = ' ';
	std::vector<char> field = { a,a,a,a,a,a,a,a,a };
};

class Game {
public:
	void	start();
	void play(int priority);
	void makeMove(char sign, int move);
	void restart();
	void checkWin(char sign);
	void congratulation(char sign);
	bool checkAnswer(int var, std::string answer);

private:
	std::vector<Player> players{};
	Board board;
	bool mode{};
	bool rst = 0;
	GameSM sm;
};

#endif