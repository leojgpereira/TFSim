#include <cmath>
#include "cpb.hpp"

cpb::cpb(unsigned int x, unsigned int y): m(x), n(y) {
    c_predictions = 0;
    c_hits = 0;

    max = (1 << n) - 1;

    patternHistoryTable.resize((1 << m), 0);
}

bool cpb::cpb_predict(unsigned int pc) {
    c_predictions++;

    return patternHistoryTable[pc % (1 << m)] & (1 << (n - 1));
}

void cpb::cpb_update(unsigned int pc, bool taken, bool hit) {
    c_hits += hit;

    int temp = patternHistoryTable[pc % (1 << m)];

    if(taken){
        temp += (temp < max);
    }else{
        temp -= (temp > 0);
    }

    patternHistoryTable[pc % (1 << m)] = temp;
}

float cpb::cpb_get_hit_rate(){
    return ((float)c_hits / (float)c_predictions) * 100;
}

int cpb::get_cpb_size() {
    return (1 << m);
}