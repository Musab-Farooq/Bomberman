#include "Player.h"

const int x = 0;
const int y = 1;
const int exists = 2;

Player::Player(string img)
{
    playersound.openFromFile("Sound/Bounce1.mp3");
    playersound.setVolume(50);

    this->player[x] = 0;
    this->player[y] = 0;
    this->playerTexture.loadFromFile(img);
    this->playerSprite.setTexture(this->playerTexture);
    this->playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    this->brickdestroyed = new int[30];

    player[exists] = true;
}

float Player::getx()
{
    return player[x];
}

float Player::gety()
{
    return this->player[y];
}

void Player::Movement(sf::Event e, float* xarray, float* yarray)
{
    int yaxis = player[y];
    int xaxis = player[x];

    bool right = true;
    bool left = true;
    bool up = true;
    bool down = true;
    bool destroy = false;

    for (int i = 0; i < 30; i++) {

        if ((xarray[i] == player[x] + 64) && (yarray[i] == player[y])) {
            
            right = false;
        }

        if ((xarray[i] == player[x] - 64) && (yarray[i] == player[y])) {
            left = false;
        }

        if ((yarray[i] == player[y] + 64) && (xarray[i] == player[x])) {
            down = false;
        }

        if ((yarray[i] == player[y] - 64) && (xarray[i] == player[x])) {
            up = false;
        }
    }

    if (e.key.code == sf::Keyboard::D && player[x] < 704 && (yaxis % 128 == 0 && yaxis != 64) && right)
    {
        player[x] += 64;
        playersound.play();
        this->playerTexture.loadFromFile("Textures/playerRR.png");
        this->playerSprite.setTexture(this->playerTexture);
        this->playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    if (e.key.code == sf::Keyboard::A && player[x] > 0 && (yaxis % 128 == 0 && yaxis != 64) && left)
    {
        player[x] -= 64;
        playersound.play();
        this->playerTexture.loadFromFile("Textures/playerLR.png");
        this->playerSprite.setTexture(this->playerTexture);
        this->playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    if (e.key.code == sf::Keyboard::W && player[y] > 0 && (xaxis % 128 == 0 && xaxis != 64) && up)
    {
        player[y] -= 64;
        playersound.play();
        this->playerTexture.loadFromFile("Textures/playerU.png");
        this->playerSprite.setTexture(this->playerTexture);
        this->playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    if (e.key.code == sf::Keyboard::S && player[y] < 704 && (xaxis % 128 == 0 && xaxis != 64) && down)
    {
        player[y] += 64;
        playersound.play();
        this->playerTexture.loadFromFile("Textures/playerD.png");
        this->playerSprite.setTexture(this->playerTexture);
        this->playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    }
    playerSprite.setPosition(player[x], player[y]);

    if (e.key.code == sf::Keyboard::Space)
    {
        bomb.setposition(player[x], player[y]);
    }
}

int* Player::Destroybrick(sf::Event e, float* xarray, float* yarray)
{
    for (int i = 0; i < 30; i++) {
        brickdestroyed[i] = -1;
    }

    if (e.key.code == sf::Keyboard::Space)
    {
        for (int i = 0; i < 30; i++) {
            if ((((xarray[i] == bomb.getpositionx() - 64) || (xarray[i] == bomb.getpositionx() - 128) || (xarray[i] == bomb.getpositionx() + 64) || (xarray[i] == bomb.getpositionx() + 128)) && (yarray[i] == bomb.getpositiony())) || (((yarray[i] == bomb.getpositiony() - 64) || (yarray[i] == bomb.getpositiony() - 128) || (yarray[i] == bomb.getpositiony() + 64) || (yarray[i] == bomb.getpositiony() + 128)) && (xarray[i] == bomb.getpositionx()))) {
                brickdestroyed[i] = i;
            }
        }
    }

    return brickdestroyed;
}

int Player::enemydestroy(int* X, int* Y)
{
    bool b = true;

    for (int i = 0; i < 5; i++) {
        if ((bomb.getpositionx() == X[i] - 64 && bomb.getpositiony() == Y[i]) || (bomb.getpositionx() == X[i] + 64 && bomb.getpositiony() == Y[i]) || (bomb.getpositiony() == Y[i] - 64 && bomb.getpositionx() == X[i]) || (bomb.getpositiony() == Y[i] + 64 && bomb.getpositionx() == X[i])) {
            sf::Music kill;
            kill.openFromFile("Sound/kill.wav");
            kill.setVolume(100);
            kill.play();
            b = false;
            return i;
        }
    }

    if (b) {
        return -1;
    }
}

bool Player::death(int* X, int* Y)
{
    for (int i = 0; i < 5; i++) {
        if ((player[x] == X[i] - 68 && player[y] == Y[i]) || (player[x] == X[i] + 60 && player[y] == Y[i]) || (player[y] == Y[i] - 60 && player[x] == X[i]) || (player[y] == Y[i] + 68 && player[x] == X[i])) {
            player[exists] = false;
            return true;
        }
    }

    return false;
}

void Player::draw(sf::RenderWindow& window)
{
    bomb.draw(window);
    if (player[exists]) {
        window.draw(playerSprite);
    }
   
}

