#include "GameSceneExit.hpp"

GameSceneExit::GameSceneExit() {
}

void GameSceneExit::handleEvents(WindowManager& window, unsigned int& status) {
}

void GameSceneExit::update(WindowManager& window, unsigned int& status) {
    //Guardar estados, liberar recursos...
    window.close();
}

void GameSceneExit::draw(WindowManager& window, unsigned int& status) {
}
