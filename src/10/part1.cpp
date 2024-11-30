#include <utils.hpp>

int solve(const std::string &input) {
	auto lines = split_int(input, "\n");
	std::sort(lines.begin(), lines.end());
	lines.insert(lines.begin(), 0);
	lines.push_back(lines.back()+3);

	auto counts = std::array{0, 0, 0, 0};

    for (int i = 0; i < lines.size()-1; ++i) {
		counts[lines[i+1] - lines[i]]++;
    }

	return counts[1] * counts[3];
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 10);
    runner.add_test_file("t2.txt", 220);

    runner.add_input_file("i1.txt");

    runner.run();
}