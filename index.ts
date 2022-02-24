import Module, { Cell, GOL } from "./out";

export default async function getInstance(cells: Cell[]): Promise<GOL> {
    const module = await Module();

    const cellVector = new module.CellVector();
    for (const cell of cells) {
        cellVector.push_back(cell);
    }

    const instance = new module.GOL(cellVector);

    return instance;
}

export { Module };