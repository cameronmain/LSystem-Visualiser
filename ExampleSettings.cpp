#include "ExampleSettings.h"
#include <vector>

/**
 * @class ExampleSettings
 * @brief Stores predefined settings for various L-system examples.
 *
 * This class provides a series of static instances representing different configurations for L-systems,
 * allowing quick setup and demonstration of various fractal patterns.
 */

ExampleSettings ExampleSettings::twiggyTree(
    "Twiggy Tree",       // Name of the setting
    "X",   // Axiom
    { {'X', "F+[[X]-X]-F[-FX]+X"},
      {'F', "FF"} },   // Rules
    30.0f,             // Angle increment
    3
);

ExampleSettings ExampleSettings::tallSeaweed(
    "Tall Seaweed",       // Name of the setting
    "F",   // Axiom
    { {'F', "F[+F]F[-F]F"} },   // Rules
    25.0f,             // Angle increment
    3
);

ExampleSettings ExampleSettings::arrowWeed(
    "Arrow Weed",       // Name of the setting
    "X",   // Axiom
    { {'F', "FF"} ,  // Rules
      {'X', "F[+X][-X]FX"} },
    30.0f,             // Angle increment
    3
);

ExampleSettings ExampleSettings::fuzzyWeed(
    "Fuzzy Weed",       // Name of the setting
    "X",   // Axiom
    { {'F', "FF"} ,  // Rules
      {'X', "F-[[X]+X]+F[+FX]-X"} },
    22.5f,             // Angle increment
    3
);

ExampleSettings ExampleSettings::wavySeaweed(
    "Wavy Seaweed",       // Name of the setting
    "F",   // Axiom
    { {'F', "FF-[-F+F+F]+[+F-F-F]"} },  // Rules 
    22.5f,             // Angle increment
    3
);

ExampleSettings ExampleSettings::stochFuzzyWeed(
    "Stochastic Fuzzy Weed",       // Name of the setting
    "X",   // Axiom
    { {'F', "FF"} ,  // Rules
      {'X', "F-[[X]+X]+F[+FX]-X,F+[[X]-X]-F[-FX]+X"} },
    22.5f,             // Angle increment
    3
);


ExampleSettings ExampleSettings::dragonCurve(
    "Dragon Curve",    // Name of the setting
    "FX",              // Axiom
    { {'Y', "-FX-Y"} ,  // Rules
      {'X', "X+YF+"}},
    90.0f,              // Angle increment
    9
);

ExampleSettings ExampleSettings::kochSnowflake(
    "Koch Snowflake",       // Name of the setting
    "F++F++F",   // Axiom
    { {'F', "F-F++F-F"} }, // Rules
    60.0f,              // Angle increment
    4
);


ExampleSettings ExampleSettings::binaryTree(
    "Binary Tree",       // Name of the setting
    "X",   // Axiom
    { {'X', "FFFF[-X][+X]"} }, // Rules
    30.0f,              // Angle increment
    3
);

ExampleSettings ExampleSettings::penroseTiling(
    "Penrose Tiling",     // Name of the setting
    "[N]++[N]++[N]++[N]++[N]", // Axiom
    { // Rules
        {'M', "OA++PA----NA[-OA----MA]++"},
        {'N', "+OA--PA[---MA--NA]+"},
        {'O', "-MA++NA[+++OA++PA]-"},
        {'P', "--OA++++MA[+PA++++NA]--NA"},
        {'A', ""}
    },
    36.0f,   // Angle increment
    4        // Number of iterations
);

std::vector<ExampleSettings> ExampleSettings::GetAllPredefinedSettings() 
{
    return 
    {
        ExampleSettings::binaryTree,
        ExampleSettings::twiggyTree,
        ExampleSettings::tallSeaweed,
        ExampleSettings::arrowWeed,
        ExampleSettings::fuzzyWeed,
        ExampleSettings::wavySeaweed,
        ExampleSettings::stochFuzzyWeed,

        ExampleSettings::dragonCurve,
        ExampleSettings::kochSnowflake,
        ExampleSettings::penroseTiling,

    };
}

ExampleSettings::ExampleSettings(const std::string& name, const std::string& axiom,
    const std::map<char, std::string>& rules, float angleIncrement, int iterationCount)
    : name(name), axiom(axiom), rules(rules), angleIncrement(angleIncrement), iterationCount(iterationCount) 
{
}

