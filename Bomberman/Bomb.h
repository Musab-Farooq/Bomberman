#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
using namespace std;

class Bomb {

	float bomb[3];
	sf::Texture bombTexture;
	sf::Sprite bombSprite;
	sf::Clock explosiontime;

public:
	
	Bomb();
	float getpositionx();
	float getpositiony();
	void setposition(float xaxis, float yaxis);
	void draw(sf::RenderWindow& window);
};