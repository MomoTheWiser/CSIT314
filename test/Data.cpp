#include "../ass3-refactor.h"
#include <gtest/gtest.h>
#include <time.h>

class Data : public::testing::Test {

    private:
        int no_of_vertices = 0, no_of_edges = 0;
    protected:
        ofstream MyFile;
        Simulation* simulation;
        //Simulation simulation;
        virtual void SetUp() override {
            simulation = new Simulation();
        }

        virtual void TearDown() override {
            delete simulation;
        }

        Data(){ 
            std::cout << "Data Class is constructed" << std::endl; 
        }
        ~Data(){ 
            std::cout << "Destructing Data Class" << std::endl; 
            MyFile.close();
        }
    public:
        void writeVertices(const char* fileName);
        void writeBadData();
        void writeInCompletePath();
};

void Data::writeVertices(const char* fileName){

    MyFile.open(fileName);
    cout << "Opened File: " << fileName << endl;
    srand(time(NULL));

    no_of_vertices = rand() % 5 + 1;
    no_of_edges = no_of_vertices +1;
    // Writes: number_of_vertices \t
    MyFile << no_of_vertices << "\t" << no_of_edges << endl;

    // Write node, posX, posY
    for(int i = 1; i <= no_of_vertices; i++){
        // Node \t posX \t posY
        int posX = rand() % 5 + 1, posY = rand() % 5 + 1;
        MyFile << i << "\t" << posX << "\t" << posY << endl;
    }
}

void Data::writeInCompletePath(){

    // Function does not write the correct amount of edges as specified on Line:1 in the file.

    int nodeStart = 1;

    for(int i = nodeStart; i < no_of_edges; i++){
        MyFile << i << "\t" << i+1 << "\t" << 1 << endl; 
    }
    MyFile << 1 << "\t" << no_of_edges << endl;
    MyFile.close();
}


void Data::writeBadData(){
    srand(time(NULL));


    int nodeStart = 1;
    // Connect the nodes
    while(nodeStart <= no_of_edges){
        // Node \t posX \t posY
        int nodeEnd = rand() % 10 + 2;

        if( nodeStart < nodeEnd ){
            MyFile << nodeStart++ << "\t" << nodeEnd << "\t" << 1 << endl;
        } else {
            MyFile << nodeStart++ << "\t" << "A" << "\t" << 1 << endl;
        }
    }
    MyFile << 1 << "\t" << no_of_vertices << endl;
    MyFile.close();
}

TEST_F(Data, InCompletedPath){
    
    const char* file = "InCompletePath.txt";
    writeVertices(file);
    writeInCompletePath();
    simulation->openFile(file);
    ASSERT_DEATH(simulation->readFile(), "");
   
}