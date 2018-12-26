#pragma once

#include <stdexcept>
using namespace std;

template<typename KEY, typename VALUE>
struct Node {
    KEY key;
    VALUE value;
    Node<KEY, VALUE>* parent;
    Node<KEY, VALUE>* left;
    Node<KEY, VALUE>* right;
    
    Node(KEY newKey, VALUE newValue, Node<KEY, VALUE>* newParent, Node<KEY, VALUE>* newLeft, Node<KEY, VALUE>* newRight)
    : key(newKey), value(newValue), parent(newParent), left(newLeft), right(newRight) {};
};

template<typename KEY, typename VALUE>
class BinarySearchTree {
private:
    Node<KEY, VALUE>* root;
    int size;
    
    Node<KEY, VALUE>* search(KEY);
    Node<KEY, VALUE>* insert(KEY, VALUE);
    void remove(KEY);
public:
    // Constructors
    BinarySearchTree() = default;
    BinarySearchTree(const BinarySearchTree&) = default;
    BinarySearchTree& operator=(const BinarySearchTree&) = default;
    ~BinarySearchTree() = default;
    
    // Getters / Setters
    int getSize();
    bool isEmpty();
    VALUE get(KEY);
    void put(KEY, VALUE);
    void erase(KEY);
    void clear();
};

// Getters / Setters
template<typename KEY, typename VALUE>
int BinarySearchTree<KEY, VALUE>::getSize() {
    return size;
}

template<typename KEY, typename VALUE>
bool BinarySearchTree<KEY, VALUE>::isEmpty() {
    return (size == 0);
}

template<typename KEY, typename VALUE>
VALUE BinarySearchTree<KEY, VALUE>::get(KEY searchKey) {
    // Kick off a recursive function to get the matching node
    Node<KEY, VALUE>* match = search(searchKey);
    
    // Instead of an exception we can return NULL.
    if (match == NULL) {
        throw logic_error("Key not found!");
    }
    
    return match->value;
}

template<typename KEY, typename VALUE>
void BinarySearchTree<KEY, VALUE>::put(KEY newKey, VALUE newValue) {
    // Use recursive function to find matching node
    Node<KEY, VALUE>* match = search(newKey);
    
    if (match != NULL) {
        // If we found a match, update the value
        match->value = newValue;
    } else {
        insert(newKey, newValue);
        size++;
    }
}

template<typename KEY, typename VALUE>
void BinarySearchTree<KEY, VALUE>::erase(KEY searchKey) {
    // Make sure search finds a value
    if (search(searchKey) != NULL) {
        // Use recursive function to erase matching node
        remove(searchKey);
        size--;
    }
}

template<typename KEY, typename VALUE>
void BinarySearchTree<KEY, VALUE>::clear() {
    while(root != NULL) {
        remove(root->key);
    }
}


// Helper functions
template<typename KEY, typename VALUE>
Node<KEY, VALUE>* BinarySearchTree<KEY, VALUE>::search(KEY desiredKey) {
    Node<KEY, VALUE>* currNode = root;
    
    while(currNode != NULL) {
        if (desiredKey == currNode->key) {
            // Found!
            return currNode;
        } else if (desiredKey < currNode->key) {
            // Visit left child, repeat
            currNode = currNode->left;
        } else {
            // Visit right child, repeat
            currNode = currNode->right;
        }
    }
    
    // Not found
    return NULL;
}

template<typename KEY, typename VALUE>
Node<KEY, VALUE>* BinarySearchTree<KEY, VALUE>::insert(KEY newKey, VALUE newValue) {
    if (root == NULL) {
        root = new Node<KEY, VALUE>(newKey, newValue, NULL, NULL, NULL);
        return root;
    } else {
        Node<KEY, VALUE>* currNode = root;
        
        // Similar to search()
        while (currNode != NULL) {
            //TODO: Add base case overriding same key
            if (newKey < currNode->key) {
                // Traverse Left
                if (currNode->left == NULL) {
                    // Left is NULL, insert new node
                    currNode->left = new Node<KEY, VALUE>(newKey, newValue, currNode, NULL, NULL);
                    return currNode->left;
                } else {
                    currNode = currNode->left;
                }
            } else {
                // Traverse Right
                if (currNode->right == NULL) {
                    // Right is NULL, insert new node
                    currNode->right = new Node<KEY, VALUE>(newKey, newValue, currNode, NULL, NULL);
                    return currNode->right;
                } else {
                    currNode = currNode->right;
                }
            }
        }
        return currNode;
    }
}

template<typename KEY, typename VALUE>
void BinarySearchTree<KEY, VALUE>::remove(KEY desiredKey) {
    Node<KEY, VALUE>* currNode = search(desiredKey);
    Node<KEY, VALUE>* parentNode = currNode->parent;
    
    if (desiredKey == currNode->key) {
        // Found!
        if (!currNode->left && !currNode->right) {
            // Left and Right are NULL, EASY!
            if (!parentNode) {
                // Parent is NULL, currNode is root node
                root = NULL;
            } else if (parentNode->left == currNode) {
                // currNode is left child of parent node
                parentNode->left = NULL;
                delete currNode;
            } else {
                // currNode is right child of parent node
                parentNode->right = NULL;
                delete currNode;
            }
        } else if (currNode->left && !currNode->right) {
            // Left is NOT NULL, Right is NULL, MEDIUM!
            if (!currNode) {
                // Parent is NULL, currNode is root node
                root = currNode->left;
            } else if (parentNode->left == currNode) {
                // currNode is left child of parent node
                parentNode->left = currNode->left;
                delete currNode;
            } else {
                // currNode is right child of parent node
                parentNode->right = currNode->left;
                delete currNode;
            }
        } else if (!currNode->left && !currNode->right) {
            // Left is NULL, Right is NOT NULL, MEDIUM!
            if (!currNode) {
                // Parent is NULL, currNode is root node
                root = currNode->right;
            } else if (parentNode->left == currNode) {
                // currNode is left child of parent node
                parentNode->left = currNode->right;
                delete currNode;
            } else {
                // currNode is right child of parent node
                parentNode->right = currNode->right;
                delete currNode;
            }
        } else {
            // Left and Right are both NOT NULL, HARD!
            Node<KEY, VALUE>* successor = currNode->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            Node<KEY, VALUE>* temp = currNode;
            remove(successor->key);
            currNode = temp;
        }
        // Node found and removed!
    }
    // Node not found!
}
