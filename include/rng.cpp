#include "headers/rng.hpp"

template<typename T, typename>
const T rand(T min, T max) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_real_distribution<T> dist(min, max);

  return dist(gen);
}

template const int rand<int>(int, int);
template const float rand<float>(float, float);
template const double rand<double>(double, double);


const sf::Vector2f rand_vec2f(float magnitude) {
  const float pi = 3.14159265; 
  const float angle = rand(0.f, 2 * pi);
  const float x = std::cos(angle);
  const float y = std::sin(angle);
  return sf::Vector2f(x * magnitude, y * magnitude);
}

const sf::Vector2i rand_vec2i(int magnitude) {
  const float pi = 3.14159265;
  const float angle = rand(0.f, 2 * pi);
  const float x = std::cos(angle) * magnitude;
  const float y = std::sin(angle) * magnitude;

  return sf::Vector2i(static_cast<int>(x), static_cast<int>(y));
}


