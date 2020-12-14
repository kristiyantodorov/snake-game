#ifndef SDLRENDERER_HPP
#define SDLRENDERER_HPP

#include <SDL2/SDL.h>
#include <string>

#include "RendererInterface.hpp"

class SDLRenderer : public RendererInterface {
public:
    SDLRenderer(std::string win_name, size_t width, size_t height);

    void drawLine(int x1, int y1, int x2, int y2) override;
    void clear() override;
    void setDrawColor(int r, int g, int b) override;
    void render() override;
    void delay(int ms) override;

    ~SDLRenderer();

private:
    SDL_Renderer* renderer_;
    SDL_Window* window_;
};

#endif