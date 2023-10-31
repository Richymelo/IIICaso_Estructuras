struct InfoWords{
    vector<int> pos;
    int repeticiones;
};

void ExtraerSust(){
    unordered_map<string, vector<string>> wordsBooksMap;
    unordered_map<string, int> wordFrequencyMap;

    vector<string> libros = {"Alexandre Dumas # Le comte de Monte Cristo.txt","Arthur Doyle # The Adventures of Sherlock Holmes.txt","Charles Dickens # A Tale of Two Cities.txt","Charles Dickens # Great Expectations.txt","Charlotte Perkins # The Yellow Wallpaper.txt","Daniel Defoe # The Life and Adventures of Robinson Crusoe.txt","Edgar Poe # The Fall of the House of Usher.txt","F.Scott Fitzgerald # The Great Gastby.txt","Franz Kafka # Metamorphosis.txt","Fyodor Dostoyevsky # The Brothers Karamazov.txt","Henrik Ibsen # A Doll's House.txt","Herman Melville # Moby Dick; Or, The Whale.txt","Homer # The Odyssey.txt","J.M. Barrie # Peter Pan.txt","James Joyce # Dubliners.txt","James Joyce # Ulysses.txt","Jonathan Swift # A Modest Proposal.txt","Joseph Conrad # Heart of Darkness.txt","L. Frank Baum # The Wonderful Wizard of Oz.txt","L.M. Montgomery # Anne of Green Gables.txt","Leo Tolstoy # War and Peace.txt","Louisa May Alcott # Little Women.txt","Mark Twain # Adventures of Huckleberry Finn.txt","Mary Shelley # Frankenstein; Or, The Modern Prometheus.txt","Miguel de Cervantes # Don Quixote.txt","Oscar Wilde # The Picture of Dorian Gray.txt","Robert Stevenson # The Strange Case of Dr. Jekyll and Mr. Hyde.txt","Theodore Alois # The Iliad.txt","Thomas Hobbes # Leviathan.txt","Washington Irving # The Legend of Sleepy Hollow.txt"};
    SustantivosR sutantivos;
    vector<string> listaSustantivos = RandNouns.getSustantivos();
    sort(listaSustantivos.begin(), listaSustantivos.end());
    listaSustantivos.erase(unique(listaSustantivos.begin(), listaSustantivos.end()), listaSustantivos.end());
}