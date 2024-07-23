#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"
#include "Iterators.hpp"

TEST_CASE("Node operations") {
    Node<int> node(5);
    CHECK(node.get_value() == 5);

    Node<int> child1(3);
    Node<int> child2(7);
    node.add_child(&child1);
    node.add_child(&child2);

    CHECK(node.get_children().size() == 2);
    CHECK(node.get_children()[0]->get_value() == 3);
    CHECK(node.get_children()[1]->get_value() == 7);
}


TEST_CASE("Tree operations") {
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(&root);

    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);

    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);
    tree.add_sub_node(&child1, &child3);

    SUBCASE("Pre-order traversal") {
        std::vector<int> expected = {1, 2, 4, 3};
        std::vector<int> result;
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Post-order traversal") {
        std::vector<int> expected = {4, 2, 3, 1};
        std::vector<int> result;
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("In-order traversal") {
        std::vector<int> expected = {4, 2, 1, 3};
        std::vector<int> result;
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("BFS traversal") {
        std::vector<int> expected = {1, 2, 3, 4};
        std::vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<int> expected = {1, 2, 4, 3};
        std::vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }
}

TEST_CASE("3-ary tree operations") {
    Tree<int, 3> tree;
    Node<int> root(1);
    tree.add_root(&root);

    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);

    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);
    tree.add_sub_node(&root, &child3);
    tree.add_sub_node(&child1, &child4);

    SUBCASE("BFS traversal") {
        std::vector<int> expected = {1, 2, 3, 4, 5};
        std::vector<int> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("DFS traversal") {
        std::vector<int> expected = {1, 2, 4, 3, 5};
        std::vector<int> result;
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result == expected);
    }

    SUBCASE("Maximum children") {
        Node<int> extra_child(6);
        CHECK_THROWS_AS(tree.add_sub_node(&root, &extra_child), std::runtime_error);
    }
}

TEST_CASE("Complex tree operations") {
    Tree<Complex> tree;
    Node<Complex> root(Complex(1, 1));
    tree.add_root(&root);

    Node<Complex> child1(Complex(2, 2));
    Node<Complex> child2(Complex(3, 3));

    tree.add_sub_node(&root, &child1);
    tree.add_sub_node(&root, &child2);

    SUBCASE("BFS traversal") {
        std::vector<Complex> expected = {Complex(1, 1), Complex(2, 2), Complex(3, 3)};
        std::vector<Complex> result;
        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
            result.push_back(it->get_value());
        }
        CHECK(result.size() == expected.size());
        for (size_t i = 0; i < result.size(); ++i) {
            CHECK(result[i].getReal() == expected[i].getReal());
            CHECK(result[i].getImag() == expected[i].getImag());
        }
    }
}