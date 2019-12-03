#include "Application.h"
#include "Director.h"

namespace engine {

Application::Application(const std::string& title, const int width, const int height)
    : sdl_{SDL2wrap::SDL::video}
    , sdl_image_{SDL2wrap::SDLImage::png}
    , window_{title, {SDL2wrap::Window::centered, SDL2wrap::Window::centered, width, height}}
    , renderer_{window_, {0xFF, 0xFF, 0xFF, 0xFF}, SDL2wrap::Renderer::accelerated | SDL2wrap::Renderer::presentvsync}
{
}

void Application::start(std::unique_ptr<Scene> starting_scene) const
{
    engine::Director::get()->play(std::move(starting_scene));
    loop();
}

void Application::loop() const
{
    for (;;) {
        const bool exit_request = process_input();

        if (exit_request) {
            break;
        }

        update();
        render();
    }
}

bool Application::process_input() const
{
    SDL_Event event;                  // REFACTOR: Implement SDL2wrap::Event (?)
    while (SDL_PollEvent(&event)) {   // REFACTOR: Implement SDL2wrap::Event::poll(...) (?)
        if (event.type == SDL_QUIT) { // REFACTOR: Implement SDL2wrap::SDL::quit (?)
            return true;
        }
        // TODO: Add later logic for processing keyboard/mouse input
    }

    return false;
}

void Application::update() const
{
    Director::get()->update();
}

void Application::render() const
{
    renderer_.clear();
    Director::get()->render();
    renderer_.present();
}

}