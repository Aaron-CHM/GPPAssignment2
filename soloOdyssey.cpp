//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#include "soloOdyssey.h"

//=============================================================================
// Constructor
//=============================================================================
SoloOdyssey::SoloOdyssey()
{

    dxFontSmall = new TextDX();     // DirectX fonts
}

//=============================================================================
// Destructor
//=============================================================================
SoloOdyssey::~SoloOdyssey()
{
    releaseAll();           // call onLostDevice() for every graphics item
    SAFE_DELETE(dxFontSmall);
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void SoloOdyssey::initialize(Graphics* g, Game* gPtr)
{
    graphics = g;
    gamePtr = gPtr;

    if (dxFontSmall->initialize(graphics, 50, true, true, "Arial") == false)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing DirectX font"));


    stage = Stage::level1;

    // main game textures
    if (!gameTextures.initialize(graphics, TEXTURES_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

    // background texture
    if (!backgroundTexture.initialize(graphics, NEBULA_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing background texture"));

    // ship
    if (!playerShip.initialize(gamePtr, playerNS::WIDTH, playerNS::HEIGHT, playerNS::TEXTURE_COLS, &gameTextures))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player ship"));
    playerShip.setFrames(playerNS::SHIP1_START_FRAME, playerNS::SHIP1_END_FRAME);
    playerShip.setCurrentFrame(playerNS::SHIP1_START_FRAME);
    playerShip.setX(GAME_WIDTH / 2 - playerNS::WIDTH / 2); //Set ship to center 
    playerShip.setY(GAME_HEIGHT / 2 - playerNS::HEIGHT / 2); //Set ship to center 


}

//=============================================================================
// Update all game items
//=============================================================================
int SoloOdyssey::update(float frameTime)
{

    if (playerShip.getHealth() <= 0)
    {
        projectiles[0]->clearProjectiles(projectiles);
        boss.setTimer(0);
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
        boss.update(frameTime, projectiles, playerShip);
        if (boss.getTimer() > 60.0f)
        {
            projectiles[0]->clearProjectiles(projectiles);
            boss.setTimer(0);
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
void SoloOdyssey::ai() {}

//=============================================================================
// Handle collisions
//=============================================================================
void SoloOdyssey::collisions()
{
    VECTOR2 collisionVector;
    for (int i = 0; i < boss.getActiveProjectiles(); ++i)
    {
        if (projectiles[i]->collidesWith(playerShip, collisionVector))
        {
            projectiles[i]->setActive(false);
            boss.setActiveProjectiles(boss.getActiveProjectiles() - 1);
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
void SoloOdyssey::render()
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
void SoloOdyssey::releaseAll()
{
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void SoloOdyssey::resetAll()
{
    return;
}

void SoloOdyssey::generateBoundary()
{

}



void SoloOdyssey::stage1Setup()
{
    //initialise textures
    //boss texture
    if (!bossTexture.initialize(graphics, ENEMYSHIP1_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing boss texture"));
    //enemy projectile Textures
    if (!enemyProjectile1Texture.initialize(graphics, ENEMYPROJECTILE1_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemyprojectile1 texture"));
    if (!enemyProjectile2Texture.initialize(graphics, ENEMYPROJECTILE2_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemyprojectile2 texture"));

    //asteroid textures
    if (!asteroidTexture.initialize(graphics, ASTEROID_IMAGE))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid textures"));

    //asteroid initialization
    if (!asteroid.initialize(gamePtr, asteroidNS::WIDTH, asteroidNS::HEIGHT, 0, &asteroidTexture))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing asteroid"));
    asteroid.setX(GAME_WIDTH / 2 - GAME_WIDTH / 3);
    asteroid.setY(GAME_HEIGHT / 3 - GAME_HEIGHT / 3);

}

//void SoloOdyssey::stage2Setup()
//{

//}

//void SoloOdyssey::stage3Setup()
//{

//}





