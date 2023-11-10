#include "Renderer.h"
#include <iostream>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>


/**
 * Constructor for Renderer object that manages the drawing of L-systems onto an SFML window.
 * @param window A pointer to the SFML window where the L-system will be drawn.
 * @param lSystem A pointer to the LSystem instance to be rendered.
 * @param lineLength The length of each line segment drawn for a "forward" command.
 * @param lineColor The colour of the line segments.
 */
Renderer::Renderer(sf::RenderWindow* window, LSystem* lSystem, float lineLength, sf::Color lineColor)
	: window(window), lSystem(lSystem), lineLength(lineLength), lineColor(lineColor) 
{
}



// Setters for Renderer properties

void Renderer::setWindow(sf::RenderWindow* newWindow)
{
	window = newWindow;
}

void Renderer::setLSystem(LSystem* newLSystem)
{
	lSystem = newLSystem;
}

void Renderer::setLineLength(float newLineLength)
{
	lineLength = newLineLength;
}

void Renderer::setLineColor(const sf::Color& newLineColor)
{
	lineColor = newLineColor;
}

// Getters for Renderer properties

sf::RenderWindow* Renderer::getWindow() const
{
	return window;
}

LSystem* Renderer::getLSystem() const
{
	return lSystem;
}

float Renderer::getLineLength() const
{
	return lineLength;
}

sf::Color Renderer::getLineColor() const
{
	return lineColor;
}


/**
 * Calculates the vertices for the lines that represent the L-system's pattern.
 * This method interprets the L-system string commands and translates them into a series of connected lines.
 * @return A VertexArray containing the line segments to be drawn.
 */
sf::VertexArray Renderer::calculateLineStrip() 
{
    sf::Vector2u windowSize = window->getSize();
    sf::Vector2f position = { windowSize.x / 2.0f, windowSize.y - lineLength };

    float angle = 90.0f;  // Starting angle facing upwards
    std::stack<sf::Vector2f> positionStack;
    std::stack<float> angleStack;

    sf::VertexArray lines(sf::LineStrip);
    lines.append(sf::Vertex(position, lineColor));

    std::string lSystemString = lSystem->getCurrentString();
    lineLength = 5;

    // Generate line strip
    for (char command : lSystemString) 
    {
        switch (command) 
        {
            // Handle drawing forward 
        case 'F': 
        {
            sf::Vector2f newPosition;
            newPosition.x = position.x + std::cos(angle * M_PI / 180.0f) * lineLength;
            newPosition.y = position.y - std::sin(angle * M_PI / 180.0f) * lineLength;
            lines.append(sf::Vertex(newPosition, lineColor));
            position = newPosition;
            break;
        }
                // Handle moving forward without drawing for other characters
        case 'X':
        case 'Y': 
        {
            position.x += std::cos(angle * M_PI / 180.0f) * lineLength;
            position.y -= std::sin(angle * M_PI / 180.0f) * lineLength;
            break;
        }
        case '+': // Turn right
            angle += lSystem->getAngleIncrement();
            break;
        case '-': // Turn left
            angle -= lSystem->getAngleIncrement();
            break;
        case '[': 
            positionStack.push(position);
            angleStack.push(angle);
            break;
        case ']': 
            if (!positionStack.empty() && !angleStack.empty()) 
            {
                position = positionStack.top();
                angle = angleStack.top();
                positionStack.pop();
                angleStack.pop();
                lines.append(sf::Vertex(position, sf::Color::Transparent));
            }
            break;
        }
        //TODO: implement case ',' with stochastic mechanisms
    }


    // Scaling and centering the line strip
    sf::FloatRect bounds = lines.getBounds();
    float scaleX = windowSize.x / bounds.width;
    float scaleY = windowSize.y / bounds.height;
    float scale = std::min(scaleX, scaleY);

    for (size_t i = 0; i < lines.getVertexCount(); ++i) 
    {
        lines[i].position.x = (lines[i].position.x - bounds.left) * scale;
        lines[i].position.y = (lines[i].position.y - bounds.top) * scale;
        lines[i].position.x += (windowSize.x - bounds.width * scale) / 2.0f;
        lines[i].position.y += (windowSize.y - bounds.height * scale) / 2.0f;
    }

    return lines;
}


void Renderer::drawLineStrip(const sf::VertexArray& lines) 
{
    window->draw(lines);
}


/**
 * Renders the L-system onto the associated SFML window.
 * This method clears the window, calculates the line strip representing the L-system,
 * and draws it onto the window.
 */
void Renderer::render() {
    if (window == nullptr || lSystem == nullptr) 
    {
        std::cerr << "Render error: window or LSystem pointer is null" << std::endl;
        return;
    }

    window->clear(sf::Color::White);
    sf::VertexArray lines = calculateLineStrip();
    drawLineStrip(lines);
}





