#include "GameSceneLoad.hpp"

GameSceneLoad::GameSceneLoad() {

    cursor = 0;

    guiImages = sf::Sprite();
    guiImages.setTexture(*ResourceManager::getTexture("gui"));

    guiLogo = sf::IntRect(0, 0, 512, 168);

    clickArea.push_back(   sf::IntRect(SCR_W/2-64, 400-16, 128, 32));
    iconActive.push_back(  sf::IntRect(  0, 200, 128, 32));
    iconInactive.push_back(sf::IntRect(  0, 168, 128, 32));
    menuOptions.push_back("[  Play  ]");
    newStatus.push_back(PLAY);

    clickArea.push_back(   sf::IntRect(SCR_W/2-64, 450-16, 128, 32));
    iconActive.push_back(  sf::IntRect(128, 200, 128, 32));
    iconInactive.push_back(sf::IntRect(128, 168, 128, 32));
    menuOptions.push_back("[ Config ]");
    newStatus.push_back(CONFIG);

    clickArea.push_back(   sf::IntRect(SCR_W/2-64, 500-16, 128, 32));
    iconActive.push_back(  sf::IntRect(256, 200, 128, 32));
    iconInactive.push_back(sf::IntRect(256, 168, 128, 32));
    menuOptions.push_back("[  Info  ]");
    newStatus.push_back(CREDITS);

    clickArea.push_back(   sf::IntRect(SCR_W/2-64, 550-16, 128, 32));
    iconActive.push_back(  sf::IntRect(384, 200, 128, 32));
    iconInactive.push_back(sf::IntRect(384, 168, 128, 32));
    menuOptions.push_back("[  Exit  ]");
    newStatus.push_back(EXIT);
}

void GameSceneLoad::handleEvents(WindowManager& window, unsigned int& status) {

    mousePos = sf::Mouse::getPosition(window);

    for (std::size_t i=0; i<menuOptions.size(); i++) {

        if (clickArea[i].contains(mousePos.x, mousePos.y)) {

            cursor = i;

            if (window.getActionEvent("LCLICK")) {
                status = newStatus[cursor];
            }
        }
    }

    if (window.getActionEvent("DOWN")) {
        cursor = (cursor < menuOptions.size() - 1 ? cursor + 1 : 0);
    }

    if (window.getActionEvent("UP")) {
        cursor = (cursor > 0 ? cursor - 1 : menuOptions.size() - 1);
    }

    if (window.getActionEvent("CANCEL")) {
        status = LOAD;
    }

    if (window.getActionEvent("ACCEPT")) {
        status = newStatus[cursor];
    }
}

void GameSceneLoad::update(WindowManager& window, unsigned int& status) {
}

void GameSceneLoad::draw(WindowManager& window, unsigned int& status) {

    window.clear();

    guiImages.setTextureRect(guiLogo);
    guiImages.setOrigin(guiImages.getLocalBounds().width/2, guiImages.getLocalBounds().height/2);
    guiImages.setPosition(SCR_W/2, 150);
    window.draw(guiImages);

    window.drawText("MAIN MENU", "mono", 24, MC, sf::Text::Bold, SCR_W/2, 300, sf::Color::White);

    for (std::size_t i=0; i<menuOptions.size(); i++) {
        if (i == cursor) {
            guiImages.setTextureRect(iconActive[i]);
        }
        else {
            guiImages.setTextureRect(iconInactive[i]);
        }
        guiImages.setOrigin(guiImages.getLocalBounds().width/2, guiImages.getLocalBounds().height/2);
        guiImages.setPosition(SCR_W/2, 400 + (i * 50));
        window.draw(guiImages);
    }

    window.display();
}
