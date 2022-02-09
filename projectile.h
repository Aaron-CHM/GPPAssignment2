//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _PROJECTILE_H               // Prevent multiple definitions if this 
#define _PROJECTILE_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace ProjectileNS
{
    const int WIDTH = 40;                   // image width
    const int HEIGHT = 40;                  // image height
    const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
    const int Y = GAME_HEIGHT / 4;

    //projectile speed
    const float PROJECTILE_EASY_SPEED = 1.0f;
    const float PROJECTILE_MEDIUM_SPEED = 0.85f;
    const float PROJECTILE_HARD_SPEED = 0.7f;

    //projectile firing rate
    const float PROJECTILE_EASY_SPAWN = 0.75f;
    const float PROJECTILE_MEDIUM_SPAWN = 1.0f;
    const float PROJECTILE_HARD_SPAWN = 1.25f;

}

// inherits from Entity class
class Projectile : public Entity
{
private:
    int damage; //projectileDamage

public:
    // constructor
    Projectile();

    // inherited member functions
    virtual void draw();
    virtual bool initialize(Game* gamePtr, int width, int height, int ncols,
        TextureManager* textureM);
    void update(float frameTime);
    void spawnProjectiles(Projectile* projectiles[]);
    void clearProjectiles(Projectile* projectiles[]);


    //get set
    void setAngle(float angle) { spriteData.angle = angle; };
    float getAngle() { return spriteData.angle; };


    void setProjectileDamage(int newDamage) { damage = newDamage; };
    int getProjectileDamage() { return damage; };
};
#endif