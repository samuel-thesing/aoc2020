#include <utils.hpp>

int64_t solve_possibilities(int count) {
    count -= 1;
    std::queue<std::pair<int64_t, int>> q{};
    int64_t result = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p.second >= count) {
            result++;
            continue;
        }

        auto mask = 0b11 << (p.second); // previous 2 bits are not set
        if ((p.first & mask) != mask) {
            q.emplace(p.first | (1 << (p.second+2)), p.second+1);
        }
        q.emplace(p.first, p.second+1);
    }

    return result;
}

int64_t solve(const std::string &input) {
    auto lines = split_int(input, "\n");
    std::ranges::sort(lines);
    lines.insert(lines.begin(), 0);

    std::vector<int> diffs{};

    for (int i = 0; i < lines.size()-1; ++i) {
        diffs.push_back(lines[i+1] - lines[i]);
    }

    auto parts = split_vec_non_empty(diffs, 3);
    auto part_counts = std::vector<int>(parts.size());
    std::ranges::transform(parts, part_counts.begin(), [](const auto& part){return part.size();});

    std::cout << part_counts << std::endl;

    std::unordered_map<int, int64_t> count_map{};
    for (const auto part_count : part_counts) {
        if (!count_map.contains(part_count)) {
            count_map[part_count] = solve_possibilities(part_count);
        }
    }

    int64_t result = 1;
    for (const auto part_count : part_counts) {
        result *= count_map[part_count];
    }

    return result;
}

int main(int argc, char** argv) {
    auto runner = Runner<int64_t>(solve, 2020, 10);
    runner.add_test_file("t1.txt", 8);
    runner.add_test_file("t2.txt", 19208);

    runner.add_input_file("i1.txt");

    runner.run();
}