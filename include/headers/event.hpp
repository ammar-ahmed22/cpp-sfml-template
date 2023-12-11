#ifndef EVENT_H
#define EVENT_H
#include <SFML/Graphics.hpp>
#include <map>
#include <functional>
#include <iostream>

using sf::Event;
using sf::RenderWindow;
using std::map;
using std::cout;
using std::endl;

using EventListener = std::function<void(Event, RenderWindow*)>;

enum EventType {
  MousePress,
  MouseRelease,
  Close
};

class EventHandler{
  public:
    EventHandler(RenderWindow* _window);

    void add_event_listener(EventType event_type, EventListener listener);
    void update();

  private:
    RenderWindow *window;
    Event event;
    map<EventType, EventListener> listeners;
    void handle_event(EventType event_type, Event event, RenderWindow *window);
};

void handle_close(Event event, RenderWindow *window);
void handle_mouse_press(Event event, RenderWindow *window);
void handle_mouse_release(Event event, RenderWindow *window);

#endif