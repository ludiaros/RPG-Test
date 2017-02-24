#ifndef GAMEEXIT_HPP
#define GAMEEXIT_HPP

#include "globals.hpp"
#include "GameScene.hpp"
#include "WindowManager.hpp"

class GameSceneExit : public GameScene {

    public:
        //Constructors
        GameSceneExit();
        //Methods
        virtual void    handleEvents    (WindowManager& window, unsigned int& status);
        virtual void    update          (WindowManager& window, unsigned int& status);
        virtual void    draw            (WindowManager& window, unsigned int& status);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
};

#endif
