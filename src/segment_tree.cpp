#include "segment_tree.h"
#include <iostream>

using namespace std;

Segment_tree::Segment_tree(int size) {
    if(size <= 0) {
        throw invalid_argument("size must be positive");
    }
    size_ = size;
    capacity_ = 1;
    while(capacity_ < size) capacity_ <<= 1;
    tree_ = new Node[capacity_ * 2 - 1];
}

Segment_tree::~Segment_tree() {
    delete[] tree_;
    size_ = capacity_ = 0;
}

void Segment_tree::set(int pos, int value) {
    if(pos < 0 || size_ <= pos) {
        throw invalid_argument("invalid argument");
    }
    set(pos, value, 0, 0, capacity_);
}

void Segment_tree::set(int pos, int value, int x, int lx, int rx) {
    if(rx - lx == 1) {
        tree_[x].max_value = tree_[x].min_value = value;
        tree_[x].sum = value;
        return;
    }
    int middle = (lx + rx) >> 1;
    if(pos < middle) set(pos, value, x * 2 + 1, lx, middle);
    else set(pos, value, x * 2 + 2, middle, rx);

    tree_[x].sum = tree_[x * 2 + 1].sum + tree_[x * 2 + 2].sum;
    tree_[x].min_value = min(tree_[x * 2 + 1].min_value, tree_[x * 2 + 2].min_value);
    tree_[x].max_value = min(tree_[x * 2 + 1].max_value, tree_[x * 2 + 2].max_value);
}

long long Segment_tree::get_sum(int l, int r) {
    if(l < 0 || size_ < r || l >= r) {
        throw invalid_argument("invalid argument");
    }
    return get_sum(l, r, 0, 0, capacity_);
}

long long Segment_tree::get_sum(int l, int r, int x, int lx, int rx) {
    if(l <= lx && rx <= r) {
        return tree_[x].sum;
    }
    if(rx <= l || r <= lx) {
        return 0;
    }
    int middle = (lx + rx) >> 1;
    return get_sum(l, r, x * 2 + 1, lx, middle) + get_sum(l, r, x * 2 + 2, middle, rx);
}

int Segment_tree::get_min(int l, int r) {
    if(l < 0 || size_ < r || l >= r) {
        throw invalid_argument("invalid argument");
    }
    return get_min(l, r, 0, 0, capacity_);
}

int Segment_tree::get_min(int l, int r, int x, int lx, int rx) {
    if(rx <= l || r <= lx) return max_possible_value;
    if(l <= lx && rx <= r) return tree_[x].min_value;
    int middle = (lx + rx) >> 1;

    int left_min = get_min(l, r, x * 2 + 1, lx, middle);
    int right_min = get_min(l, r, x * 2 + 2, middle, rx);

    return min(left_min, right_min);
}

int Segment_tree::get_max(int l, int r) {
    if(l < 0 || size_ < r || l >= r) {
        throw invalid_argument("invalid argument");
    }
    return get_max(l, r, 0, 0, capacity_);
}

int Segment_tree::get_max(int l, int r, int x, int lx, int rx) {
    if(rx <= l || r <= lx) return min_possible_value;
    if(l <= lx && rx <= r) return tree_[x].max_value;
    int middle = (lx + rx) >> 1;

    int left_min = get_max(l, r, x * 2 + 1, lx, middle);
    int right_min = get_max(l, r, x * 2 + 2, middle, rx);

    return max(left_min, right_min);
}

int Segment_tree::get_size() {
    return size_;
}

int Segment_tree::get_capacity() {
    return capacity_;
}
