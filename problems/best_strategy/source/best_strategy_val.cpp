#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(2, 5000, "testCount");
    inf.readEoln();
    
    for (int i = 0; i < testCount; i++) {
        int n = inf.readInt(-400000, 400000, "n");
        inf.readSpace();
    }

    inf.readEof();
}