#include "Tree.hpp"
#include <sstream>
#include <string>
#include <queue>
#include <vector>


using namespace std;


// Constructor with default arity
template <typename T, size_t k>
Tree<T, k>::Tree() : root(nullptr) {
  if (k <= 0) {
    throw runtime_error("Arity of the tree must be greater than 0");
  }
}

// Destructor to clear the tree
template <typename T, size_t k>
Tree<T, k>::~Tree() {
  clear(root);
}

// Recursive function to clear the tree
template <typename T, size_t k>
void Tree<T, k>::clear(Node<T> *node) {
  if (node) {
    for (auto child : node->get_children()) {
      clear(child); // Clear each child
    }
    delete node; // Delete the node itself
  }
}

// Add root to the tree
template <typename T, size_t k>
void Tree<T, k>::add_root(Node<T> &root_node) {
  root = new Node<T>(root_node.get_value(), k); // Initialize root with the correct arity
}

/// Add sub-node to a parent node
template <typename T, size_t k>
bool Tree<T, k>::add_sub_node(Node<T> &parent_node, Node<T> &sub_node) {
  Node<T> *parent = find_node(root, parent_node.get_value()); // Find the parent node
  if (parent) {
    auto& children = parent->get_children();
    for (size_t i = 0; i < parent->get_k(); ++i) {
      if (!children[i]) {
        children[i] = new Node<T>(sub_node.get_value(), k); // Initialize sub_node with the correct arity
        return true; // Successfully added sub-node
      }
    }
  }
  // Failed to add sub-node
  throw runtime_error("Failed to add sub-node!");
}

// Find a node by value
template <typename T, size_t k>
Node<T> *Tree<T, k>::find_node(Node<T> *node, T value) {
  if (!node)
    return nullptr;

  if (node->get_value() == value)
    return node; // Node found

  for (auto child : node->get_children()) {
    Node<T> *result = find_node(child, value); // Recursive search in children
    if (result)
      return result;
  }

  return nullptr; // Node not found
}

// Iterator methods

// Begin pre-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::begin_pre_order() {
  return typename IteratorType<T, k>::PreOrder(root);
}

// End pre-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::PreOrder Tree<T, k>::end_pre_order() {
  return typename IteratorType<T, k>::PreOrder(nullptr);
}

// Begin post-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::begin_post_order() {
  return typename IteratorType<T, k>::PostOrder(root);
}

// End post-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::PostOrder Tree<T, k>::end_post_order() {
  return typename IteratorType<T, k>::PostOrder(nullptr);
}

// Begin in-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::begin_in_order() {
  return typename IteratorType<T, k>::InOrder(root);
}

// End in-order traversal
template <typename T, size_t k>
typename IteratorType<T, k>::InOrder Tree<T, k>::end_in_order() {
  return typename IteratorType<T, k>::InOrder(nullptr);
}

// Begin BFS traversal
template <typename T, size_t k>
BFSIterator<T, k> Tree<T, k>::begin_bfs_scan() {
  return BFSIterator<T, k>(root);
}

// End BFS traversal
template <typename T, size_t k>
BFSIterator<T, k> Tree<T, k>::end_bfs_scan() {
  return BFSIterator<T, k>(nullptr);
}

// Begin DFS traversal
template <typename T, size_t k>
DFSIterator<T, k> Tree<T, k>::begin_dfs() {
  return DFSIterator<T, k>(root);
}

// End DFS traversal
template <typename T, size_t k>
DFSIterator<T, k> Tree<T, k>::end_dfs() {
  return DFSIterator<T, k>(nullptr);
}

// Begin BFS iterator
template <typename T, size_t k>
BFSIterator<T, k> Tree<T, k>::begin() {
  return BFSIterator<T, k>(root);
}

// End BFS iterator
template <typename T, size_t k>
BFSIterator<T, k> Tree<T, k>::end() {
  return BFSIterator<T, k>(nullptr);
}

// Begin Min-Heap traversal
template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::begin_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(root);
  else
    throw runtime_error("The tree isn't binary tree!");
}

// End Min-Heap traversal
template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::end_min_heap() {
  if (k == 2)
    return MinHeapIterator<T, k>(nullptr); // End iterator
  else
    throw runtime_error("The tree isn't binary tree!");
}

/// Convert the tree to a min-heap and return an iterator
template <typename T, size_t k>
MinHeapIterator<T, k> Tree<T, k>::myHeap() {
  if (k != 2) {
    throw runtime_error("The tree isn't a binary tree!");
  }

  // Helper function to heapify the tree
  auto heapify = [](Node<T>* node) {
    if (!node) return;
    
    vector<Node<T>*> nodes;
    queue<Node<T>*> q;
    q.push(node);
    
    while (!q.empty()) {
      Node<T>* current = q.front();
      q.pop();
      nodes.push_back(current);
      for (auto child : current->get_children()) {
        if (child) {
          q.push(child);
        }
      }
    }

    // Sort nodes based on their values
    sort(nodes.begin(), nodes.end(), [](Node<T>* a, Node<T>* b) {
      return a->get_value() < b->get_value();
    });

    // Reassign children to maintain the heap property
    for (size_t i = 0; i < nodes.size(); ++i) {
      for (size_t j = 0; j < k; ++j) {
        size_t child_index = k * i + j + 1;
        nodes[i]->get_children()[j] = (child_index < nodes.size()) ? nodes[child_index] : nullptr;
      }
    }
  };

  heapify(root);
  return MinHeapIterator<T, k>(root);
}

// Draw the tree using SFML
template <typename T, size_t k>
void Tree<T, k>::printTree() {
   if (!root) return;

    // Constants for drawing
    const float windowWidth = 1000;
    const float windowHeight = 800;
    const float nodeRadius = 45; // Increased node radius
    const float verticalSpacing = 130;

    // Create a window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tree Visualization");
    
    // Load the font
    sf::Font font;
    if (!font.loadFromFile("font/Roboto-Regular.ttf")) {
        cerr << "Error loading font\n";
        return;
    }

    // Function to recursively draw the nodes
    function<void(Node<T>*, float, float, float)> drawNode =
        [&](Node<T>* node, float x, float y, float xOffset) {
            if (!node) return;

            // Recursively draw the children
            float newXOffset = xOffset / 2;
            float childX = x - xOffset * ((node->get_children().size() - 1) / 2.0f);
            float childY = y + verticalSpacing;
            for (auto child : node->get_children()) {
                if (child) {
                    // Draw the line connecting the node to its child
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(x, y), sf::Color::Red),
                        sf::Vertex(sf::Vector2f(childX, childY), sf::Color::Red)
                    };
                    window.draw(line, 2, sf::Lines);

                    // Draw the child node
                    drawNode(child, childX, childY, newXOffset);
                    childX += xOffset;
                }
            }

            // Draw the node
            sf::CircleShape circle(nodeRadius);
            circle.setFillColor(sf::Color::White); // White fill color for empty circle
            circle.setOutlineColor(sf::Color::Red); // Blue outline color
            circle.setOutlineThickness(3); // Outline thickness to create empty circle effect
            circle.setPosition(x - nodeRadius, y - nodeRadius);
            window.draw(circle);

            // Draw the node's value
            string to_draw = to_string(node->get_value());
            sf::Text text(to_draw, font, 20);
            text.setFillColor(sf::Color::Black); // Black text color
            // Center the text in the circle
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f,
                           textRect.top + textRect.height / 2.0f);
            text.setPosition(x, y);
            window.draw(text);
        };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // White background color
        drawNode(root, windowWidth / 2, nodeRadius * 2, windowWidth / 4);
        window.display();
    }
}
