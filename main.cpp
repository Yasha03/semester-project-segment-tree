#include <iostream>
#include "src/segment_tree.h"
#include "src/test_generator.h"
#include "src/tester.h"

using namespace std;

int main(int argc, char* argv[]) {

    //Test_generator tg;
    //tg.make_tests(argv[0]);

    Tester tester;
    tester.run_tests(argv[0]);

}
