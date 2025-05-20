#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <cmath>
using namespace std;

class Blocks {

	float blocks[36][3];
	sf::Texture blocksTexture;;
	sf::Sprite blocksSprite[36];

public:
	Blocks();
	void draw(sf::RenderWindow& window);
};