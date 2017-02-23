#include "GameScreenExit.hpp"

GameScreenExit::GameScreenExit() {
}

void GameScreenExit::handleEvents(WindowManager& window, unsigned int& status) {
}

void GameScreenExit::update(WindowManager& window, unsigned int& status) {
    //Guardar estados, liberar recursos...
    window.close();
}

void GameScreenExit::draw(WindowManager& window, unsigned int& status) {
}
