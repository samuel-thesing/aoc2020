#include <utils.hpp>

uint64_t solve(const std::string &input) {
	auto lines = split(input, "\n");
	std::vector<std::vector<int>> slopes = {
		{1, 1},
		{3, 1},
		{5, 1},
		{7, 1},
		{1, 2}
	};
	uint64_t result = 1;
	for (auto slope : slopes) {
		uint64_t count = 0;
		for (int i = 1; i * slope[1] < lines.size(); i++) {
			if (lines[i*slope[1]][(i*slope[0]) % lines[i].size()] == '#') {
				count++;
			}
		}
		std::cout << count << std::endl;
		result *= count;
	}

	return result;
}

int main(int argc, char** argv) {
	auto runner = Runner<uint64_t>(solve, 2020, 03);
	runner.add_test_file("t1.txt", 336);

	runner.add_input_file("i1.txt");

	runner.run();
}