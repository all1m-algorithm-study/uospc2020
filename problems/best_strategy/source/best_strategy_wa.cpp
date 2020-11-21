// Greedy

#include <iostream>

using namespace std;

const int MAXN = 5000;
int card[MAXN + 1];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> card[i];

    int jh = 0, mk = 0;
    int l = 1, r = n;
    bool turn = false;  // jh
    while(l + 1 <= r) {
        int l2 = card[l] + card[l+1];
        int r2 = card[r-1] + card[r];
        int l1r1 = card[l] + card[r];
        if(l2 >= r2 && l2 >= l1r1) {
            if(!turn) {
                jh += l2;
            } else {
                mk += l2;
            }
            turn = !turn;
            l += 2;
        } else if(r2 >= l2 && r2 >= l1r1) {
            if(!turn) {
                jh += r2;
            } else {
                mk += r2;
            }
            turn = !turn;
            r -= 2;
        } else {
            if(!turn) {
                jh += l1r1;
            } else {
                mk += l1r1;
            }
            turn = !turn;
            l++, r--;
        }
    }

    cout << jh;
}