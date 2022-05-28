#include "widget.hpp"
#include <SFML/Graphics/Font.hpp>

    sf::Vector2f Widget::get_size() const{
        return size;
    }
    sf::Vector2f Widget::get_position() const{
        return position;
    }
    sf::Color Widget::get_background() const{
        return background;
    }
    sf::Color Widget::get_foreground() const{
        return foreground;
    }

    void Widget::set_size(sf::Vector2f new_size){
        size=new_size;
    }
    void Widget::set_position(sf::Vector2f new_position){
        position=new_position;
    }
    void Widget::set_background(sf::Color new_background){
        background=new_background;
    }
    void Widget::set_foreground(sf::Color new_foreground){
        foreground=new_foreground;
    }

    sf::Font Widget::font; 