
#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "src/app/app.hpp"

int main(){
    App app(720, 720);
    

    //Loop
    while ((app.get_window_is_open())){
        //Update
       app.update();
        //Render
       app.render();
    }
    return 0;
}
