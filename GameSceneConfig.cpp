#include "GameSceneConfig.hpp"

GameSceneConfig::GameSceneConfig() {

    cursor = 0;

    clickArea.push_back(sf::IntRect(600, 385, 160, 40));
    menuOptions.push_back("[  Back  ]");
    newStatus.push_back(LOAD);
}

void GameSceneConfig::handleEvents(WindowManager& window, unsigned int& status) {

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

void GameSceneConfig::update(WindowManager& window, unsigned int& status) {
}

void GameSceneConfig::draw(WindowManager& window, unsigned int& status) {

    window.clear();

    window.drawText("Ivernia Legend (WIP)", "unique", 64, MC, sf::Text::Bold, SCR_W/2, 150, sf::Color::White);
    window.drawText("<A SFML Game by LuDiArOs>", "unique", 32, MC, sf::Text::Regular, SCR_W/2, 225, sf::Color::White);
    window.drawText("CONFIGURATION MENU", "mono", 32, MC, sf::Text::Bold, SCR_W/2, 300, sf::Color::White);

    for (std::size_t i=0; i<menuOptions.size(); i++) {
        if (i == cursor) {
            window.drawText(
                menuOptions[i],
                "mono",
                24,
                MC,
                sf::Text::Regular,
                SCR_W/2,
                400 + (i * 50),
                sf::Color(128, 128, 128, 255)
            );
        }
    }

    /*sf::RectangleShape r;
    r.setSize(sf::Vector2f(clickArea[cursor].width, clickArea[cursor].height));
    r.setPosition(clickArea[cursor].left, clickArea[cursor].top);
    r.setFillColor(sf::Color(128, 255, 128, 128));*/

    //window.draw(r);

    window.display();
}
