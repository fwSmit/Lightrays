#include "vectorOperations.h"

namespace op
{

sf::Vector2f rotate(const sf::Vector2f& in, const float r)
{
    sf::Vector2f result;
    result.x = in.x * cos(r) - in.y * sin(r);
    result.y = in.x * sin(r) + in.y * cos(r);
    return result;
}


float angle(const sf::Vector2f& a, const sf::Vector2f& b)
{
    auto l = length(a)*length(b);
    return acos(dot(a,b)/(l));
}

sf::Vector2f normalize(const sf::Vector2f& a)
{
    sf::Vector2f result = a;
    result /= length(a);
    return result;
}



sf::Vector2f deltaPos(const sf::Vector2f& a, const sf::Vector2f& b)
{
    return b - a;
}


float dot(const sf::Vector2f& a, const sf::Vector2f& b)
{
    sf::Vector2f result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    return result.x + result.y;
}

float length(const sf::Vector2f& in)
{
    return sqrt(pow(in.x, 2) + pow(in.y, 2));
}

float length(const sf::Vector2u& in)
{
    return sqrt(pow(in.x, 2) + pow(in.y, 2));
}

float sq_lenght(const sf::Vector2f& in)
{
    return pow(in.x, 2) + pow(in.y, 2);
}

}
