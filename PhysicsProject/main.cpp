#include "SFML/Graphics.hpp"


#include <iostream>

#include "App.h"
#include "Input.h"
#include "Scene.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4.0;
    
    const double SCALE = 30.0;
    //window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grumpy Goons", sf::Style::Default, settings);
    App::SetWindow(window);
    window.setFramerateLimit(0);
    
    sf::Image icon;
    icon.loadFromFile("Resources/Sprites/Goon1.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    
    sf::Clock clock;
    float fixedTS = 1.0f / 60.0f;
    float fixedTSCounter = fixedTS;

    Renderer::m_window = &window;
    Scene scene;
    
    while (window.isOpen())
    {
        
        float dt = clock.restart().asSeconds();
        fixedTSCounter += dt;

        //sky blue background
        sf::Color sky = sf::Color(135, 206, 235);
        window.clear(sky);

        sf::Event event{};
        while (window.pollEvent(event))
        {
            Input::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }

        scene.Update(dt);
        
        if (fixedTSCounter >= fixedTS)
        {
            scene.FixedUpdate(fixedTS);
            fixedTSCounter = 0.0f;
        }
        
        scene.Draw();

        Renderer::Flush();
        
        scene.DeferredDestroy();

        
        Input::Reset();
        window.display();
    }

    return 0;
}
