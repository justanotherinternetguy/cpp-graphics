#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Window");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;

    sf::Vector2f rectanglePosition(600, 360);
    rect.setPosition(rectanglePosition);
    rect.setSize(sf::Vector2f(50, 50));

    int r = 0;
    int g = 255;
    int b = 0;
    rect.setFillColor(sf::Color(r, g, b));

    float xVelocity = 3;
    float yVelocity = 3;


    // main event loop
    while(window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // physics

        if (rectanglePosition.x < 0 || rectanglePosition.x > 1280-50) {
            xVelocity *= -1;
            r = 255;
            b = 0;
            rect.setFillColor(sf::Color(r, g, b));
        }


        if (rectanglePosition.y < 0 || rectanglePosition.y > 720-50) {
            yVelocity *= -1;
            b = 255;
            r = 0;
            rect.setFillColor(sf::Color(r, g, b));
        }


        rectanglePosition.x += xVelocity;
        rectanglePosition.y += yVelocity;
        rect.setPosition(rectanglePosition);



        // render
        window.clear();
        window.draw(rect);
        window.display();
    }



    return 0;
}
