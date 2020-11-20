#include <cassert>
#include <iostream>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int min_val = atoi(argv[2]);
    int max_val = atoi(argv[3]);

    assert(min_val >= 0);
    assert(max_val <= 1);

    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << rnd.next(min_val, max_val);
    cout << '\n';

    return 0;
}