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
#include "player.h"

namespace stage1NS
{
    const int WIDTH = 32;                   // image width
    const int HEIGHT = 32;                  // image height
    const int X = GAME_WIDTH / 2 - WIDTH / 3;   // location on screen
    const int Y = GAME_HEIGHT / 3 - HEIGHT / 3;
    const float SPEED = 100;                // 100 pixels per second
    const float MASS = 300.0f;              // mass
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
    float projectileAngle; //angle the projectile needs to curve, to hit the player
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
    void projectileInitialization(Projectile* projectile);
    void setupProjectile(Projectile* projectile, Player ship); //set up velocity + angle of projectiles
    void spawnProjectiles(Projectile* projectiles[], float frameTime, Player ship);  //spawn projectiles
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

    void setActiveProjectiles(int newActiveProjectiles) { activeProjectiles = newActiveProjectiles; };

    int getActiveProjectiles() { return activeProjectiles; };

};
#endif


