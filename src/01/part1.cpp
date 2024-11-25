#include <utils.hpp>

int solve(const std::string &input) {
	auto nums = split<int>(input, "\n", [](std::string s) {return std::stoi(s);});
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i+1; j < nums.size(); ++j) {
			if (nums[i] + nums[j] == 2020) {
				return nums[i] * nums[j];
			}
		}
	}

	return 0;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 01);
    runner.add_test_file("t1.txt", 514579);

    runner.add_input_file("i1.txt");

    runner.run();
}