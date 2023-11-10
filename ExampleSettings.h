#pragma once

#include <string>
#include <map>
#include <vector>

class ExampleSettings 
{
public:
    std::string name;
    std::string axiom;
    std::map<char, std::string> rules;
    float angleIncrement;
    int iterationCount;

    static std::vector<ExampleSettings> GetAllPredefinedSettings();


    ExampleSettings(const std::string& name, const std::string& axiom,
        const std::map<char, std::string>& rules, float angleIncrement, int iterationCount);

    // Static instances of predefined settings
    static ExampleSettings binaryTree;
    static ExampleSettings dragonCurve;
    static ExampleSettings penroseTiling;
    static ExampleSettings tallSeaweed;
    static ExampleSettings arrowWeed;
    static ExampleSettings fuzzyWeed;
    static ExampleSettings wavySeaweed;
    static ExampleSettings stochFuzzyWeed;
    static ExampleSettings kochSnowflake;
    static ExampleSettings twiggyTree;

};
