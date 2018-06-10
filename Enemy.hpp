#ifndef ENEMY_HPP
#   define  ENEMY_HPP
#   include "Entity.hpp"

class   Enemy : public Entity {
    public:
        Enemy(WINDOW *, char);
        ~Enemy();
        Enemy & operator=(Enemy const & enemy);
        virtual void    display();
        void            updatePos();

        void            setPosition(int x, int y);

        WINDOW * win;
};

#endif