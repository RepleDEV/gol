#ifndef GOL_H
#define GOL_H

#include <iostream>
#include <vector>
#include <string>

#include "util.h"

namespace gol {
    struct Cell {
        int x;
        int y;
    };

    struct NeighborCell : Cell {
        int value;
    };

    class NeighboringCells {            
        public:
            std::vector<NeighborCell*> cells;

            void push(int x, int y) {
                // std::cout << "DEBUG, PUSH: " << x << " " << y << "\n";

                for (NeighborCell* c : cells) {
                    if (x == c->x && y == c->y) {
                        c->value++;
                        return;
                    }
                }

                struct NeighborCell* c = new NeighborCell();
                c->x = x, c->y = y, c->value = 1;
                cells.push_back(c);
            }
    };

    class Main {
        private:
            std::vector<Cell> cells;
        
        public:
            // GOL
            // Basic rules:
            // A cell with one or no neighbors (0 <= neighbors <= 1) dies
            // A cell with four or more neighbors (4 <= neighbors) dies
            // A cell with two or three neighbors (2 <= neighbors <= 3) survives
            // Unpopulated cells with three neighbors become populated

            // Implementation:
            // Create a function that takes an input of an array of cells and stores it
            // Then create a next() function that calculates the next cycle
            // The next() functions calls another function that calculates the neighboring cells of each cell
            // That function calculates the amount of neighboring cells of the neighboring cells of each cell
            // By storing the x and y values and the amount of neighbors of the cells
            // Then by looping over the neighboring cells we can evaluate the next cycle

            explicit Main(std::vector<Cell> c): cells(c) {}

            NeighboringCells* getNeighboringCells() {
                NeighboringCells* neighboringCells = new NeighboringCells();

                for (const Cell c : cells) {
                    for (int x = -1;x < 2;x++) {
                        for (int y = -1;y < 2;y++) {
                            if (x == 0 && y == 0)continue;
                            neighboringCells->push(c.x + x, c.y + y);
                        }
                    }
                }

                // std::cout << "DEBUG, NCLEN: " << neighboringCells->cells.size() << "\n";

                return neighboringCells;
            }

            void next() {
                NeighboringCells* neighboringCells = getNeighboringCells();

                // std::cout << "DEBUG: " << neighboringCells->cells.size() << "\n";

                std::vector<Cell>* newCells = new std::vector<Cell>();

                for (const NeighborCell* c : neighboringCells->cells) {
                    struct Cell* newCell = new Cell();
                    newCell->x = c->x;
                    newCell->y = c->y;

                    // std::cout << "DEBUG: " << c->value << ", " << c->x << " : " << c->y << "\n";
                    
                    if (c->value == 3) {    
                        newCells->push_back(*newCell);
                        continue;
                    } else if (c->value == 2) {
                        bool isAdded = false;

                        for (const Cell cc : cells) {
                            if (cc.x == c->x && cc.y == c->y) {
                                newCells->push_back(*newCell);
                                isAdded = true;
                                break;
                            }
                        }

                        if (isAdded)continue;
                    }

                    delete newCell;
                }

                // util::printVector<NeighborCell*>(neighboringCells->cells, [](NeighborCell* c) mutable -> std::string { 
                //     return std::to_string(c->x) + ":" + std::to_string(c->y) + ":" + std::to_string(c->value);
                // });

                // util::printVector<Cell*>(*newCells, [](Cell* c) mutable -> std::string {
                //     return std::to_string(c->x) + ":" + std::to_string(c->y);         
                // });

                cells.swap(*newCells);

                delete newCells;
                delete neighboringCells;
            }



            std::vector<Cell> getCells() const {
                return cells;
            }
            void setCells(std::vector<Cell> c) {
                cells = c;
            }
    };
}

#endif
