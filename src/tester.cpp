#include "tester.h"
#include "segment_tree.h"
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void Tester::run_tests(string path) {
    string path_of_result = make_path(path);
    ofstream fout(path_of_result.c_str());

    for(int type = 1; type <= 4; type++) {
        for(int size = 100; size <= 1e6; size *= 10) {
            for(int number_of_queries = 100; number_of_queries <= 1e6; number_of_queries *= 10) {
                double result = run_test(type, size, number_of_queries, path);
                fout << "type: " << type << " size: " << size << " queries: " << number_of_queries << " time: " << result << '\n';
            }
        }
    }

    fout.close();
}

double Tester::run_test(int type, int size, int number_of_queries, string path) {
    string path_of_test = make_path(type, size, number_of_queries, path);

    ifstream fin(path_of_test.c_str());

    Segment_tree tree(size);
    if(type == 2 || type == 4) {
        for(int i = 0; i < size; i++) {
            int value = -1e6 + rand() % int(2e6);
            tree.set(i, value);
        }
    }

    int start_time = clock();

    int q;
    fin >> q;
    cout << type << ' ' << size << ' ' << number_of_queries;
    while(q--) {
        string oper; fin >> oper;
        if(oper == "sum") {
            int l, r; fin >> l >> r;
            tree.get_sum(l, r);
        }
        if(oper == "set") {
            int pos, value; fin >> pos >> value;
            tree.set(pos, value);
        }
        if(oper == "min") {
            int l, r; fin >> l >> r;
            tree.get_min(l, r);
        }
        if(oper == "max") {
            int l, r; fin >> l >> r;
            tree.get_max(l, r);
        }
    }

    int end_time = clock();
    double result = 1.0 * (end_time - start_time) / CLOCKS_PER_SEC;
    cout << ' ' << result << endl;

    fin.close();
    return result;
}

string Tester::make_path(string path) {
    path = path.substr(0, path.length() - 33);
    path += "\\time_results.txt";
    return path;
}

string Tester::make_path(int type, int size, int number_of_queries, string path) {
    path = path.substr(0, path.length() - 33);
    path += "test_cases";
    if(type == 1) path += "\\mash_up";
    if(type == 2) path += "\\min_max";
    if(type == 3) path += "\\set";
    if(type == 4) path += "\\sum";
    path += "\\" + to_string(size) + "\\" + to_string(number_of_queries) +  ".txt";

    return path;
}