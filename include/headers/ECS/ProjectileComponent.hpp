#pragma once

#include "ECS.hpp"
#include "Components.hpp"
#include "../Vector2D.hpp"

class ProjectileComponent : public Component
{
public:
	ProjectileComponent(int sp, Vector2D vel) : speed(sp), velocity(vel)
	{}
	~ProjectileComponent()
	{}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		transform->velocity = velocity;
	}

	void update() override
	{
    if (transform->position.x > 800 ||
				transform->position.x < 0 ||
				transform->position.y > 640 ||
				transform->position.y < 0)
		{
			std::cout << "Out of bounds!" << std::endl;
			entity->destroy();
		}
	}

private:

	TransformComponent* transform;

	int speed = 0;
	Vector2D velocity;


};