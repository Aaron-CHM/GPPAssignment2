//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#include "stage1.h"
#include<iostream>
#include "player.h"

Stage1::Stage1()
{
	//animation
	spriteData.width = stage1NS::WIDTH;           // size of stage1
	spriteData.height = stage1NS::HEIGHT;
	spriteData.x = stage1NS::X;                   // location on screen
	spriteData.y = stage1NS::Y;
	frameDelay = stage1NS::ANIMATION_DELAY;
	startFrame = stage1NS::START_FRAME;     // first frame of stage1 animation
	endFrame = stage1NS::END_FRAME;     // last frame of stage1 animation
	spriteData.rect.bottom = stage1NS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = stage1NS::WIDTH;
	currentFrame = startFrame;

	//boss variables
	projectileSpeed = ProjectileNS::PROJECTILE_EASY_SPEED;
	spawnRate = ProjectileNS::PROJECTILE_EASY_SPAWN;
	timer = 0;
	spawnTimer = 0;
	waveValue = Wave::wave1;
	activeProjectiles = 0;
	spawnBool = true;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y



}

bool Stage1::initialize(Game* gamePtr, int width, int height, int ncols,
	TextureManager* textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Stage1::draw()
{
	Image::draw();
}

void Stage1::update(float frameTime, Projectile* projectiles[], Player ship)
{

	Entity::update(frameTime);
	updateAbilities(projectiles, frameTime);
	spawnProjectilesAll(projectiles, frameTime);

	spriteData.x += frameTime * velocity.x;         // move boss along X 
	spriteData.y += frameTime * velocity.y;         // move boss along Y

	// Bounce off walls
	if (spriteData.x > boundaryEnvironmentNS::MAX_X - boundaryEnvironmentNS::WIDTH)    // if hit right screen edge
	{
		spriteData.x = (boundaryEnvironmentNS::MAX_X - boundaryEnvironmentNS::WIDTH);    // position at right screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	else if (spriteData.x < boundaryEnvironmentNS::MIN_X)                    // else if hit left screen edge
	{
		spriteData.x = ((float)boundaryEnvironmentNS::MIN_X);                           // position at left screen edge
		velocity.x = -velocity.x;                   // reverse X direction
	}
	if (spriteData.y > boundaryEnvironmentNS::MAX_Y - boundaryEnvironmentNS::HEIGHT)  // if hit bottom screen edge
	{
		spriteData.y = ((float)boundaryEnvironmentNS::MAX_Y - boundaryEnvironmentNS::HEIGHT);  // position at bottom screen edge
		velocity.y = -velocity.y;                   // reverse Y direction
	}
	else if (spriteData.y < boundaryEnvironmentNS::MIN_Y)                    // else if hit top screen edge
	{
		spriteData.y = ((float)boundaryEnvironmentNS::MIN_Y);                           // position at top screen edge
		velocity.y = -velocity.y;                  // reverse Y direction
	}

}

void Stage1::projectileInitialization(Projectile* projectile)//Initialize projectiles
{
	projectile->setWidth(ProjectileNS::WIDTH);
	projectile->setHeight(ProjectileNS::HEIGHT);
	projectile->setX(getX());
	projectile->setX(getY());
	projectile->setRectBottom(ProjectileNS::HEIGHT);
	projectile->setRectRight(ProjectileNS::WIDTH);
	projectile->setCurrentFrame(startFrame);
	projectile->setCollisionType(entityNS::CIRCLE);
	projectile->setLoop(false);
	projectile->setCollisionRadius(ProjectileNS::WIDTH / 4);
	projectile->setProjectileDamage(0);
	projectile->setActive(false);
	projectile->setMass(300.0f);
}

void Stage1::setupProjectileLeftRight(Projectile* projectile1, Projectile* projectile2) //setup projectiles velocity
{
	projectile1->setX(getX());
	projectile1->setY(getY());
	projectile2->setX(getX());
	projectile2->setY(getY());

	D3DXVECTOR2 velocity1 = VECTOR2(-getX(), 0);
	D3DXVECTOR2 velocity2 = VECTOR2(getX(), 0);

	projectile1->setVelocity(velocity1 * projectileSpeed);
	projectile2->setVelocity(velocity2 * projectileSpeed);

}



void Stage1::setupProjectileUpDownLeftRight(Projectile* projectile1, Projectile* projectile2, Projectile* projectile3, Projectile* projectile4) //setup projectiles velocity 
{
	projectile1->setX(getX());
	projectile1->setY(getY());
	projectile2->setX(getX());
	projectile2->setY(getY());
	projectile3->setX(getX());
	projectile3->setY(getY());
	projectile4->setX(getX());
	projectile4->setY(getY());

	D3DXVECTOR2 velocity1 = VECTOR2(-getX(), 0);
	D3DXVECTOR2 velocity2 = VECTOR2(getX(), 0);
	D3DXVECTOR2 velocity3 = VECTOR2(0, -getY());
	D3DXVECTOR2 velocity4 = VECTOR2(0, getY());
	projectile1->setVelocity(velocity1 * projectileSpeed);
	projectile2->setVelocity(velocity2 * projectileSpeed);
	projectile3->setVelocity(velocity3 * projectileSpeed);
	projectile4->setVelocity(velocity4 * projectileSpeed);

}


void Stage1::setupProjectileAll(Projectile* projectile1, Projectile* projectile2, Projectile* projectile3, Projectile* projectile4,
	Projectile* projectile5, Projectile* projectile6, Projectile* projectile7, Projectile* projectile8) //setup projectiles velocity 
{
	projectile1->setX(getX());
	projectile1->setY(getY());
	projectile2->setX(getX());
	projectile2->setY(getY());
	projectile3->setX(getX());
	projectile3->setY(getY());
	projectile4->setX(getX());
	projectile4->setY(getY());

	projectile5->setX(getX());
	projectile5->setY(getY());
	projectile6->setX(getX());
	projectile6->setY(getY());
	projectile7->setX(getX());
	projectile7->setY(getY());
	projectile8->setX(getX());
	projectile8->setY(getY());

	D3DXVECTOR2 velocity1 = VECTOR2(-getX(), 0);
	D3DXVECTOR2 velocity2 = VECTOR2(getX(), 0);
	D3DXVECTOR2 velocity3 = VECTOR2(0, -getY());
	D3DXVECTOR2 velocity4 = VECTOR2(0, getY());

	//bottom right
	D3DXVECTOR2 velocity5 = VECTOR2(getX(), getY());

	//top right
	D3DXVECTOR2 velocity6 = VECTOR2(getX(), -getY());

	//bottom left
	D3DXVECTOR2 velocity7 = VECTOR2(-getX(), getY());

	//top left
	D3DXVECTOR2 velocity8 = VECTOR2(-getX(), -getY());


	projectile1->setVelocity(velocity1 * projectileSpeed);
	projectile2->setVelocity(velocity2 * projectileSpeed);
	projectile3->setVelocity(velocity3 * projectileSpeed);
	projectile4->setVelocity(velocity4 * projectileSpeed);

	projectile5->setVelocity(velocity5 * projectileSpeed);
	projectile6->setVelocity(velocity6 * projectileSpeed);
	projectile7->setVelocity(velocity7 * projectileSpeed);
	projectile8->setVelocity(velocity8 * projectileSpeed);

}

void Stage1::spawnProjectilesLeftRight(Projectile* projectiles[], float frameTime)
{

	if (spawnBool)
	{
		spawnTimer += frameTime;
		if (spawnTimer > spawnRate)
		{
			for (int i = 0; i < MAX_PROJECTILES; i += 2)
			{
				if (projectiles[i]->getActive() == false)
				{
					setupProjectileLeftRight(projectiles[i], projectiles[i + 1]);
					projectiles[i]->setActive(true);
					projectiles[i + 1]->setActive(true);
					activeProjectiles += 2;

					break;
				}
			}
			spawnTimer -= spawnRate;
		}

	}
}


void Stage1::spawnProjectilesUpDownLeftRight(Projectile* projectiles[], float frameTime)
{
	if (spawnBool)
	{
		spawnTimer += frameTime;
		if (spawnTimer > spawnRate)
		{
			for (int i = 0; i < MAX_PROJECTILES; i += 4)
			{
				if (projectiles[i]->getActive() == false)
				{
					setupProjectileUpDownLeftRight(projectiles[i], projectiles[i + 1], projectiles[i + 2], projectiles[i + 3]);
					projectiles[i]->setActive(true);
					projectiles[i + 1]->setActive(true);
					projectiles[i + 2]->setActive(true);
					projectiles[i + 3]->setActive(true);
					activeProjectiles += 4;

					break;
				}
			}
			spawnTimer -= spawnRate;
		}

	}
}

void Stage1::spawnProjectilesAll(Projectile* projectiles[], float frameTime)
{
	if (spawnBool)
	{
		spawnTimer += frameTime;
		if (spawnTimer > spawnRate)
		{
			for (int i = 0; i < MAX_PROJECTILES; i++)
			{
				if (projectiles[i]->getActive() == false)
				{
					setupProjectileAll(projectiles[i], projectiles[i + 1], projectiles[i + 2], projectiles[i + 3], projectiles[i + 4]
						, projectiles[i + 5], projectiles[i + 6], projectiles[i + 7]);
					projectiles[i]->setActive(true);
					projectiles[i + 1]->setActive(true);
					projectiles[i + 2]->setActive(true);
					projectiles[i + 3]->setActive(true);
					projectiles[i + 4]->setActive(true);
					projectiles[i + 5]->setActive(true);
					projectiles[i + 6]->setActive(true);
					projectiles[i + 7]->setActive(true);
					activeProjectiles += 8;

					break;
				}
			}
			spawnTimer -= spawnRate;
		}

	}
}

void Stage1::updateAbilities(Projectile* projectiles[], float frameTime)
{
	timer += frameTime;
	if (timer > 20.0f && timer < 21.0f)
	{
		resetSpawn();
		projectiles[0]->clearProjectiles(projectiles);
	}
	if (timer > 40.0f && timer < 41.0f)
	{
		resetSpawn();
		projectiles[0]->clearProjectiles(projectiles);
	}
	if (timer > 61.0f)
	{
		resetSpawn();
		projectiles[0]->clearProjectiles(projectiles);
	}
	if (timer > 41.0f && timer < 60.0f)
	{
		if (!spawnBool)
		{
			spawnBool = true;
		}
		waveValue = wave3;
	}
	else if (timer > 21.0f && timer < 40.0f)
	{
		if (!spawnBool)
		{
			spawnBool = true;
		}
		waveValue = wave2;
	}


	switch (waveValue)
	{
	case wave1:
		spawnProjectilesLeftRight(projectiles, frameTime);
		projectileSpeed = ProjectileNS::PROJECTILE_EASY_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_EASY_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; i++)
		{
			projectiles[i]->setProjectileDamage(10);
		}
		break;

	case wave2:
		spawnProjectilesUpDownLeftRight(projectiles, frameTime);
		projectileSpeed = ProjectileNS::PROJECTILE_MEDIUM_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_MEDIUM_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; ++i)
		{
			projectiles[i]->setProjectileDamage(7);
		}
		break;

	case wave3:
		spawnProjectilesAll(projectiles, frameTime);
		projectileSpeed = ProjectileNS::PROJECTILE_HARD_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_HARD_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; ++i)
		{
			projectiles[i]->setProjectileDamage(5);
		}
		break;
	}

}

void Stage1::resetSpawn()
{
	spawnBool = false;
	spawnTimer = 0;
	activeProjectiles = 0;
}


