#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;

template<typename Iterator, typename T>
void check_iterator_values(Iterator begin, Iterator end, const vector<T> &expected_values) {
    auto it = begin;
    for (const auto &expected_value : expected_values) {
        REQUIRE(it != end);  // Ensure we haven't reached the end prematurely
        REQUIRE((*it)->get_value() == expected_value);  // Check the value
        ++it;
    }
    REQUIRE(it == end);  // Ensure the iterator reaches the end
}

template<typename T>
Tree<T> create_binary_tree(const vector<pair<Node<T> *, vector<Node<T> *>>> &node_structure) {
    Tree<T> tree;
    if (!node_structure.empty()) {
        tree.add_root(*node_structure[0].first);
        for (const auto &[parent, children] : node_structure) {
            for (const auto &child : children) {
                tree.add_sub_node(*parent, *child);
            }
        }
    }
    return tree;
}

template<typename T, size_t k>
Tree<T, k> create_k_ary_tree(const vector<pair<Node<T> *, vector<Node<T> *>>> &node_structure) {
    Tree<T, k> tree;
    if (!node_structure.empty()) {
        tree.add_root(*node_structure[0].first);
        for (const auto &[parent, children] : node_structure) {
            for (const auto &child : children) {
                tree.add_sub_node(*parent, *child);
            }
        }
    }
    return tree;
}

TEST_CASE("Test tree creation") {
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    vector<pair<Node<double> *, vector<Node<double> *>>> binary_structure = {
            {&root_node, {&n1, &n2}},
            {&n1,        {&n3, &n4}},
            {&n2,        {&n5}}
    };

    vector<pair<Node<double> *, vector<Node<double> *>>> k_ary_structure = {
            {&root_node, {&n1, &n2, &n3}},
            {&n1,        {&n4}},
            {&n2,        {&n5}}
    };

    SECTION("Test default k") {
        Tree<double> tree = create_binary_tree(binary_structure);

        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = tree.begin();
        auto it_end = tree.end();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("Test k=3") {
        Tree<double, 3> three_ary_tree = create_k_ary_tree<double, 3>(k_ary_structure);

        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = three_ary_tree.begin();
        auto it_end = three_ary_tree.end();
        check_iterator_values(it, it_end, expected_values);
    }
}

TEST_CASE("Test iterators doubles") {
    Node<double> root_node_double(1.1);
    Node<double> n1_double(1.2);
    Node<double> n2_double(1.3);
    Node<double> n3_double(1.4);
    Node<double> n4_double(1.5);
    Node<double> n5_double(1.6);

    vector<pair<Node<double> *, vector<Node<double> *>>> binary_structure_double = {
            {&root_node_double, {&n1_double, &n2_double}},
            {&n1_double,        {&n3_double, &n4_double}},
            {&n2_double,        {&n5_double}}
    };

    Tree<double> tree = create_binary_tree(binary_structure_double);

    SECTION("Pre order double") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("Post order double") {
        vector<double> expected_values = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("In order double") {
        vector<double> expected_values = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("DFS double") {
        vector<double> expected_values = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("BFS double") {
        vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("MinHeap Iterator") {
        SECTION("MinHeap double") {
            vector<double> expected_values = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
            auto it = tree.begin_min_heap();
            auto it_end = tree.end_min_heap();
            check_iterator_values(it, it_end, expected_values);
        }

        SECTION("MinHeap int") {
            Node<int> root_node_int(10);
            Node<int> n1_int(20);
            Node<int> n2_int(30);
            Node<int> n3_int(40);
            Node<int> n4_int(50);
            Node<int> n5_int(60);
            Node<int> n6_int(70);
            Node<int> n7_int(80);
            Node<int> n8_int(-10);
            Node<int> n9_int(-20);

            vector<pair<Node<int> *, vector<Node<int> *>>> binary_structure_int = {
                    {&root_node_int, {&n1_int, &n2_int}},
                    {&n1_int,        {&n3_int, &n4_int}},
                    {&n2_int,        {&n5_int, &n6_int}},
                    {&n3_int,        {&n7_int, &n8_int}},
                    {&n4_int,        {&n9_int}}
            };

            Tree<int> ints_tree = create_binary_tree(binary_structure_int);
            vector<int> expected_values = {-20, -10, 10, 20, 30, 40, 50, 60, 70, 80};
            auto it = ints_tree.begin_min_heap();
            auto it_end = ints_tree.end_min_heap();
            check_iterator_values(it, it_end, expected_values);
        }
    }
}

TEST_CASE("Test iterators strings") {
    Node<string> root_node_string("root");
    Node<string> n1_string("n1");
    Node<string> n2_string("n2");
    Node<string> n3_string("n3");
    Node<string> n4_string("n4");
    Node<string> n5_string("n5");

    vector<pair<Node<string> *, vector<Node<string> *>>> binary_structure_string = {
            {&root_node_string, {&n1_string, &n2_string}},
            {&n1_string,        {&n3_string, &n4_string}},
            {&n2_string,        {&n5_string}}
    };
    Tree<string> tree = create_binary_tree(binary_structure_string);

    SECTION("Pre order string") {
        vector<string> expected_values = {"root", "n1", "n3", "n4", "n2", "n5"};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("Post order string") {
        vector<string> expected_values = {"n3", "n4", "n1", "n5", "n2", "root"};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("In order string") {
        vector<string> expected_values = {"n3", "n1", "n4", "root", "n5", "n2"};
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("DFS string") {
        vector<string> expected_values = {"root", "n1", "n3", "n4", "n2", "n5"};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("BFS string") {
        vector<string> expected_values = {"root", "n1", "n2", "n3", "n4", "n5"};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("MinHeap string") {
        vector<string> expected_values = {"n1", "n2", "n3", "n4", "n5", "root"};
        auto it = tree.begin_min_heap();
        auto it_end = tree.end_min_heap();
        check_iterator_values(it, it_end, expected_values);
    }
}

TEST_CASE("Test iterators Complex") {
    Node<Complex> root_node_complex(Complex(1, 2));
    Node<Complex> n1_complex(Complex(2, 3));
    Node<Complex> n2_complex(Complex(3, 4));
    Node<Complex> n3_complex(Complex(4, 5));
    Node<Complex> n4_complex(Complex(5, 6));
    Node<Complex> n5_complex(Complex(6, 7));

    vector<pair<Node<Complex> *, vector<Node<Complex> *>>> binary_structure_complex = {
            {&root_node_complex, {&n1_complex, &n2_complex}},
            {&n1_complex,        {&n3_complex, &n4_complex}},
            {&n2_complex,        {&n5_complex}}
    };
    Tree<Complex> tree = create_binary_tree(binary_structure_complex);

    SECTION("Pre order complex") {
        vector<Complex> expected_values = {Complex(1, 2), Complex(2, 3), Complex(4, 5), Complex(5, 6), Complex(3, 4), Complex(6, 7)};
        auto it = tree.begin_pre_order();
        auto it_end = tree.end_pre_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("Post order complex") {
        vector<Complex> expected_values = {Complex(4, 5), Complex(5, 6), Complex(2, 3), Complex(6, 7), Complex(3, 4), Complex(1, 2)};
        auto it = tree.begin_post_order();
        auto it_end = tree.end_post_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("In order complex") {
        vector<Complex> expected_values = {Complex(4, 5), Complex(2, 3), Complex(5, 6), Complex(1, 2), Complex(6, 7), Complex(3, 4)};
        auto it = tree.begin_in_order();
        auto it_end = tree.end_in_order();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("DFS complex") {
        vector<Complex> expected_values = {Complex(1, 2), Complex(2, 3), Complex(4, 5), Complex(5, 6), Complex(3, 4), Complex(6, 7)};
        auto it = tree.begin_dfs();
        auto it_end = tree.end_dfs();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("BFS complex") {
        vector<Complex> expected_values = {Complex(1, 2), Complex(2, 3), Complex(3, 4), Complex(4, 5), Complex(5, 6), Complex(6, 7)};
        auto it = tree.begin_bfs_scan();
        auto it_end = tree.end_bfs_scan();
        check_iterator_values(it, it_end, expected_values);
    }

    SECTION("MinHeap complex") {
        vector<Complex> expected_values = {Complex(1, 2), Complex(2, 3), Complex(3, 4), Complex(4, 5), Complex(5, 6), Complex(6, 7)};
        auto it = tree.begin_min_heap();
        auto it_end = tree.end_min_heap();
        check_iterator_values(it, it_end, expected_values);
    }
}

TEST_CASE("Test iterator arithmetic") {
    SECTION("Test sum of elements") {
        Node<int> root_node(10);
        Node<int> n1(20);
        Node<int> n2(30);
        Node<int> n3(40);
        Node<int> n4(50);
        Node<int> n5(60);
        Node<int> n6(70);
        Node<int> n7(80);
        Node<int> n8(90);
        Node<int> n9(100);

        vector<pair<Node<int> *, vector<Node<int> *>>> binary_structure_int = {
                {&root_node, {&n1, &n2}},
                {&n1,        {&n3, &n4}},
                {&n2,        {&n5, &n6}},
                {&n3,        {&n7, &n8}},
                {&n4,        {&n9}}
        };

        Tree<int> ints_tree = create_binary_tree(binary_structure_int);
        int sum = accumulate(ints_tree.begin(), ints_tree.end(), 0, [](int acc, Node<int>* node) { return acc + node->get_value(); });

        REQUIRE(sum == 550);
    }

    SECTION("Test sum of complex elements") {
        Node<Complex> root_node_complex(Complex(1, 2));
        Node<Complex> n1_complex(Complex(2, 3));
        Node<Complex> n2_complex(Complex(3, 4));
        Node<Complex> n3_complex(Complex(4, 5));
        Node<Complex> n4_complex(Complex(5, 6));
        Node<Complex> n5_complex(Complex(6, 7));

        vector<pair<Node<Complex> *, vector<Node<Complex> *>>> binary_structure_complex = {
                {&root_node_complex, {&n1_complex, &n2_complex}},
                {&n1_complex,        {&n3_complex, &n4_complex}},
                {&n2_complex,        {&n5_complex}}
        };
        Tree<Complex> tree = create_binary_tree(binary_structure_complex);

        Complex sum = accumulate(tree.begin(), tree.end(), Complex(0, 0), [](Complex acc, Node<Complex>* node) { return acc + node->get_value(); });

        REQUIRE(sum == Complex(21, 27));
    }
}
