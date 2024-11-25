#include <utils.hpp>

int solve(const std::string &input) {
	auto lines = split(input, "\n");
	int count = 0;
	for (int i = 1; i < lines.size(); i++) {
		if (lines[i][(i*3) % lines[i].size()] == '#') {
			count++;
		}
	}

	return count;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 03);
    runner.add_test_file("t1.txt", 7);

    runner.add_input_file("i1.txt");

    runner.run();
}