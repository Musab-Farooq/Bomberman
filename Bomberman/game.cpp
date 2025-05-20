#include "game.h"

const int resolutionX = 768;
const int resolutionY = 768;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX;
const int gameColumns = resolutionY / boxPixelsY;

int gameGrid[gameRows][gameColumns] = {};

const int x = 0;
const int y = 1;
const int exists = 2;

Bomberman::Bomberman()
{
}

void Bomberman::play()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Bomberman", sf::Style::Close | sf::Style::Titlebar);


    window.setSize(sf::Vector2u(640, 640));
    window.setPosition(sf::Vector2i(100, 0));

    // BackGround Music
    sf::Music bgMusic;
    bgMusic.openFromFile("Music/bgmusic.mp3");
    bgMusic.play();
    bgMusic.setVolume(20);

    // Initializing Background.
    Screens background, startscreen,highscore,gameover;
    background.setscreen("Textures/background.png", 0);
    startscreen.setscreen("Textures/startscreen.png", 3);
    highscore.setscreen("Textures/highscore.png",1);
    gameover.setscreen("Textures/gameover.png", 0);

    startscreen.setbuttons(1, "Textures/button.png", 250, 70, 250, 470, sf::Color::White); // Start Button 
    startscreen.setbuttons(2, "Textures/highscorebutton.png", 250, 70, 250, 570, sf::Color::White); // highscre button
    startscreen.setbuttons(3, "Textures/exitbutton.png", 250, 70, 250, 670, sf::Color::White);// Exit button
    highscore.setbuttons(1, "Textures/backbutton.png", 290, 90, 470, 670, sf::Color::White);

    bool Startscreen = true; 
    bool end = true;
    bool gamescreen = false;
    bool highscorescreen = true;
    bool scorescreen = true;
    bool stop = true;

    // Initializing Player and Player Sprites.
    Player player("Textures/player.png");

    Blocks block;

    Brick brick;

    Enemy enemy;
    enemy.setposition(brick.getpositionx(), brick.getpositiony());

    // Mouse
    sf::Mouse m;

    // score

    score scores;

    // Highscore

    Highscore hscore;

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e)) {

            if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                exit(0);
            }

            if (Startscreen && !gamescreen) {
                startscreen.functionality(m, e, window);
                Startscreen = startscreen.screenexist(e, 1);
                highscorescreen = startscreen.screenexist(e, 2);
                end = startscreen.screenexist(e, 3);
                if (!Startscreen) {
                    gamescreen = true;
                }
                if (!end) {
                    exit(0);
                }
            }

            if (gamescreen && !Startscreen) {
                if (e.type == sf::Event::KeyPressed)
                {
                    player.Movement(e, brick.getpositionx(), brick.getpositiony());
                    scores.brickscore(player.Destroybrick(e, brick.getpositionx(), brick.getpositiony()));
                    scores.setscores();
                    brick.existance(player.Destroybrick(e, brick.getpositionx(), brick.getpositiony()));
                    if (e.key.code == sf::Keyboard::BackSpace) {
                        gamescreen = background.screenexist(e, 0);
                    }
                    if (!gamescreen) {
                        Startscreen = true;
                    }
                }
            }

            if (!highscorescreen) {
                Startscreen = false;
                gamescreen = false;
                highscore.functionality(m, e, window);
                scorescreen = highscore.screenexist(e, 1);
                if (!scorescreen) {
                    Startscreen = true;
                    highscorescreen = true;
                }
            }
        }

        if (player.death(enemy.getpositionX(), enemy.getpositionY())) {
            if (stop) {
                hscore.save(scores.getscore());
                stop = false;
            }
            Startscreen = false;
            gamescreen = false;
            gameover.draw(window);
            sf::Clock end;
            bgMusic.pause();
            sf::Music death;
            death.openFromFile("Music/death.wav");
            death.setVolume(50);
            death.play();
            if (end.getElapsedTime().asSeconds() >= 3) {
                exit(0);
                end.restart();
            }
        }

        if (Startscreen && !gamescreen) {
            startscreen.draw(window);
        }

        if (gamescreen && !Startscreen) {
            enemy.movements();
            background.draw(window);
            player.draw(window);
            block.draw(window);
            scores.enemyscore(player.enemydestroy(enemy.getpositionX(), enemy.getpositionY()));
            scores.setscores();
            enemy.draw(window, player.enemydestroy(enemy.getpositionX(), enemy.getpositionY()));
            brick.draw(window);
            scores.displays(window);
        }

        if (!highscorescreen) {
            highscore.draw(window);
            hscore.display(window);
        }

        window.display();
        window.clear();
    }
}
