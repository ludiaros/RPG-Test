#include "GameScreenManager.hpp"

GameScreenManager::GameScreenManager() {
}

void GameScreenManager::addState(int id, GameScreen* state) {

    listStates[id] = state;
}

void GameScreenManager::previousState() {

    currStatus = prevStatus;
}

void GameScreenManager::setState(unsigned int status) {

    prevStatus = currStatus;
    currStatus = status;
}

GameScreen* GameScreenManager::getState() {

    return listStates[currStatus];
}


