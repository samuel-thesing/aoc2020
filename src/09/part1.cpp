#include <utils.hpp>

int64_t solve(const std::string &input, int preamble) {
	int result = 0;

	auto lines = split_int64(input, "\n");

    for (int i = preamble + 1; i < lines.size(); i++) {
		for (int j = i - preamble - 1; j < i; j++) {
			for (int k = j+1; k < i; k++) {
				if (lines[j] + lines[k] == lines[i]) {
					goto outer;
				}
			}
		}
    	return lines[i];

    	outer:;
    }

	return -1;
}

int main(int argc, char** argv) {
    auto runner = Runner<int64_t, int>(solve, 2020, 9);
    runner.add_test_file("t1.txt", 127, 5);

    runner.add_input_file("i1.txt", 25);

    runner.run();
}