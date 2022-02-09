//  Module:             Gameplay Programming
//  Assignment2:        So-Lo Odyssey
//  Student Name:       Aaron Choo 
//  Student Number:     S10194746C

#include "boss.h"
#include<iostream>
#include "player.h"

Boss::Boss()
{
	spriteData.width = BossNS::WIDTH;           // size of boss
	spriteData.height = BossNS::HEIGHT;
	spriteData.x = BossNS::X;                   // location on screen
	spriteData.y = BossNS::Y;
	spriteData.rect.bottom = BossNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = BossNS::WIDTH;

	//stage variables
	projectileSpeed = ProjectileNS::PROJECTILE_EASY_SPEED;
	spawnRate = ProjectileNS::PROJECTILE_EASY_SPAWN;
	timer = 0;
	spawnTimer = 0;
	waveValue = Wave::wave1;
	activeProjectiles = 0;
	spawnBool = true;
	velocity.x = 0;
	velocity.y = 0;

}

bool Boss::initialize(Game* gamePtr, int width, int height, int ncols,
	TextureManager* textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

void Boss::draw()
{
	Image::draw();
}

void Boss::update(float frameTime, Projectile* projectiles[], Player ship)
{
	Entity::update(frameTime);
	updateWave(projectiles, frameTime);
	spawnProjectiles(projectiles, frameTime, ship);
}

void Boss::projectileInitialization(Projectile* projectile)//Initialize projectiles
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

void Boss::setupProjectile(Projectile* projectile, Player ship) //setup projectiles to shoot towards the player
{
	projectile->setX(getX());
	projectile->setY(getY());
	D3DXVECTOR2 shipVector = VECTOR2(ship.getX(), ship.getY());
	D3DXVECTOR2 bossVector = VECTOR2(getX(), getY());
	D3DXVECTOR2 lineVector = VECTOR2(getX() - 1, getY());
	D3DXVECTOR2 horizontalVector = VECTOR2(lineVector - bossVector);
	D3DXVECTOR2 diagonalVector = VECTOR2(shipVector - bossVector);
	graphics->Vector2Normalize(&horizontalVector);
	graphics->Vector2Normalize(&diagonalVector);
	float dotProduct = graphics->Vector2Dot(&horizontalVector, &diagonalVector);
	float angle = acos(dotProduct);
	projectileAngle = (360 * (PI / 180)) - angle;


	D3DXVECTOR2 velocity = VECTOR2(ship.getX() - getX(), ship.getY() - getY());
	projectile->setVelocity(velocity * projectileSpeed);
	projectile->setAngle(projectileAngle);
}

void Boss::spawnProjectiles(Projectile* projectiles[], float frameTime, Player ship) //projectile spawning
{

	if (spawnBool)
	{
		spawnTimer += frameTime;
		if (spawnTimer > spawnRate)
		{
			for (int i = 0; i < MAX_PROJECTILES; ++i)
			{
				if (projectiles[i]->getActive() == false)
				{
					setupProjectile(projectiles[i], ship);
					projectiles[i]->setActive(true);
					activeProjectiles += 1;

					break;
				}
			}
			spawnTimer -= spawnRate;
		}

	}
}

void Boss::offScreenProjectile(Projectile* projectiles[]) //delete projectiles when offscreen
{
	for (int i = 0; i < activeProjectiles; ++i)
	{
		if (projectiles[i]->getActive())
		{
			if (projectiles[i]->getX() > GAME_WIDTH) //right side      
			{
				projectiles[i]->setActive(false);
				activeProjectiles -= 1;
				break;
			}


			if (projectiles[i]->getX() < 0) //left side

			{
				projectiles[i]->setActive(false);
				activeProjectiles -= 1;
				break;
			}


			if (projectiles[i]->getY() > GAME_HEIGHT) //bottom
			{
				projectiles[i]->setActive(false);
				activeProjectiles -= 1;
				break;
			}

		}

	}
}

void Boss::updateWave(Projectile* projectiles[], float frameTime)
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
		projectileSpeed = ProjectileNS::PROJECTILE_EASY_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_EASY_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; i++)
		{
			projectiles[i]->setProjectileDamage(10);
		}
		break;

	case wave2:
		projectileSpeed = ProjectileNS::PROJECTILE_MEDIUM_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_MEDIUM_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; ++i)
		{
			projectiles[i]->setProjectileDamage(7);
		}
		break;

	case wave3:
		projectileSpeed = ProjectileNS::PROJECTILE_HARD_SPEED;
		spawnRate = ProjectileNS::PROJECTILE_HARD_SPAWN;
		for (int i = 0; i < MAX_PROJECTILES; ++i)
		{
			projectiles[i]->setProjectileDamage(5);
		}
		break;
	}

}

void Boss::resetSpawn()
{
	spawnBool = false;
	spawnTimer = 0;
	activeProjectiles = 0;
}


