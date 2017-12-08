#include "GameObject.h"
#include "Camera2D.h"

Uint16 GameObject::gameObjectsInitialized = 0;

// Constructors (all require a texture for the sprite)
GameObject::GameObject(Texture* t_texture_to_use) : position(0, 0), rotation(0), texture(t_texture_to_use), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
}

GameObject::GameObject(Texture* t_texture_to_use, const glm::vec2 t_new_position) : position(t_new_position), rotation(0), texture(t_texture_to_use), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
}

GameObject::GameObject(Texture* t_texture_to_use, const glm::vec2 t_new_position, const int t_new_depth): rotation(0), texture(t_texture_to_use), position(t_new_position), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
	texture->SetDepth(t_new_depth);
}

GameObject::GameObject(Texture* t_texture_to_use, const glm::vec2 t_new_position, const float t_new_rotation) : position(t_new_position), rotation(t_new_rotation), texture(t_texture_to_use), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
}

GameObject::GameObject(Texture* t_texture_to_use, const glm::vec2 t_new_position, const glm::vec2 t_new_scale) : position(t_new_position), scale(t_new_scale), texture(t_texture_to_use), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
}

GameObject::GameObject(Texture* t_texture_to_use, const glm::vec2 t_new_position, const glm::vec2 t_new_scale, const float t_new_rotation) : position(t_new_position), rotation(t_new_rotation), scale(t_new_scale), texture(t_texture_to_use), id(gameObjectsInitialized)
{
	gameObjectsInitialized++;
	dimensions = glm::vec2(texture->GetTextureWidth(), texture->GetTextureHeight());
}

GameObject::~GameObject()
{
	gameObjectsInitialized--;
}

void GameObject::SetPosition(const glm::vec2 t_new_position)
{
	// Set the position to the passed new Vector2D
	this->position = t_new_position;
}

void GameObject::SetRotation(const float t_new_rotation)
{
	// Set the rotation to the passed new float value
	this->rotation = t_new_rotation;
}

void GameObject::SetScale(const glm::vec2 t_new_scale)
{
	// Set the scale to the passed new Vector2D value
	this->scale = t_new_scale;
}

glm::vec2 GameObject::GetPosition() const
{
	// Return the current position of the object
	return this->position;
}

glm::vec4 GameObject::GetRect() const
{
	// Return the current position of the object and its dimensions
	return (dimensions.x != 0 && dimensions.y != 0) ? 
		glm::vec4(position.x, position.y, dimensions.x, dimensions.y) : 
		glm::vec4(position.x, position.y, texture->GetTextureWidth(), texture->GetTextureHeight());
}

double GameObject::GetRotation() const
{
	// Return the current rotation value of the object
	return this->rotation;
}

glm::vec2 GameObject::GetScale() const
{
	// Return the current scale value of the object
	return this->scale;
}

glm::vec2 GameObject::GetDimensions() const
{
	return this->dimensions;
}

Texture* GameObject::GetTexture()
{
	return this->texture;
}

// Get the current value of the object velocity
glm::vec2 GameObject::GetVelocity() const
{
	return this->velocity;
}

// Get the current value of the object acceleration
glm::vec2 GameObject::GetAcceleration() const
{
	return acceleration;
}

// Set the current value of the object velocity
void GameObject::SetVelocity(const glm::vec2 t_new_velocity)
{
	this->velocity = t_new_velocity;
}


// Set the current value of the object acceleration
void GameObject::SetAcceleration(const glm::vec2 t_new_acceleration)
{
	this->acceleration = t_new_acceleration;
}

void GameObject::Update()
{
	// This method would always be overwritten
}

void GameObject::Update(float t_delta_time)
{
	// This method would always be overwritten
}

bool GameObject::IsOnScreen(Camera2D* t_main_camera) const
{
	if (abs((abs(position.x) + texture->GetTextureWidth()/2) - t_main_camera->GetPosition().x) < t_main_camera->GetScreenDimensions().x / 2)
	{
		return true;
	}
	
	return false;
}
