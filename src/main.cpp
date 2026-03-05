#include "idk/platform/platform.hpp"
#include "idk/idk_gfx.hpp"
#include <cstdio>


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    auto *plat = idk::platform::createPlatform({
        "A Game Probably", 1280, 720
    });

    auto *win = plat->getWindow();
    // auto *ren = idk::Platform::createRenderer(win);

    while (plat->running())
    {
        plat->update();
    }


    // // auto *cam = gfx->createCamera(512, 512);
    // // (void)cam;

    // // GameObject player;
    // // player.addComponent<GraphicsComponent>();
    // // player.addComponent<KeybdIoComponent>();
    // // player.addComponent<MouseIoComponent>();
    // // player.addComponent<PhysicsComponent>();
    // // player.addComponent<GraphicsComponent>();

    // while (plat.running())
    // {
    //     plat.update();
    //     // player.update();

    //     // if (kb->keyWasPressed(SDL_SCANCODE_E))
    //     //     printf("E PRESSED\n");
    //     // if (kb->keyWasReleased(SDL_SCANCODE_E))
    //     //     printf("E RELEASED\n");

    //     // if (ms->mouseWasPressed(iolib::Mouse::Button::LEFT))
    //     //     printf("Mouse LEFT PRESSED\n");
    //     // if (ms->mouseWasReleased(iolib::Mouse::Button::LEFT))
    //     //     printf("Mouse LEFT RELEASED\n");
    // }

    return 0;
}

