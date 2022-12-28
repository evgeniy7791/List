#include <iostream>


template<typename T>
struct Node {
    T value;
    Node* next;
};

template<typename T>
class List {
private:
    Node<T>* head;
    size_t size;

public:
    List() {
        size = 0;
        head = nullptr;
    }

    List(T val) {
        head = new Node<T>;
        size = 1;
        head->value = val;
        head->next = nullptr;
    }

    List(std::initializer_list<T> init_list) {
        head = new Node<T>;
		Node<T>* curr = head;
        auto it = init_list.begin();
        curr->value = *it;
        curr->next = nullptr;
        it++;
        while (it != init_list.end()) {
            curr->next = new Node<T>;
            curr = curr->next;
            curr->value = *it;
            curr->next = nullptr;
            it++;
        }
    }

    List(const List& l1) {
        if (l1.head == nullptr) {
            head = nullptr;
            size = 0;
            return;
        }
        head = new Node<T>;
        head->value = l1.head->value;
        head->next = nullptr;
        size = 1;
        auto* curr = head;
        auto* l1_curr = l1.head->next;
        while (l1_curr) {
            curr->next = new Node<T>;
            curr = curr->next;
            curr->value = l1_curr->value;
            curr->next = nullptr;
            l1_curr = l1_curr->next;
            size++;
        }
    }

    void clear() {
        while (head) {
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
        size = 0;
    }

    ~List() {
        clear();
    }

    size_t getSize() {
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void pushFront(T val) {
        Node<T>* temp = new Node<T>;
        temp->value = val;
        temp->next = head;
        head = temp;
        size++;
    }

    void pushBack(T val) {
        size++;
        if (head == nullptr) {
            head = new Node<T>;
            head->value = val;
            head->next = nullptr;
            return;
        }
        auto* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node<T>;
        curr = curr->next;
        curr->value = val;
        curr->next = nullptr;
    }

    T popFront() {
        if (head == nullptr) {
            throw "List is empty";
        }
        size--;
        auto* temp = head;
        T val = head->value;
        head = head->next;
        delete temp;
        return val;
    }

    T popBack() {
        if (head == nullptr) {
            throw "List is empty";
        }
        size--;
        auto* curr = head;
        if (!head->next) {
            T val = head->value;
            delete head;
            head = nullptr;
            return val;
        }
        while (curr->next->next) {
            curr = curr->next;
        }
        T val = curr->next->value;
        delete curr->next;
        curr->next = nullptr;
        return val;
    }

    List& operator = (List const& l1) {
        if (this == &l1) {
            return *this;
        }

        clear();
        if (l1.head == nullptr) {
            head = nullptr;
            size = 0;
            return *this;
        }

        head = new Node<T>;
        head->value = l1.head->value;
        head->next = nullptr;
        auto* curr = head;
            size = 1;
        auto* l1_curr = l1.head->next;
        while (l1_curr) {
            curr->next = new Node<T>;
            curr = curr->next;
            curr->value = l1_curr->value;
            curr->next = nullptr;
            l1_curr = l1_curr->next;
            size++;
        }
        return *this;
    }

    void reverse() {
        Node<T>* curr, *next, *prev = nullptr;
        curr = head;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    
    T& operator [] (size_t index) {
        if (index >= size) {
            throw "List index out of range";
        }
        Node<T>* curr = head;
        for (size_t i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    void insertNext(Node<T>* prev, T val) {
        Node<T>* next = prev->next;
        prev->next = new Node<T>;
        prev->next->value = val;
        prev->next->next = next;
    }

    void deleteNext(Node<T>* prev) {
        if (!prev->next) {
            throw "Nothing to delete";
        }
        Node<T>* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }

    Node<T>* find(T target) {
        Node<T>* curr = head;
        while (curr) {
            if (curr->value == target) return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};
