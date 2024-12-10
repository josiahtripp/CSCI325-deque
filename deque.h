/**
 * @file deque.h
 * @author Josiah Tripp
 * @date 2024-12-09
 * @brief Defines the Deque class and its associated methods
 * 
 * 
 */
#ifndef DEQUE_H
#define DEQUE_H

class Deque{
  
private:
  int** blockMap; // The blockMap array containing pointers to our blocks
  unsigned long long currentSize; // The current number of elements in the deque
  unsigned int mapSize; // Entries in blockmap
  const static unsigned int blockSize = 1024; // Default size of each block (in elements)
  const static unsigned int defaultMapSize = 8; // Default number of blocks in blockMap
  unsigned int firstBlock; // The index of the first block
  unsigned int firstElement; // The first index of the first block

/**
 * Allocated a new block to be added onto the front of the current set of blocks on the blockMap
 *
 * @pre 
 * @return void 
 * @post A new block has been added onto the front of the current set of blocks on the blockMap
 * 
 */
  void allocateFrontBlock();
  
/**
 * Allocated a new block to be added onto the back of the current set of blocks on the blockMap
 *
 * @pre 
 * @return void 
 * @post A new block has been added onto the back of the current set of blocks on the blockMap
 * 
 */
  void allocateBackBlock();

/**
 * Doubles the current size of the blockMap and copies over all current blocks & centers them
 *
 * @pre 
 * @return void 
 * @post The size of the blockMap has been doubled and any existing blocks on the old blockMap have been copied over and centered
 * 
 */
  void resizeBlockMap();

/**
 * Returns the index of the last used block on the blockMap 
 *
 * @pre 
 * @return unsigned The index of the last used block on the blockMap
 * @post 
 * 
 */
  unsigned int lastBlockIndex();

/**
 * Returns the index of the last element of the last block
 *
 * @pre 
 * @return unsigned The index of the last element of the last block in the blockMap
 * @post 
 * 
 */
  unsigned int lastElementIndex();
public:

/**
 * Default constructor, initializes variables & allocated initial blockMap & block
 *
 * @pre 
 * @post All relevant member variables of the Deque have been initialized & a blockMap & initial block have been allocated
 * 
 */
  Deque();

/**
 * Default destructor, delete all allocated blocks & the blockmap
 *
 * @pre 
 * @post The blockmap and all allocated blocks have been deleted
 * 
 */
  ~Deque();

/**
 * Pushes an element to the front of the deque
 *
 * @param int element The element to push
 * @pre 
 * @return void 
 * @post The element passed has been pushed onto the front of the deque
 * 
 */
  void push_front(int element);

/**
 * Pops an element off of the front of the deque
 *
 * @pre 
 * @return int The element popped off of the deque
 * @post The element at the top of the deque has been popped off
 * 
 */
  int pop_front();

/**
 * Pushes an element to the back of the deque
 *
 * @param int element The element to push
 * @pre 
 * @return void
 * @post The element passed has been pushed onto the front of the deque
 * 
 */
  void push_back(int element);

/**
 * Pops an element off of the back of the deque
 *
 * @pre 
 * @return int The element popped off of the deque 
 * @post The element at the back of the deque has been popped off
 * 
 */
  int pop_back();

/**
 * Returns the value of the element at the front of the deque
 *
 * @pre 
 * @return int The element at the front of the deque
 * @post 
 * 
 */
  int front();

/**
 * Returns the value of the element at the back of the deque
 *
 * @pre 
 * @return int The element at the back of the deque
 * @post 
 * 
 */
  int back();

/**
 * Returns whether or not the deque is empty
 *
 * @pre 
 * @return bool Whether or not the deque is empty
 * @post 
 * 
 */
  bool empty();

/**
 * Accessor for the currentSize member variable of the deque
 *
 * @pre 
 * @return unsigned long long The value of the member variable "currentSize" 
 * @post 
 * 
 */
  unsigned long long size();

/**
 * Returns the element at the specified index
 *
 * @param unsigned long long index The index of the element to return
 * @pre 
 * @return int The element at the specified index 
 * @post 
 * 
 */
  int operator[](unsigned long long index);
};

#endif
