#include <utils.hpp>

int solve(const std::string &input) {
	int result = 0;

	auto lines = split(input, "\n");

	std::regex pattern("(.+) (\\+|-)(\\d+)");
	std::unordered_set<int> executed{};
	int pc = 0;
    while (!executed.contains(pc)) {
    	executed.insert(pc);
    	const auto [instruction, sign, num] = extract_data<std::string, char, int>(pattern, lines[pc]);

    	auto number = (sign == '-') ? -num : num;

    	if (instruction == "nop") {
    	} else if (instruction == "acc") {
    		result += number;
    	} else if (instruction == "jmp") {
    		pc += number;
    		continue;
    	}

    	pc++;
    }

	return result;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 8);
    runner.add_test_file("t1.txt", 5);

    runner.add_input_file("i1.txt");

    runner.run();
}