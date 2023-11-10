#include "UIManager.h"
#include <iostream>

UIManager::UIManager(sf::RenderWindow& window)
    : window(window), currentSettingIndex(-1), num_iterations(5) 
{
    ImGui::SFML::Init(window);
}

UIManager::~UIManager() 
{
    ImGui::SFML::Shutdown();
}

void UIManager::Update(sf::Time deltaTime) 
{
    ImGui::SFML::Update(window, deltaTime);
}

void UIManager::Render() 
{
    ImGui::SFML::Render(window);
}

void UIManager::HandleEvent(sf::Event& event) 
{
    ImGui::SFML::ProcessEvent(event);
}

void UIManager::AddPredefinedSettings(const ExampleSettings& settings) 
{
    predefinedSettings.push_back(settings);
}

ExampleSettings UIManager::GetCurrentSettings() const 
{
    if (currentSettingIndex >= 0 && currentSettingIndex < predefinedSettings.size()) 
    {
        return predefinedSettings[currentSettingIndex];
    }
    // Return a default ExampleSettings or handle this case appropriately
    return ExampleSettings("Default", "X", { {'X', "F+[[X]-X]-F[-FX]+X"} }, 0.0f, 3);
}

void UIManager::CreateGUI() 
{
    ImGui::Begin("L-System Generator");

    // Dropdown to select predefined settings
    if (ImGui::BeginCombo("Examples", currentSettingIndex >= 0 ? predefinedSettings[currentSettingIndex].name.c_str() : "Select...")) 
    {
        for (int i = 0; i < predefinedSettings.size(); i++) 
        {
            bool isSelected = (currentSettingIndex == i);
            if (ImGui::Selectable(predefinedSettings[i].name.c_str(), isSelected)) 
            {
                currentSettingIndex = i;
                // When new setting selected, update the update with appropriate settings
                ExampleSettings currentSettings = predefinedSettings[currentSettingIndex];

                num_iterations = currentSettings.iterationCount;
                currentAxiom = currentSettings.axiom;
                currentRules = currentSettings.rules;

                std::cout << "Current setting: " << currentSettings.name << std::endl;
                std::cout << "Current axiom: " << currentAxiom << std::endl;
                std::cout << "Current iterations count: " << num_iterations << std::endl;
                std::cout << "Current no. of rules: " << currentRules.size() << std::endl;
                std::cout << "Current rules: ";
                for (const auto& rule : currentRules) 
                {
                    std::cout << rule.first << " -> " << rule.second << "; ";
                }
                std::cout << std::endl;

                newSettingSelected = true;
            }
            if (isSelected) 
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }

    // UI slider to control iterations
    ImGui::SliderInt("Iterations", &num_iterations, 0, 10);

    if (ImGui::Button("Generate")) 
    {
        newSettingSelected = true; // Flag that new settings should be applied
    }

    ImGui::End();
}