#include "ConvertTime.h"

double ConvertTime::stringToSec(std::string * time) {
    double hour,minute,second;
    hour = std::stod(*(time + 0));
    minute = std::stod(*(time + 1));
    second = std::stod(*(time + 2));
    minute += hour*60;
    second += minute*60;
    return second;
}
