#include <SFML/Graphics.hpp>
#include <vector>
#include "ExampleSettings.h"
#include "imgui.h"
#include "imgui-SFML.h"

/**
 * @class UIManager
 * @brief Manages the user interface for the L-system generator application.
 *
 * This class integrates with the ImGui library to create an interactive GUI.
 * It allows users to select predefined L-system configurations, adjust parameters, and trigger the generation process.
 */

class UIManager 
{
public:
    UIManager(sf::RenderWindow& window);
    ~UIManager();

    void Update(sf::Time deltaTime);
    void Render();
    void CreateGUI();
    void HandleEvent(sf::Event& event);
    void AddPredefinedSettings(const ExampleSettings& settings);
    ExampleSettings GetCurrentSettings() const;

    bool ShouldUpdateLSystem() const { return newSettingSelected; }
    void ResetUpdateFlag() { newSettingSelected = false; }


    const std::string& GetCurrentAxiom() const { return currentAxiom; }
    const std::map<char, std::string>& GetCurrentRules() const { return currentRules; }
    int GetNumIterations() const { return num_iterations; }

private:
    bool newSettingSelected = false;
    std::string currentAxiom;
    std::map<char, std::string> currentRules;
    int num_iterations;
    sf::RenderWindow& window;
    std::vector<ExampleSettings> predefinedSettings;
    int currentSettingIndex;

};