#ifndef MIRROR_H
#define MIRROR_H

#include <TwoPointObject.h>


class Mirror : public TwoPointObject
{
    public:
        Mirror(sf::Vector2f firstPos, sf::Vector2f secondPos) : TwoPointObject(firstPos, secondPos) {};
        virtual ~Mirror();

    protected:

    private:
};

#endif // MIRROR_H
