#ifndef GAMECONFIG_HPP
#define GAMECONFIG_HPP

#include <vector>

#include "globals.hpp"
#include "GameScreen.hpp"
#include "WindowManager.hpp"

class GameScreenConfig : public GameScreen {

    public:
        //Constructors
        GameScreenConfig();
        //Methods
        virtual void                handleEvents    (WindowManager& window, unsigned int& status);
        virtual void                update          (WindowManager& window, unsigned int& status);
        virtual void                draw            (WindowManager& window, unsigned int& status);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
        unsigned int                cursor;
        sf::Vector2i                mousePos;
        std::vector<sf::IntRect>    clickArea;
        std::vector<sf::String>     menuOptions;
        std::vector<int>            newStatus;
};

#endif
