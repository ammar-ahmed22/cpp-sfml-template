#ifndef RNG_H
#define RNG_H
#include <iostream>
#include <random>
#include <type_traits>
#include <SFML/Graphics.hpp>
#include <cmath>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
const T rand(T min, T max);

const sf::Vector2f rand_vec2f(float magnitude);
const sf::Vector2i rand_vec2i(int magnitude);

#endif


