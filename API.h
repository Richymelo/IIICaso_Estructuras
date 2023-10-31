class Http{
    public:
        static size_t WriteCallback(void* data, size_t tamanno, size_t nmemb, string* r) {
            size_t tamannoTotal = tamanno * nmemb;
            r->append(static_cast<char*>(data), tamannoTotal);
            return tamannoTotal;
        }
};

class SustantivosR {
    private:

        CURL* curl;
        CURLcode res;
        vector<string> listaLetras = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    public:

        vector<string> getSustantivos() {

            curl = curl_easy_init();
            vector<string> listaPalabras;

            if (curl) {
                for (int i = 0; i < listaLetras.size(); i++) {
                    string url = "https://random-word-form.repl.co/random/noun/" + listaLetras[i] + "?count=15000";
                    curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
                    string r;
                    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpUtils::WriteCallback);
                    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &r);
                    res = curl_easy_perform(curl);

                    if (res == CURLE_OK) {
                        size_t pos = 0;
                        while ((pos = r.find("\"", pos)) != string::npos) {
                            size_t end_pos = r.find("\"", pos + 1);
                            if (end_pos != string::npos) {
                                string word = r.substr(pos + 1, end_pos - pos - 1);
                                listaPalabras.push_back(word);
                                listaPalabras.push_back(word+"ed");
                                listaPalabras.push_back(word+"s");
                            }
                            pos = end_pos + 1;
                        }
                    } else {
                        std::cerr << "Error en la solicitud para la letra " << listaLetras[i] << ": " << curl_easy_strerror(res) << std::endl;
                    }
                }

                curl_easy_cleanup(curl);
            }

            return listaPalabras;
        }
};

class ChatGPT{
    private:
        string apiKey = "XXXXXXXXXXXXXXXXXXXXXX";
        string url = "https://api.openai.com/v1/chat/completions";
        string model = "gpt-3.5-turbo";
    public:

        void requestChat(const string& prompt) {

            json requestData;
            requestData["model"] = model;
            requestData["messages"].push_back({{"role", "user"}, {"content", prompt}});
            string requestDataStr = requestData.dump();

            CURL* curl = curl_easy_init();

            if (curl) {

                string response;
                struct curl_slist* headers = NULL;

                headers = curl_slist_append(headers, "Content-Type: application/json");
                headers = curl_slist_append(headers, ("Authorization: Bearer " + apiKey).c_str());

                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestDataStr.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestDataStr.length());
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, HttpUtils::WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                CURLcode res = curl_easy_perform(curl);

                if (res != CURLE_OK) {
                    std::cerr << "Curl request failed: " << curl_easy_strerror(res) << std::endl;
                } else {
                    std::cout << response << std::endl;
                }

                curl_easy_cleanup(curl);
                curl_slist_free_all(headers);

            } else {

                std::cerr << "Failed to initialize cURL." << std::endl;
            }
        }
}