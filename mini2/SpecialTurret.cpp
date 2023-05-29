#include <allegro5/base.h>
#include <allegro5/allegro.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <memory>
#include<iostream>

#include "AudioHelper.hpp"
#include "SpecialBullet.hpp"
#include "Group.hpp"
#include "SpecialTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "SpecialShootingEffect.hpp"
#include "Enemy.hpp"

const int SpecialTurret::Price = 40;
SpecialTurret::SpecialTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    
    Turret("play/tower-base.png", "play/firewheel.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    std::cout << stop << " ";
    Anchor.y += 8.0f / GetBitmapHeight();
}
void SpecialTurret::CreateBullet() {
    special_bullet_num = 8;
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.

    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(100, 0), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(-100, 0), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(0, 100), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(0, -100), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(70.71, 70.71), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(-70.71, 70.71), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(70.71, -70.71), diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SpecialBullet(Position + Engine::Point(-70.71, -70.71), diff, rotation, this));

    AudioHelper::PlayAudio("gun.wav");
}

void SpecialTurret::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	imgBase.Position = Position;
	imgBase.Tint = Tint;
	if (!Enabled)
		return;
        
    while (!special_bullet_num && stop<=0) {
        CreateBullet();
        stop++;

    }
    if(!special_bullet_num && stop == 1) getPlayScene()->EffectGroup->AddNewObject(new SpecialShootingEffect(Position.x, Position.y));
    
}
