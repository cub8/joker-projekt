#pragma once
#include "widget.hpp"
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <functional>

class Button : public Widget{
    public:
    Button() = default;
    virtual void draw(sf::RenderWindow & window) const override;
    virtual void update() override;
    virtual void handle_events(sf::Event & event) override;
    void set_text(sf::String new_text);
    sf::String get_text() const;
    std::function<void()> on_click;

    
    private:
    sf::String text;

};