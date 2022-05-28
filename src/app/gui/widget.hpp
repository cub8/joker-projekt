#pragma once


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <map>

class Widget{
public:
    Widget() = default;
    virtual void draw(sf::RenderWindow & window) const = 0;
    virtual void update() = 0;
    virtual void handle_events(sf::Event & event)  = 0;

    sf::Vector2f get_size() const;
    sf::Vector2f get_position() const;
    sf::Color get_background() const;
    sf::Color get_foreground() const;

    void set_size(sf::Vector2f new_size);
    void set_position(sf::Vector2f new_position);
    void set_background(sf::Color background);
    void set_foreground(sf::Color foreground);

    static sf::Font font;
private:
    sf::Vector2f size{};
    sf::Vector2f position{};
    sf::Color background{sf::Color::Black};
    sf::Color foreground{sf::Color::Black};

};