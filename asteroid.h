//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#ifndef _ASTEROID_H               // Prevent multiple definitions if this 
#define _ASTEROID_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"
#include "projectile.h"

namespace asteroidNS
{
    const int   WIDTH = 43;                // image width
    const int   HEIGHT = 43;               // image height
    const int   COLLISION_RADIUS = 120 / 2;   // for circular collision
    const int   X = GAME_WIDTH / 2 - WIDTH / 3; // location on screen
    const int   Y = GAME_HEIGHT / 3 - HEIGHT / 3;
    const float MASS = 1000.0f;         // mass
    const float SPEED = 120;                // 120 pixels per second
    const float DAMAGE = 10;
}


class Asteroid : public Entity            // inherits from Entity class
{
protected:

public:
    // constructor
    Asteroid();
    virtual void draw();
    virtual bool initialize(Game* gamePtr, int width, int height, int ncols,
        TextureManager* textureM);

    void update(float frameTime);
};
#endif

