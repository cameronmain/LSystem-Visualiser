#include <SFML/Graphics.hpp>
#include "UIManager.h"
#include "Renderer.h"
#include "LSystem.h"

/**
 * @class Application
 * @brief The main application class that sets up and runs the L-system visualisation.
 *
 * This class is responsible for initialising the application, handling the main loop, and integrating
 * all other components like the UIManager and Renderer to visualize the L-systems.
 */

class Application 
{
public:
    Application();
    ~Application();
    void Run();


private:
    sf::RenderWindow window;
    UIManager uiManager;
    Renderer renderer;
    LSystem lSystem;

    void Initialize();
    void Update(sf::Time deltaTime);
    void Render();
    void ProcessEvents();
};