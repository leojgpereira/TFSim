#include <iostream>
#include <vector>

using namespace std;

class cpb {
    private:
        vector<int> patternHistoryTable;
        unsigned int m;
        unsigned int n;
        unsigned int c_predictions;
        int max;
        int c_hits;

    public:
        cpb(unsigned int m, unsigned int n);
        bool cpb_predict(unsigned int pc);
        void cpb_update(unsigned int pc, bool taken, bool hit);
        float cpb_get_hit_rate();
        int get_cpb_size();
};