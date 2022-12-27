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

    List(T* arr, size_t len) {
        head = new Node<T>;
        head->value = arr[0];
        head->next = nullptr;
        size = 1;
        Node<T>* curr = head;
        for (size_t i = 1; i < len; i++) {
            curr->next = new Node<T>;
            curr = curr->next;
            curr->value = arr[i];
            curr->next = nullptr;
            size++;
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
        auto* temp = new Node<T>;
        temp->value = val;
        temp->next = head;
        temp = head;
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
        while (curr->next) {
            curr = curr->next;
        }
        T val = curr->value;
        delete curr;
        return val;
    }

    List& operator = (List const& l1) {
        if (this == &l1) {
            return *this;
        }

        delete this;
        if (l1.head == nullptr) {
            head = nullptr;
            size = 0;
            return *this;
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

    void reverse() {
        Node<T>* curr, next, prev = nullptr;
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
};
