#include <deque.h>
#include <iostream>

using namespace std;

bool testPush(unsigned int testElements, bool fullOutput, Deque& myDeque);

bool testValues(unsigned int testElements, bool fullOutput, Deque& myDeque);

bool testPop(unsigned int testElements, bool fullOutput, Deque& myDeque);

int main(){

    // Deque object used for testing
    Deque myDeque;

    // Miscellaneous test variables
    char userInput;
    bool fullOutput = false; // Default to partial test output
    const unsigned int testElements = 100000; // Default to 100,000 test elements (CHANGE THIS TO TEST OTHER AMOUNTS)

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

    // Run tests
    bool passedTestPush = testPush(testElements, fullOutput, myDeque);
    cout << endl;
    bool passedTestValues = testValues(testElements, fullOutput, myDeque);
    cout << endl;
    bool passedTestPop = testPop(testElements, fullOutput, myDeque);
    cout << endl;

    cout << "############################################################\n";
    cout << "Test results...\n\n";

    int testsPassed = 0;
    
    cout << "push_back(), push_front() & size() test: ";
    if(passedTestPush){
        cout << "[PASSED]\n";
        testsPassed++;
    }
    else{
        cout << "[FAILED]\n";
    }

    cout << "Verify values and operator[], front() & back() test: ";
    if(passedTestValues){
        cout << "[PASSED]\n";
        testsPassed++;
    }
    else{
        cout << "[FAILED]\n";
    }

    cout << "pop_front(), pop_back() & empty() test: ";
    if(passedTestPop){
        cout << "[PASSED]\n";
        testsPassed++;
    }
    else{
        cout << "[FAILED]\n";
    }

    cout << endl << testsPassed << " / 3 Tests passed\n";
    cout << "Program conclusion: ";
    if(testsPassed == 3){
        cout << "[PASSED]\n";
    }
    else{
        cout << "[FAILED]\n";
    }
    cout << "############################################################\n";
}

bool testPush(unsigned int testElements, bool fullOutput, Deque& myDeque){

    unsigned int midPoint = testElements / 2; // Used to split elements between push back / front
    unsigned long long initialSize = myDeque.size();

    cout << "------------------------------------------------------------\n";
    cout << "Testing push_back() by pushing " << testElements - midPoint << " elements\n";
    cout << "Testing push_front() by pushing " << midPoint << " elements\n";
    cout << "Adding a total of " << testElements << " elements to the deque...\n\n";

    if(fullOutput){

        for(unsigned int i = midPoint; i < testElements; i++){// Use push back to add the first half of the elements to the deque
            myDeque.push_back(i);
            cout << "Added element '" << i << "' to the deque using push_back()\n";
        }
        for(int i = (int) midPoint - 1; i > -1; i--){// Use push front to add the first half of the elements to the front of the deque
            myDeque.push_front(i);
            cout << "Added element '" << i << "' to the deque using push_front()\n";
        }
    }
    else{

        int partialPrintInterval = testElements / 10;

        cout << "Printing information for 5 elements of each push type:\n";

        for(unsigned int i = midPoint; i < testElements; i++){// Use push back to add the first half of the elements to the deque
            myDeque.push_back(i);
            if(i % partialPrintInterval == 0){
                cout << "Added element '" << i << "' to the deque using push_back()\n";
            }
        }
        for(int i = (int) midPoint - 1; i > -1; i--){// Use push front to add the first half of the elements to the front of the deque
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

bool testValues(unsigned int testElements, bool fullOutput, Deque& myDeque){

    cout << "------------------------------------------------------------\n";
    cout << "Comparing all values of deque to their expected values...\n\n";
    
    bool isValid = true;

    if(fullOutput){

        for(unsigned int i = 0; i < testElements; i++){
            cout << "Index " << i << " value: " << myDeque[i];
            cout << " | Expected: " << i;
            if(i != (unsigned int) myDeque[i]){
                isValid = false;
                cout << " -INVALID";
            }
            cout << endl;
        }
    }
    else{

        int partialPrintInterval = testElements / 10;

        cout << "Printing information for 10 elements: (still comparing all)\n";

        for(unsigned int i = 0; i < testElements; i++){

            if(i % partialPrintInterval == 0 || i != (unsigned int) myDeque[i]){
                cout << "Index " << i << " value: " << myDeque[i];
                cout << " | Expected: " << i;

                if(i != (unsigned int) myDeque[i]){
                    isValid = false;
                    cout << " -INVALID";
                }
                cout << endl;
            }
        }
    }

    cout << "\nValue of front(): " << myDeque.front() << endl;
    cout << "Value of back(): " << myDeque.back() << endl;

    if(isValid & (myDeque.front() == myDeque[0]) && (myDeque.back() == myDeque[myDeque.size() - 1])){
        cout << "Successfully verified all " << testElements << " elements in the deque\n";
        cout << "[TEST PASSED]\n";
        cout << "------------------------------------------------------------\n";
        return true;
    }
    else{
        cout << "Failed to verify the " << testElements << " elements in the deque\n";
        cout << "[TEST FAILED]\n";
        cout << "------------------------------------------------------------\n";
        return false;
    }
}

bool testPop(unsigned int testElements, bool fullOutput, Deque& myDeque){

    cout << "------------------------------------------------------------\n";
    cout << "Popping all elements from the deque...\n\n";
    
    unsigned int elementsPopped = 0;

    if(fullOutput){

        while(!myDeque.empty()){

            cout << "Popped " << myDeque.pop_back() << " off of the back of the deque\n";
            elementsPopped++;
            if(!myDeque.empty()){
                cout << "Popped " << myDeque.pop_front() << " off of the front of the deque\n";
                elementsPopped++;
            }
        }
    }
    else{

        int partialPrintInterval = testElements / 10;

        cout << "Printing information for 10 elements: (still popping all)\n";

        while(!myDeque.empty()){
            
            int tmp = myDeque.pop_back();
            if(elementsPopped % partialPrintInterval == 0){
                cout << "Popped " << tmp << " off of the back of the deque\n";
            }
            elementsPopped++;
            if(!myDeque.empty()){
                int tmp = myDeque.pop_back();
                if(elementsPopped % partialPrintInterval == 0){
                    cout << "Popped " << tmp << " off of the front of the deque\n";
                }
                elementsPopped++;
            }
        }
    }

    cout << "\nElements popped: " << elementsPopped << " | Expected: " << testElements << endl;

    if(elementsPopped == testElements){
        cout << "Successfully popped all " << testElements << " elements off the deque\n";
        cout << "[TEST PASSED]\n";
        cout << "------------------------------------------------------------\n";
        return true;
    }
    else{
        cout << "Failed to pop all " << testElements << " elements off the deque\n";
        cout << "[TEST FAILED]\n";
        cout << "------------------------------------------------------------\n";
        return false;
    }
}