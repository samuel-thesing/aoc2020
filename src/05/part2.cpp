#include <utils.hpp>

int solve(const std::string &input) {
	auto lines = split(input, "\n");

	std::vector<int> ids{};

	for (const auto& line : lines) {
		int row = 0;
		for (int i = 0; i < 7; i++) {
			row *= 2;
			if (line[i] == 'B')
				row++;
		}

		int col = 0;
		for (int i = 7; i < 10; i++) {
			col *= 2;
			if (line[i] == 'R')
				col++;
		}

		ids.emplace_back(row * 8 + col);
	}
	std::sort(ids.begin(), ids.end());
	for (int i = 1; i < ids.size(); i++) {
		if (ids[i] != ids[i - 1] + 1) {
			return ids[i - 1] + 1;
		}
	}

	return -1;
}

int main(int argc, char** argv) {
	auto runner = Runner<int>(solve, 2020, 05);

	runner.add_input_file("i1.txt");

	runner.run();
}