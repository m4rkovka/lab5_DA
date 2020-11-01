#ifndef SUFFIX_TREE_HPP
#define SUFFIX_TREE_HPP 1

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

struct Node {
    int l, r;
    int *n_r = nullptr;
    Node *parent;
    Node *suff_link;
    bool leaf;
    int num_of_leaf;
    std::map<char, Node *> childs{};

    Node(int l = -1, int r = -1, Node *par = nullptr, bool leaf = false);
    ~Node();
    int len();
    int end();
    void print(const std::string &str, int tab);
};

struct SuffixTree {
    Node *root;
    Node *to_first_suff;
    Node *last_node;
    std::string string;
    int n_p;
    int cnt;

    enum Link {
        DO_LINK,
        DO_LINK_TO_ROOT,
        DONT_LINK
    };

    SuffixTree(const std::string &str);
    ~SuffixTree();
    void build();
    void do_phase(int &start_in_new_phase, int end, int &last_case_number, std::pair<Node *, int> &res_case3);
    std::pair<Node *, int> analysis_links(int start, int end);
    std::pair<Node *, int> find_path(int start, int end, Node *it);
    int analysis(std::pair<Node *, int> &pos, int end);
    std::pair<Node *, Link> case2(const std::pair<Node *, int> &pos, int start, int end, bool do_link);
    std::pair<Node *, int> case3(const std::pair<Node *, int> &pos, bool do_link);
    std::vector<int> find_word(const std::string &str);
    void depth_search(std::vector<int> &v, Node *it);
    void print();
    int minimal_cut(int size);
};

#endif // SUFFIX_TREE_HPP