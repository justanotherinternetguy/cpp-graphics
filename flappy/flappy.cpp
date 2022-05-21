// Recreate flappy bird in SFML, cpp
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

/*
* birdTexture - TEXTURE FOR BIRD
* bird - ACTUAL SPRITE
*/

int main() {
    int x = 2560;
    int y = 1600;
    // create the window
    sf::RenderWindow window(sf::VideoMode(x, y), "flappy bird recreation");
    sf::Texture birdTexture;
    // error
    if (!birdTexture.loadFromFile("./data/bird.png")) {
        cerr << "Failed to load image" << '\n';
        exit(1);
    }

    sf::Sprite bird;
    bird.setTexture(birdTexture);
    bird.setScale(sf::Vector2f(0.4f, 0.4f));
    bird.setOrigin(sf::Vector2f(-x/2, -y/2));

    sf::Font font;
    if (!font.loadFromFile("./data/arial.ttf")) {
        cerr << "Failed to load image" << '\n';
        exit(1);
    }
    int score = 0;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Green);
    text.setString(to_string(score));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // close
            if (event.type == sf::Event::Closed) { window.close(); }

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // transform the mouse position from window coordinates to world coordinates
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // retrieve the bounding box of the sprite
                sf::FloatRect bounds = bird.getGlobalBounds();

                // hit test
                if (bounds.contains(mouse)) {
                    score++;
                    text.setString(to_string(score));
                }
            }

            window.clear(sf::Color::Black);

            window.draw(text);
            window.draw(bird);

            window.display();
        }
    }

    return 0;
}