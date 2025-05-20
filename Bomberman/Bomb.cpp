#include "Bomb.h"

const int x = 0;
const int y = 1;
const int exists = 2;

Bomb::Bomb()
{
	bomb[exists] = false;
	bombTexture.loadFromFile("Textures/bomb.png");
	bombSprite.setTexture(bombTexture);
	bombSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Bomb::setposition(float xaxis, float yaxis)
{
	if (bomb[exists] == false) {
		bomb[x] = xaxis;
		bomb[y] = yaxis;
		bombSprite.setPosition(bomb[x], bomb[y]);
		bomb[exists] = true;
	}
}

float Bomb::getpositionx()
{
	if (bomb[exists]) {
		return bomb[x];
	}
}

float Bomb::getpositiony()
{
	if (bomb[exists]) {
		return bomb[y];
	}
}

void Bomb::draw(sf::RenderWindow& window)
{
	if (bomb[exists] == true) {
		
		window.draw(bombSprite);
		//cout << explosiontime.getElapsedTime().asSeconds() << endl;
		if (explosiontime.getElapsedTime().asSeconds() >= 3) {
			bombTexture.loadFromFile("Textures/bomb.png");
			bombSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}

		if (explosiontime.getElapsedTime().asSeconds() <= 4 && explosiontime.getElapsedTime().asSeconds() > 3) {
			bombTexture.loadFromFile("Textures/explosion.png");
			bombSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		}

		if (explosiontime.getElapsedTime().asSeconds() <= 5 && explosiontime.getElapsedTime().asSeconds() > 4) {
			bombTexture.loadFromFile("Textures/bomb.png");
			bombSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			bomb[exists] = false;
		}
	}

	else {
		explosiontime.restart();
	}
}
