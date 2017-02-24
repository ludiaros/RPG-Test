#include "GameSceneManager.hpp"

GameSceneManager::GameSceneManager() {
}

void GameSceneManager::addState(int id, GameScene* state) {

    listStates[id] = state;
}

void GameSceneManager::previousState() {

    currStatus = prevStatus;
}

void GameSceneManager::setState(unsigned int status) {

    prevStatus = currStatus;
    currStatus = status;
}

GameScene* GameSceneManager::getState() {

    return listStates[currStatus];
}


