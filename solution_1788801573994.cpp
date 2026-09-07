class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        this->key = k;
        this->value = v;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add an existing node just before tail
    // This makes it the Most Recently Used (MRU) node
    void addNode(Node* node) {
        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

    // Remove a node from the doubly linked list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return -1;

        // Get the existing node
        Node* node = mp[key];

        // Move it to MRU position
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // If capacity is 0, we cannot store anything
        if (capacity == 0)
            return;

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            // Update value
            node->value = value;

            // Move to MRU
            deleteNode(node);
            addNode(node);

            return;
        }

        // Cache is full
        if (mp.size() == capacity) {

            // LRU node is right after head
            Node* lru = head->next;

            // Remove from linked list
            deleteNode(lru);

            // Remove from hashmap
            mp.erase(lru->key);

            // Free memory
            delete lru;
        }

        // Create new node
        Node* newNode = new Node(key, value);

        // New node becomes MRU
        addNode(newNode);

        // Store it in hashmap
        mp[key] = newNode;
    }
};