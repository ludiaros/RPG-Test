#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <map>

#include "globals.hpp"

#include "GameScene.hpp"

class GameSceneManager {

    public:
        //Constructors
        GameSceneManager();
        //Methods
        void                        addState        (int id, GameScene* state);
        void                        previousState   ();
        void                        setState        (unsigned int status);
        GameScene*                 getState        ();
        //Fields
        unsigned int                currStatus;
        unsigned int                prevStatus;

    private:
        //Constructors
        //Methods
        //Fields
        std::map<int, GameScene*>  listStates;
};

#endif
