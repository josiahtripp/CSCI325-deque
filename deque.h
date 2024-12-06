#ifndef DEQUE_H
#define DEQUE_H

    class deque{

        private:
            int blockmap;
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