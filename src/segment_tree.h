#ifndef SEMESTROVKA_SEGMENT_TREE_H
#define SEMESTROVKA_SEGMENT_TREE_H

#include "node.h"

/**
 * Дерево отрезков — структура данных, позволяющая быстро выполнять различные операции на отрезке,
 *      такие как поиск минимума/максимума, сумма, прибавление, присваивание и так далее (здесь реализованы:
 *      поиск минимума/максимума, сумма).
 *
 * В памяти представляется одномерным массивом.
 * Требует памяти O(n)
 *
 * Индексация узлов в массиве:
 *      0 - корневой узел
 *      2 * i + 1 - левый потомок узла i
 *      2 * i + 2 - правый потомок узла i
 *      (i - 1) / 2 - родитель узла i
 */

struct Segment_tree {
    static constexpr int min_possible_value = std::numeric_limits<int>::min();
    static constexpr int max_possible_value = std::numeric_limits<int>::max();

    protected:
        int size_{0};
        int capacity_{0};
        Node* tree_;
    public:
        /**
         * Создание дерева отрезков указанного размера.
         * Предварительно размер увеличивается до ближайшей большей или равной степени двойки
         * Размер ограничен и не может быть изменен.
         *
         * @param capacity - значение емкости двоичной кучи
         */
        explicit Segment_tree(int size);

        ~Segment_tree();

        /**
         * Изменение элемента за O(log(n))
         *
         * @param pos - позиция изменяемого элемента
         * @param val - новое значение
         */
        void set(int pos, int val);

        /**
         * Возвращает сумму на отрезке за O(log(n))
         *
         * @param l - левая граница запроса (включительно)
         * @param r - правая граница запроса (не включительно)
         * @return полученная сумма
         */
        long long get_sum(int l, int r);

        /**
         * Возвращает минимальное значение на отрезке за O(log(n))
         *
         * @param l - левая граница запроса (включительно)
         * @param r - правая граница запроса (не включительно)
         * @return найденный минимум
         */
        int get_min(int l, int r);

        /**
         * Возвращает максимальное значение на отрезке за O(log(n))
         *
         * @param l - левая граница запроса (включительно)
         * @param r - правая граница запроса (не включительно)
         * @return найденный максимум
         */
        int get_max(int l, int r);

        /**
         * @return Размер массива
         */
        int get_size();

        /**
         * @return Размер построенного массива
         */
        int get_capacity();

    // Вспомогательные функции
    private:
        void set(int pos, int value, int x, int lx, int rx);

        long long get_sum(int l, int r, int x, int lx, int rx);

        int get_min(int l, int r, int x, int lx, int rx);

        int get_max(int l, int r, int x, int lx, int rx);
};

#endif //SEMESTROVKA_SEGMENT_TREE_H
