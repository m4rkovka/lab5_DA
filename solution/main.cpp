#include <iostream>
#include <string>
#include "suffix_tree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    if (str == "") {
        std::cout << "";
        return 0;
    } else {
        std::string new_str{str + str};
        SuffixTree s{new_str};
        int start = s.minimal_cut(str.size());
        int end = start + str.size() - 1;
        for (int i = start; i <= end; i++) {
            std::cout << new_str[i];
        }
        std::cout << "\n";
        return 0;
    }
}