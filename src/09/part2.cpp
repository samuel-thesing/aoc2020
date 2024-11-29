#include <utils.hpp>

int solve1(const std::string &input, int preamble) {
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

int64_t solve(const std::string &input, int preamble) {
    int result = solve1(input, preamble);
    if (result == -1) return -1;

    auto lines = split_int64(input, "\n");

    for (int i = 0; i < lines.size(); i++) {
        int64_t sum = lines[i];
        for (int j = i+1; j < lines.size(); j++) {
            sum += lines[j];
            if (sum == result) {
                auto result_set = std::vector<int64_t>{lines.begin()+i, lines.begin()+j+1};
                return max(result_set) + min(result_set);
            }
            if (sum > result) {
                break;
            }
        }
    }

    return -1;
}

int main(int argc, char** argv) {
    auto runner = Runner<int64_t, int>(solve, 2020, 9);
    runner.add_test_file("t1.txt", 62, 5);

    runner.add_input_file("i1.txt", 25);

    runner.run();
    // 189876169 low
}