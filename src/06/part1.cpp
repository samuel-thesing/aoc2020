#include <utils.hpp>

int solve(const std::string &input) {
	auto blocks = split(input, "\n\n");

	int result = 0;

	for (const auto& block : blocks) {
		std::set<char> answers{};
		auto lines = split(block, "\n");
		for (const auto& line : lines) {
			std::set<char> answer_line{};
			for (char c : line)
				answer_line.insert(c);

			std::set_intersection(answer_line.begin(), answer_line.end(), answers.begin(), answers.end(), std::inserter(answers, answers.begin()));
		}

		result += answers.size();
	}

	return result;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 06);
    runner.add_test_file("t1.txt", 11);

    runner.add_input_file("i1.txt");

    runner.run();
}