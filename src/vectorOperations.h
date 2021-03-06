
#ifndef VECTOR_OPERATIONS
#define VECTOR_OPERATIONS

#include "SFML/System/Vector2.hpp"
#include <cmath>

namespace op
{

/**
 * \return vector rotated by x radians clockwise
 */
sf::Vector2f rotate(const sf::Vector2f& in, const float x);


/**
 * \return vector in the direction of a, but with length 1
 */
sf::Vector2f normalize(const sf::Vector2f& a);

/**
 * \return smallest angle between vectors a and b
 */
float angle(const sf::Vector2f& a, const sf::Vector2f& b);


/**
 * \return difference in position of the 2 vectors
 */
sf::Vector2f deltaPos(const sf::Vector2f& a, const sf::Vector2f& b);


/**
 * \return dot product of vectors a and b
 */
float dot(const sf::Vector2f& a, const sf::Vector2f& b);

/**
 * \return lenght of vector in
 */
float length(const sf::Vector2f& in);

/**
 * \return lenght of vector in
 */
float length(const sf::Vector2u& in);

/**
 * \return square lenght of vector in
 */
float sq_lenght(const sf::Vector2f& in);


}
#endif // VECTOR_OPERATIONS
