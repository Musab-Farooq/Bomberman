#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include "Bomb.h"
using namespace std;

class Player {

	float player[3];
	Bomb bomb;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Clock clock;
	int* brickdestroyed;
	sf::Music playersound;

public:

	Player(string img);
	float getx();
	float gety();
	void Movement(sf::Event e, float* xarray, float* yarray);
	int* Destroybrick(sf::Event e, float* xarray, float* yarray);
	int enemydestroy(int* X, int* Y);
	bool death(int* X, int* Y);
	void draw(sf::RenderWindow& window);
};