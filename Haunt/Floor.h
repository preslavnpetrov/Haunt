#pragma once
#include <Engine/GameObject.h>
#include <Engine/Collider.h>

[event_receiver(native)]
class Floor: public GameObject
{
private:
	Collider floorCollider;

	void HandleCollision(Collider* t_other_object);
	void HandleEscape(Collider* t_other_collider);
	void HookCollisionEvents();
public:
	Floor(Texture* t_texture_to_use, glm::vec2 t_new_position);
	Floor(Texture* t_texture_to_use, glm::vec2 t_new_position, glm::vec2 t_new_dimensions);
	~Floor();
};