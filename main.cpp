#include <SFML/Window.hpp>

#include "globals.hpp"

#include "ResourceManager.hpp"
#include "WindowManager.hpp"
#include "GameSceneManager.hpp"
//#include "GameSceneLoad.hpp"
//#include "GameSceneConfig.hpp"
#include "GameScenePlay.hpp"
//#include "GameScenePause.hpp"
//#include "GameSceneOver.hpp"
//#include "GameSceneWin.hpp"
//#include "GameSceneReset.hpp"
//#include "GameSceneCredits.hpp"
//#include "GameSceneExit.hpp"

WindowManager       window;
GameSceneManager    scenes;

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

    //ResourceManager::addSound("sound0", "data/sound/000.ogg")
    //----------------------------------------------------------------------------------------------

    //INITIALIZE GAME SCENES -----------------------------------------------------------------------
    /*scenes.addScene(LOAD,    new GameSceneLoad());
    scenes.addScene(CONFIG,  new GameSceneConfig());
    scenes.addScene(PLAY,    new GameScenePlay());
    scenes.addScene(PAUSED,  new GameScene());
    scenes.addScene(RESET,   new GameScene());
    scenes.addScene(OVER,    new GameScene());
    scenes.addScene(WIN,     new GameScene());
    scenes.addScene(CREDITS, new GameScene());
    scenes.addScene(EXIT,    new GameSceneExit());*/

    scenes.setStatus(LOAD);
    //----------------------------------------------------------------------------------------------

    //INITIALIZE WORLD AND ENTITIES-----------------------------------------------------------------
    //----------------------------------------------------------------------------------------------

    //MAIN LOOP-------------------------------------------------------------------------------------
    while (window.isOpen()) {

        window.handleWindowEvents(scenes.currStatus);

        scenes.getScene()->handleInput(window, scenes.currStatus);
        scenes.getScene()->update(window, scenes.currStatus);
        scenes.getScene()->draw(window, scenes.currStatus);

        //Modificar el GameSceneManager para que acepte:
        //nextStatus -> El valor que se pasa como referencia a cada GameScene para que lo modifique
        //              pero la idea es que nose modifique dentro del GameScene, sino en esta etapa
        //previousStatus -> Guarda un respaldo del estado anterior antes de cambiar el estado
        //currStatus -> El puntero que se va a usar realmente para direccionar los GameScene
    }
    //----------------------------------------------------------------------------------------------

    return EXIT_SUCCESS;
}
