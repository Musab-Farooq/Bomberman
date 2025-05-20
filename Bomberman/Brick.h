#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <ctime>
using namespace std;

class Brick {
	
	float brick[30][3];
	float positionx[30];
	float positiony[30];
	sf::Texture brickTexture;;
	sf::Sprite brickSprite[30];

public:
	Brick();
	float* getpositionx();
	float* getpositiony();
	void existance(int* num);
	void draw(sf::RenderWindow& window);
};