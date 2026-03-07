#include "idk/platform/platform.hpp"
#include "idk/gfx/gfx.hpp"

#include "idk/core/nbufferedvector.hpp"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    using tbuf_type = idk::core::NBufferedVector<float, 3, 64>;
    tbuf_type tbuf;

    idk::core::NBufferedVectorWriter<tbuf_type> tbufWriter(tbuf);
    idk::core::NBufferedVectorReader<tbuf_type> tbufReader(tbuf);

    tbufWriter.push_back(3.04f);
    tbufWriter.push_back(1.15149f);
    tbufWriter.push_back(1.0f);

    tbufWriter.flush();
    tbufWriter.flush();

    for (auto &x: tbufReader)
    {
        printf("%f\n", x);
    }

    auto *plat = idk::platform::createPlatform({
        "A Game Probably", 1280, 720
    });

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

