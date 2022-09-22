#include "Scene.h"

#include <iostream>
#include <SFML/Window/Mouse.hpp>

#include "FallingBlock.h"
#include "Ground.h"
#include "Ball.h"
#include "Catapult.h"
#include "Enemy.h"

Scene::Scene() : m_world({0.0f, 9.8f})
{
    listener = new ContactListener();
    m_world.SetContactListener(listener);
    
    SpawnActor<Ground>({1000.f, 1080.f});
    SpawnActor<Catapult>({300.0f, 960.f});

    SpawnActor<FallingBlock>({1800.f, 1000});
    SpawnActor<FallingBlock>({1800.f, 900});
    SpawnActor<FallingBlock>({1800.f, 800});
    SpawnActor<FallingBlock>({1800.f, 700});

    SpawnActor<Enemy>({1700.f, 1000.f});
    
}

void Scene::Update(float dt)
{
    for (Actor* actor : m_actorsToBeginPlay)
    {
        actor->BeginPlay();
    }
    m_actorsToBeginPlay.clear();
    
    for (int i = 0; i < m_actors.size(); ++i)
    {
        m_actors[i]->Update(dt);
    }
}

void Scene::FixedUpdate(float dt)
{
    m_world.Step(dt, 8, 3);
    
    for (Actor* actor : m_actors)
    {
        actor->FixedUpdate(dt);
    }
}

void Scene::Draw()
{
    for (Actor* actor : m_actors)
    {
        actor->Draw();
    }
}

void Scene::DeferredDestroy()
{
    for (int i = 0; i < m_actorsToDestroy.size(); ++i)
    {
            m_actorsToDestroy[i]->OnDestroy();
            m_actors.erase(std::remove(m_actors.begin(), m_actors.end(), m_actorsToDestroy[i]), m_actors.end());
            delete m_actorsToDestroy[i];
    }
    m_actorsToDestroy.clear();
    
}

void Scene::DestroyActor(Actor* actor)
{
    if (!actor)
        return;
    if (actor->IsMarkedForDestroy())
        return;
    m_actorsToDestroy.push_back(actor);
    actor->MarkForDestroy();
}

void Scene::DestroyBody(b2Body* body)
{
    m_world.DestroyBody(body);
}

void Scene::SetGravity(const b2Vec2& gravity)
{
    m_world.SetGravity(gravity);
}

sf::Vector2f Scene::GetMousePositionScreen() const
{
    return sf::Vector2f(sf::Mouse::getPosition(*Renderer::m_window));
}

sf::Vector2f Scene::GetMousePositionWorld() const
{
    return Renderer::m_window->mapPixelToCoords(sf::Vector2i(GetMousePositionScreen()));;
}
