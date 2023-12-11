#include "headers/renderer.hpp"

Renderer::Renderer(RenderWindow *_window) {
  window = _window;
}

void Renderer::line(const Vector2f &from, const Vector2f &to, const Color &color) {
  Vertex line[2];
  line[0].position = from;
  line[0].color = color;
  line[1].position = to;
  line[1].color = color;

  window->draw(line, 2, Lines);
}

void Renderer::text(const Font &font, const string &str, const Vector2f &pos, const int &size, const Color &color) {
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(size);
  text.setPosition(pos);
  text.setFillColor(color);
  text.setString(str);

  window->draw(text);
}