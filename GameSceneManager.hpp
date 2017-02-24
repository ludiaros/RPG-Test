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
        void                        addScene        (int id, GameScene* scene);
        void                        previousScene   ();
        void                        setScene        (unsigned int scene);
        GameScene*                  getScene        ();
        //Fields
        unsigned int                currScene;
        unsigned int                prevScene;

    private:
        //Constructors
        //Methods
        //Fields
        std::map<int, GameScene*>  listScenes;
};

#endif
