﻿#include "Scene.h"

#include <iostream>
#include <SFML/Window/Mouse.hpp>

#include "FallingBlock.h"
#include "Ground.h"
#include "Ball.h"
#include "Camera.h"
#include "Catapult.h"
#include "Enemy.h"

Scene::Scene() : m_world({0.0f, 9.8f})
{
    listener = new ContactListener();
    m_world.SetContactListener(listener);

    SpawnActors();
}

void Scene::Update(float dt)
{
    
    std::sort(m_actorsToBeginPlay.begin(), m_actorsToBeginPlay.end(), [](const Actor* a, const Actor* b) { return a->GetUpdatePriority() < b->GetUpdatePriority(); });
    for (Actor* actor : m_actorsToBeginPlay)
    {
        actor->BeginPlay();
    }
    m_actorsToBeginPlay.clear();

    std::sort(m_actors.begin(), m_actors.end(), [](const Actor* a, const Actor* b) { return a->GetUpdatePriority() < b->GetUpdatePriority(); });

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

void Scene::SpawnActors()
{
    SpawnActor<Ground>({1000.f, 1080.f});
    auto cat = SpawnActor<Catapult>({300.0f, 960.f});

    //Floor
    SpawnActor<FallingBlock>({1800.f, 1000}, 90.f)->AddTag("Destructible");
    SpawnActor<FallingBlock>({1700.f, 1000}, 90.f)->AddTag("Destructible");
    SpawnActor<FallingBlock>({1600.f, 1000}, 90.f)->AddTag("Destructible");

    //Right Wall
    SpawnActor<FallingBlock>({1800.f, 900})->SetWeight(3);
    SpawnActor<FallingBlock>({1800.f, 800})->SetWeight(3);

    //Left Wall
    SpawnActor<FallingBlock>({1600.f, 900})->SetWeight(3);
    SpawnActor<FallingBlock>({1600.f, 800})->SetWeight(3);

    //Roof
    auto roof = SpawnActor<FallingBlock>({1700.f, 780}, 90.f);
    roof->AddTag("Destructible");
    roof->SetSize({20.f, 300.f});
    

    SpawnActor<Enemy>({1700.f, 900.f});
    auto cam = SpawnActor<Camera>({Renderer::GetWindowSize().x / 2.f, Renderer::GetWindowSize().y / 2.f});
    cam->SetActiveCamera();
    cam->SetParent(cat);
    cat->cam = cam;
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
