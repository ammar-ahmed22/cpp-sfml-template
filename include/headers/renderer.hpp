#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "debug.hpp"



class Renderer{
  private:
    sf::RenderWindow *window;
  
  public:
    Renderer(sf::RenderWindow *_window);
    
    void line(const sf::Vector2f &from, const sf::Vector2f &to, const sf::Color &color = sf::Color::White);
    void text(const sf::Font &font, const std::string &str, const sf::Vector2f &pos = {0.f, 0.f}, const int &size = 10, const sf::Color &color = sf::Color::White);

};


#endif