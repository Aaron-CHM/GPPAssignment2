//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#include "projectile.h"

Projectile::Projectile()
{
	//default values set to first boss
	spriteData.width = ProjectileNS::WIDTH;
	spriteData.height = ProjectileNS::HEIGHT;
	spriteData.x = ProjectileNS::X;                   // location on screen
	spriteData.y = ProjectileNS::Y;
	spriteData.rect.bottom = ProjectileNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = ProjectileNS::WIDTH;
	currentFrame = startFrame;
	collisionType = entityNS::CIRCLE;
	damage = 0;
	loop = false;

}

bool Projectile::initialize(Game* gamePtr, int width, int height, int ncols,
	TextureManager* textureM)
{

	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Projectile::draw()
{
	Image::draw();
}

void Projectile::update(float frameTime)
{
	spriteData.x += frameTime * velocity.x;         // move ship along X 
	spriteData.y += frameTime * velocity.y;         // move ship along Y
	Entity::update(frameTime);
}

void Projectile::spawnProjectiles(Projectile* projectiles[])
{
	for (int i = 0; i < MAX_PROJECTILES; ++i)
	{
		if (projectiles[i]->getActive())
		{
			projectiles[i]->draw();

		}
	}
}

void Projectile::clearProjectiles(Projectile* projectiles[])
{
	for (int i = 0; i < MAX_PROJECTILES; ++i)
	{
		projectiles[i]->setActive(false);
	}
}