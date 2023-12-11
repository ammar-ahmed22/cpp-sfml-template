#include "headers/event.hpp"

EventHandler::EventHandler(RenderWindow *_window) {
  window = _window;
  listeners = {};
  event = {};
}

void EventHandler::add_event_listener(EventType event_type, EventListener listener) {
  if (listeners.find(event_type) != listeners.end()) {
    listeners[event_type] = listener;
  } else {
    listeners.insert({ event_type, listener });
  }
}

void EventHandler::handle_event(EventType event_type, Event event, RenderWindow *window) {
  if (listeners.find(event_type) != listeners.end()) {
    EventListener listener = listeners.at(event_type);
    listener(event, window);
  }
}

void EventHandler::update() {
  while(window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      handle_event(Close, event, window);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
      handle_event(MousePress, event, window);
    }

    if (event.type == sf::Event::MouseButtonReleased) {
      handle_event(MousePress, event, window);
    }
  }
}

void handle_close(Event event, RenderWindow *window) {
  cout << "close called" << endl;
  window->close();
}

void handle_mouse_press(Event event, RenderWindow *window) {
  cout << "press" << endl;
}
void handle_mouse_release(Event event, RenderWindow *window) {
  cout << "release" << endl;
}
