#ifndef SEMESTROVKA_NODE_H
#define SEMESTROVKA_NODE_H

#include <limits>

/**
 * Узел дерева отрезков
 */
struct Node final {

    static constexpr int min_possible_value = std::numeric_limits<int>::min();
    static constexpr int max_possible_value = std::numeric_limits<int>::max();

    // поля
    long long sum{0};
    long long min_value{max_possible_value};
    long long max_value{min_possible_value};

    // конструкторы
    Node() = default;
};

#endif //SEMESTROVKA_NODE_H
