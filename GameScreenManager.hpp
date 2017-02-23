#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <map>

#include "globals.hpp"

#include "GameScreen.hpp"

class GameScreenManager {

    public:
        //Constructors
        GameScreenManager();
        //Methods
        void                        addState        (int id, GameScreen* state);
        void                        previousState   ();
        void                        setState        (unsigned int status);
        GameScreen*                 getState        ();
        //Fields
        unsigned int                currStatus;
        unsigned int                prevStatus;

    private:
        //Constructors
        //Methods
        //Fields
        std::map<int, GameScreen*>  listStates;
};

#endif
