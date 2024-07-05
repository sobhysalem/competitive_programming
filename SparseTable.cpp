#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5+5;  // Adjust as needed
const int K = 25;  // K should be such that 2^K >= MAXN
int LOG[MAXN+1];
int st[MAXN][K + 1];
int marge(int a,int b){
    return min(a,b);
}
void computeLogs() {
    LOG[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
}

void buildSparseTable(int n, const vector<int>& a) {
    for (int i = 0; i < n; ++i)
        st[i][0] = a[i];

    for (int j = 1; j <= K; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = marge(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

int queryMin(int L, int R) {
    int j = LOG[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

int main() {
    int n;
    cin >> n;
     int queries;
    cin >> queries;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    computeLogs();
    buildSparseTable(n, a);


    while (queries--) {
        int L, R;
        cin >> L >> R;

        cout << queryMin(L-1, R-1) << "\n";
    }

    return 0;
}
