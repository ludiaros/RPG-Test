#ifndef GAMELOAD_HPP
#define GAMELOAD_HPP

#include <vector>

#include "globals.hpp"
#include "ResourceManager.hpp"

#include "GameScreen.hpp"
#include "GameScreenManager.hpp"
#include "WindowManager.hpp"

class GameScreenLoad : public GameScreen {

    public:
        //Constructors
        GameScreenLoad();
        //Methods
        virtual void    handleEvents    (WindowManager& window, unsigned int& status);
        virtual void    update          (WindowManager& window, unsigned int& status);
        virtual void    draw            (WindowManager& window, unsigned int& status);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
        unsigned int                cursor;
        sf::IntRect                 guiLogo;
        sf::Sprite                  guiImages;
        sf::Vector2i                mousePos;
        std::vector<sf::IntRect>    clickArea;
        std::vector<sf::IntRect>    iconActive;
        std::vector<sf::IntRect>    iconInactive;
        std::vector<sf::String>     menuOptions;
        std::vector<int>            newStatus;
};

#endif
