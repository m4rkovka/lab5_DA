#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include "../solution/suffix_tree.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cout << "File doesn't open\n";
        return 1;
    }
    std::string input_string;
    in >> input_string;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    SuffixTree s{input_string};
    end = std::chrono::system_clock::now();
    int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "TIME: " << time << "ms\n";
    in.close();
    return 0;
}