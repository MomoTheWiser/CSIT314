#include "../ass3-refactor.h"
#include <gtest/gtest.h>

class HeapTest : public::testing::Test {

    protected:
        HeapTest(){ 
            std::cout << "SimulationFile is constructed" << std::endl; 
            verticesTest = new vertex[5];
        }
        ~HeapTest(){ 
            std::cout << "Destructing SimulationFile" << std::endl; 
            delete verticesTest;
        }
        vertex *verticesTest;
        int heap[5]{0};
    public:
     bool check(int[]);
};

bool HeapTest::check(int heap[]){
    if(heap == 0){ // check whether the arr is null itself, not the element
        return false; // here we assume null is not a heap (open for discussion)
    }
    for(int i=1 ; i <= 5 ;i++){
        if(verticesTest[heap[i]].length + verticesTest[heap[i]].heuristic < verticesTest[heap[(i-1)/2]].length + verticesTest[heap[(i-1)/2]].heuristic){ // the node is less than its parent
            return false; // we know there is an error, so return false
        }
    }
   return true; // all checks succeeded, return true
}

TEST_F(HeapTest, subtestOne){
    verticesTest[1].length = 50; verticesTest[1].heuristic = 100;
    verticesTest[2].length = 50; verticesTest[2].heuristic = 49;
    verticesTest[3].length = 50; verticesTest[3].heuristic = 48;
    verticesTest[4].length = 50; verticesTest[4].heuristic = 47;
    verticesTest[5].length = 50; verticesTest[5].heuristic = 46;

    /*
    for(int i=5 ; i >= 1; i--){
        heap[i] = i;
        cout << heap[i] << "\t";
    }
    */

    for(int i=1 ; i <= 5; i++){
        heap[i] = i;
        cout << heap[i] << "\t";
    }

    cout << endl;
    cout << "Result of check: " << check(heap) << endl;
}

