#include "Tile.hpp"

Tile::Tile() {
}

void Tile::init(unsigned int id, int x, int y) {
    std::stringstream convert;
    convert << "tile" << id;
    convert.str();
    setTexture(*ResourceManager::getTexture(convert.str()));
    setPosition(x, y);
}
