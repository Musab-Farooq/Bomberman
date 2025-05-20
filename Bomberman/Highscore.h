#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <fstream>
#include "score.h"
using namespace std;

class Highscore : public score{

public:
	Highscore();
	void save(int score);
	void display(sf::RenderWindow& window);
};