#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "../SDL2wrap/SDL.h"
#include "../SDL2wrap/SDLImage.h"
#include "../SDL2wrap/Window.h"
#include "../SDL2wrap/Renderer.h"
#include <string>

namespace engine {

class Application {
public:
    Application(const std::string& title, const int width, const int height);
private:
    void loop() const;

    SDL2wrap::SDL sdl_;
    SDL2wrap::SDLImage sdl_image_;
    SDL2wrap::Window window_;
    SDL2wrap::Renderer renderer_;
};

}

#endif