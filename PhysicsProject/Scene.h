#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <SFML/Graphics/Font.hpp>

#include "Actor.h"
#include "ContactListener.h"
#include "box2d\box2D.h"

class Scene
{
protected:
    Scene();
    ~Scene();
    friend class SceneManager;
public:
    
    void Update(float dt);
    void FixedUpdate(float dt);
    void Draw();
    void DeferredDestroy();
    
    void DestroyActor(Actor* actor);

    virtual void SpawnActors();

    b2Body* CreateBody(const b2BodyDef* def);
    void DestroyBody(b2Body* body);
    
    void SetGravity(const b2Vec2& gravity);

    sf::Vector2f GetMousePositionScreen() const;
    sf::Vector2f GetMousePositionWorld() const;
    
    b2World m_world;
    sf::Vector2f m_gravity = { 0.0f, 9.8f };

    ContactListener* listener;
    std::vector<Actor*> m_actors;
    std::vector<Actor*> m_actorsToDestroy;
    std::vector<Actor*> m_actorsToBeginPlay;
    std::vector<std::pair<sf::Vector2f, float>> m_explosionsToSpawn;
    sf::Font font;
    int m_sceneIndex = -1;
public:
    template <typename T>
    T* SpawnActor(const sf::Vector2f& location = {0, 0}, const float& angle = 0)
    {
        T* actor = new T();
        m_actors.push_back(actor);
        m_actorsToBeginPlay.push_back(actor);
        actor->SetScene(this);
        actor->SetPosition(location);
        actor->SetRotation(angle);
        actor->OnConstruct();
        return actor;
    }
    
};

inline b2Body* Scene::CreateBody(const b2BodyDef* def)
{
    if (m_world.IsLocked())
    {
        return nullptr;
    }
    return m_world.CreateBody(def);
}
