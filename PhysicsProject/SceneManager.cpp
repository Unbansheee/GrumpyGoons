#include "SceneManager.h"

void SceneManager::Update(float dt)
{
    if (currentScene)
    {
        currentScene->Update(dt);
    }
}


void SceneManager::FixedUpdate(float dt)
{
    if (currentScene)
    {
        currentScene->FixedUpdate(dt);
    }
    
}

void SceneManager::Draw()
{
    if (currentScene)
    {
        currentScene->Draw();
    }
}

void SceneManager::DeferredDestroy()
{
    if (currentScene)
    {
        currentScene->DeferredDestroy();
    }
    
}

int SceneManager::GetSceneID()
{
    if (currentScene)
    {
        return currentScene->m_sceneIndex;
    }
    return -1;
}
