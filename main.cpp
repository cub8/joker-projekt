
#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "src/app/app.hpp"

int main(){
    App app(720, 720);
    app.program_loop();

    return 0;
}
