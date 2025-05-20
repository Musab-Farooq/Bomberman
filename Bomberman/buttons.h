#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
using namespace std;

class Buttons {

    sf::Texture buttonTexture;
    sf::RectangleShape button;
    string path;
    sf::Color color;
    float buttonsizeX;
    float buttonsizeY;
    float buttonpositionX;
    float buttonpositionY;
    bool exist;


public:
    Buttons();
	void setButton(string path, float Bsizex, float Bsizey, float Bposx, float Bposy, sf::Color c);
    void hover(float Bsizex, float Bsizey, float Bposx, float Bposy);
    void functionality(sf::Mouse m, sf::Event e, sf::RenderWindow& window);
    bool getcheck();
    void draw(sf::RenderWindow& window);
};