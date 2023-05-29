#ifndef SPECIALBULLET_HPP
#define SPECIALBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class SpecialBullet : public Bullet {
public:
    explicit SpecialBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;
};
#endif // WOODBULLET_HPP
