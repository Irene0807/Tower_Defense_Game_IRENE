#ifndef FOURTURRET_HPP
#define FOURTURRET_HPP
#include "Turret.hpp"

class FourTurret : public Turret {
public:
    static const int Price;
    FourTurret(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
};
#endif // FOURTURRET_HPP
