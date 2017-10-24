#ifndef MATERIAL_H
#define MATERIAL_H

#include <PhysicsObject.h>


class Material : public PhysicsObject
{
    // defined as c/v
    // where c is the speed of light in vacuum and v is the phase velocity of light in the medium
    const float refractive_index = 1;
    public:
        Material();
        virtual ~Material();

    protected:

    private:
};

#endif // MATERIAL_H
