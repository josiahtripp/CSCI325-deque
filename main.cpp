#include <deque.h>
#include <iostream>

using namespace std;

bool testPush(unsigned int testElements, bool fullOutput, deque& myDeque);

int main(){

    // Deque object used for testing
    deque myDeque;

    // Miscellaneous test variables
    char userInput;
    bool fullOutput = false; // Default to partial test output
    int testElements = 100000; // Default to 100,000 test elements

    // Get user selection
    cout << "Welcome to the deque test program - Please enter 'p' for partial test output or 'f' for full test output: ";
    cin >> userInput;

    // User input / selection confirmation
    switch (userInput){

        case 'p':
        case 'P':
            cout << "Running tests with partial test output...\n\n";
        break;

        case 'f':
        case 'F':
            cout << "Running tests with full test output...\n\n";
            fullOutput = true;
        break;

        default:
            cout << "Invalid input selection - Defaulting to running tests with partial test output...\n\n";
        break;
    }

    // Get user's desired number of test elements
    

    cout << "Front element: " << myDeque.front() << endl;
    cout << "Back element: " << myDeque.back() << endl;

    for(int i = 0; i < myDeque.size(); i += 1000){

        cout << "Element #" << i << ": " << myDeque[i] << endl;
    }
    cout << endl;

    bool frontLast = true;

    while(!myDeque.empty()){

        if(frontLast){
            cout << "Popped back element: " << myDeque.pop_back() << endl;
            frontLast = false;
        }
        else{
            cout << "Popped front element: " << myDeque.pop_front() << endl;
            frontLast = true;
        }
    }

    cout << "Deque size: " << myDeque.size() << endl;
}

bool testPush(unsigned int testElements, bool fullOutput, deque& myDeque){

    int midPoint = testElements / 2; // Used to split elements between push back / front
    int initialSize = myDeque.size();

    cout << "------------------------------------------------------------\n";
    cout << "Testing push_back() by pushing " << testElements - midPoint << " elements\n";
    cout << "Testing push_front() by pushing " << midPoint << " elements\n";
    cout << "Adding a total of " << testElements << " elements to the deque...\n\n";

    if(fullOutput){

        for(int i = midPoint; i < testElements; i++){// Use push back to add the first half of the elements to the deque
            myDeque.push_back(i);
            cout << "Added element '" << i << "' to the deque using push_back()\n";
        }
        for(int i = 0; i < midPoint; i++){// Use push front to add the first half of the elements to the front of the deque
            myDeque.push_front(i);
            cout << "Added element '" << i << "' to the deque using push_front()\n";
        }
    }
    else{

        int partialPrintInterval = (testElements - 1) / 10;

        cout << "Printing information for 5 elements of each push type:\n";

        for(int i = midPoint; i < testElements; i++){// Use push back to add the first half of the elements to the deque
            myDeque.push_back(i);
            if(i % partialPrintInterval == 0){
                cout << "Added element '" << i << "' to the deque using push_back()\n";
            }
        }
        for(int i = 0; i < midPoint; i++){// Use push front to add the first half of the elements to the front of the deque
            myDeque.push_front(i);
            if(i % partialPrintInterval == 0){
                cout << "Added element '" << i << "' to the deque using push_front()\n";
            }
        }
    }

    cout << "\nInitial deque size: " << initialSize << endl;
    cout << "New deque size: " << myDeque.size() << endl;

    if(myDeque.size() - initialSize == testElements){
        cout << "Successfully added " << testElements << " elements to the deque\n";
        cout << "[TEST PASSED]\n";
        cout << "------------------------------------------------------------\n";
        return true;
    }
    else{
        cout << "Failed to add " << testElements << " elements to the deque\n";
        cout << "[TEST FAILED]\n";
        cout << "------------------------------------------------------------\n";
        return false;
    }
}