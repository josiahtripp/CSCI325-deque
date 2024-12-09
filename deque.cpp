#include <deque.h>
#include <iostream>

using namespace std;

/* Uncomment line to enable debugging info output program */
//#define DEBUG

#ifdef DEBUG
void deque::printDebugInfo(){

    cout << "\tcurrentSize = " << currentSize << endl;
    cout << "\tmapSize = " << mapSize << endl;
    cout << "\tfirstBlock = " << firstBlock << endl;
    cout << "\tfirstElement = " << firstElement << endl;
    cout << "\tfront() = " << front() << endl;
    cout << "\tback() = " << back() << endl;
    cout << "------------------------------------------------------" << endl << endl;
}
#endif

void deque::allocateFrontBlock(){

    // There is room on the blockMap, just allocate and add a new block to the front
    if(firstBlock > 0){
        blockMap[firstBlock - 1] = new int[blockSize];
        #ifdef debug
            cout << "Allocated a new front block (without resizing map): " << endl;
            printDebugInfo();
        #endif
        return;
    }

    // Resize of blockMap is required
    resizeBlockMap();
    blockMap[firstBlock - 1] = new int[blockSize];
    #ifdef debug
        cout << "Allocated a new front block (map resized): " << endl;
        printDebugInfo();
    #endif
}

void deque::allocateBackBlock(){

    // There is room on the blockMap, just allocate and add a new block to the back
    if(lastBlockIndex() + 1 < mapSize){
        blockMap[lastBlockIndex() + 1] = new int[blockSize];
        #ifdef debug
            cout << "Allocated a back block (without resizing map): " << endl;
            printDebugInfo();
        #endif
        return;
    }

    // Resize of blockMap is required
    resizeBlockMap();
    blockMap[lastBlockIndex() + 1] = new int[blockSize];
    #ifdef debug
        cout << "Allocated a new back block (map resized): " << endl;
        printDebugInfo();
    #endif
}

void deque::resizeBlockMap(){

    // Allocate space for new blockmap with double the size of the current one
    int newMapSize = mapSize * 2;
    int** newBlockMap = new int*[newMapSize];
    for(int i = 0; i < newMapSize; i++){
        newBlockMap[i] = nullptr;
    }

    // Find new center to copy over allocated blocks
    int allocatedBlocksCount = lastBlockIndex() - firstBlock + 1;

    // Center the new blocks onto the new blockMap (delete old blockmap)
    for(int i = 0; i < allocatedBlocksCount; i++){
        newBlockMap[i + (newMapSize - allocatedBlocksCount) / 2] = blockMap[i + firstBlock];
        #ifdef debug
            cout << "-Added block '" << i+firstBlock << "' of the old blockMap to block '"
                << i + (newMapSize - allocatedBlocksCount) / 2
                << "' of the new blockmap" << endl;
        #endif
    }

    //Delete old blockMap
    delete[] blockMap;

    // Set new values
    firstBlock = (newMapSize - allocatedBlocksCount) / 2;
    blockMap = newBlockMap;
    mapSize = newMapSize;
    #ifdef debug
        cout << "Resized blockMap: " << endl;
        cout << "-newMapSize = " << newMapSize << endl;
        cout << "-allocatedBlocksCount = " << allocatedBlocksCount << endl;
        printDebugInfo();
    #endif
}

int deque::lastBlockIndex(){

    return ((firstElement + currentSize - 1) / blockSize) + firstBlock;
}

int deque::lastElementIndex(){

    return (firstElement + currentSize - 1) % blockSize;
}

deque::deque(){

    // Initialize values
    currentSize = 0;
    mapSize = defaultMapSize;

    // Center starting point (center element of center block in blockMap)
    firstElement = blockSize / 2;
    firstBlock = mapSize / 2;

    // Allocate space for blockMap & first block
    blockMap = new int*[mapSize];
    for(int i = 0; i < mapSize; i++){
        blockMap[i] = nullptr;
    }
    blockMap[firstBlock] = new int[blockSize];

    #ifdef debug
        cout << "Constructor initialized a new deque:" << endl;
        printDebugInfo();
    #endif
}

deque::~deque(){

    // Delete blocks currently in use
    for(int i = firstBlock; i < lastBlockIndex() + 1; i++){
        delete[] blockMap[i];
        blockMap[i] = nullptr;
        #ifdef debug
            cout << "-Delete block at index '" << i << "' of the blockMap" << endl;
        #endif
    }
    // Delete blockMap
    delete[] blockMap;
    blockMap = nullptr;
    #ifdef debug
        cout << "Destructor deleted " << lastBlockIndex() - firstBlock + 1 << " blocks & the blockMap" << endl;
        printDebugInfo();
    #endif
}

void deque::push_front(int element){

    // There is still room within the current block
    if(firstElement > 0){
        firstElement--;
        currentSize++;
        blockMap[firstBlock][firstElement] = element;
        #ifdef debug
            cout << "Pushed front element '" << element << "' (Stayed in current block)" << endl;
            printDebugInfo();
        #endif
        return;
    }
    
    // Add another block to the front
    allocateFrontBlock();
    firstBlock--;
    firstElement = blockSize - 1;
    currentSize++;
    blockMap[firstBlock][firstElement] = element;
    #ifdef debug
        cout << "Pushed front element '" << element << "' (Moved back a block)" << endl;
        printDebugInfo();
    #endif
}

int deque::pop_front(){

    // No elements to pop, return 0
    if(currentSize == 0){
        return 0;
    }

    // Pop element
    int tmp = front();
    currentSize--;

    // We can remain in the current block
    if(firstElement < blockSize - 1){
        firstElement++;
        #ifdef debug
            cout << "Popped front element '" << tmp << "' (Stayed in current block)" << endl;
            printDebugInfo();
        #endif
        return tmp;
    }

    // We must move to the next block (delete previous block)
    firstElement = 0;
    firstBlock++;
    delete[] blockMap[firstBlock - 1];
    blockMap[firstBlock - 1] = nullptr;
    #ifdef debug
        cout << "Popped front element '" << tmp << "' (Moved forward a block)" << endl;
        printDebugInfo();
    #endif
    return tmp;
}

void deque::push_back(int element){

    // There is still room within the current block
    if(lastElementIndex() + 1 < blockSize){
        currentSize++;
        blockMap[lastBlockIndex()][lastElementIndex()] = element;
        #ifdef debug
            cout << "Pushed back element '" << element << "' (Stayed in current block)" << endl;
            printDebugInfo();
        #endif
        return;
    }

    // Add another block to the back
    allocateBackBlock();
    currentSize++;
    blockMap[lastBlockIndex()][lastElementIndex()] = element; 
    #ifdef debug
        cout << "Pushed back element '" << element << "' (Moved forward a block)" << endl;
        printDebugInfo();
    #endif
}

int deque::pop_back(){

    // No elements to pop, return 0
    if(currentSize == 0){
        return 0;
    }

    // Pop element
    int tmp = back();

    // We can remain in the current block
    if(lastElementIndex() > 0){
        currentSize--;
        #ifdef debug
            cout << "Popped back element '" << tmp << "' (stayed in current block)" << endl;
            printDebugInfo();
        #endif
        return tmp;
    }

    // We must move to the previous block (delete next block)
    delete[] blockMap[lastBlockIndex()];
    blockMap[lastBlockIndex()] = nullptr;
    currentSize--;
    #ifdef debug
        cout << "Popped back element '" << tmp << "' (moved back a block)" << endl;
        printDebugInfo();
    #endif
    return tmp;
}

int deque::front(){

    return blockMap[firstBlock][firstElement];
}

int deque::back(){

    return blockMap[lastBlockIndex()][lastElementIndex()];
}

bool deque::empty(){

    return (currentSize > 0) ? false : true;
}

int deque::size(){

    return currentSize;
}

int deque::operator[](int index){

    return blockMap[((index + firstElement) / blockSize) + firstBlock][(index + firstElement) % blockSize];
}