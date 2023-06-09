#include "Collision.h"
#include "ECS\ColliderComponent.h"

int Collision::hitCount = 0;
bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
	if(
	recB.x >= recA.x +15 &&
		 recB.y >= recA.y +15
		)
	{
		if (recB.x == recA.x + 15 &&
			recB.y == recA.y + 15)
		{
			Audio a;
			hitCount++;
			if(hitCount != 5)
			a.playEffects("gameLoop/effects/ouch.wav");
		}
		return true;
	}
	return false;
}
bool Collision::AABB(const ColliderComponent& colA, const ColliderComponent& colB)
{
	if (AABB(colA.collider, colB.collider))
	{
		return true;
	}
	else
		return false;
 }

