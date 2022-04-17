#include <iostream>
#include "src/segment_tree.h"
#include <vector>

using namespace std;

int main() {
    Segment_tree segtree(7);

    vector<int> v = {3, 1, 4, 6, 0, 1, -2};

    for(int i = 0; i < v.size(); i++) {
        segtree.set(i, v[i]);
    }
    cout << segtree.get_sum(0, 7);

    return 0;
}
