#include <iostream>
#include <list>
#include <unordered_map>

struct Node
{
    int key;
    int value;

    Node(int Key, int Value) : key(Key), value(Value) {}
};

class LRUCache
{
    size_t capacity;

    std::list<Node> list; // hold K-V pairs
    std::unordered_map<int, std::list<Node>::iterator> cache;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int
    get(int key);

    void
    put(int key, int value);
};

void LRUCache::put(int key, int value)
{
    // std::cout << "\nput: " << key << ":" << value << "\t";

    if (cache.count(key))
    {
        const auto &key_node_itr = cache[key];
        list.splice(begin(list), list, key_node_itr);
        key_node_itr->value = value;
        return;
    }

    if (list.size() == capacity)
    {
        const auto &LRU_node = list.back();
        cache.erase(LRU_node.key);
        list.pop_back();
    }

    list.emplace_front(key, value);
    cache[key] = begin(list);
}

int LRUCache::get(int key)
{
    // std::cout << "\nget: " << key << "\t";

    if (!cache.count(key))
        return -1;

    const auto &key_node_itr = cache[key];
    list.splice(begin(list), list, key_node_itr);
    return key_node_itr->value;
}

int main()
{
    LRUCache *lRUCache = new LRUCache(2);

    lRUCache->put(2, 1);

    lRUCache->put(1, 1);

    lRUCache->put(2, 3);

    lRUCache->put(4, 1);

    std::cout << lRUCache->get(1);

    std::cout << lRUCache->get(2);

    return 0;
}