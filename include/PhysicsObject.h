#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H


class PhysicsObject
{
    public:
        PhysicsObject(){};
        virtual ~PhysicsObject(){};
        virtual sf::VertexArray getDrawable() = 0;
        virtual void collide (const class Lightray& ray, const class Hitresult& hitresult) = 0;
    protected:

    private:
};

#endif // PHYSICSOBJECT_H
