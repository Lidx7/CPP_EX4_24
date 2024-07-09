#include <QApplication>
#include <QMainWindow>
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "TreeWidget.hpp"
#include "Complex.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cout << "Hello, World!" << endl;

    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.8);

    cout << "Adding nodes to the tree..." << endl;

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    cout << "Tree structure created." << endl;

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-order traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "Post-order traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "In-order traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;

    cout << "BFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    }
    cout << endl;


    Tree<double,3> three_ary_tree; // 3-ary tree.
    Node<double> root_node2 = Node<double>(1.1);
    Node<double> n11(1.2);
    Node<double> n21(1.3);
    Node<double> n31(1.4);
    Node<double> n41(1.5);
    Node<double> n51(1.8);

    three_ary_tree.add_root(root_node2);
    three_ary_tree.add_sub_node(&root_node2, &n11);
    three_ary_tree.add_sub_node(&root_node2, &n21);
    three_ary_tree.add_sub_node(&root_node2, &n31);
    three_ary_tree.add_sub_node(&n11, &n41);
    three_ary_tree.add_sub_node(&n21, &n51);


    Tree<Complex,3> complex_tree; // Binary tree that contains complex numbers.
    Node<Complex> root_node3 = Node<Complex>(Complex(1.1, 2.2));
    Node<Complex> n12 = Node<Complex>(Complex(1.2, 2.3));
    Node<Complex> n22 = Node<Complex>(Complex(1.3, 2.4));
    Node<Complex> n32 = Node<Complex>(Complex(1.4, 2.5));
    Node<Complex> n42 = Node<Complex>(Complex(1.5, 2.6));
    Node<Complex> n52 = Node<Complex>(Complex(1.8, 2.7));

    complex_tree.add_root(root_node3);
    complex_tree.add_sub_node(&root_node3, &n12);
    complex_tree.add_sub_node(&root_node3, &n22);
    complex_tree.add_sub_node(&root_node3, &n32);
    complex_tree.add_sub_node(&n12, &n42);
    complex_tree.add_sub_node(&n22, &n52);


    Tree<string> string_tree; // Binary tree that contains strings.
    Node<string> root_node4 = Node<string>("root");
    Node<string> n13 = Node<string>("n1");
    Node<string> n23 = Node<string>("n2");
    Node<string> n33 = Node<string>("n3");
    Node<string> n43 = Node<string>("n4");
    Node<string> n53 = Node<string>("n5");

    string_tree.add_root(root_node4);
    string_tree.add_sub_node(&root_node4, &n13);
    string_tree.add_sub_node(&root_node4, &n23);
    string_tree.add_sub_node(&n13, &n33);
    string_tree.add_sub_node(&n13, &n43);
    string_tree.add_sub_node(&n23, &n53);



    // Create and show the GUI
    QMainWindow mainWindow;
    QTabWidget *tabWidget = new QTabWidget();

    TreeWidget<double, 2> *doubleTreeWidget = new TreeWidget<double, 2>(tree);
    TreeWidget<double, 3> *threeAryTreeWidget = new TreeWidget<double, 3>(three_ary_tree);
    TreeWidget<Complex, 3> *complexTreeWidget = new TreeWidget<Complex, 3>(complex_tree);
    TreeWidget<string> *stringTreeWidget = new TreeWidget<string>(string_tree);

    tabWidget->addTab(doubleTreeWidget, "Double Tree");
    tabWidget->addTab(threeAryTreeWidget, "3-ary Double Tree");
    tabWidget->addTab(complexTreeWidget, "3-ary Complex Tree");
    tabWidget->addTab(stringTreeWidget, "String Tree");

    mainWindow.setCentralWidget(tabWidget);
    mainWindow.resize(800, 600);
    mainWindow.setWindowTitle("Tree Visualization");
    mainWindow.show();

    cout << "GUI window opened. Close the window to end the program." << endl;

    return a.exec();
}
