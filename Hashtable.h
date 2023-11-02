const int tableSize = 7507;
template <typename T>
struct KeyValue {
    string key;
    typename AVLTree<T>::node* value;
};

template <typename T>

class NodosHashtable{
    private:

        vector<KeyValue<T>> table[tableSize];

        int hash(const string& key) {
            int sum = 0;
            for (char c : key) {
                sum += c;
            }
            return sum % tableSize;
        }

        AVLTree<T> AVLBook;
    
    public:
        void insert(const string& key, typename AVLTree<T>::node* value) {
                int i = hash(key);
                for (KeyValue<T>& k : table[i]) {
                    if (k.key == key) {
                        cout << "Clave duplicada: " << key << endl;
                        return;
                    }
                }
                KeyValue<T> k;
                kv.key = key;
                kv.value = value;
                table[i].push_back(k);
        }
        typename AVLTree<T>::node* search(const string& key) {
            int index = hash(key);
            for (const KeyValue<T>& kv : table[index]) {
                if (kv.key == key) {
                    return kv.value;
                }
            }
            return nullptr;
        }

        vector<string> searchReturn(const string& key) {
            vector<string> bookslist;
            typename AVLTree<T>::node* result = search(key);
            if (result) {
                for (const string& book : result->BooksVector) {
                    bookslist.push_back(book);
                }
            } 
            return bookslist;
        }


        void searchAndPrint(const string& key) {
            typename AVLTree<T>::node* result = search(key);
            if (result) {
                cout << "Palabra encontrada: " << key << endl;
                cout << "Libros asociados:" << endl;
                for (const string& book : result->BooksVector) {
                    cout << "  " << book << endl;
                }
            } else {
                cout << "Palabra no encontrada: " << key << endl;
            }
        }

        vector<KeyValue<T>> getTable() {
            vector<KeyValue<T>> result;
            for (int i = 0; i < tableSize; i++) {
                for (const KeyValue<T>& kv : table[i]) {
                    result.push_back(kv);
                }
            }
            return result;
        }

        void generateWordsHashTable() {
            JsonParser JsonParser("NounsWordsBooks/!AllWordsExtract.json");
            vector<WordInfo> wordInfoList = JsonParser.extractWordJSON();
            for (const WordInfo& info : wordInfoList) {
                const string& word = info.word;
                const vector<string>& book = info.books;
                typename AVLTree<T>::node* AVLNode = new typename AVLTree<T>::node(word, book);
                AVLLibro.insert(word, book);
                insert(word, AVLNode);
            }
        }
};