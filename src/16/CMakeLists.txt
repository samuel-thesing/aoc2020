
add_executable(aoc2020_16_1
        part1.cpp
        ../../utils/Logger.cpp
        ../../utils/utils.hpp
        ../../utils/matrix.hpp
)

target_link_dependency(aoc2020_16_1 HEADER spdlog-1.14.1)
target_include_directories(aoc2020_16_1 PUBLIC ../../utils)


add_executable(aoc2020_16_2
        part2.cpp
        ../../utils/Logger.cpp
        ../../utils/utils.hpp
        ../../utils/matrix.hpp
)


target_link_dependency(aoc2020_16_2 HEADER spdlog-1.14.1)
target_include_directories(aoc2020_16_2 PUBLIC ../../utils)
