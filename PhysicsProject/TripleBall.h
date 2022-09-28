#pragma once
#include "Ball.h"
#include "Ticker.h"

class TripleBall : public Ball
{
public:
    void OnConstruct() override;
    void Update(float deltaTime) override;

    void SpawnChild();
private:
    bool m_isParent = true;
    Ticker dropTimer;
    Ticker dieTimer;
};
