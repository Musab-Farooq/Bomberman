#include "buttons.h"

class Screens {

	string path;
	sf::Texture screenTexture;
	sf::Sprite screenSprite;
	bool exist;
	Buttons* button;
	int numberofbuttons;

public:

	Screens();
	void setscreen(string path, int num);
	void setbuttons(int num, string path, float Bsizex, float Bsizey, float Bposx, float Bposy, sf::Color c);
	void functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window);
	bool screenexist(sf::Event e, int n);
	void draw(sf::RenderWindow& window);
};