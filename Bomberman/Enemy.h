#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
using namespace std;

class Enemy {

	int numberofenemies;
	float** enemy;
	int* PosX;
	int* PosY;
	sf::Texture enemyTexture;
	sf::Sprite* enemySprite;
	sf::Clock enemyclock;

public:
	Enemy();
	void setposition(float* notpositionx, float* notpositiony);
	int* getpositionX();
	int* getpositionY();
	void movements();
	void draw(sf::RenderWindow& window, int n);
	~Enemy();
};
