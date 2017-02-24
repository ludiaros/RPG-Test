#ifndef GAMEPAUSE_HPP
#define GAMEPAUSE_HPP

#include "globals.hpp"
#include "GameScene.hpp"
#include "WindowManager.hpp"

class GameScenePause : public GameScene {

    public:
        //Constructors
        GameScenePause();
        //Methods
        virtual void    handleInput     (WindowManager& window, unsigned int& status);
        virtual void    update          (WindowManager& window, unsigned int& status);
        virtual void    draw            (WindowManager& window, unsigned int& status);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
};

#endif
