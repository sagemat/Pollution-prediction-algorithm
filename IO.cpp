#include "IO.h"
#include "FilterData.h"
#include "ConvertTime.h"
#include <fstream>
#include <iostream>


void IO::printData() {
    std::fstream f("data.in");
    f.open("C:\\Users\\texur\\OneDrive\\Documents1\\gp\\data.txt", std::ios::in);
    std::string* list = new std::string[10];
    if (f.is_open()) {
        std::string line;
        while(getline(f, line)) {
            list = FilterData::separateString(line, '|');
            std::cout<<"GPS:  "<<*(list + 1)<<std::endl;
            std::cout<<"TIME: "<<*(list + 2)<<std::endl;
            std::cout<<"SO2:  "<<*(list + 3)<<std::endl;
            std::cout<<std::endl;
        }
    }
    //In between these lines I should read the provided input to the global variables
    //for GPS, CO2Pollution, Time.. Etc
    f.close();
}
void IO::readData() {
    std::fstream f("data.in");
    f.open("C:\\Users\\texur\\OneDrive\\Documents1\\gp\\data.txt", std::ios::in);
    std::string* list = new std::string[10];
    std::string* time = new std::string[4];
    std::string stringSO2;
    double seconds;
    double so2;

    int varPairNo = 1;
    this->datasetNo = 1;
    if (f.is_open()) {
        std::string line;
        while(getline(f, line)) {
            list = FilterData::separateString(line, '|');
            //for the time   (x)
            time = FilterData::separateString(*(list + 2), ':');
            seconds = ConvertTime::stringToSec(time);

            //for the pollution value    (y)
            stringSO2 = *(FilterData::separateString(*(list + 3), ',') + 3);
            so2 = std::stod(stringSO2) * 100;

            pF[1][varPairNo] = new Polynomial(Dot(seconds, so2));
            varPairNo++;
        }
        for (int no = getDatasetNo(); no > 0; no--)
            this->varPairNo[no] = varPairNo - 1;
    }
    //In between these lines I should read the provided input to the global variables
    //for GPS, CO2Pollution, Time.. Etc
    f.close();
}

void IO::writeFunctions() {
    std::ofstream functions;
    functions.open("Files/functions.txt");
    //In between these lines I should write the provided function/s into the global variable/s
    //for PredictNO2Pollution, PredictCO2Pollution, PredictH2Pollution.. Etc
    //an example:    write functions << "cacamaca\n";
    functions.close();
}

void IO::setVarPairNo() {
    int no = getDatasetNo();
    int * varPairNo = getVarPairNo();
    for (no; no > 0; no--) {
        while (*(varPairNo + no) <= 0) {
            std::cout<<"Please state the number of variable pairs you will add..\n";
            std::cin>>this->varPairNo[no];
            varPairNo = getVarPairNo();
        }
    }
}
void IO::setDatasetNo() {
    int no = 0;
    while(no <= 0) {
        std::cout<<"Please state the number of datasets you will add.." << std::endl;
        std::cin>>no;
    }
    this->datasetNo = no;
}

void IO::inputData() {
    setDatasetNo();
    setVarPairNo();
    double x;
    double y;
    int datasetNo = getDatasetNo();
    int *p_varPairNo = getVarPairNo();
    int varPairNo[100];

    for (datasetNo; datasetNo > 0; datasetNo--) {
        varPairNo[datasetNo] = *(p_varPairNo + datasetNo);
        std::cout<<"Please add the values for the new dataset..\n\n";
        for (varPairNo[datasetNo]; varPairNo[datasetNo] > 0; varPairNo[datasetNo]--) {
            std::cout<<"Please type the value of x..\n";
            std::cin>>x; 
            std::cout<<"Please type the value of y..\n";
            std::cin>>y;
            pF[datasetNo][varPairNo[datasetNo]] = new Polynomial(Dot(x, y));
        }
    }
}

void IO::printFunctions() {

    int datasetNo = getDatasetNo();
    int *p_varPairNo = getVarPairNo();
    int varPairNo[100];
    
    for (datasetNo; datasetNo > 0; datasetNo--) {
        varPairNo[datasetNo] = *(p_varPairNo + datasetNo);
        std::cout<<"\n";
        for (varPairNo[datasetNo]; varPairNo[datasetNo] > 0; varPairNo[datasetNo]--) {
            Polynomial f = *pF[datasetNo][varPairNo[datasetNo]];
            int maxOrder = f.findOrder();
            for (int order = 0; order<= maxOrder; order++) {
                std::cout << *(f.getFunx() + order) << std::endl;
            }
            std::cout<<"\n";
        }
    }
}

void IO::printBestFunction() {

    int datasetNo = getDatasetNo();
    int *p_varPairNo = getVarPairNo();
    int varPairNo[100];

    for (datasetNo; datasetNo > 0; datasetNo--) {
        varPairNo[datasetNo] = *(p_varPairNo + datasetNo);
        std::string listOfFunctions[100];
        int listIndex = 0;
        for (varPairNo[datasetNo]; varPairNo[datasetNo] > 0; varPairNo[datasetNo]--) {
            Polynomial f = *pF[datasetNo][varPairNo[datasetNo]];
            int maxOrder = f.findOrder();
            for (int order = 0; order<= maxOrder; order++) {
                listOfFunctions[listIndex] = *(f.getFunx() + order);
                listIndex++;
            }
        }

        std::cout << Check::maxFreq(listOfFunctions, listIndex)<<std::endl;
        //Check::setBestFunction(pListOfFunctions);
        //std::cout << Check::getBestFunction() << std::endl;
    }
}


