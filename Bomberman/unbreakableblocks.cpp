#include "unbreakableblocks.h"

const int x = 0;
const int y = 1;
const int exists = 2;

Blocks::Blocks()
{
    blocksTexture.loadFromFile("Textures/blocks.png");

    float startx = 64;
    float starty = 64;

    for (int i = 0; i < 36; i++)
    {

        if (i % 6 == 0 && i != 0) {
            starty += 128;
            startx = 64;
        }

        blocks[i][x] = startx;
        blocks[i][y] = starty;
        blocks[i][exists] = 1;
        blocksSprite[i].setTexture(blocksTexture);
        blocksSprite[i].setTextureRect(sf::IntRect(0, 0, 64, 64));

        startx += 128;
    }
}

void Blocks::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 36; i++)
    {
        if (blocks[i][exists])
        {
            blocksSprite[i].setPosition(blocks[i][x], blocks[i][y]);
            window.draw(blocksSprite[i]);
        }
    }
}
