#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H


class PhysicsObject
{
    public:
        PhysicsObject(){};
        virtual ~PhysicsObject(){};
        virtual bool collide (const class Lightray& ray, class Hitresult& hitresult, bool debugDraw = false) = 0;
        virtual class sf::VertexArray getDrawable() = 0;
        void print (){}
    protected:

    private:
};

#endif // PHYSICSOBJECT_H
