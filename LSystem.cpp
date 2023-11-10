#include "LSystem.h"
#include <iostream>

// Default constructor
LSystem::LSystem() : axiom(""), angleIncrement(0.0f), iterationCount(0)
{
}


/**
 * Constructs an L-system with a given axiom, a set of production rules, and an angle increment.
 * @param axiom The initial string from which the system starts evolving.
 * @param rules A map of character to string replacements that define the production rules.
 * @param angleIncrement The angle by which the drawing cursor turns for '+' and '-' commands.
 */
LSystem::LSystem(const std::string& axiom, const std::map<char, std::string>& rules, float angleIncrement)
    : axiom(axiom), rules(rules), angleIncrement(angleIncrement), iterationCount(0)
{
    generateSystem(); // Generate the system upon construction
}

// Setters for L-system properties
void LSystem::setAxiom(const std::string& newAxiom)
{
    axiom = newAxiom;

}

void LSystem::setRules(const std::map<char, std::string>& newRules)
{
    rules = newRules;
}

void LSystem::setAngleIncrement(float angle)
{
    angleIncrement = angle;
}

void LSystem::setIterationCount(unsigned int count)
{
    iterationCount = count;
    //generateSystem();
}

// Getters for L-system properties
std::string LSystem::getAxiom() const
{
    return axiom;
}

std::map<char, std::string> LSystem::getRules() const
{
    return rules;
}

std::string LSystem::getCurrentString() const
{
    return currentString;
}

float LSystem::getAngleIncrement() const
{
    return angleIncrement;
}

unsigned int LSystem::getIterationCount() const
{
    return iterationCount;
}


/**
 * Generates the final string of the L-system by applying the production rules for a number of iterations.
 * This method transforms the current axiom into a complex string that represents the final state of the L-system.
 */
void LSystem::generateSystem() 
{
    currentString = axiom; // Start with the axiom
    for (unsigned int i = 0; i < iterationCount; ++i) 
    {
        currentString = applyRules(currentString, rules); // Use the updated string
        std::cout << "GEN " << i << ": current L - system string: " << currentString << std::endl;
    }
}


std::string LSystem::applyRules(const std::string& axiom, const std::map<char, std::string>& rules) 
{


    std::string output = "";
    for (char ch : axiom) 
    {
        if (rules.find(ch) != rules.end()) 
        {
            output += rules.at(ch);
        }
        else 
        {
            output += ch; // If the character doesn't have a rule, keep it unchanged
        }
    }
    return output;
}


