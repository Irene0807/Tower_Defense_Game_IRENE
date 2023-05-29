#ifndef SPECIALTURRET_HPP
#define SPECIALTURRET_HPP
#include "Turret.hpp"

class SpecialTurret : public Turret {
public:
    static const int Price;
    SpecialTurret(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime) override;
};
#endif // FOURTURRET_HPP
