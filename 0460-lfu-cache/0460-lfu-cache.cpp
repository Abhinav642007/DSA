class LFUCache {
public:

    // DLL Node
    class Node {
    public:
        int key, value, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = NULL;
            next = NULL;
        }
    };

    // key -> node
    unordered_map<int, Node*> mp;

    // freq -> DLL
    unordered_map<int, list<Node*>> freqList;

    int capacity;
    int minFreq;


    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }


    int get(int key) {

        // Key nahi mili
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Frequency increase
        increaseFreq(node);

        return node->value;
    }


    void put(int key, int value) {

        // Capacity 0
        if (capacity == 0)
            return;

        // Key already present
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Value update
            node->value = value;

            // Frequency increase
            increaseFreq(node);

            return;
        }

        // Cache full
        if (mp.size() == capacity) {

            // LFU frequency ki list
            auto &lst = freqList[minFreq];

            // Front = LRU
            Node* lru = lst.front();

            // Remove LRU
            lst.pop_front();

            mp.erase(lru->key);

            delete lru;
        }

        // New node
        Node* node = new Node(key, value);

        // Store node
        mp[key] = node;

        // New node -> freq 1
        freqList[1].push_back(node);

        // Minimum frequency = 1
        minFreq = 1;
    }


    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        // Old frequency list
        auto &oldList = freqList[oldFreq];

        // Find node
        for (auto it = oldList.begin(); it != oldList.end(); it++) {

            if (*it == node) {
                oldList.erase(it);
                break;
            }
        }

        // Frequency increase
        node->freq++;

        int newFreq = node->freq;

        // New frequency list mein MRU
        freqList[newFreq].push_back(node);

        // Agar old minimum list empty ho gayi
        if (oldFreq == minFreq && oldList.empty()) {
            minFreq++;
        }
    }
};