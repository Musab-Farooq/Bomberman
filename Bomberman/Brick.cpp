#include "Brick.h"

const int x = 0;
const int y = 1;
const int exists = 2;

Brick::Brick()
{
    brickTexture.loadFromFile("Textures/breakblocks.png");

    float startx = 0;
    float starty = 0;
    

    for (int i = 0; i < 30; i++)
    {

        while (1 > 0) {
            int n = (rand() % 705);
            if (n % 64 == 0 && n != 64 && n != 192 && n != 320 && n != 448 && n != 576 && n != 704 ) {
                startx = n;
                break;
            }
        }


        while (1 > 0) {
            int n = (rand() % 705);
            if (n % 64 == 0 && n != 64 && n != 192 && n != 320 && n != 448 && n != 576 && n != 704) {
                if (startx == 0 && n == 0) {}

                else {
                    starty = n;
                    break;
                }
            }
        }

        brick[i][x] = startx;
        brick[i][y] = starty;
        brick[i][exists] = 1;
        brickSprite[i].setTexture(brickTexture);
        brickSprite[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
        brickSprite[i].setPosition(brick[i][x], brick[i][y]);
    }
}

float* Brick::getpositionx()
{
    for (int i = 0; i < 30; i++) {
        if (brick[i][exists]) {
            positionx[i] = brick[i][x];
        }
        else {
            positionx[i] = 768;
        }
    }

    return positionx;
}

float* Brick::getpositiony()
{
    for (int i = 0; i < 30; i++) {
        if (brick[i][exists]) {
            positiony[i] = brick[i][y];
        }
        else {
            positiony[i] = 768;
        }
    }

    return positiony;
}

void Brick::existance(int* num)
{
    for (int i = 0; i < 30; i++) {
        if (num[i] != -1){
            brick[i][exists] = false;
        }
    }
}

void Brick::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 30; i++)
    {
        if (brick[i][exists])
        {       
            window.draw(brickSprite[i]);
        }
    }
}
