#include "button.hpp"
#include "widget.hpp"
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

void Button::draw(sf::RenderWindow & window) const{
    sf::RectangleShape rect;
    rect.setPosition(get_position());
    rect.setSize(get_size());
    rect.setFillColor(get_background());
    window.draw(rect);
    sf::Text text(get_text(),Widget::font, 40);
    auto bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2, bounds.height/2);
    text.setPosition(get_position().x + (get_size().x/2), 
        get_position().y + (get_size().y/2)
    );
    text.setFillColor(get_foreground());
    window.draw(text);
}
void Button::handle_events(sf::Event & event){
    if(event.type == sf::Event::MouseButtonPressed ){
        sf::FloatRect rect(get_position(), get_size());
        auto mouse = sf::Mouse::getPosition();
        if(rect.contains({(float)mouse.x, (float)mouse.y}) && on_click){
            on_click();
        }
    }
}
void Button::update(){

}
sf::String Button::get_text() const{
    return text;
}
void Button::set_text(sf::String new_text){
    text=new_text;
}

