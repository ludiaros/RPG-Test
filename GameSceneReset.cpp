#include "GameScreenReset.hpp"

GameScreenReset::GameScreenReset() {
    start = false;
    maxTimeActive = 2;
}

void GameScreenReset::handleEvents(WindowManager& window, unsigned int& status) {


    if (window.eventMap["VK_RETURN"]) {
        window.eventMap["VK_RETURN"] = false;
        start = false;
        status = PLAY;
    }
}

void GameScreenReset::update(WindowManager& window, unsigned int& status) {

    if (!start) {
        start = true;
        timeActive.restart();
    }

    if (timeActive.getElapsedTime().asSeconds() > maxTimeActive) {

        start = false;
        status = PLAY;
    }
}

void GameScreenReset::draw(WindowManager& window, unsigned int& status) {

    window.clear();
    window.drawText("Reset", "mono", 32, MIDCENTER, sf::Text::Regular, SCR_W/2, SCR_H/2);
    window.display();
}
