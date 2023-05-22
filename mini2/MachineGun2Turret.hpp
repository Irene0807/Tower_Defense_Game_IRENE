#ifndef MACHINEGUN2TURRET_HPP
#define MACHINEGUN2TURRET_HPP
#include "Turret.hpp"

class MachineGun2Turret : public Turret {
public:
    static const int Price;
    MachineGun2Turret(float x, float y);
    void CreateBullet() override;
};
#endif // MACHINEGUNTURRET_HPP
