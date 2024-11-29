#include <utils.hpp>

int solve(const std::string &input) {
	int result = 0;

	auto blocks = split(input, "\n\n");

	for (const auto& block : blocks) {
		auto lines = split(block, "\n");
		auto lines2 = split_int(block, "\n");


        const auto [] = extract_data<>(std::regex(""), block);

		for (const auto& line : lines) {

		}

	}

	auto lines = split(input, "\n");
	auto lines2 = split_int(input, "\n");

    for (const auto& line : lines) {
    	const auto [] = extract_data<>(std::regex(""), line);
    }

	return result;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 14);
    runner.add_test_file("t1.txt", 0);

    runner.add_input_file("i1.txt");

    runner.run();
}