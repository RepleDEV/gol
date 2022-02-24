#include <iostream>
#include <vector>
#include <utility>

#include "gol.h"

int main() {
    std::vector<gol::Cell> cells;

    std::vector<std::pair<int, int>> cellCoords = {
        std::make_pair(0, 0),
        std::make_pair(-1, 0),
        std::make_pair(0, 1),
        std::make_pair(1, 0),
        std::make_pair(0, -1),
    };

    for (const std::pair<int, int> c : cellCoords) {
        struct gol::Cell cell = { c.first, c.second };

        cells.push_back(cell);
    }

    gol::Main gol(cells);

    gol.next();

    for (const gol::Cell c : gol.getCells()) {
        std::cout << c.x << " : " << c.y << "\n";
    }

    return 0;
}