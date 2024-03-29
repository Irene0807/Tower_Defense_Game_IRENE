#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "MachineGun2Turret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootingEffect.hpp"

const int MachineGun2Turret::Price = 40;
MachineGun2Turret::MachineGun2Turret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 300, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGun2Turret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point right = Engine::Point(cos(Rotation - ALLEGRO_PI), sin(Rotation - ALLEGRO_PI));
    Engine::Point normalized = diff.Normalize();
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + right.Normalize() *6 + normalized * 36, diff, rotation, this));

    Engine::Point left = Engine::Point(cos(Rotation), sin(Rotation));
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + left.Normalize() *6 + normalized * 36, diff, rotation, this));
    
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}
