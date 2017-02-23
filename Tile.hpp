#ifndef TILE_HPP
#define TILE_HPP

#include <sstream>

#include <SFML/Graphics.hpp>

#include "globals.hpp"
#include "ResourceManager.hpp"

class Tile : public sf::Sprite {
    public:
        //Constructors
        Tile();
        //Methods
        void        init(unsigned int id, int x, int y);
        //Fields
    private:
        //Constructors
        //Methods
        //Fields
};

#endif
