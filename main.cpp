#include "Complex.hpp"
#include "Node.hpp"
#include "Tree.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {

  // Create Complex objects
  Complex c1(1, 1);
  Complex c2(2, 2);
  Complex c3(3, 3);
  Complex c4(4, 4);
  Complex c5(5, 5);
  

  // Create nodes
  Node<Complex> root_node_complex(c1);
  Node<Complex> n1_complex(c2);
  Node<Complex> n2_complex(c3);
  Node<Complex> n3_complex(c4);
  Node<Complex> n4_complex(c5);
  

  // Create tree and add nodes
  Tree<Complex> complex_tree;
  complex_tree.add_root(root_node_complex);
  complex_tree.add_sub_node(root_node_complex, n1_complex);
  complex_tree.add_sub_node(root_node_complex, n2_complex);
  complex_tree.add_sub_node(n1_complex, n3_complex);
  complex_tree.add_sub_node(n1_complex, n4_complex);
  

  complex_tree.printTree();
  /*
          (1 , 1i)
        /         \
      (2,2i)      (3 , 3i)
      /   \
  (4,4i)  (5,5i)

 */

  for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node) {
    cout << node->get_value() <<", ";
  }
   cout<<""<<endl;

 

    Tree<double> tree; // Binary tree that contains doubles.
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */
    tree.printTree();
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
     cout<<""<<endl;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
     cout<<""<<endl;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
     cout<<""<<endl;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
     cout<<""<<endl;

    for (auto node : tree)
    {
        cout << node->get_value() <<", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<""<<endl;
    
    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);
    three_ary_tree.printTree();
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */


    Node<string> root_string("THIS");
    Node<string> n1_string("IS");
    Node<string> n2_string("HOW");
    Node<string> n3_string("WE");
    Node<string> n4_string("DO");
    Node<string> n5_string("IT");
    Node<string> n6_string("!!!!");

    Tree<string,3> three_ary_tree_strings; // 3-ary tree.
    three_ary_tree_strings.add_root(root_string);
    three_ary_tree_strings.add_sub_node(root_string, n1_string);
    three_ary_tree_strings.add_sub_node(root_string, n2_string);
    three_ary_tree_strings.add_sub_node(root_string, n3_string);
    three_ary_tree_strings.add_sub_node(n1_string, n4_string);
    three_ary_tree_strings.add_sub_node(n2_string, n5_string);
    three_ary_tree_strings.add_sub_node(n3_string, n6_string);
    three_ary_tree_strings.printTree();


    for (auto node = three_ary_tree_strings.begin_bfs_scan(); node != three_ary_tree_strings.end_bfs_scan(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: THIS, IS, HOW, WE, DO, IT, !!!!,
     cout<<""<<endl;

    for (auto node : three_ary_tree_strings)
    {
        cout << node->get_value() <<", ";
    } // same as BFS: THIS, IS, HOW, WE, DO, IT, !!!!,
    cout<<""<<endl;



    Node<int> root_int(1);
    Node<int> n1_int(2);
    Node<int> n2_int(3);
    Node<int> n3_int(4);
    Node<int> n4_int(5);
    Node<int> n5_int(6);

    Tree<int> binary_tree_ints; // 2-ary tree.
    binary_tree_ints.add_root(root_int);
    binary_tree_ints.add_sub_node(root_int, n1_int);
    binary_tree_ints.add_sub_node(root_int, n2_int);
    binary_tree_ints.add_sub_node(n2_int, n3_int);
    binary_tree_ints.add_sub_node(n2_int, n4_int);
    binary_tree_ints.add_sub_node(n3_int, n5_int);
    /**
     *       root = 1
     *            /   \    
     *           2      3     
     *                /   \
     *               4     5
     *                      \
     *                       6 
     */
    binary_tree_ints.printTree();

    
    binary_tree_ints.myHeap();
    /**
     *        root = 1
     *            /     \    
     *           2       3           
     *         /   \    /
     *        4     5  6                
     */
   
    binary_tree_ints.printTree();


cout<<"------------------------"<<endl;

for (auto node = binary_tree_ints.begin_pre_order(); node != binary_tree_ints.end_pre_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 1, 2, 4, 5, 3, 6,
     cout<<""<<endl;

    for (auto node = binary_tree_ints.begin_post_order(); node != binary_tree_ints.end_post_order(); ++node)
    {
        cout << node->get_value() <<", ";
    } // prints: 4, 5, 2, 6, 3, 1, 
     cout<<""<<endl;

    for (auto node = binary_tree_ints.begin_in_order(); node != binary_tree_ints.end_in_order(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 4, 2, 5, 1, 6, 3,
     cout<<""<<endl;

    for (auto node = binary_tree_ints.begin_bfs_scan(); node != binary_tree_ints.end_bfs_scan(); ++node)
    {
         cout << node->get_value() <<", ";
    } // prints: 1, 2, 3, 4, 5, 6,
     cout<<""<<endl;

    for (auto node : binary_tree_ints)
    {
        cout << node->get_value() <<", ";
    } // same as BFS: 1, 2, 3, 4, 5, 6,
    cout<<""<<endl;







  return 0;
}
