#include "Check.h"

std::string Check::maxFreq(std::string *functions, int n) {
    int count[100] = {0};
    for(int i = 1; i < n ; i++)
        for(int j = 1; j < n ; j++) {
            if(functions[i] == functions[j])
                count[i]++;
        }
    int max = 0;
    int maxIndex;
    for (int i = 1; i < n ; i++)
        if(count[i] > max) {
            max = count[i];
            maxIndex = i;
        }
    return functions[maxIndex];
}






