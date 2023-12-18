#include "headers/event.hpp"

EventContext::EventContext(sf::RenderWindow *p_window, sf::View &p_view) : window(p_window), view(p_view) {}

EventHandler::EventHandler(sf::RenderWindow *_window, sf::View &_view) : m_event_ctx(_window, _view) {
  listeners = {};
}

void EventHandler::addEventListener(EventType event_type, EventListener listener) {
  if (listeners.find(event_type) != listeners.end()) {
    listeners[event_type] = listener;
  } else {
    listeners.insert({ event_type, listener });
  }
}

void EventHandler::handleEvent(EventType event_type) {
  if (listeners.find(event_type) != listeners.end()) {
    EventListener listener = listeners.at(event_type);
    listener(m_event_ctx);
  }
}

void EventHandler::update() {
  sf::RenderWindow *window = m_event_ctx.window;
  sf::Event &event = m_event_ctx.event;
  while(window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      handleEvent(Close);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
      handleEvent(MousePress);
    }

    if (event.type == sf::Event::MouseButtonReleased) {
      handleEvent(MousePress);
    }

    if (event.type == sf::Event::Resized) {
      handleEvent(Resize);
    }

    if (event.type == sf::Event::MouseWheelScrolled) {
      handleEvent(MouseScroll);
    }
  }
}

void handleClose(EventContext &event_ctx) {
  std::cout << "close called" << std::endl;
  event_ctx.window->close();
}

void handleMousePress(EventContext &event_ctx) {
  std::cout << "press" << std::endl;
}
void handleMouseRelease(EventContext &event_ctx) {
  std::cout << "release" << std::endl;
}

void handleResize(EventContext &event_ctx) {
  sf::Event &event = event_ctx.event;
  sf::FloatRect visible_area(0, 0, event.size.width, event.size.height);
  event_ctx.window->setView(sf::View(visible_area));
}

void handleScroll(EventContext &event_ctx) {
  sf::Event &event = event_ctx.event;
  if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
    float zoom_factor = 1 + (event.mouseWheelScroll.delta / 100.f);
    sf::Vector2i mouse_pos = sf::Vector2i(event.mouseWheelScroll.x, event.mouseWheelScroll.y);
    sf::Vector2f before = event_ctx.window->mapPixelToCoords(mouse_pos, event_ctx.view);
    event_ctx.view.zoom(zoom_factor);
    sf::Vector2f after = event_ctx.window->mapPixelToCoords(mouse_pos, event_ctx.view);
    event_ctx.view.move(before - after);
  }
}