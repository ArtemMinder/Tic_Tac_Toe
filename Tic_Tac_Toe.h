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
	void setName(const std::string& newName);
	std::string getName() const;
	void setSign(const char& newSign);
	char getSign() const;
private:
	std::string name{};
	char sign{};
};

class Board {
public:
	Board();
	void setField(const char& newSign, const int& position);
	std::vector<char> getField()const;
	void showField() const;
	void clearField();
private:
	std::vector<char> field{};
};

class Game {
public:
	void	start();
	void play(int& priority);
	void makeMove(const char& sign, const int& move);
	void restart();
	void checkWin(const char& sign);
	void congratulation(const char& sign);
	bool validation(const int& var, const std::string& answer);
<<<<<<< HEAD
	bool noRepaint(const std::string& turn);
=======
>>>>>>> ede936a724db25a6ac0fda1ce9cbaaf52e2db9d6

private:
	std::vector<Player> players{};
	Board board;
	bool botMode = false;
	bool rst = false;
	GameSM sm;
};
#endif