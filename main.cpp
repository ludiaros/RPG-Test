#include <SFML/Window.hpp>

#include "globals.hpp"

#include "ResourceManager.hpp"
#include "WindowManager.hpp"
#include "GameScreenManager.hpp"
#include "GameScreenLoad.hpp"
#include "GameScreenConfig.hpp"
#include "GameScreenPlay.hpp"
#include "GameScreenPause.hpp"
#include "GameScreenOver.hpp"
#include "GameScreenWin.hpp"
#include "GameScreenReset.hpp"
#include "GameScreenCredits.hpp"
#include "GameScreenExit.hpp"

WindowManager     window;
GameScreenManager gstate;

int main() {

    //LOAD RESOURCES -------------------------------------------------------------------------------
    ResourceManager::addFont("mono", "data/font/DejaVuSansMono.ttf");
    ResourceManager::addFont("unique", "data/font/Unique.ttf");

    ResourceManager::addTexture("gui", "data/gfx/gui.png");
    ResourceManager::addTexture("cursor", "data/gfx/0/1.png");

    ResourceManager::addTexture("hero", "data/gfx/hero.png");
    ResourceManager::addTexture("tile0", "data/gfx/000.png");
    ResourceManager::addTexture("tile1", "data/gfx/001.png");
    ResourceManager::addTexture("tile2", "data/gfx/002.png");
    ResourceManager::addTexture("tile3", "data/gfx/003.png");
    ResourceManager::addTexture("tile4", "data/gfx/004.png");
    ResourceManager::addTexture("tile5", "data/gfx/005.png");
    ResourceManager::addTexture("tile6", "data/gfx/006.png");
    ResourceManager::addTexture("tile7", "data/gfx/007.png");
    ResourceManager::addTexture("tile8", "data/gfx/008.png");
    ResourceManager::addTexture("tile9", "data/gfx/009.png");
    //----------------------------------------------------------------------------------------------

    //INITIALIZE OPTIONS AND GAME DATA -------------------------------------------------------------
    window.gameInfo.maxEnemies = 2500;
    window.gameInfo.maxHeroes  = 5;
    //----------------------------------------------------------------------------------------------

    //INITIALIZE GAME STATES -----------------------------------------------------------------------
    gstate.addState(LOAD,    new GameScreenLoad());
    gstate.addState(CONFIG,  new GameScreenConfig());
    gstate.addState(PLAY,    new GameScreenPlay());
    gstate.addState(PAUSED,  new GameScreen());
    gstate.addState(RESET,   new GameScreen());
    gstate.addState(OVER,    new GameScreen());
    gstate.addState(WIN,     new GameScreen());
    gstate.addState(CREDITS, new GameScreen());
    gstate.addState(EXIT,    new GameScreenExit());
    /*
    gstate.addState(PAUSED,  new GameScreenPause());
    gstate.addState(RESET,   new GameScreenReset());
    gstate.addState(OVER,    new GameScreenOver());
    gstate.addState(WIN,     new GameScreenWin());
    gstate.addState(CREDITS, new GameScreenCredits());
    gstate.addState(EXIT,    new GameScreenExit());
    */
    gstate.currStatus = LOAD;
    //----------------------------------------------------------------------------------------------

    //MAIN LOOP-------------------------------------------------------------------------------------
    while (window.isOpen()) {

        window.handleWindowEvents(gstate.currStatus);

        gstate.getState()->handleEvents(window, gstate.currStatus);
        gstate.getState()->update(window, gstate.currStatus);
        gstate.getState()->draw(window, gstate.currStatus);

        //Modificar el GameScreenManager para que acepte:
        //nextStatus -> El valor que se pasa como referencia a cada GameScreen para que lo modifique
        //              pero la idea es que nose modifique dentro del GameScreen, sino en esta etapa
        //previousStatus -> Guarda un respaldo del estado anterior antes de cambiar el estado
        //currStatus -> El puntero que se va a usar realmente para direccionar los GameScreen
    }
    //----------------------------------------------------------------------------------------------

    return EXIT_SUCCESS;
}
