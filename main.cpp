
#include "IO.h"
#include <fstream>
IO io;

using namespace std;
int main()
{
    io.readData();
    //io.inputData();
    io.printData();
    io.printFunctions();
    std::cout<<"Below is the approximate function:"<<std::endl;
    io.printBestFunction();
}
