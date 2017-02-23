#ifndef WORLDMANAGER_HPP
#define WORLDMANAGER_HPP

#include <vector>
#include <iostream>

#include "globals.hpp"
#include "WindowManager.hpp"
#include "Tile.hpp"

class WorldManager {

    public:
        //Constructors
        WorldManager();
        //Methods
        void                    init                ();
        void                    update              (WindowManager& window);
        void                    draw                (WindowManager& window);
        //Fields

    private:
        //Constructors
        //Methods
        //Fields
        unsigned int            rows;
        unsigned int            cols;
        std::vector<Tile>       tileMap;
        std::vector<int>        intMap;
};

#endif
