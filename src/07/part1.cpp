#include <utils.hpp>

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

	std::unordered_map<std::string, std::vector<std::string>> reversed_bags{};
	for (const auto& bag : map_key_list(bag_map)) {
		reversed_bags.emplace(bag, std::vector<std::string>{});
	}

	for (const auto& [outer_bag, inner_bags] : bag_map) {
		for (const auto& [_, inner_bag] : inner_bags) {
			reversed_bags[inner_bag].push_back(outer_bag);
		}
	}

	std::set<std::string> done{};
	std::queue<std::string> todo{};
	todo.emplace("shiny gold");
	while (!todo.empty()) {
		const auto bag = todo.front();
		todo.pop();

		if (done.contains(bag)) continue;

		result++;

		done.emplace(bag);
		auto it = reversed_bags.find(bag);
		if (it == reversed_bags.end()) {
			Logger::critical("bag {} not found", bag);
		}

		for (const auto& container : it->second) {
			if (done.contains(container)) continue;

			todo.push(container);
		}
	}

	return result-1;
}

int main(int argc, char** argv) {
    auto runner = Runner<int>(solve, 2020, 07);
    runner.add_test_file("t1.txt", 4);

    runner.add_input_file("i1.txt");

    runner.run();
}