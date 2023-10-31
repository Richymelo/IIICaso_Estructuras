#ifndef _NODOGENERICO_
#define _NODOGENERICO_ 1

class node {

            public:

                T key;
                std::vector<string> BooksVector;
                int height;
                node* left;
                node* right;

                node(T k, const std::vector<string>& words) {
                    height = 1;
                    key = k;
                    BooksVector = words;
                    left = NULL;
                    right = NULL;
                }
        };