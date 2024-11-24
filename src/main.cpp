#include "main.hpp"


Engine engine(80,50);

float rnadomfloat(int min, int max)
{
    TCODRandom *rng = TCODRandom::getInstance();
    float new_def = round(rng->getFloat(min,max));

    return new_def;
}

int main() {
    while ( !TCODConsole::isWindowClosed() ) {
        engine.update();
        engine.render();
        TCODConsole::flush();
    }
    return 0;
}
// #include "hhh.hpp"


//gcc src/*.cpp -o tuto -Iinclude -L. -ltcod -ltcodxx -Wall