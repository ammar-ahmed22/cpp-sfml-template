#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "event.hpp"
#include "renderer.hpp"

int main() {

  // Constants
  const float    window_width  = 1200.f;
  const float    window_height = 800.f;
  const std::string   window_name   = "Test";
  const int      grid_spacing  = 40;
  const int      num_rows      = window_height / grid_spacing;
  const int      num_cols      = window_width / grid_spacing;
  const sf::Vector2f center        = { window_width / 2, window_height / 2 };

  // Creating window
  sf::ContextSettings settings;
  settings.antialiasingLevel = 1.0;
  sf::RenderWindow window(
    sf::VideoMode(window_width, window_height), 
    window_name, 
    sf::Style::Default, 
    settings
  );

  // Renderer
  Renderer renderer(&window);

  // View
  sf::View view(center, sf::Vector2f(window_width, window_height));

  //Event handler
  EventHandler event_handler(&window, view);
  event_handler.addEventListener(Close, handleClose);
  event_handler.addEventListener(MousePress, handleMousePress);
  event_handler.addEventListener(MouseRelease, handleMouseRelease);
  event_handler.addEventListener(Resize, handleResize);
  event_handler.addEventListener(MouseScroll, handleScroll);

  // Loading font for text
  sf::Font font;
  if (!font.loadFromFile("./resources/SF-Pro-Text-Regular.otf")) {
    std::cout << "Font could not be loaded!" << std::endl;
  }

  

  while(window.isOpen()) {
    // Clear the screen
    window.clear(sf::Color::Black);
    // Update the event handler
    event_handler.update(); 
    // Set the view
    window.setView(view);

    // Drawing some things :)

    // Drawing a grid with lines
    // Vertical lines
    for (int i = 0; i < num_cols; ++i) {
      const sf::Vector2f start(grid_spacing * i, 0);
      const sf::Vector2f end(grid_spacing * i, window_height);
      renderer.line(start, end);
    }

    // Horizontal lines
    for (int i = 0; i < num_rows; ++i) {
      const sf::Vector2f start(0, grid_spacing * i);
      const sf::Vector2f end(window_width, grid_spacing * i);
      renderer.line(start, end);
    }



    renderer.text(font, "Hello World!", center, 30);

    window.display();
  }

  return 0;
}