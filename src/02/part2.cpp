#include <utils.hpp>

int solve(const std::string &input) {
	std::regex pattern("(\\d+)-(\\d+) (.): (.+)");
	auto lines = split(input, "\n");

	int result = 0;

	for (const auto &line : lines) {
		const auto [mi, ma, c, pwd] = extract_data<int, int, char, std::string>(pattern, line);
		if ((pwd[mi-1] == c) != (pwd[ma-1] == c)) {
			result++;
		}
	}

	return result;
}

int main(int argc, char** argv) {
	auto runner = Runner<int>(solve, 2020, 02);
	runner.add_test_file("t1.txt", 1);

	runner.add_input_file("i1.txt");

	runner.run();
}