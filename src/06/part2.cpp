#include <utils.hpp>

int solve(const std::string &input) {
	auto blocks = split(input, "\n\n");

	int result = 0;

	for (const auto& block : blocks) {
		auto lines = split(block, "\n");
		std::set<char> answers{};
		for (char c : lines[0]) {
			answers.insert(c);
		}

		for (const auto& line : lines) {
			std::set<char> answer_line{};
			for (char c : line)
				answer_line.insert(c);

			answers = set_intersection(answers, answer_line);
		}

		result += answers.size();
	}

	return result;
}

int main(int argc, char** argv) {
	auto runner = Runner<int>(solve, 2020, 06);
	runner.add_test_file("t1.txt", 6);

	runner.add_input_file("i1.txt");

	runner.run();
}