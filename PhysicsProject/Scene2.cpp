#include "Scene2.h"

#include "Catapult.h"
#include "Ground.h"
#include "Camera.h"
#include "Enemy.h"
#include "FallingBlock.h"

Scene2::Scene2()
{
    m_sceneIndex = 1;
}

void Scene2::SpawnActors()
{
    //Scene::SpawnActors();
    SpawnActor<Ground>({1000.f, 1080.f});
    auto cat = SpawnActor<Catapult>({300.0f, 960.f});

    auto cam = SpawnActor<Camera>({Renderer::GetWindowSize().x / 2.f, Renderer::GetWindowSize().y / 2.f});
    cam->SetActiveCamera();
    cam->SetParent(cat);
    cat->cam = cam;

    SpawnActor<FallingBlock>({1000.f, 1000.f});
    SpawnActor<FallingBlock>({1100.f, 1000.f});
    SpawnActor<FallingBlock>({1200.f, 1000.f});
    SpawnActor<FallingBlock>({1300.f, 1000.f});
    SpawnActor<FallingBlock>({1400.f, 1000.f});
    SpawnActor<FallingBlock>({1500.f, 1000.f});

    SpawnActor<Enemy>({1050.f, 1000.f});
    SpawnActor<Enemy>({1150.f, 1000.f});
    SpawnActor<Enemy>({1250.f, 1000.f});
    SpawnActor<Enemy>({1350.f, 1000.f});
    SpawnActor<Enemy>({1450.f, 1000.f});

    auto roof = SpawnActor<FallingBlock>({1250, 900}, 90.f);
    roof->SetSize({20, 550});
    roof->AddTag("Destructible");

    SpawnActor<Enemy>({1050.f, 880.f});
    SpawnActor<Enemy>({1150.f, 880.f});
    SpawnActor<Enemy>({1250.f, 880.f});
    SpawnActor<Enemy>({1350.f, 880.f});
    SpawnActor<Enemy>({1450.f, 880.f});

    SpawnActor<FallingBlock>({1000.f, 850.f});
    SpawnActor<FallingBlock>({1100.f, 850.f});
    SpawnActor<FallingBlock>({1200.f, 850.f});
    SpawnActor<FallingBlock>({1300.f, 850.f});
    SpawnActor<FallingBlock>({1400.f, 850.f});
    SpawnActor<FallingBlock>({1500.f, 850.f});

    auto roof2 = SpawnActor<FallingBlock>({1250, 800}, 90.f);
    roof2->SetSize({20, 750});
    roof2->AddTag("Destructible");

    SpawnActor<FallingBlock>({900.f, 750.f});
    SpawnActor<FallingBlock>({1600.f, 750.f});

    SpawnActor<Enemy>({950.f, 750.f});
    SpawnActor<Enemy>({1550.f, 750.f});
}
