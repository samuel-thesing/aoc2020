#include <utils.hpp>

int solve(const std::string &input) {

	return 0;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 13);
    runner.add_test_file("t1.txt", 0);

    runner.add_input_file("i1.txt");

    runner.run();
}