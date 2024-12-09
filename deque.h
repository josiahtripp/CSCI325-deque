#ifndef DEQUE_H
#define DEQUE_H

    class deque{

        private:
            int** blockMap;
            int currentSize; // The current number of elements in the deque
            int mapSize; // Entries in blockmap
            const static int blockSize = 1024; // Size of each block (in elements)
            int firstBlock; // The index of the first block
            int firstElement; // The first index of the first block
            void allocateFrontBlock();
            void allocateBackBlock();
            void resizeBlockMapFront();
            void resizeBlockMapBack();
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
    };

#endif