#ifndef SEMESTROVKA_TEST_GENERATOR_H
#define SEMESTROVKA_TEST_GENERATOR_H

#include <string>
using namespace std;

struct Test_generator {
public:
    void make_tests(string path);

private:
    void make_test(int type, int size, int number_of_queries, string path);

    string make_path(int type, int size, int number_of_queries, string path);

    string create_sum_operation(int size);

    string create_max_operation(int size);

    string create_min_operation(int size);

    string create_set_operation(int size);
};


#endif //SEMESTROVKA_TEST_GENERATOR_H
