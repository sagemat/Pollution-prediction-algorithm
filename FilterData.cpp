#include "FilterData.h"
#include <vector>
#include <string>

std::string * FilterData::separateString(std::string line, char c) {
    std::string* list = new std::string[10];
    int i = 0;
    for(int k = 0; k < line.length(); k++) {
        if(c == line[k]) {
            i++;
        }
        else {
            list[i] += line[k];
        }
    }
    return list;
}
