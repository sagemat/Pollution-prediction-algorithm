#include "Intersection.h"
#include "Matrix.h"
#include "Check.h"

class IO {
private:
    int datasetNo;
    int varPairNo[100];
public:
    int  getDatasetNo(){ return datasetNo; }
    int *getVarPairNo(){ return varPairNo; }
    void setDatasetNo();
    void setVarPairNo();
    Polynomial *pF[100][100];
    //A function to read the pollution data from the files
    void readData();
    //A function to write the pollution functions into txt files to read it later
    void writeFunctions();


    //A function that reads inputs from the terminal window (/keyboard input)
    void inputData();
    //A function that writes the functions to the console terminal
    void printFunctions();

    //A function that checks for the best function for each dataset and returns those functions for those datasets
    void printBestFunction();
    void printData();
};

