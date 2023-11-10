#pragma once

#include <SFML/Graphics.hpp>
#include "LSystem.h"
/**
 * @class Renderer
 * @brief Responsible for rendering the L-system patterns onto a given SFML window.
 *
 * This class takes an LSystem instance and draws the resulting patterns using SFML primitives.
 * It manages the translation of L-system strings into visual elements on the screen.
 */
class Renderer 
{
private:
    sf::RenderWindow* window; // Pointer to the SFML window for rendering
    LSystem* lSystem; // Pointer to the LSystem instance to be rendered
    float lineLength; // Length of each "forward" movement
    sf::Color lineColor; 

public:
    // Constructor
    Renderer(sf::RenderWindow* window, LSystem* lSystem, float lineLength = 100.0f, sf::Color lineColor = sf::Color::Black);

    // Setters
    void setWindow(sf::RenderWindow* newWindow);
    void setLSystem(LSystem* newLSystem);
    void setLineLength(float newLineLength);
    void setLineColor(const sf::Color& newLineColor);

    // Getters
    sf::RenderWindow* getWindow() const;
    LSystem* getLSystem() const;
    float getLineLength() const;
    sf::Color getLineColor() const;

    // Render the L-system
    void render();

    // Calculates the vertices for the lines that represent the L-system's pattern.
    sf::VertexArray calculateLineStrip();

    // Draw the calculated linestrip
    void drawLineStrip(const sf::VertexArray& lines);
};
