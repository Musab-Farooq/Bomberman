#include "Enemy.h"

const int x = 0;
const int y = 1;
const int exists = 2;
float directionX = 0.05;
float directionY = 0.05;

Enemy::Enemy()
{
    this->numberofenemies = 5;
    enemy = new float* [numberofenemies];
    for (int i = 0; i < numberofenemies; i++) {
        enemy[i] = new float[3];
    }

    enemySprite = new sf::Sprite[numberofenemies];
    PosX = new int[5];
    PosY = new int[5];
}

void Enemy::setposition(float* notpositionx, float* notpositiony) 
{
    enemyTexture.loadFromFile("Textures/enemy.png");
    float startx = 0;
    float starty = 0;
    bool notbreak = true;

    for (int i = 0; i < 5; i++)
    {

        while (1 > 0) {

            while (1 > 0) {
                int n = (rand() % 705);
                if (n % 64 == 0 && n != 64 && n != 192 && n != 320 && n != 448 && n != 576 && n != 704 && n != 0) {
                    startx = n;
                    break;
                }
            }

            while (1 > 0) {
                int n = (rand() % 705);
                if (n % 64 == 0 && n != 64 && n != 192 && n != 320 && n != 448 && n != 576 && n != 704 && n != 0) {
                    starty = n;
                    break;
                }
            }

            for (int i = 0; i < 30; i++) {
                if (startx == notpositionx[i] && starty == notpositiony[i]) {
                    notbreak = true;
                }
                else {
                    notbreak = false;
                }
            }

            if (!notbreak) {
                break;
            }
        }


        enemy[i][x] = startx;
        enemy[i][y] = starty;
        enemy[i][exists] = 1;
        enemySprite[i].setTexture(enemyTexture);
        enemySprite[i].setTextureRect(sf::IntRect(0, 0, 64, 64));
        enemySprite[i].setPosition(enemy[i][x], enemy[i][y]);
    }
}

int* Enemy::getpositionX()
{
    for (int i = 0; i < 5; i++) {
        PosX[i] = enemy[i][x];
    }

    return PosX;
}

int* Enemy::getpositionY()
{
    for (int i = 0; i < 5; i++) {
        PosY[i] = enemy[i][y];
    }

    return PosY;
}

void Enemy::movements()
{
   for (int i = 0; i < 5; i++) {
       if (enemy[i][exists]) {
           if (enemy[i][x] >= 700) {
               directionX *= -1;
           }

           if (enemy[i][x] <= 2) {
               directionX *= -1;
           }

           if (enemy[i][y] >= 700) {
               directionY *= -1;
           }

           if (enemy[i][y] <= 2) {
               directionY *= -1;
           }

           if (enemy[i][x] >= 0 && i < 3) {
               enemy[i][x] += directionX;
           }

           if (enemy[i][y] >= 0 && i >= 3) {
               enemy[i][y] += directionY;
           }
       }
    }
}

void Enemy::draw(sf::RenderWindow& window, int n)
{
    if (n >= 0 && n < 5) {
        enemy[n][exists] = false;
    }

    for (int i = 0; i < 5; i++)
    {
        if (enemy[i][exists])
        {
            enemySprite[i].setPosition(enemy[i][x], enemy[i][y]);
            window.draw(enemySprite[i]);
        }

        if (!enemy[i][exists]) 
        {
            enemy[i][x] = -1;
            enemy[i][y] = -1;
        }
    }
}

Enemy::~Enemy() 
{
    for (int i = 0; i < numberofenemies; i++) {
        delete[] enemy[i];
    }
    delete[] enemy;

    delete[] PosX;
    delete[] PosY;
    delete[] enemySprite;
}