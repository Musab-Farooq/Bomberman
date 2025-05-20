#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
using namespace std;

class score {

protected:

	int text;
	sf::Text scores;
	sf::Font font;

public:
	score();
	void setscores();
	int getscore();
	void brickscore(int* increment);
	void enemyscore(int increment);
	void displays(sf::RenderWindow& window) const;
};