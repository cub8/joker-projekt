#include "gui.hpp"
#include "button.hpp"
#include "widget.hpp"
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <ostream>

GUI::GUI(){
    Widget::font.loadFromFile("../resources/Roboto-Regular.ttf");
    Button * button1 = new Button();
    button1->set_size({100.0f, 100.0f});
    button1->set_background(sf::Color::Cyan);
    button1->set_position({100, 100});
    button1->on_click = [](){};
    button1->set_text("test");
    button1->set_foreground(sf::Color::Red);
    widgets.push_back(button1);
}

void GUI::draw(sf::RenderWindow &window) const{
   for(const auto& w: widgets){
       w->draw(window);
   }
}

void GUI::handle_events(sf::Event &event){
    for( auto& w: widgets){
       w->handle_events(event);
   }
}

void GUI::update(){
    for(auto& w: widgets){
       w->update();
   }

}


