#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#define PI 3.14159265358979323846f

#define FPS     60

#define SCR_W   1200    //Ancho de la ventana
#define SCR_H   600     //Altura de la ventana

#define MAP_W   6400   //Ancho del mapa
#define MAP_H   6400   //Altura del mapa

#define SPR_W   32000   //Ancho del sprite
#define SPR_H   32000   //Altura del sprite

enum GameSceneStates {LOAD, CONFIG, PLAY, PAUSED, RESET, OVER, WIN, CREDITS, EXIT};

enum Align {TL, TC, TR, ML, MC, MR, BL, BC, BR};

struct GameData {//Refleja el estado de algunas variables del juego para ponerlas en pantalla
    unsigned int    maxEnemies;
    unsigned int    maxHeroes;
    unsigned int    worldEnemies;
    float           playerSpeed;
    float           playerPosX;
    float           playerPosY;
    float           playerAngle;
};

#endif
