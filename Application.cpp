#include "Application.h"
#include <iostream>

Application::Application()
    : window(sf::VideoMode(800, 600), "L-System Visualization"),
    uiManager(window),
    renderer(&window, &lSystem, 10.0f, sf::Color::Black) 
{
    Initialize();
}

Application::~Application() 
{

}

void Application::Initialize() 
{
    // Load predefined settings into UIManager
    auto predefinedSettings = ExampleSettings::GetAllPredefinedSettings();
    for (const auto& setting : predefinedSettings) 
    {
        uiManager.AddPredefinedSettings(setting);
    }
    
    //Set default tree when initialising
    lSystem.setRules({
        {'X', "F[@[-X]+X]"},
        {'F', "FF-[-F+F+F]+[+F-F-F]"},
        {'@', "[^^F][&&F][%%F][##F]"}
        });
    lSystem.setAxiom("X");
    lSystem.setAngleIncrement(25.0f);
    lSystem.setIterationCount(5);
    lSystem.generateSystem();

    // Render L-system
    renderer.render();
}

void Application::Run() 
{
    sf::Clock clock;
    while (window.isOpen()) 
    
    {
        sf::Time deltaTime = clock.restart();
        ProcessEvents();
        Update(deltaTime);
        Render();
    }
}

void Application::ProcessEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            window.close();

        uiManager.HandleEvent(event);
    }
}



void Application::Update(sf::Time deltaTime) 
{
    uiManager.Update(deltaTime);


    if (uiManager.ShouldUpdateLSystem()) 
    {
        // Apply the new settings to the LSystem
        lSystem.setAxiom(uiManager.GetCurrentAxiom());
        lSystem.setRules(uiManager.GetCurrentRules());
        lSystem.setIterationCount(uiManager.GetNumIterations());
        lSystem.generateSystem(); 

        // Now, trigger the renderer to redraw
        renderer.setLSystem(&lSystem);
        renderer.render();

        // Reset the flag in UIManager
        uiManager.ResetUpdateFlag();
    }

}

void Application::Render() 
{
    // Render L-system
    renderer.render();  

    // Render ImGui
    uiManager.CreateGUI();
    uiManager.Render();

    window.display();
}


int main() 
 {
    Application app;
    app.Run();
    return 0;
}