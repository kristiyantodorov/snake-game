#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <string>

#include "SDLRenderer.hpp"

#include "Game.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

const int width = 60;

int main()
{
    srand(time(NULL));
    // creates a surface to load an image into the main memory
    const size_t gridSize = 20;
    const size_t max_width = 50, max_height = 50;
    std::shared_ptr<RendererInterface> rend = std::make_shared<SDLRenderer>(std::string("Snake"), max_width * gridSize, max_height * gridSize);

    Game game(rend.get(), max_width, max_height, gridSize);

    int fps = 10;

    // controls annimation loop
    int close = 0;
    Directions dir = Directions::NONE;

    // annimation loop
    while (!close) {
        SDL_Event event;

        // Events mangement
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_KEYDOWN:
                // keyboard API for key pressed
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    // printf("UP\n");
                    if ( dir != Directions::DOWN )
                        dir = Directions::UP;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    // printf("LEFT\n");
                    if ( dir != Directions::RIGHT )
                        dir = Directions::LEFT;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    // printf("DOWN\n");
                    if ( dir != Directions::UP )
                        dir = Directions::DOWN;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    // printf("RIGHT\n");
                    if ( dir != Directions::LEFT )
                        dir = Directions::RIGHT;
                    break;
                case SDL_SCANCODE_Q:
                    close = 1;
                    break;
                }

            }
        }

        rend->setDrawColor(0, 0, 0);
        rend->clear();

        try {
            game.drawFrame(dir);
        } catch (std::out_of_range& ex) {
            rend->delay(1000);
            close = 1;
        }

        // triggers the double buffers
        // for multiple rendering

        rend->render();
        rend->delay(1000 / fps);
    }

    return 0;
}
