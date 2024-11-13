#ifndef QUANLYDAYSO_SINGLELINKEDLIST_HPP
#define QUANLYDAYSO_SINGLELINKEDLIST_HPP

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    // Constructor
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class SingleLinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    SingleLinkedList() : head(nullptr) {}

    // Destructor
    ~SingleLinkedList() {
        clear();
    }

    // Lay phan tu dau (tra ve con tro toi phan tu dau)
    Node<T>* getFront() const {
        return head;
    }

    void sort() {
        Node<T>* p = head;
        while (p != nullptr) {
            Node<T>* q = p->next;
            while (q != nullptr) {
                if (p->data > q->data) {
                    T temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }

    // Thêm phần tử vào đầu danh sách
    void addFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Thêm phần tử vào cuối danh sách
    void addBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Thêm phần tử vào vị trí k
    void addAt(T value, int k) {
        if (k == 0) {
            addFront(value);
            return;
        }

        Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 0; i < k - 1; i++) {
            if (temp == nullptr) return;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Đếm số lần xuất hiện của phần tử có giá trị value
    int count(T value) const {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) count++;
            temp = temp->next;
        }
        return count;
    }

    // Xóa phần tử đầu tiên có giá trị value
    void remove(T value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // Không tìm thấy value

        Node<T>* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Hiển thị danh sách
    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    // Xóa toàn bộ danh sách
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif //QUANLYDAYSO_SINGLELINKEDLIST_HPP
