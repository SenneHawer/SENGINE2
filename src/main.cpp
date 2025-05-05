#include "config.h"
#include "Engine.h"

int main(){

    Engine engine;
    engine.Init();
    engine.Run();

    engine.~Engine();

    return 0;
}
