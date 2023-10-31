#include "nodo.h"
template <typename T>

class AVLTree {

    public:
    
        node* root = NULL;
        int n;

        void insert(T value, const std::vector<string>& words) {
            root = insertUtil(root, value, words);
        }

        void remove(T value) {
            root = removeUtil(root, value);
        }

        std::vector<string> search(T value) {
            node* result = searchUtil(root, value);
            if (result) {
                return result->BooksVector;
            } else {
                return std::vector<string>();
            }
        }

        void inorder() {
            inorderUtil(root);
            cout << endl;
        }

    private:

        int height(node* head) {
            if (head == NULL) return 0;
            return head->height;
        }

        node* rightRotation(node* head) {
            node* newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1 + max(height(head->left), height(head->right));
            newhead->height = 1 + max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        node* leftRotation(node* head) {
            node* newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1 + max(height(head->left), height(head->right));
            newhead->height = 1 + max(height(newhead->left), height(newhead->right));
            return newhead;
        }

        void inorderUtil(node* head) {
            if (head == NULL) return;
            inorderUtil(head->left);
            cout << head->key << " ";
            for (const string& word : head->BooksVector) {
                cout << word << " ";
            }
            cout << endl;
            inorderUtil(head->right);
        }

        node* insertUtil(node* head, T value, const std::vector<string>& words) {
            if (head == NULL) {
                n += 1;
                node* temp = new node(value, words);
                return temp;
            }

            if (value < head->key) head->left = insertUtil(head->left, value, words);
            else if (value > head->key) head->right = insertUtil(head->right, x, words);
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if (bal > 1) {
                if (value < head->left->key) {
                    return rightRotation(head);
                } else {
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            } else if (bal < -1) {
                if (value > head->right->key) {
                    return leftRotation(head);
                } else {
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        node* removeUtil(node* head, T value) {
            if (head == NULL) return NULL;
            if (value < head->key) {
                head->left = removeUtil(head->left, value);
            } else if (value > head->key) {
                head->right = removeUtil(head->right, value);
            } else {
                node* r = head->right;
                if (head->right == NULL) {
                    node* l = head->left;
                    delete (head);
                    head = l;
                } else if (head->left == NULL) {
                    delete (head);
                    head = r;
                } else {
                    while (r->left != NULL) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if (head == NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
            int bal = height(head->left) - height(head->right);
            if (bal > 1) {
                if (height(head->left) >= height(head->right)) {
                    return rightRotation(head);
                } else {
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            } else if (bal < -1) {
                if (height(head->right) >= height(head->left)) {
                    return leftRotation(head);
                } else {
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        node* searchUtil(node* head, T value) {
            if (head == NULL) return NULL;
            T k = head->key;
            if (k == value) return head;
            if (k > value) return searchUtil(head->left, value);
            if (k < value) return searchUtil(head->right, value);
        }

};