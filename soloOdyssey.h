//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _SoLoOdyssey_H             // prevent multiple definitions if this 
#define _SoLoOdyssey_H             // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "player.h"
#include "environment.h"
#include "projectile.h"
#include "textDX.h"
#include "asteroid.h"
#include "stage1.h"
//#include "gameOver.h"
//=============================================================================
// Create game class
//=============================================================================
class SoLoOdyssey
{
private:


    //Game Variables
    Graphics* graphics;
    Game* gamePtr;





    //text variables
    TextDX* dxFontSmall;       // DirectX fonts


    // variables
    TextureManager gameTextures;    // game texture

    TextureManager stage1Texture;    //stage1 texture 
    TextureManager stage2Texture;    //stage2 texture 
    TextureManager stage3Texture;    //stage3 texture 

    Stage1 stage1;
    Stage2 stage2;
    Stage3 stage3;

    Projectile* projectiles[MAX_PROJECTILES]; //pointer to projectiles;
    Projectile tempProjectiles[MAX_PROJECTILES]; //for initializing projectiles

    TextureManager asteroidTexture; //asteroid texture
    TextureManager enemy1ProjectileTexture; //projectile texture for stage1
    TextureManager enemy2ProjectileTexture; //projectile texture for stage2
    TextureManager bossProjectileTexture; //projectile texture for boss stage
    
    Asteroid asteroid;
    Projectile enemy1Projectile;
    Projectile enemy2Projectile;
    Projectile bossProjectile;

    Player    playerShip;          // spaceship



public:
    enum Stage
    {
        level1,
        level2,
        level3
    };

    Stage stage;

    // Constructor
    SoLoOdyssey();

    // Destructor
    virtual ~SoLoOdyssey();

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
    void stage2Setup();     //setup second stage
    void stage3Setup();     //setup third stage

    void setStage (Stage stageNo) { stage = stageNo; };


};

#endif
