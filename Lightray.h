#ifndef LIGHTRAY_H
#define LIGHTRAY_H

#include <SFML/Graphics.hpp>

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& obj);

using namespace std;

class Lightray
{
    const int defaultLenght;
    double angle;
    sf::VertexArray vertices;
public:
    void calculateVertices();
    void setAngle(double angle);
    void setStartingPosition(sf::Vector2f position);
    Lightray(double angle, sf::Vector2f starting_position, const int maxLenght);
    virtual ~Lightray();
    sf::VertexArray getDrawable() const
    {
        return vertices;
    }
protected:

private:
};

#endif // LIGHTRAY_H
