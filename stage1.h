//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _STAGE1_H                 // Prevent multiple definitions if this 
#define _STAGE1_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "projectile.h"
#include "environment.h"

namespace stage1NS
{
    const int WIDTH = 32;                   // image width
    const int HEIGHT = 32;                  // image height
    const int X = GAME_WIDTH / 2 - WIDTH / 3;   // location on screen
    const int Y = GAME_HEIGHT / 3 - HEIGHT / 3;
    const float SPEED = 100;                // 100 pixels per second
    const float MASS = 300.0f;              // mass
    const int   TEXTURE_COLS = 1;           // texture has 1 columns
    const int   START_FRAME = 4;      // starts at frame 4
    const int   END_FRAME = 7;        // animation frames 4,5,6,7
    const float ANIMATION_DELAY = 0.2f;    // time between frames
    const float DAMAGE = 0.1;       // damage when player collide with boss
}

// inherits from Entity class
class Stage1 : public Entity
{
protected:

    enum Wave
    {
        wave1,
        wave2,
        wave3

    };
    Wave waveValue; //current wave
    float projectileSpeed; //speed of projectile 
    float spawnRate; //spawnRate of projectiles in seconds
    float spawnTimer; //timer to track spawning
    float timer;      //timer to keep track of boss;
    int activeProjectiles; //Number of active projectiles;
    bool spawnBool; //true if want to spawn projectiles, false if projectiles should not spawn


public:
    // constructor
    Stage1();

    // inherited member functions
    virtual void draw();
    void update(float frameTime, Projectile* projectiles[], Player ship);
    virtual bool initialize(Game* gamePtr, int width, int height, int ncols,
        TextureManager* textureM);
    void update(float frameTime, Projectile* projectiles[]);
    void projectileInitialization(Projectile* projectile);
    void setupProjectileLeftRight(Projectile* projectile1, Projectile* projectile2); //set velocity of projectiles for wave 1
    void setupProjectileUpDownLeftRight(Projectile* projectile1, Projectile* projectile2, Projectile* projectile3,
        Projectile* projectile4);//set velocity of projectiles for wave 2
    void setupProjectileAll(Projectile* projectile1, Projectile* projectile2, Projectile* projectile3, Projectile* projectile4,
        Projectile* projectile5, Projectile* projectile6, Projectile* projectile7, Projectile* projectile8);//set velocity of projectiles for wave 3
    void spawnProjectilesLeftRight(Projectile* projectiles[], float frameTime);  //spawning of first wave projectiles
    void spawnProjectilesUpDownLeftRight(Projectile* projectiles[], float frameTime);  //spawning of second wave projectiles
    void spawnProjectilesAll(Projectile* projectiles[], float frameTime);  //spawning of third wave projectiles
    void updateAbilities(Projectile* projectiles[], float frameTime);
    void resetSpawn();



    //get setters
    void setX(float x) { spriteData.x = x; };

    float getX() { return spriteData.x; };

    void setY(float y) { spriteData.y = y; };

    float getY() { return spriteData.y; };

    float getSpawnTimer() { return spawnTimer; };

    void setTimer(float t) { timer = t; };

    float getTimer() { return timer; };

    int getWaveValue() { return waveValue; };

    int getActiveProjectiles() { return activeProjectiles; };

};
#endif


