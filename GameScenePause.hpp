#ifndef GAMEPAUSE_HPP
#define GAMEPAUSE_HPP

#include "globals.hpp"
#include "GameScreen.hpp"
#include "WindowManager.hpp"

class GameScreenPause : public GameScreen {

    public:
        //Constructors
        GameScreenPause();
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
