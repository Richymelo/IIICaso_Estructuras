#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using json = nlohmann::json;

struct WordInfo {

    string word;
    vector<string> books;
};

class ConfigLoader{
    private:
        json data;
    
    public:
    configLoader(const string& jsonFileName){
        ifstream file(jsonFileName);

            if (!file.is_open()) {
                cerr << "No se pudo abrir el archivo JSON" << endl;
                throw runtime_error("Error al abrir el archivo JSON");
            }

            file >> data;

            file.close();
    }
    vector<WordInfo> extraerPalabra() { 

            vector<WordInfo> listaPalabras;

            json words = data["words"];

            for (json::iterator it = words.begin(); it != words.end(); ++it) {

                WordInfo info;
                info.word = it.key();
                info.books = it.value().at("Book").get<vector<string>>();
                listaPalabras.push_back(info);

            }
            
            return listaPalabras;
        }
        vector<int> extraerPosicion(const string& word) {
            vector<int> listaPosicion;

            json words = data["Nouns"];

            for (const auto& entry : words) {
                string entryWord = entry["word"];
                if (entryWord == word) {
                    vector<int> pos = entry["postions"].get<vector<int>>();
                    listaPosicion.insert(listaPosicion.end(), pos.begin(), pos.end());
                }
            }

            return listaPosicion;
        }
}