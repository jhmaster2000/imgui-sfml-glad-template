#pragma clang diagnostic ignored "-Wunused-result"

#include <glad/glad.h>

#include <imgui/imgui.h>
#include <imgui-sfml/imgui-SFML.h>
#include "imgui-style.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include "log.h"

int main() {
    Logger::init(plog::verbose);
    LOGN << "Initialized.";

    sf::RenderWindow window(sf::VideoMode(1080, 720), "ImGui SFML", sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window, false);

    ImGuiIO& IO = ImGui::GetIO();
    IO.Fonts->AddFontFromFileTTF("data/fonts/verdana.ttf", 18.0f);
    ImGui::SFML::UpdateFontTexture();
    setImGuiStyle();

    sf::CircleShape shape(100.0f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100.0f, 100.0f);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if (event.type == sf::Event::Closed) window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowDemoWindow();

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.clear();
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
