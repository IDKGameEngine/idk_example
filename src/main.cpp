#include "idk/engine/engine.hpp"
#include "idk/gfx/gfx.hpp"
#include "idk/gfx/renderer.hpp"
#include "idk/game/game.hpp"

#include <barrier>
#include <thread>


static std::barrier mainloop_sync_(2);
static std::barrier shutdown_sync_(2);


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    idk::Engine engine;
    std::thread t0(idk::game::main, &engine);

    t0.detach();
    idk::gfx::main(&engine);

    return 0;
}



void idk::gfx::main(idk::core::IEngine *engine)
{
    idk::gfx::RenderEngine ren({
        "A Game Probably", 1280, 720
    });

    while (engine->get_stat() != EngineStat::Dead)
    {
        ren.beginFrame();

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                VLOG_INFO("SDL_EVENT_QUIT");
                engine->shutdown();
            }
        }

        ren.endFrame();
        engine->update();

        mainloop_sync_.arrive_and_wait();
    }

    shutdown_sync_.arrive_and_wait();
}



void idk::game::main(idk::core::IEngine *engine)
{
    idk::game::Game g;

    while (engine->get_stat() != EngineStat::Dead)
    {
        g.update();

        mainloop_sync_.arrive_and_wait();
    }

    shutdown_sync_.arrive_and_wait();
}
