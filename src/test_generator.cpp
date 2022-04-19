#include "test_generator.h"
#include <fstream>
#include <string>
#include <random>
#include <chrono>

using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void Test_generator::make_tests(string path) {
    for(int type = 1; type <= 4; type++) {
        for(int size = 100; size <= 1e6; size *= 10) {
            for(int number_of_queries = 100; number_of_queries <= 1e6; number_of_queries *= 10)
                make_test(type, size, number_of_queries, path);
        }
    }
}

void Test_generator::make_test(int type, int size, int number_of_queries, string path) {
    path = make_path(type, size, number_of_queries, path);
    ofstream fout(path.c_str());

    fout << number_of_queries << '\n';

    for(int i = 0; i < number_of_queries; i++) {
        if(type == 1) {
            int oper = rnd() % 4;
            if(oper == 0) fout << create_set_operation(size) << '\n';
            if(oper == 1) fout << create_max_operation(size) << '\n';
            if(oper == 2) fout << create_min_operation(size) << '\n';
            if(oper == 3) fout << create_sum_operation(size) << '\n';
        }
        if(type == 2) {
            int oper = rnd() % 2;
            fout << (oper ? create_min_operation(size) : create_max_operation(size)) << '\n';
        }
        if(type == 3) {
            fout << create_set_operation(size) << '\n';
        }
        if(type == 4) {
            fout << create_sum_operation(size) << '\n';
        }
    }

    fout.close();
}

string Test_generator::make_path(int type, int size, int number_of_queries, string path) {
    path = path.substr(0, path.length() - 33);
    path += "test_cases";
    if(type == 1) path += "\\mash_up";
    if(type == 2) path += "\\min_max";
    if(type == 3) path += "\\set";
    if(type == 4) path += "\\sum";

    path += "\\" + to_string(size) + "\\" + to_string(number_of_queries) +  ".txt";
    return path;
}

string Test_generator::create_sum_operation(int size) {
    int left = rnd() % size;
    int right = left + 1 + rnd() % (size - left);
    string res = "sum " + to_string(left) + " " + to_string(right);
    return res;
}

string Test_generator::create_min_operation(int size) {
    int left = rnd() % size;
    int right = left + 1 + rnd() % (size - left);
    string res = "min " + to_string(left) + " " + to_string(right);
    return res;
}

string Test_generator::create_max_operation(int size) {
    int left = rnd() % size;
    int right = left + 1 + rnd() % (size - left);
    string res = "max " + to_string(left) + " " + to_string(right);
    return res;
}

string Test_generator::create_set_operation(int size) {
    int pos = rnd() % size;
    int value = -1e6 + rnd() % int(2e6);
    string res = "set " + to_string(pos) + " " + to_string(value);
    return res;
}