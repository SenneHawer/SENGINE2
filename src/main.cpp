#include "config.h"
#include "Engine.h"

int main(){
    std::cout << "SENGINE@TEST" << std::endl;

    Engine engine;
    engine.Init();
    engine.Run();

    engine.~Engine();

    std::cout << "Engine terminated" << std::endl;
    return 0;
}
