#include <utils.hpp>

int solve(const std::string &input) {
	std::set<std::string> required = {"byr","iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};
	auto eyeCols = std::set<std::string>{"amb", "blu", "brn", "grn", "gry", "hzl", "oth"};

	int count = 0;

	std::regex pattern("[ \n]+");
	auto passports = split(input, "\n\n");
	for (const auto &passport : passports) {
		const auto pairs = split_regex(passport, pattern);
		std::set<std::string> fields{};
		for (const auto &pair : pairs) {
			const auto keyValue = split_once(pair, ":");
			if (required.find(keyValue.first) == required.end()) {
				goto outer;
			}

			switch (keyValue.first) {
				case "byr": {
					auto value = std::stoi(keyValue.second);
					if (value < 1920 || value > 2002) {
						goto outer;
					}
				} break;

				case "iyr": {
					auto value = std::stoi(keyValue.second);
					if (value < 2010 || value > 2020) {
						goto outer;
					}
				} break;

				case "eyr": {
					auto value = std::stoi(keyValue.second);
					if (value < 2020 || value > 2030) {
						goto outer;
					}
				} break;

				case "hgt": {
					if (keyValue.second.ends_with("cm")) {
						auto val = std::stoi(keyValue.second.substr(0, keyValue.second.size() - 2));
						if (val < 150 || val > 193) {
							goto outer;
						}
					} else if (keyValue.second.ends_with("in")) {
						auto val = std::stoi(keyValue.second.substr(0, keyValue.second.size() - 2));
						if (val < 59 || val > 76) {
							goto outer;
						}
					}
					goto outer;
				} break;

				case "hcl": {
					if (!std::regex_match(keyValue.second, std::regex("#[0-9a-f]{6}"))) {
						goto outer;
					}
				} break;

				case "ecl": {
					if (!eyeCols.contains(keyValue.second)) {
						goto outer;
					}
				} break;

				case "pid": {
					if (!std::regex_match(keyValue.second, std::regex("[0-9]{9}"))) {
						goto outer;
					}
				} break;

				default:
					goto outer;
			}
		}

		fields.insert("cid");

		if (fields == required) {
			count++;
		}
		outer:;
	}

	return count;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 04);
    runner.add_test_file("t1.txt", 2);

    runner.add_input_file("i1.txt");

    runner.run();
}