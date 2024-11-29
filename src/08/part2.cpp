#include <utils.hpp>

std::optional<int> run_code(const std::vector<std::pair<std::string, int>>& instructions) {
    std::unordered_set<int> executed{};
    int pc = 0;
    int acc = 0;
    while (pc < instructions.size()) {
        if (executed.contains(pc)) {
            return {};
        }
        executed.insert(pc);

        const auto [instruction, number] = instructions[pc];


        if (instruction == "nop") {
        } else if (instruction == "acc") {
            acc += number;
        } else if (instruction == "jmp") {
            pc += number;
            continue;
        }

        pc++;
    }

    return acc;
}

int solve(const std::string &input) {
    auto lines = split(input, "\n");

    std::regex pattern("(.+) (\\+|-)(\\d+)");
    auto instructions = std::vector<std::pair<std::string, int>>{};
    for (const auto& line : lines) {
        const auto [instruction, sign, num] = extract_data<std::string, char, int>(pattern, line);

        auto number = (sign == '-') ? -num : num;
        instructions.emplace_back(instruction, number);
    }

    for (int i = 0; i < instructions.size(); ++i) {
        if (instructions[i].first == "acc") continue;

        auto instructions_cpy = instructions;

        instructions_cpy[i] = std::make_pair((instructions[i].first == "nop") ? "jmp" : "nop", i);

        if (auto result = run_code(instructions_cpy)) return result.value();
    }

    Logger::critical("No solution found");
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 8);
    runner.add_test_file("t1.txt", 8);

    runner.add_input_file("i1.txt");

    runner.run();
}