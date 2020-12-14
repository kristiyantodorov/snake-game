#include "SDLRenderer.hpp"

SDLRenderer::SDLRenderer(std::string win_name, size_t width, size_t height) {
    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    window_ = SDL_CreateWindow(win_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    // creates a renderer to render our images
    renderer_ = SDL_CreateRenderer(window_, -1, render_flags);
}

void SDLRenderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}

void SDLRenderer::setDrawColor(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer_, r, g, b, SDL_ALPHA_OPAQUE);
}

void SDLRenderer::clear() {
    SDL_RenderClear(renderer_);
}

void SDLRenderer::delay(int ms) {
    SDL_Delay(ms);
}

void SDLRenderer::render() {
    SDL_RenderPresent(renderer_);
}

SDLRenderer::~SDLRenderer() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
}