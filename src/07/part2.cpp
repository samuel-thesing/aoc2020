#include <utils.hpp>

int recursive(const std::unordered_map<std::string, std::vector<std::tuple<int, std::string>>>& bag_map, const std::string& bag) {
	auto it = bag_map.find(bag);
	if (it == bag_map.end()) {
		Logger::critical("Bag {} does not exist", bag);
	}

	int result = 1;
	for (const auto [num, bag_in] : it->second) {
		int size = recursive(bag_map, bag_in);
		result += num * size;
	}

	return result;
}

int solve(const std::string &input) {
	int result = 0;

	auto lines = split(input, "\n");

	std::unordered_map<std::string, std::vector<std::tuple<int, std::string>>> bag_map{};

	for (const auto& line : lines) {
		const auto [outer_bag, inner_bags] = split_once(line, " bags contain ");

		if (inner_bags == "no other bags.") {
			bag_map.emplace(outer_bag, std::vector<std::tuple<int, std::string>>{});
			continue;
		}

		const auto inner_bags_vec = split(inner_bags, ", ");

		std::vector<std::tuple<int, std::string>> bag_list{};
		for (const auto& inner_bag : inner_bags_vec) {
			bag_list.push_back(extract_data<int, std::string>(std::regex("(\\d+) (.+) bags?\\.?"), inner_bag));
		}

		bag_map.emplace(outer_bag, bag_list);
	}

	return recursive(bag_map, "shiny gold")-1;
}

int main(int argc, char** argv) {
	auto runner = Runner<int>(solve, 2020, 07);
	runner.add_test_file("t1.txt", 32);
	runner.add_test_file("t2.txt", 126);

	runner.add_input_file("i1.txt");

	runner.run();
}