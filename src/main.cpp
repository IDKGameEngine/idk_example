#include "idk/engine/engine.hpp"
#include "idk/core/platform.hpp"
#include "idk/core/nbufferedvector.hpp"

#include <thread>

static std::vector<std::thread> threads;

static idk::Engine *engine;
static idk::core::IPlatform *plat;
static idk::core::IRenderer *ren;

static void platform_main()
{
    while (engine->getStatus() != idk::EngineStat::Off)
    {
        plat->onUpdate();
    }  
}

static void render_main()
{
    while (engine->getStatus() != idk::EngineStat::Off)
    {
        engine->onUpdate();
        ren->onUpdate();
    }
}



int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    engine = new idk::Engine({"A Game Probably", 1280, 720});
    plat = engine->getPlatform();

    threads.push_back(std::thread(platform_main));
    for (auto &thread: threads)
    {
        thread.detach();
    }

    render_main();

    return 0;
}

