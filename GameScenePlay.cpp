#include "GameScenePlay.hpp"

GameScenePlay::GameScenePlay() {
    world = WorldManager();
    cursor = Cursor();
    //players = PlayerManager();
    start = false;
}

void GameScenePlay::handleEvents(WindowManager& window, unsigned int& status) {

    window.eventMap["VK_UP"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    window.eventMap["VK_W"] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

    window.eventMap["VK_DOWN"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    window.eventMap["VK_S"] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    window.eventMap["VK_LEFT"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    window.eventMap["VK_A"] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);

    window.eventMap["VK_RIGHT"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    window.eventMap["VK_D"] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

    window.eventMap["VK_SPACE"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (window.getActionEvent("CANCEL")) {
        start = false;
        status = LOAD;
    }
    if (window.getActionEvent("ACCEPT")) {
        status = PAUSED;
    }
}

void GameScenePlay::update(WindowManager& window, unsigned int& status) {

    //Verifica si hay que reiniciar el juego o continuar con la ultima instancia
    if (!start) {

        srand(time(0));

        world.init();
        //world.reset(window);//Reinicia el mundo (posiciona las estrellas y asteroides)
        //gunsm.reset(window);
        //shipm.reset(window);//Reincia las naves (reinicia el estado y la posicion de cada nave)

        start = true;
    }

    window.restartClock();

    //Actualiza la logica --------------------------------------------------------------------------
    if (!window.paused) {

        world.update(window);

        //players.update(window, world);
        //enemies.update(window, world);

        //cursor.update(window);
    }

    // Verifica si hay game over o win -------------------------------------------------------------

}

void GameScenePlay::draw(WindowManager& window, unsigned int& status) {

    window.clear();
    window.resetView();
    //window.setCenter(players.players[players.m].getPosition());
    world.draw(window);

    //players.draw(window);
    //enemies.draw(window);

    //window.draw(cursor);

    window.setDefaultView();

    /*window.clear();
    window.resetView();
    window.view.setCenter(window.gameInfo.playerPosX, window.gameInfo.playerPosY);  //Hace que la camara siga a la nave
                                                                                    //controlada

    if (!window.rotationRef) { window.view.setRotation(0); }                        //Hace el angulo de la camara fijo
    else { window.view.setRotation(window.gameInfo.playerAngle); }                  //La camara rota siguiendo el
                                                                                    //angulo de la nave controlada

    */
    world.draw(window);
    //gunsm.draw(window);
    //shipm.draw(window);

    window.drawLimits();

    window.setDefaultView();

    window.drawFPS();

    window.display();
}
