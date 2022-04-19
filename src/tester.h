#ifndef SEMESTROVKA_TESTER_H
#define SEMESTROVKA_TESTER_H

#include <string>

using namespace std;

struct Tester {
public:
    void run_tests(string path);

private:
    double run_test(int type, int size, int number_of_queries, string path);

    string make_path(string path);

    string make_path(int type, int size, int number_of_queries, string path);
};


#endif //SEMESTROVKA_TESTER_H
