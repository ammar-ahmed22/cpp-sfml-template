#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>
#include <string>

using sf::RenderWindow;
using sf::Vector2f;
using sf::Vector2i;
using sf::Color;
using sf::Font;
using sf::Vertex;
using sf::Lines;

using std::string;

class Renderer{
  private:
    RenderWindow *window;
  
  public:
    Renderer(RenderWindow *_window);
    
    void line(const Vector2f &from, const Vector2f &to, const Color &color = Color::White);
    void text(const Font &font, const string &str, const Vector2f &pos = {0.f, 0.f}, const int &size = 10, const Color &color = Color::White);

};


#endif