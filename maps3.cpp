#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

// Entry class to hold the letter and its corresponding cryptogram character
template <typename K, typename V>
class Entry {
private:
    K _key;   // Original letter
    V _value; // Corresponding cryptogram letter

public:
    // Constructor
    Entry(K key, V value) : _key(key), _value(value) {}

    // Destructor
    virtual ~Entry() {}

    // Getters and Setters
    K getK() const { return _key; }
    V getV() const { return _value; }
    void setK(K key) { _key = key; }
    void setV(V value) { _value = value; }
};

// Node for Doubly Linked List
template <typename K, typename V>
class Node {
public:
    Entry<K, V> entry;
    Node* next;
    Node* prev;

    Node(const Entry<K, V>& entry) : entry(entry), next(nullptr), prev(nullptr) {}
};

// NodeCryptogram class that implements a doubly linked list using std::map
template <typename K, typename V>
class NodeCryptogram {
private:
    int uniqueKeys; // Current number of unique keys
    int size;       // Total number of entries
    Node<K, V>* header;  // Head sentinel
    Node<K, V>* trailer; // Tail sentinel
    std::map<K, Node<K, V>*> cryptogramMap; // Map for letter lookups

public:
    // Constructor
    NodeCryptogram();

    // Destructor
    virtual ~NodeCryptogram();

    // Add a new cryptogram entry
    void put(const K& key, const V& value);

    // Find and return a node by key
    Node<K, V>* find(const K& key);

    // Remove entry by key
    void erase(const K& key);

    // Print all cryptogram entries from the beginning
    void printCryptogram();

    // Print all cryptogram entries from the end
    void printCryptogramReverse();

    // Get the number of unique keys
    int uniqueKeysCount() const;

    // Get the total number of entries
    int size() const;

    bool empty() const;
};

template <typename K, typename V>
NodeCryptogram<K, V>::NodeCryptogram() : uniqueKeys(0), size(0), header(nullptr), trailer(nullptr) {
    header = new Node<K, V>(Entry<K, V>("", "")); // Create head sentinel
    trailer = new Node<K, V>(Entry<K, V>("", "")); // Create tail sentinel
    header->next = trailer;
    trailer->prev = header;
}

template <typename K, typename V>
NodeCryptogram<K, V>::~NodeCryptogram() {
    Node<K, V>* current = header->next;
    while (current != trailer) {
        Node<K, V>* temp = current;
        current = current->next;
        delete temp;
    }
    delete header;
    delete trailer;
}

template <typename K, typename V>
void NodeCryptogram<K, V>::put(const K& key, const V& value) {
    if (cryptogramMap.find(key) == cryptogramMap.end()) {
        Entry<K, V> newEntry(key, value);
        Node<K, V>* newNode = new Node<K, V>(newEntry);
        cryptogramMap[key] = newNode;
        // Insert the node in the list
        Node<K, V>* lastNode = trailer->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = trailer;
        trailer->prev = newNode;
        uniqueKeys++;
    }
}

template <typename K, typename V>
Node<K, V>* NodeCryptogram<K, V>::find(const K& key) {
    return cryptogramMap[key];
}

template <typename K, typename V>
void NodeCryptogram<K, V>::erase(const K& key) {
    if (cryptogramMap.find(key) != cryptogramMap.end()) {
        Node<K, V>* nodeToRemove = cryptogramMap[key];
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
        delete nodeToRemove;
        cryptogramMap.erase(key);
        uniqueKeys--;
    }
}

template <typename K, typename V>
void NodeCryptogram<K, V>::printCryptogram() {
    Node<K, V>* current = header->next;
    while (current != trailer) {
        cout << current->entry.getK() << " -> " << current->entry.getV() << endl;
        current = current->next;
    }
}

template <typename K, typename V>
void NodeCryptogram<K, V>::printCryptogramReverse() {
    Node<K, V>* current = trailer->prev;
    while (current != header) {
        cout << current->entry.getK() << " -> " << current->entry.getV() << endl;
        current = current->prev;
    }
}

template <typename K, typename V>
int NodeCryptogram<K, V>::uniqueKeysCount() const {
    return uniqueKeys;
}

template <typename K, typename V>
int NodeCryptogram<K, V>::size() const {
    return size;
}

template <typename K, typename V>
bool NodeCryptogram<K, V>::empty() const {
    return size == 0;
}

// Cryptogram class to manage the cryptogram key
class Cryptogram {
private:
    string name;                      // Name of the cryptogram
    NodeCryptogram<char, char> cryptogram; // Internal cryptogram key storage

public:
    // Constructor
    Cryptogram(string name);

    // Destructor
    virtual ~Cryptogram();

    // Add letter mapping
    void add(Entry<char, char> entry);

    // Delete letter mapping by original letter
    void deleteMapping(char letter);

    // Print the cryptogram key
    void printCryptogram(bool fromStart = true);

    // Get the number of unique letter mappings
    int uniqueMappings() const;

    bool empty() const;
};

Cryptogram::Cryptogram(string name) : name(name) {}

Cryptogram::~Cryptogram() {}

void Cryptogram::add(Entry<char, char> entry) {
    cryptogram.put(entry.getK(), entry.getV());
}

void Cryptogram::deleteMapping(char letter) {
    cryptogram.erase(letter);
}

void Cryptogram::printCryptogram(bool fromStart) {
    if (fromStart) {
        cryptogram.printCryptogram();
    } else {
        cryptogram.printCryptogramReverse();
    }
}

int Cryptogram::uniqueMappings() const {
    return cryptogram.uniqueKeysCount();
}

bool Cryptogram::empty() const {
    return cryptogram.empty();
}

int main() {
    // Create a cryptogram key
    Cryptogram myCryptogram("My Cryptogram");

    // Add some letter mappings (cryptogram key)
    myCryptogram.add(Entry<char, char>('a', 'z'));
    myCryptogram.add(Entry<char, char>('b', 'y'));
    myCryptogram.add(Entry<char, char>('c', 'x'));
    myCryptogram.add(Entry<char, char>('d', 'w'));

    // Print the cryptogram key from the beginning
    cout << "Cryptogram from start:" << endl;
    myCryptogram.printCryptogram(true);

    // Print the cryptogram key from the end
    cout << "Cryptogram from end:" << endl;
    myCryptogram.printCryptogram(false);

    // Remove a letter mapping
    myCryptogram.deleteMapping('b');

    // Print the cryptogram key after deletion
    cout << "After deleting 'b':" << endl;
    myCryptogram.printCryptogram(true);

    return 0;
}
