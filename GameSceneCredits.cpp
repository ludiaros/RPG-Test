#include "GameScreenCredits.hpp"

GameScreenCredits::GameScreenCredits() {

    start = false;
    maxTimeActive = 3;
}

void GameScreenCredits::handleEvents(WindowManager& window, unsigned int& status) {

    if (window.eventMap["VK_RETURN"]) {
        window.eventMap["VK_RETURN"] = false;

        start = false;
        status = LOAD;
    }

    if (window.eventMap["VK_ESCAPE"]) {
        window.eventMap["VK_ESCAPE"] = false;

        status = EXIT;
    }
}

void GameScreenCredits::update(WindowManager& window, unsigned int& status) {

    if (!start) {
        start = true;
        timeActive.restart();
    }

    if (timeActive.getElapsedTime().asSeconds() > maxTimeActive) {

        start = false;
        status = LOAD;
    }
}

void GameScreenCredits::draw(WindowManager& window, unsigned int& status) {

    window.clear();
    window.drawText("SF-SpaceG (WIP)", "unique", 64, MIDCENTER, sf::Text::Bold, SCR_W/2, 150);
    window.drawText("<A SFML Game by LuDiArOs>", "unique", 32, MIDCENTER, sf::Text::Regular, SCR_W/2, 225);
    window.drawText("Here goes the credits", "mono", 32, MIDCENTER, sf::Text::Bold, SCR_W/2, 300);
    window.drawText("Press ENTER to return, ESC to exit", "mono", 32, MIDCENTER, sf::Text::Regular, SCR_W/2, 400);
    window.drawText("It returns to GameScreenLoad", "mono", 32, MIDCENTER, sf::Text::Regular, SCR_W/2, 450);
    window.drawText("automatically after 3 seconds", "mono", 32, MIDCENTER, sf::Text::Regular, SCR_W/2, 500);
    window.display();
}
