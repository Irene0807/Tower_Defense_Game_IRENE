#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "ArrowBullet.hpp"
#include "Group.hpp"
#include "FourTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootingEffect.hpp"
#include "Enemy.hpp"

const int FourTurret::Price = 40;
FourTurret::FourTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/ufo.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void FourTurret::CreateBullet() {
    bullet_num = 4;
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.

    getPlayScene()->BulletGroup->AddNewObject(new ArrowBullet(Position + Engine::Point(100, 0), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new ArrowBullet(Position + Engine::Point(-100, 0), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new ArrowBullet(Position + Engine::Point(0, 100), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new ArrowBullet(Position + Engine::Point(0, -100), diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}

void FourTurret::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	imgBase.Position = Position;
	imgBase.Tint = Tint;
	if (!Enabled)
		return;

    while (!bullet_num) {

        CreateBullet();
    }
}
