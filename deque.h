#ifndef DEQUE_H
#define DEQUE_H

    class deque{

        private:
            int** blockMap; // The blockMap array containing pointers to our blocks
            unsigned long long currentSize; // The current number of elements in the deque
            unsigned long long mapSize; // Entries in blockmap
            const static unsigned long long blockSize = 1024; // Size of each block (in elements)
            const static unsigned long long defaultMapSize = 8; // Default number of blocks in blockMap
            unsigned long long firstBlock; // The index of the first block
            int firstElement; // The first index of the first block
            void allocateFrontBlock();
            void allocateBackBlock();
            void resizeBlockMap();
            int lastBlockIndex();
            int lastElementIndex();
        public:
            deque();
            ~deque();
            void push_front(int element);
            int pop_front();
            void push_back(int element);
            int pop_back();
            int front();
            int back();
            bool empty();
            int size();
            int operator[](int index);
    };

#endif