#include "score.h"

score::score()
{
    text = 0;
    scores.setCharacterSize(30);
    scores.setPosition(704, 0);
    scores.setFillColor(sf::Color::Black);
    scores.setStyle(sf::Text::Bold);
    font.loadFromFile("Fonts/arial.ttf");
    scores.setFont(font);    
}

void score::setscores()
{
    scores.setString(to_string(text));
}

int score::getscore()
{
    return text;
}

void score::brickscore(int* increment)
{
    for (int i = 0; i < 30; i++) {
        if (increment[i] != -1) {
            text += 5;
        }
    }
}

void score::enemyscore(int increment)
{
    if (increment != -1) {
        
        text += 50;
    }
}

void score::displays(sf::RenderWindow& window) const
{
    window.draw(scores);
}
