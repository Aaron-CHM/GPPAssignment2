//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#include "SoLoOdyssey.h"

//=============================================================================
// Constructor
//=============================================================================
SoLoOdyssey::SoLoOdyssey()
{

    dxFontSmall = new TextDX();     // DirectX fonts
}

//=============================================================================
// Destructor
//=============================================================================
SoLoOdyssey::~SoLoOdyssey()
{
    releaseAll();           // call onLostDevice() for every graphics item
    SAFE_DELETE(dxFontSmall);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SoLoOdyssey::initialize(Graphics* g, Game* gPtr)
{
    graphics = g;
    gamePtr = gPtr;

    if (dxFontSmall->initialize(graphics, 50, true, true, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));


    stage = Stage::level1;

    // main game textures
    if (!gameTextures.initialize(graphics, TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // ship
    if (!playerShip.initialize(gamePtr, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing ship1"));
    playerShip.setFrames(playerNS::SHIP1_START_FRAME, playerNS::SHIP1_END_FRAME);
    playerShip.setCurrentFrame(playerNS::SHIP1_START_FRAME);
    playerShip.setX(GAME_WIDTH / 2 - playerNS::WIDTH / 2); //Set ship to center 
    playerShip.setY(GAME_HEIGHT / 2 - playerNS::HEIGHT / 2); //Set ship to center 


}

//=============================================================================
// Update all game items
//=============================================================================
int SoLoOdyssey::update(float frameTime)
{

    if (playerShip.getHealth() <= 0)
    {
        projectiles[0]->clearProjectiles(projectiles);
        stage1.setTimer(0);
        playerShip.setHealth(100);
        return 1;
    }

    playerShip.update(frameTime);

    switch (stage)
    {
    case Stage::level1:

        for (int i = 0; i < MAX_PROJECTILES; ++i)
        {
            projectiles[i]->update(frameTime);
        }
        stage1.update(frameTime, projectiles, playerShip);
        if (stage1.getTimer() > 60.0f)
        {
            projectiles[0]->clearProjectiles(projectiles);
            stage1.setTimer(0);
            playerShip.setHealth(100);
            return 2;
        }

        break;

    default:
        break;
    }





}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void SoLoOdyssey::ai() {}

//=============================================================================
// Handle collisions
//=============================================================================
void SoLoOdyssey::collisions()
{
    VECTOR2 collisionVector;
    for (int i = 0; i < stage1.getActiveProjectiles(); ++i)
    {
        if (projectiles[i]->collidesWith(playerShip, collisionVector))
        {
            projectiles[i]->setActive(false);
            stage1.setActiveProjectiles(stage1.getActiveProjectiles() - 1);
            playerShip.setHealth(playerShip.getHealth() - projectiles[i]->getProjectileDamage());
            break;
        }
    }

    if (playerShip.collidesWith(asteroid, collisionVector))
    {
        playerShip.bounce(collisionVector, asteroid);
        playerShip.setHealth(playerShip.getHealth() - asteroidNS::DAMAGE);
    }
}

//=============================================================================
// Render game items
//=============================================================================
void SoLoOdyssey::render()
{
    graphics->spriteBegin();                // begin drawing sprites

    projectiles[0]->spawnProjectiles(projectiles);

    playerShip.draw();                           // add ship to scene
    graphics->spriteEnd();                  // end drawing sprites


}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void SoLoOdyssey::releaseAll()
{
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SoLoOdyssey::resetAll()
{
    return;
}

void SoLoOdyssey::generateBoundary()
{

}



void SoLoOdyssey::stage1Setup()
{

}

void SoLoOdyssey::stage2Setup()
{

}

void SoLoOdyssey::stage3Setup()
{

}





