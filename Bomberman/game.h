#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <cmath>
#include "unbreakableblocks.h"
#include "Player.h"
#include "Brick.h"
#include "Enemy.h"
#include "Screens.h"
#include "Highscore.h"
using namespace std;

class Bomberman {
public:
	Bomberman();
	void play();
};