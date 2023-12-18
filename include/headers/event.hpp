#ifndef EVENT_H
#define EVENT_H
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>
#include <iostream>
#include "debug.hpp"


enum EventType {
  MousePress,
  MouseRelease,
  Close,
  Resize,
  MouseScroll
};

class EventContext {
  public:
    sf::RenderWindow *window;
    sf::Event event;
    sf::View &view;

    EventContext(sf::RenderWindow *p_window, sf::View &p_view);
};

using EventListener = std::function<void(EventContext &)>;

class EventHandler{
  public:
    EventHandler(sf::RenderWindow* _window, sf::View &view);

    void addEventListener(EventType event_type, EventListener listener);
    void update();

  private:
    EventContext m_event_ctx;
    std::map<EventType, EventListener> listeners;
    void handleEvent(EventType event_type);
};

void handleClose(EventContext &event_ctx);
void handleMousePress(EventContext &event_ctx);
void handleMouseRelease(EventContext &event_ctx);
void handleResize(EventContext &event_ctx);
void handleScroll(EventContext &event_ctx);

#endif