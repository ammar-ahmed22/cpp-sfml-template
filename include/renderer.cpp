#include "headers/renderer.hpp"

Renderer::Renderer(sf::RenderWindow *_window) {
  window = _window;
}

void Renderer::line(const sf::Vector2f &from, const sf::Vector2f &to, const sf::Color &color) {
  sf::Vertex line[2];
  line[0].position = from;
  line[0].color = color;
  line[1].position = to;
  line[1].color = color;

  window->draw(line, 2, sf::Lines);
}

void Renderer::text(const sf::Font &font, const std::string &str, const sf::Vector2f &pos, const int &size, const sf::Color &color) {
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(size);
  text.setPosition(pos);
  text.setFillColor(color);
  text.setString(str);

  window->draw(text);
}