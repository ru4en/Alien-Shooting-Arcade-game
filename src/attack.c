
#include "common.h"
static void tick(void);
static void touch(Entity* other);

static SDL_Texture* bulletTex[1];

void initBullet(void)
{
	bullet = malloc(sizeof(Entity));
	memset(bullet, 0, sizeof(Entity));
	stage.entityTail->next = bullet;
	stage.entityTail = bullet;

	bullet->health = 1;
	bullet->x = player->x;
	bullet->y = player->y;
	bullet->touch = touch;
	bullet->tick = tick;

	if (player->facing == RIGHT)
	{
		bullet->dx = 70;
	}
	else if (player->facing == LEFT)
	{
		bullet->dx = -70;
	}

	bulletTex[1] = loadTexture("gfx/shot.png");
	bullet->texture = bulletTex[1];

	SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);
}

static void touch(Entity* other)
{
	if (other == self)
	{
		self->health -= 1;
	}
}


static void tick(void)
{
	if (self->isOnGround)
	{
		self->health = 0;
	}
}