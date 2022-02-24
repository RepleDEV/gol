import { Module } from "../index.js";
import assert from "assert";

(async () => {
    const wasmInstance = await Module();

    describe("GOL (Game of Life)", () => {
        describe("Looping cell configurations.", () => {
            it("Should flip from a horizontal 1x3 line to a vertical 3x1 line.", () => {
                const config = [
                    [
                        0, 0
                    ],
                    [
                        -1, 0
                    ],
                    [
                        1, 0
                    ]
                ];
                const cellVec = new wasmInstance.CellVector();
                for (const c of config) {
                    const [x, y] = c;
                    cellVec.push_back({ x, y });
                }

                const gol = new wasmInstance.GOL(cellVec);

                gol.next();
                const cells = wasmInstance.getCellsFromInstance(gol);

                let result = true;
                let l = cells.get(0).x;

                const len = cells.size();
                for (let i = 1;i < len;i++) {
                    if (cells.get(i).x != l) {
                        result = false;
                        break;
                    }
                }

                gol.delete();

                assert(result);
            });
        });
    });
})()