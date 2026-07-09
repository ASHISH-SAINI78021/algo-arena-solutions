class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node before tail (Most Recently Used)
    void addNode(Node* node) {
        Node* prevNode = tail->prev;

        prevNode->next = node;
        node->prev = prevNode;

        node->next = tail;
        tail->prev = node;
    }

    // Remove a node from the list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move to MRU position
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        // Cache full
        if (mp.size() == capacity) {

            Node* lru = head->next;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);

        mp[key] = newNode;
    }
};