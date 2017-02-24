#ifndef GAME_HPP
#define GAME_HPP

#include "globals.hpp"
#include "WindowManager.hpp"

class GameScene {

    public:
        //Constructors
        GameScene();
        //Methods
        virtual void    handleEvents    (WindowManager& window, unsigned int& status);
        virtual void    update          (WindowManager& window, unsigned int& status);
        virtual void    draw            (WindowManager& window, unsigned int& status);
        //Fields
        unsigned int    id;

    private:
        //Constructors
        //Methods
        //Fields
};

#endif
