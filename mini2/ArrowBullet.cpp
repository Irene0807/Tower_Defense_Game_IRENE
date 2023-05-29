#include <allegro5/base.h>
#include <random>
#include <string>

#include "Turret.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ArrowBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Collider.hpp"


class Turret;

ArrowBullet::ArrowBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/arrow.png", 300, 2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
}


void ArrowBullet::OnExplode(Enemy* enemy) {
    std::random_device dev; 
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-1.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
void ArrowBullet::Update(float deltaTime) {
	float T = 2 * ALLEGRO_PI * 100 / speed; //¶g´Á
	float rotation1 = 2 * ALLEGRO_PI * deltaTime / T;
	float rotation0 = atan2(Position.y - parent->Position.y, Position.x - parent->Position.x);
	Position.x = parent->Position.x + 100 * cos(rotation1 + rotation0);
	Position.y = parent->Position.y + 100 * sin(rotation1 + rotation0);
	
	//Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
			OnExplode(enemy);
			enemy->Hit(damage);
			parent->bullet_num--;
			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize())) {
		parent->bullet_num--;
		getPlayScene()->BulletGroup->RemoveObject(objectIterator);
	}
}

