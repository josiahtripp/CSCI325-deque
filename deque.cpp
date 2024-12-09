#include <deque.h>

void deque::allocateFrontBlock(){

    // There is room on the blockMap, just allocate and add the block
    if(firstBlock > 0){
        firstBlock--;
        blockMap[firstBlock] = new int[blockSize];
        return;
    }

    // Resize of blockMap is required
    resizeBlockMapFront();
    firstBlock--;
    blockMap[firstBlock] = new int[blockSize];
}

void deque::allocateBackBlock(){


}

void deque::resizeBlockMapFront(){

    // Allocate space for new blockmap with 1 more spot on the front
    int** tmpBlockMap = new int*[mapSize + 1];

    // Copy over blockMap data
    for(int i = 0; i < mapSize; i++){
        tmpBlockMap[i+1] = blockMap[i];
    }

    // Increment blockMap size
    mapSize++;

    // Move starting block index
    firstBlock++;                                      
}

void deque::resizeBlockMapBack(){

    // Allocate space for new blockmap with 1 more spot on the back
    int** tmpBlockMap = new int*[mapSize + 1];

    // Copy over blockMap data
    for(int i = 0; i < mapSize; i++){
        tmpBlockMap[i] = blockMap[i];
    }

    // Increment blockMap size
    mapSize++;
}

deque::deque(){

    currentSize = 0;
    mapSize = 0;
}

deque::~deque(){

    // Delete blocks
    for(int i = 0; i < mapSize; i++){
        delete[] blockMap[i + firstBlock];
    }
    // Delete blockMap
    delete[] blockMap;
}
void deque::push_front(int element){

    // There is still room within the first block
    if(firstElement > 0){
        firstElement--;
        blockMap[firstBlock][firstElement] = element;
        return;
    }
    
    // Move to another block
    allocateFrontBlock();
    firstBlock--;
    firstElement = blockSize - 1;
    blockMap[firstBlock][firstElement] = element;
    return;
}

int  deque::pop_front();
void deque::push_back(int element);
int  deque::pop_back();
int  deque::front();
int  deque::back();
bool deque::empty();
int  deque::size();