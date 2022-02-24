declare module "out";

// !btw these are only limited type definitions
// !these r so i dont get lost

/**
 * Cell object.
 */
export declare interface Cell {
    /**
     * X position.
     */
    x: number;
    /**
     * Y position.
     */
    y: number;
}

/**
 * std::vector<struct Cell> class.
 */
declare class CellVector {
    constructor();

    /**
     * std::vector::push_back method.
     * @param cell Cell object.
     */
    push_back(cell: Cell): void;
    /**
     * std::vector::size method.
     */
    size(): number;
    /**
     * std::vector::get method.
     * @param index Index of element.
     */
    get(index: number): Cell;
}

/**
 * GOL Class
 */
declare class GOL {
    cells: CellVector;

    /**
     * Initialize class.
     * @param cellVector Vector of cells.
     */
    constructor(cellVector: CellVector);

    /**
     * Calculate next cycle.
     */
    next(): void;

    /**
     * Call class destructor and free the memory.
     */
    delete(): void;
}
/**
* Get cell array from GOL class instance.
* @param instance GOL class instance.
*/
declare function getCellsFromInstance(instance: GOL): CellVector;

export declare interface ModuleObject {
    GOL: typeof GOL;
    CellVector: typeof CellVector;
    getCellsFromInstance: typeof getCellsFromInstance;
}

/**
 * Module promise.
 */
export default function Module(): Promise<ModuleObject>;