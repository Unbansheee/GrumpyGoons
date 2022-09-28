#pragma once
#include "Scene.h"

class SceneManager
{
public:
    static void Update(float dt);
    static void FixedUpdate(float dt);
    static void Draw();
    static void DeferredDestroy();
    
    template <typename T>
    static void LoadScene();
    static int GetSceneID();
private:
    inline static Scene* currentScene;
    
};

template <typename T>
void SceneManager::LoadScene()
{
    if (currentScene != nullptr)
    {
        delete currentScene;
    }
    currentScene = new T();
    currentScene->SpawnActors();
}
