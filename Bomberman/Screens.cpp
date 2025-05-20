#include "Screens.h"

Screens::Screens()
{
	this->path = "";
	bool exist = true;
	this->numberofbuttons = 0;
	button = NULL;
}

void Screens::setscreen(string path, int num)
{
	this->path = path;
	screenTexture.loadFromFile(this->path);
	screenSprite.setTexture(screenTexture);
	screenSprite.setColor(sf::Color(255, 255, 255, 255 * 0.9));

	button = new Buttons[num];
	this->numberofbuttons = num;
}

void Screens::setbuttons(int num, string path, float Bsizex, float Bsizey, float Bposx, float Bposy, sf::Color c)
{
	button[num-1].setButton(path, Bsizex, Bsizey, Bposx, Bposy,c);
}

void Screens::functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window)
{
	for (int i = 0; i < this->numberofbuttons; i++) {
		button[i].functionality(m, e,window);
	}
}

bool Screens::screenexist(sf::Event e, int n)
{
	if (numberofbuttons == 0) {
		exist = false;	
		return exist;
	}

	else {
		return button[n-1].getcheck();
	}
	
}

void Screens::draw(sf::RenderWindow& window)
{
	window.draw(screenSprite);
	for (int i = 0; i < this->numberofbuttons; i++) {
		button[i].draw(window);
	}
}
