#include "app.hpp"

void App::init_variables() //Initalization
    {
        this->window = nullptr;

    }

void App::init_window(int width, int height){
     this->video_mode.height =width;
    this->video_mode.width = height ; 
    //this->videoMode.getDesktopMode();

    this->window = new sf::RenderWindow(this->video_mode, "TEST", sf::Style::Titlebar | sf::Style::Close);
    
}
App::App(int width, int height){
    this->init_variables();
    this->init_window( width,  height);

}
App::~App(){
    delete this->window;
}

const bool App::get_window_is_open() const{
    return this->window->isOpen();
}
void App::poll_events(){
      while(this->window->pollEvent(this->ev)){
            switch (this->ev.type) {
                case sf::Event::Closed:
                    this->window->close();
                    break;
                case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape) //konkretne klawisze
                    this->window->close();
            }
        }
}
void App::render(){
          this->window->clear();

    this->window->display();
    }
    void App::update(){
         this->poll_events();
    }