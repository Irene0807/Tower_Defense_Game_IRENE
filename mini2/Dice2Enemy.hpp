#ifndef DICE2ENEMY_HPP
#define DICE2ENEMY_HPP
#include "Enemy.hpp"


class Dice2Enemy : public Enemy {
public:
    Dice2Enemy(int x, int y);
    void OnExplode();
};
#endif // REDNORMALENEMY_HPP
