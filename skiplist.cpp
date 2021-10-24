#include <iostream>
#include <ostream>
#include <memory>
#include <utility>
#include <limits.h>

bool flip() {
    return false;
}

class Node : public std::enable_shared_from_this<Node> {
    friend class Skiplist;
private:
    int key;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> down;

public:
    Node(int key);
    ~Node();
    bool search(int key);
    std::pair<std::shared_ptr<Node>, bool> insert(int key);
    std::pair<bool, bool> del(int key);
};

Node::Node(int key) {
    std::cout<<"Node(" << key << ") construct called" << std::endl;
    this->key = key;
    this->next = nullptr;
    this->down = nullptr;
}

Node::~Node() {
    std::cout<<"Node(" << this->key << ") deconstruct called" << std::endl;
}


std::pair<bool, bool> Node::del(int key) {
    auto p = this->shared_from_this();
    while (p->next != nullptr && p->key < key) {
        p = p->next;
    }

    bool deleted = false;
    if (p->down != nullptr) {
        auto ret = p->down->del(key);
        deleted = ret.first;
        if (!ret.second) {
            return std::make_pair(ret.first, false);
        }

        // ret.second == true
        if (p->next != nullptr && p->next->key == key) {
            auto next = p->next;
            p->next = next->next;
            return std::make_pair(true, true);
        }

        return std::make_pair(true, false);
    } else { // p->down == nullptr
        if (p->next != nullptr && p->next->key == key) {
            auto next = p->next;
            p->next = next->next;
            return std::make_pair(true, true);
        }

        return std::make_pair(false, false);
    }
}

// assume this->key < key
bool Node::search(int key) {
    // std::shared_ptr<Node> p = this->shared_from_this();
    auto p = this->shared_from_this();
    while (p->next != nullptr && p->key < key) {
        p = p->next;
    }

    if (p->down != nullptr) {
        return p->down->search(key);
    }

    if (p->next == nullptr) {
        return false;
    }

    return p->next->key == key;
}

std::pair<std::shared_ptr<Node>, bool> Node::insert(int key) {
    auto p = shared_from_this();

    while (p->next != nullptr && p->key < key) {
        p = p->next;
    }

    if (p->down != nullptr) {
        auto o = p->down->insert(key);
        if (!o.second || !flip()) {
            return std::pair<std::shared_ptr<Node>, bool>(o.first, false);
        }
        
        auto up = std::shared_ptr<Node>(new Node(key));
        up->down = o.first;
        up->next = p;
        p->next = up;
        return std::pair<std::shared_ptr<Node>, bool>(up, true);
    } else {
        std::cout<<"insert " << key << " after: " << p->key << std::endl;
        auto o = std::shared_ptr<Node>(new Node(key));
        o->down = nullptr;
        o->next = p->next;
        p->next = o;
        
        return std::pair<std::shared_ptr<Node>, bool>(o, true);
    }
}

class Skiplist {
public:
    Skiplist();
    ~Skiplist();
    void Insert(int key);
    bool Search(int key);
    bool Del(int key);
    void Display();

private:
    // std::shared_ptr<Node> head;
    std::shared_ptr<Node> head;
};

Skiplist::Skiplist() {
    std::cout<<"Skiplist() construct called"<<std::endl;
    this->head = std::shared_ptr<Node>(new Node(INT_MIN));
}

Skiplist::~Skiplist() {
    std::cout<<"Skiplist() deconstruct called"<<std::endl;
}

void Skiplist::Insert(int key) {
    auto o = this->head->insert(key);
    // TODO create new layer if necessary
    if (!o.second || !flip()) {
        return;
    }

    auto h = std::shared_ptr<Node>(new Node(INT_MIN));
    auto e = std::shared_ptr<Node>(new Node(key));
    h->next = e;
    e->down = o.first;
    h->down = this->head;
}

bool Skiplist::Search(int key) {
    return this->head->search(key);
}

bool Skiplist::Del(int key) {
    auto ret = this->head->del(key);
    return ret.first;
}

void Skiplist::Display() {
    auto p = this->head;
    while (p->down != nullptr) {
        p = p->down;
    }

    std::cout << "the list: ";
    p = p->next;
    while (p != nullptr) {
        std::cout << p->key << ", ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
    std::unique_ptr<Skiplist> sl = std::unique_ptr<Skiplist>(new Skiplist());
    std::cout<< sl->Search(0) << std::endl;
    sl->Insert(1);
    sl->Insert(2);
    sl->Insert(3);
    sl->Insert(4);
    sl->Insert(5);
    sl->Display();

    return 0;
}

