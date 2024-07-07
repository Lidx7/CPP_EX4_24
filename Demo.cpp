/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

int main()
{
    cout << "Hello, World!" << endl;

    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    cout << "Hello, World!" << endl;

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    cout << "Hello, World!" << endl;
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */


    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // cout  <<  tree  <<  endl;


    //TODO: fix this
    // for (auto node : tree)
    // {
    //     cout << node->get_value() << endl;
    // } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    //TODO:cout << tree; // Should print the graph using GUI.

    Tree<double,3> three_ary_tree; // 3-ary tree.
    Node<  double> root_node2 = Node<double>(1.1);
    three_ary_tree.add_root(root_node2);
    three_ary_tree.add_sub_node(&root_node2, &n1);
    three_ary_tree.add_sub_node(&root_node2, &n2);
    three_ary_tree.add_sub_node(&root_node2, &n3);
    three_ary_tree.add_sub_node(&n1, &n4);
    three_ary_tree.add_sub_node(&n2, &n5);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    fflush(stdout);
}


// int main()
// {
//     cout << "Hello, World!" << endl;

//     auto root_node = Node<double>(1.1);
//     Tree<double> tree; // Binary tree that contains doubles.
//     tree.add_root(root_node);
//     auto n1 = Node<double>(1.2);
//     auto n2 = Node<double>(1.3);
//     auto n3 = Node<double>(1.4);
//     auto n4 = Node<double>(1.5);
//     auto n5 = Node<double>(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);


//     // cout << "Pre-order traversal:" << endl;
//     // for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
//     // {
//     //     cout << it->get_value() << " ";
//     // }
//     // cout << endl;

//     /*TODO: this fails probably because the root pointer isnt reseted back after the first
//         iterator used it. should find a way to fix this problem.*/
//     cout << "Post-order traversal:" << endl;
//     for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
//     {
//         //cout << "here" << endl;
//         cout << it->get_value() << " ";
//     }
//     cout << endl;

//     cout << "In-order traversal:" << endl;
//     for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
//     {
//         cout << it->get_value() << " ";
//     }
//     cout << endl;

//     cout << "BFS traversal:" << endl;
//     for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
//     {
//         cout << it->get_value() << " ";
//     }
//     cout << endl;

//}