//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _soloOdyssey_H             // prevent multiple definitions if this 
#define _soloOdyssey_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "player.h"
#include "environment.h"
#include "projectile.h"
#include "textDX.h"
#include "asteroid.h"
#include "boss.h"
//#include "gameOver.h"
//=============================================================================
// Create game class
//=============================================================================
class SoloOdyssey
{
private:


    //Game Variables
    Graphics* graphics;
    Game* gamePtr;





    //text variables
    TextDX* dxFontSmall;       // DirectX fonts


    // variables
    TextureManager gameTextures;    // game texture

    TextureManager backgroundTexture;    //background texture
    Image background;

    Projectile* projectiles[MAX_PROJECTILES]; //pointer to projectiles;
    Projectile tempProjectiles[MAX_PROJECTILES]; //for initializing projectiles

    TextureManager asteroidTexture; //asteroid texture
    Asteroid asteroid;

    TextureManager bossTexture; //boss texture
    Boss boss;

    TextureManager enemyProjectile1Texture; //projectile texture 1
    Projectile enemy1Projectile;

    TextureManager enemyProjectile2Texture; //projectile texture 2
    Projectile enemy2Projectile;

    TextureManager playerShipTexture; //player ship texture
    Player    playerShip;



public:
    enum Stage
    {
        level1,
        //level2,
        //level3
    };

    Stage stage;

    // Constructor
    SoloOdyssey();

    // Destructor
    virtual ~SoloOdyssey();

    // Initialize the game
    void initialize(Graphics* g, Game* gPtr);
    int update(float frameTime);      // must override pure virtual from Game
    void ai();          // "
    void collisions();  // "
    void render();      // "
    void releaseAll();
    void resetAll();
    void generateBoundary(); //generating the boundaries of the box
    void stage1Setup();     //setup first stage
    //void stage2Setup();     //setup second stage
    //void stage3Setup();     //setup third stage

    void setStage (Stage stageNo) { stage = stageNo; };


};

#endif
