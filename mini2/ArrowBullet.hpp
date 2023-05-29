#ifndef ARROWBULLET_HPP
#define ARROWBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class ArrowBullet : public Bullet {
public:
    explicit ArrowBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;
};
#endif // WOODBULLET_HPP
