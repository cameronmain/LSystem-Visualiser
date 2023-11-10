#pragma once

#include <string>
#include <map>
#include <vector>

/**
 * @class LSystem
 * @brief Encapsulates the logic and properties of a Lindenmayer System (L-system).
 *
 * This class manages the construction and iteration of L-system strings based on an initial axiom and a set of production rules.
 */

class LSystem 
{
private:
    std::string axiom;
    std::map<char, std::string> rules;
    std::string currentString;
    float angleIncrement;
    unsigned int iterationCount;

public:
    LSystem();
    LSystem(const std::string& axiom, const std::map<char, std::string>& rules, float angleIncrement);

    // Setters for L-system properties
    void setAxiom(const std::string& axiom);
    void setRules(const std::map<char, std::string>& rules);
    void setAngleIncrement(float angle);
    void setIterationCount(unsigned int count);

    // Getters for L-system properties
    std::string getAxiom() const;
    std::map<char, std::string> getRules() const;
    std::string getCurrentString() const;
    float getAngleIncrement() const;
    unsigned int getIterationCount() const;

    void generateSystem();

    std::string applyRules(const std::string& axiom, const std::map<char, std::string>& rules);


};