class LRUCache {
public:

    // DLL Node
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;

    // key -> node address
    unordered_map<int, Node*> mp;

    // Dummy nodes
    Node* head; // LRU side
    Node* tail; // MRU side

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // Empty DLL
        head->next = tail;
        tail->prev = head;
    }

    // Remove node from DLL
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Add node at MRU side
    void addToMRU(Node* node) {
        Node* last = tail->prev;

        last->next = node;
        node->prev = last;

        node->next = tail;
        tail->prev = node;
    }

    // Get value
    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Mark as recently used
        remove(node);
        addToMRU(node);

        return node->value;
    }

    // Insert / Update
    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Make it MRU
            remove(node);
            addToMRU(node);

            return;
        }

        // Create new node
        Node* node = new Node(key, value);

        // Store in map
        mp[key] = node;

        // New node = MRU
        addToMRU(node);

        // Capacity exceeded
        if (mp.size() > capacity) {

            // First real node = LRU
            Node* lru = head->next;

            // Remove from DLL
            remove(lru);

            // Remove from map
            mp.erase(lru->key);

            delete lru;
        }
    }
};



// # 🔥 LeetCode 146 — LRU Cache

// ### Approach

// * `unordered_map` → key ko **O(1)** me find karta hai.
// * Doubly Linked List → **LRU → MRU order** maintain karti hai.
// * `head->next` = LRU
// * `tail->prev` = MRU

// ```cpp
// class LRUCache {
// public:

//     // DLL Node
//     struct Node {
//         int key, value;
//         Node* prev;
//         Node* next;

//         Node(int k, int v) {
//             key = k;
//             value = v;
//             prev = nullptr;
//             next = nullptr;
//         }
//     };

//     int capacity;

//     // key -> node address
//     unordered_map<int, Node*> mp;

//     // Dummy nodes
//     Node* head; // LRU side
//     Node* tail; // MRU side

//     LRUCache(int capacity) {
//         this->capacity = capacity;

//         head = new Node(-1, -1);
//         tail = new Node(-1, -1);

//         // Empty DLL
//         head->next = tail;
//         tail->prev = head;
//     }

//     // Remove node from DLL
//     void remove(Node* node) {
//         Node* prevNode = node->prev;
//         Node* nextNode = node->next;

//         prevNode->next = nextNode;
//         nextNode->prev = prevNode;
//     }

//     // Add node at MRU side
//     void addToMRU(Node* node) {
//         Node* last = tail->prev;

//         last->next = node;
//         node->prev = last;

//         node->next = tail;
//         tail->prev = node;
//     }

//     // Get value
//     int get(int key) {

//         // Key doesn't exist
//         if (mp.find(key) == mp.end())
//             return -1;

//         Node* node = mp[key];

//         // Mark as recently used
//         remove(node);
//         addToMRU(node);

//         return node->value;
//     }

//     // Insert / Update
//     void put(int key, int value) {

//         // Key already exists
//         if (mp.find(key) != mp.end()) {

//             Node* node = mp[key];

//             // Update value
//             node->value = value;

//             // Make it MRU
//             remove(node);
//             addToMRU(node);

//             return;
//         }

//         // Create new node
//         Node* node = new Node(key, value);

//         // Store in map
//         mp[key] = node;

//         // New node = MRU
//         addToMRU(node);

//         // Capacity exceeded
//         if (mp.size() > capacity) {

//             // First real node = LRU
//             Node* lru = head->next;

//             // Remove from DLL
//             remove(lru);

//             // Remove from map
//             mp.erase(lru->key);

//             delete lru;
//         }
//     }
// };
// ```

// ### 🧠 बस logic याद रखो:

// ```text
// GET:
// find → remove → MRU → return

// PUT:
// new/update → MRU
//        ↓
// capacity full?
//        ↓
// remove LRU
// ```

// ```text
// HEAD → LRU → ... → MRU → TAIL
//           Doubly Linked List
// ```

// **Time:** `get = O(1)`, `put = O(1)`
// **Space:** `O(capacity)`
