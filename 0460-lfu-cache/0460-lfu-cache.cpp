class LFUCache {
public:

    // key -> value
    unordered_map<int, int> value;

    // key -> frequency
    unordered_map<int, int> freq;

    // frequency -> keys
    unordered_map<int, list<int>> mp;

    int capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        // Key nahi hai
        if (value.find(key) == value.end())
            return -1;

        // Old frequency
        int old = freq[key];

        // Frequency increase
        freq[key]++;

        // Old frequency list se remove
        mp[old].remove(key);

        // New frequency list mein add
        mp[freq[key]].push_back(key);

        return value[key];
    }

    void put(int key, int val) {

        // Capacity 0
        if (capacity == 0)
            return;

        // Key already present
        if (value.find(key) != value.end()) {

            // Value update
            value[key] = val;

            // Frequency increase
            get(key);

            return;
        }

        // Cache full
        if (value.size() == capacity) {

            int minFreq = INT_MAX;

            // Minimum frequency find
            for (auto x : freq) {
                minFreq = min(minFreq, x.second);
            }

            // LFU key
            int removeKey = mp[minFreq].front();

            // Remove LFU key
            mp[minFreq].pop_front();
            value.erase(removeKey);
            freq.erase(removeKey);
        }

        // New key add
        value[key] = val;

        // New key ki frequency = 1
        freq[key] = 1;

        // Frequency 1 list mein add
        mp[1].push_back(key);
    }
};