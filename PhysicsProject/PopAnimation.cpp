#include "PopAnimation.h"

#include "Log.h"

PopAnimation::PopAnimation()
{

}



void PopAnimation::Update(float deltaTime)
{
    if (deathTimer.Update(deltaTime))
    {
        shapes.clear();
        Destroy();
    }
    
    for (auto& shape : shapes)
    {
        float directionx = cos(shape.getRotation() * 3.14 / 180);
        float directiony = sin(shape.getRotation() * 3.14 / 180);

        // ease out cubic
        float alpha = deathTimer.GetProgress();
        float speed = Ease(m_speed, 50, alpha);

        shape.move(directionx * speed * deltaTime, directiony * speed * deltaTime);

        float scale = Ease(1, 0, alpha);
        shape.setScale(scale, scale);
        
    }

    
}

void PopAnimation::OnConstruct()
{
    deathTimer.Pause();
    deathTimer = 0.5f;
}

void PopAnimation::Play(sf::Color color, float duration, float scale, float speed)
{
    int numOfShapes = floor(8 * scale);
    float angleInterval = 360 / numOfShapes;
    m_speed = speed;
    m_scale = scale;
    for (int i = 0; i < numOfShapes; i++)
    {
        sf::RectangleShape rect(sf::Vector2f(10 * scale, 5 * scale));
        rect.setOrigin(0, 2.5f * scale);
        rect.setPosition(GetPosition());
        rect.setFillColor(color);

        rect.setRotation(i * angleInterval + rand() % (int)angleInterval - (angleInterval * 0.8f));

        shapes.push_back(rect);
    }
    deathTimer.Start();
}

void PopAnimation::BeginPlay()
{
}

void PopAnimation::OnDestroy()
{
}

void PopAnimation::Draw()
{
    Actor::Draw();
    for (auto& shape : shapes)
    {
        Renderer::Submit(shape, 20);
    }
}
