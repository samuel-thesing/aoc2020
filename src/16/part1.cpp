#include <utils.hpp>

int solve(const std::string &input) {
	auto blocks = split(input, "\n\n");

	for (const auto& block : blocks) {
		auto lines = split(block, "\n");
		auto lines2 = split_int(block, "\n");


        const auto [] = extract_data<>(block, std::regex(""));

		for (const auto& line : lines) {

		}

	}

	auto lines = split(input, "\n");
	auto lines2 = split_int(input, "\n");

    for (const auto& line : lines) {
    	const auto [] = extract_data<>(line, std::regex(""));
    }

	return 0;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 16);
    runner.add_test_file("t1.txt", 0);

    runner.add_input_file("i1.txt");

    runner.run();
}