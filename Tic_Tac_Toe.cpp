#include "Tic_Tac_Toe.h"
#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include "QApplication"




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



void  Player::setName(const std::string& newName) {
    name = newName;
}
std::string Player::getName() const {
    return name;
}
void Player::setSign(const char& newSign) {
    sign = newSign;
}
char Player::getSign() const {
    return sign;
}


Board::Board() {
    std::vector<char> init(9, ' ');
    field = init;
}

void Board::setField(const char& newSign, const int& position) {
    field[position] = newSign;
}
std::vector<char> Board::getField() const {
    return field;
}
void Board::showField() const {
    std::cout << "                     [" << field[0] << "]" << "[" << field[1] << "]" << "[" << field[2]
        << "]" << "\n" << "                     [" << field[3] << "]" << "[" << field[4] << "]"
        << "[" << field[5] << "]" << "\n" << "                     [" << field[6] << "]" << "[" << field[7]
        << "]" << "[" << field[8] << "]" << std::endl;
}
void Board::clearField() {
    std::vector<char> init(9, ' ');
    field = init;
}

void Game::start() {
    int priority{};
    std::string answer{};
    sm.initiate();
    std::string first{};
    std::string second{};
    Player player1;
    players.push_back(player1);
    Player player2;
    players.push_back(player2);
    if (!rst) {
        sm.process_event(game_init());
    }
    else if (rst) {
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
    if (!rst) {
        std::cout << "         Select game mode: For two(1)/With computer(0)" << std::endl;
        setting.exec();
        answer=setting.getMode();
        while (!validation(1, answer)) { std::cin>>answer;}
        std::cout<<answer<<"\n";
        if (answer == "2") {
            sm.process_event(game_exit());
            exit(0);
        }
        else if (answer == "0") {
            std::cout << "         Enter your name: ";
            //std::cin >> first;
            first = setting.getFirstName();
            gamewindow.getFirst(first);
            std::cout <<first<<"\n";
            players[0].setName(first);
            players[1].setName("Computer");
            gamewindow.getSecond("Computer");
            botMode = Mods::multiPlayer;
            system("cls");
        }
        else if (answer == "1"){
            std::cout << "         Enter the name of 1st player: ";
             first = setting.getFirstName();
             gamewindow.getFirst(first);
            std::cout <<first<<"\n";
            std::cout << "         Enter the name of 2nd player: ";
             second = setting.getSecondName();
             gamewindow.getSecond(second);
             std::cout <<second<<"\n";
            players[0].setName(first);
            players[1].setName(second);
            std::random_device dev;
            std::mt19937 engine(dev());
            std::uniform_int_distribution<int> uid(0, 1);
            priority = uid(engine);
            std::cout<<priority;
            gamewindow.getSelector(players[priority].getName());
            std::cout << players[priority].getName() << ", you are lucky to pick a sign first, choose your sign.  X(1)/O(0):\n";
            gamewindow.exec();
            answer = gamewindow.getSign();
            std::cout<<answer<<"\n";
            while (!validation(2, answer)) {
                std::cin >> answer;
            }
            system("cls");
            if (answer!="0") {
                players[priority].setSign(Figures::cross);
            }
            else {
                players[priority].setSign(Figures::zeros);
            }
            if (priority == 0) {
                priority = 1;
            }
            else if (priority == 1) {
                priority = 0;
            }
            if (answer != "0") {
                players[priority].setSign(Figures::zeros);
            }
            else { players[priority].setSign(Figures::cross); }
        }
    }
    else if (rst){
        std::cout << "         You have an unfinished game, do You want to continue? Yes(1)/No(0)" << std::endl;
        //std::cin >> answer;
        answer = setting.restart();
        while (!validation(1, answer)) { std::cin >> answer; }
        if (answer == "1") {
            system("cls");
            play(priority);
        }
        else if (answer == "2") {
            sm.process_event(game_exit());
            exit(0);
        }
        else if (answer == "0") {
            system("cls");
            board.clearField();
            gamewindow.clearField();
            rst = false;
            start();
        }
    }
    play(priority);
}
void Game::play(int& priority) {
    std::string answer{};
    char sign{};
    int turn = 0;
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
    if (botMode == Mods::singlePlayer) {
        for (auto i = 0; i < 9; i++) {
            std::cout << "               " << players[priority].getName() << ", your turn: ";
            //std::cin >> answer;
            gamewindow.exec();
            answer = gamewindow.getMove();
            while (!validation(3, answer) || !noRepaint(answer)) {std::cin >> answer; }
            turn = std::stoi(answer);
            if (turn == 9){
                system("cls");
                rst = true;
                if (priority == 1) {
                    priority = 0;
                }
                else if (priority == 0) {
                    priority = 1;
                }
                restart();
            }
            sign = players[priority].getSign();
            if (sign == Figures::cross) {

                makeMove(Figures::cross, turn);
                board.showField();
                checkWin(Figures::cross);
            }
            else {
                makeMove(Figures::zeros, turn);
                board.showField();
                checkWin(Figures::zeros);
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
        //std::cin >> answer;
        win.winner("1");
        win.exec();
        board.clearField();
        gamewindow.clearField();
        answer = win.again();
        while (!validation(4, answer)) { std::cin >> answer; }
        if (answer!="0") {
            restart();
        }
        else {
            sm.process_event(game_exit());
            exit(0);
        }
    } else {
            gamewindow.botPresrt();
            for (auto i = 0; i < 4; i++) {
            std::cout << "      " << players[0].getName() << ", your turn: ";
            //std::cin >> answer;
            gamewindow.exec();
            answer = gamewindow.getMove();
            while (!validation(3, answer) || !noRepaint(answer)) { std::cin >> answer; }
            turn = std::stoi(answer);
            if (turn == 9) {
                system("cls");
                rst = true;
                if (priority == 1) {
                    priority = 0;
                }
                else if (priority == 0) {
                    priority = 1;
                }
                botMode = Mods::singlePlayer; //*****
                restart();
            }
            sign = players[0].getSign();
            makeMove(Figures::cross, turn);
            board.showField();
            checkWin(Figures::cross);
            std::cout << "               " << players[1].getName() << "'s turn" << std::endl;
            std::vector<char> fields = board.getField();
            std::vector<int> free{};
            for (auto i = 0; i <= 8; i++) {
                if (fields[i] != Figures::cross && fields[i] != Figures::zeros) {
                    free.push_back(i);
                }
            }
            std::random_device dev;
            std::mt19937 engine(dev());
            std::uniform_int_distribution<size_t> uid(0, free.size());
            sign = players[1].getSign();
            int turn = free[uid(engine)];
            makeMove(Figures::zeros, turn);

            std::cout<<turn;
            gamewindow.botMove(turn);
            board.showField();
            checkWin(Figures::zeros);
        }
        std::cout << "                " << players[0].getName() << ", your turn" << std::endl;
       // std::cin >> answer;
        gamewindow.exec();
        answer = gamewindow.getMove();
        while (!validation(3, answer) || !noRepaint(answer)) { std::cin >> answer; }
        turn = std::stoi(answer);
        sign = players[0].getSign();
        makeMove(Figures::cross, turn);
        board.showField();
        checkWin(Figures::cross);
    }
    std::cout << "                  No one won" << std::endl;
    std::cout << "         Do you want to play again? Yes(1)/No(0)";
    //std::cin >> answer;
    win.winner("1");
    win.exec();
    board.clearField();
    gamewindow.clearField();
    answer = win.again();
    while (!validation(4, answer)) { std::cin >> answer; }
    if (answer != "0") {
        restart();
    }
    else {
        sm.process_event(game_exit());
        exit(0);
    }
}

void Game::makeMove(const char& sign, const int& move) {
    board.setField(sign, move);
}

void Game::restart() {
    if (rst == false) {
        board.clearField();
        gamewindow.clearField();
    }
    rst = true;
    system("cls");
    start();
}
void Game::checkWin(const char& sign) {
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
void Game::congratulation(const char& sign) {
    std::string answer{};
    if (sign == Figures::cross) {
        win.winner("X");
        win.exec();
        std::cout << "         X - Wins!" << std::endl;
    }
    else {
        win.winner("O");
        win.exec();
        std::cout << "         O - Wins!" << std::endl;
    }
    std::cout << "         Do you want to play again? Yes(1)/No(0): ";
   // std::cin >> answer;
    board.clearField();
    gamewindow.clearField();
    answer = win.again();

    while (!validation(4, answer)) { std::cin >> answer; }
    if (answer != "0") {
        restart();
    }
    else {
        sm.process_event(game_exit());
        exit(0);
    }
}
bool Game::validation(const int& var, const std::string& answer) {
    switch (var) {
        case 1: {
            const std::regex myRegex2("[0,1,2]");
            if (std::cin.fail()) {
                std::cout << "Incorrect answer. You can enter [1] or [0] for choose game mode or [2] for exit.\n";
                return false;
            }
            else {
                if (std::regex_match(answer, myRegex2)) {
                    return true;
                }
                else {
                    std::cout << "Incorrect answer.You can enter[1] or [0] for choose game mode or [2] for exit.\n";
                    return false;
                }
            }
        }
        case 2: {
            const std::regex myRegex2("[0,1]");
            if (std::cin.fail()) {
                std::cout << "Incorrect answer .You can enter[1] or [0] for choose Your sign.\n";
                return false;
            }
            else {
                if (std::regex_match(answer, myRegex2)) {
                    return true;
                }
                else {
                    std::cout << "Incorrect answer .You can enter[1] or [0] for choose Your sign.\n";
                    return false;
                }
            }
        }
        case 3: {
            const std::regex myRegex2("[0-9]");
            if (std::cin.fail()) {
                std::cout << "Incorrect answer. You can enter [0-8] for make a move or [9] for enter game menu.\n";
                return false;
            }
            else {
                if (std::regex_match(answer, myRegex2)) {
                    return true;
                }
                else {
                    std::cout << "Incorrect answer. You can enter [0-8] for make a move or [9] for enter game menu.\n";
                    return false;
                }
            }
        }
        case 4: {
            const std::regex myRegex2("[0,1,9]");
            if (std::cin.fail()) {
                std::cout << "Incorrect answer. You can enter [1] for play again, [0] for finish game or [9] for enter game menu.\n";
                return false;
            }
            else {
                if (std::regex_match(answer, myRegex2)) {
                    return true;
                }
                else {
                    std::cout << "Incorrect answer. You can enter [1] for play again, [0] for finish game or [9] for enter game menu.\n";
                    return false;
                }

            }
        }
        default:
            return false;
    }
}
bool Game::noRepaint(const std::string& answer) {
    if (answer == "9") { return true; }
    int turn = std::stoi(answer);
    if (board.getField()[turn] != Figures::cross && board.getField()[turn] != Figures::zeros) {
        return true;
    }
    else {
        std::cout << "This move has already been made, select a free cell.\n";
        return false;
    }
}
