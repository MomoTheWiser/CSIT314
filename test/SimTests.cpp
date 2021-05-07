#include "../ass3-refactor.h"
#include <gtest/gtest.h>
#include <fstream>

using namespace std;

int openFile(const char* fileName){

    ifstream fin;

    //cerr << "Entering the file name: " << fileName << endl;

    fin.open(fileName);

    if(!fin){
        cerr << "Error opening file " << fileName << ". Program will exit" << endl;
        return 0;
    }
    return 1;
}

TEST(True, subTest1){
    ASSERT_TRUE(true);
}

TEST(TestCase1, subTest1){
    Simulation sim;
    //sim.openFile("Ass3.txt");
    openFile("Ass3.txt");
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}