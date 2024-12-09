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
            void allocateFrontBlock();
            void allocateBackBlock();
            void resizeBlockMap();
            unsigned int lastBlockIndex();
            unsigned int lastElementIndex();
        public:
            Deque();
            ~Deque();
            void push_front(int element);
            int pop_front();
            void push_back(int element);
            int pop_back();
            int front();
            int back();
            bool empty();
            unsigned long long size();
            int operator[](unsigned long long index);
    };

#endif