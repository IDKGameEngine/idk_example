#include "idk/platform.hpp"
#include "idk/idk_gfx.hpp"
#include <cstdio>


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    idk::core::WindowDesc windesc = {
        .title = "Game Name",
        .width = 1024,
        .height = 1024
    };

    idk::platform::Platform plat;
    idk::platform::WindowSDL3 win(windesc);
    idk::gfx::RendererOpenGL ren(&win);

    // auto *cam = gfx->createCamera(512, 512);
    // (void)cam;

    // GameObject player;
    // player.addComponent<GraphicsComponent>();
    // player.addComponent<KeybdIoComponent>();
    // player.addComponent<MouseIoComponent>();
    // player.addComponent<PhysicsComponent>();
    // player.addComponent<GraphicsComponent>();

    while (plat.running())
    {
        plat.update();
        // player.update();

        // if (kb->keyWasPressed(SDL_SCANCODE_E))
        //     printf("E PRESSED\n");
        // if (kb->keyWasReleased(SDL_SCANCODE_E))
        //     printf("E RELEASED\n");

        // if (ms->mouseWasPressed(iolib::Mouse::Button::LEFT))
        //     printf("Mouse LEFT PRESSED\n");
        // if (ms->mouseWasReleased(iolib::Mouse::Button::LEFT))
        //     printf("Mouse LEFT RELEASED\n");
    }

    return 0;
}

