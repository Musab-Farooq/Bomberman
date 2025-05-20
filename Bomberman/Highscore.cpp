#include "Highscore.h"

Highscore::Highscore()
{
    font.loadFromFile("Fonts/arial.ttf");
    scores.setFont(font);

    scores.setCharacterSize(100);
    scores.setPosition(400, 130);
    scores.setFillColor(sf::Color::Red);
    scores.setStyle(sf::Text::Bold);
    scores.setOutlineColor(sf::Color::Black);
    scores.setOutlineThickness(5);
}

void Highscore::save(int score)
{
    ofstream save("highscore.txt", ios::in | ios::app);
    if (!save.is_open()) {
        cout << "Error while input opening file " << endl;
    }

    save << score << endl;
    save.close();
}

void Highscore::display(sf::RenderWindow& window)
{
    ifstream show("highscore.txt", ios::out);
    if (!show.is_open()) {
        cout << "Error while opening output file " << endl;
    }

    int output = 0;
    int count = 0;
    int* temp = new int[1000];
    while (show >> output) {
        temp[count] = output;
        count++;
    }

    sort(temp, temp + count);

    int x = 1;
    for (int i = count-1; i > count-4; i--) {

        output = temp[i];
        scores.setPosition(300, 150 + x);
        scores.setString(to_string(output));
        x += 150;
        window.draw(scores);
    }

    show.close();
}
