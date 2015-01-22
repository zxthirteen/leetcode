/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

/*
可以用C++里的list，也可以自己实现双向链表，实现链表也并不复杂，加上头和尾的结点，代码如下
*/

class LRUCache{
public:
    LRUCache(int capacity) {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        cachemap.clear();
        capa = capacity;
        size = 0;
    }
    
    int get(int key) {
        auto findres = cachemap.find(key);
        if (findres == cachemap.end()) {
            return -1;
        }
        touch(findres->second);
        cachemap[key] = head->next;
        return head->next->value;
    }
    
    void set(int key, int value) {
        auto findres = cachemap.find(key);
        if (findres != cachemap.end()) {
            touch(findres->second);
            head->next->value = value;
            cachemap[key] = head->next;
        } else {
            if (size == capa) {
                node* old = tail->prev;
                tail->prev = old->prev;
                old->prev->next = tail;
                cachemap.erase(old->key);
                delete(old);
                size--;
            }
            node *newnode = new node(key, value);
            newnode->next = head->next;
            newnode->prev = head;
            head->next->prev = newnode;
            head->next = newnode;
            size++;
            cachemap[key] = newnode;
        }
    }
    
    struct node {
        int key;
        int value;
        node *prev;
        node *next;
        node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
    };
    
    int size;
    int capa;
    node *head, *tail;
    unordered_map<int, node*> cachemap;
    
    void touch(node *hit) {
        hit->prev->next = hit->next;
        hit->next->prev = hit->prev;
        hit->prev = head;
        hit->next = head->next;
        head->next->prev = hit;
        head->next = hit;
    }
};

/*
如果要用C++的list的话，需要用如下结构
*/

list < pair <int, int> > itemList;
unordered_map <int, list<pair <int, int> > :: iterator> itemMap;

/*
一定不能是list<int>，key和value都要存在list里，否则在set的时候，如果在list中满了，去掉最后一个结点时，如果只存在value在list里面，就无法知道key,也就没办法从map中找到它了
*/