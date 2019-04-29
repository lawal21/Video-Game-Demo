#include "Bullets.h"

Bullets::Bullets(bool is_enemy)
{
	if (is_enemy) {
		ofLoadImage(Bullet, "Enemy Bullet.png");
		bullet_height = 2;
		enemy = is_enemy;
	}
	else {
		ofLoadImage(Bullet, "Player Bullet.png");
		bullet_height = 1;
		enemy = is_enemy;
	}
}


bool Bullets::MonsterCollision(Monsters monster) {
	if (PixelWithinBounds(LocationTopLeft, monster.LocationTopLeft, monster.LocationBottomRight) ||
		PixelWithinBounds(LocationBottomRight, monster.LocationTopLeft, monster.LocationBottomRight)) {
		return true;
	}
	return false;
}

bool Bullets::PlayerCollision(Players player) {
	if (PixelWithinBounds(LocationTopLeft, player.LocationTopLeft, player.LocationBottomRight)) {
		return true;
	}
	return false;
	
}

bool Bullets::PixelWithinBounds(Location pixel, Location tlBound, Location brBound) {
	if ((pixel.GetX() >= tlBound.GetX() && pixel.GetX <= brBound.GetX()) &&
		pixel.GetY() >= tlBound.GetY() && pixel.GetY <= brBound.GetY()) {
		return true;
	}
	return false;
}