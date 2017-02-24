#include "GameSceneManager.hpp"

GameSceneManager::GameSceneManager() {
}

void GameSceneManager::addScene(int id, GameScene* scene) {

    listScenes[id] = scene;
}

void GameSceneManager::previousScene() {

    currScene = prevScene;
}

void GameSceneManager::setScene(unsigned int scene) {

    prevScene = currScene;
    currScene = scene;
}

GameScene* GameSceneManager::getScene() {

    return listScenes[currScene];
}


