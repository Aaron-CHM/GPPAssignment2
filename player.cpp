#include "player.h"

//=============================================================================
// default constructor
//=============================================================================
Player::Player() : Entity()
{
    spriteData.width = playerNS::WIDTH;           // size of Ship1
    spriteData.height = playerNS::HEIGHT;
    spriteData.x = playerNS::X;                   // location on screen
    spriteData.y = playerNS::Y;
    spriteData.rect.bottom = playerNS::HEIGHT;    // rectangle to select parts of an image
    spriteData.rect.right = playerNS::WIDTH;
    frameDelay = playerNS::SHIP_ANIMATION_DELAY;
    startFrame = playerNS::SHIP1_START_FRAME;     // first frame of ship animation
    endFrame = playerNS::SHIP1_END_FRAME;     // last frame of ship animation
    currentFrame = startFrame;
    health = 100;
    radius = playerNS::WIDTH / 2.0;
    collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Player::initialize(Game* gamePtr, int width, int height, int ncols,
    TextureManager* textureM)
{
    return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Player::draw()
{
    Image::draw();              // draw ship
}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Player::update(float frameTime)
{
    Entity::update(frameTime);


    if (input->isKeyDown(SHIP1_RIGHT_KEY)) //move right
    {
        spriteData.x = spriteData.x + playerNS::SPEED;
    }

    if (input->isKeyDown(SHIP1_LEFT_KEY)) //move left
    {
        spriteData.x = spriteData.x - playerNS::SPEED;
    }

    if (input->isKeyDown(SHIP1_UP_KEY)) //move up
    {
        spriteData.y = spriteData.y - playerNS::SPEED;
    }

    if (input->isKeyDown(SHIP1_DOWN_KEY)) //move down
    {
        spriteData.y = spriteData.y + playerNS::SPEED;
    }


    if (spriteData.x > GAME_WIDTH - playerNS::WIDTH) //right side      
        spriteData.x = GAME_WIDTH - playerNS::WIDTH;

    if (spriteData.x < playerNS::WIDTH) //left side
        spriteData.x = playerNS::WIDTH;

    if (spriteData.y > GAME_HEIGHT - playerNS::HEIGHT)
        spriteData.y = GAME_HEIGHT - playerNS::HEIGHT;
    if (spriteData.y < playerNS::HEIGHT)
        spriteData.y = playerNS::HEIGHT;

}
