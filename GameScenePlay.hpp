#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "globals.hpp"
#include "GameScene.hpp"
#include "WindowManager.hpp"
#include "WorldManager.hpp"
#include "Cursor.hpp"
//#include "GunsManager.hpp"
//#include "ShipsManager.hpp"

class GameScenePlay : public GameScene {

    public:
        //Constructors
        GameScenePlay();
        //Methods
        virtual void    handleEvents    (WindowManager& window, unsigned int& status);
        virtual void    update          (WindowManager& window, unsigned int& status);
        virtual void    draw            (WindowManager& window, unsigned int& status);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
        bool            start;
        WorldManager    world;
        Cursor          cursor;
        //GunsManager     gunsm;
        //ShipsManager    shipm;
};

#endif
