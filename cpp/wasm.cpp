#include <iostream>
#include <vector>
#include <string>

#include <emscripten/bind.h>

#include "gol.h"

using namespace emscripten;

std::vector<val> getCellsFromInstance(const gol::Main& instance) {
    std::vector<gol::Cell> cells = instance.getCells();

    std::vector<val> objVec;

    for (const gol::Cell c : cells) {
        val obj = val::object();
        obj.set(std::string("x"), c.x);
        obj.set(std::string("y"), c.y);

        objVec.push_back(obj);
    }

    return objVec;
}

EMSCRIPTEN_BINDINGS(my_module) {
    value_object<gol::Cell>("Cell")
        .field("x", &gol::Cell::x)
        .field("y", &gol::Cell::y)
        ;

    register_vector<gol::Cell>("CellVector");
    register_vector<val>("CellObjectVector");

    function("getCellsFromInstance", &getCellsFromInstance);

    class_<gol::Main>("GOL")
        .constructor<std::vector<gol::Cell>>()
        .function("next", &gol::Main::next)
        .property("cells", &gol::Main::getCells, &gol::Main::setCells)
        ;
}
