# Deque Toolkit

Created by Josiah Tripp

<br>

## Member Functions

`(Constructor)` - Initializes Deque member variables & allocates an initial block & block map
<br>
`(Destructor)` - Deletes all allocated blocks in the block map & then deletes the block map

### Element access

`operator[]` - access specified element of the deque
<br>
`front()` - access the first element
<br>
`back()` - access the last element
<br>

### Capacity

`empty()` - checks whether the deque is empty
<br>
`size()` - returns the number of elements in the deque
<br>

### Modifiers

`push_back()` - adds an element to the end of the deque
<br>
`push_front()` - adds an element to the front of the deque
<br>
`pop_back()` - removes & returns the last element in the deque
<br> `pop_front()` - removes & returns the first element in the deque

<br>

## Bugs / Issues Encountered during the project

I encountered numerous issues relating to memory management during the development of this project.<br>
I used a proccess of trial and error & developed my own debugging methods.<br>
I incorporated some preprocessor directives into most of my class methods, which would output member variable information at that current time. These are still within the program, but are disabled since DEBUG keyword is not defined. Debugging info can be turned back on by uncommenting line 16 in deque.cpp, defining the DEBUG keyword.
<br>
Due to these debugging methods, I was able to ensure that every part of the Deque class is functioning properly with no memory leaks.

<br>

## Breakdown of Group Work

I completed this assignment as a solo project, rather than in a group