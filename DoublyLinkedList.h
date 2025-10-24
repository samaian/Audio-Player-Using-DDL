#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <string>
#include<vector>
#include<exception>
using namespace std;
template <typename t>
struct Node {
    t data;
    Node* next;
    Node* prev;
    Node(const t& data) : data(data), next(nullptr), prev(nullptr) {}
};
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int Size;

public:
    bool isEmpty() const { return head == nullptr; }
    DoublyLinkedList() : head(nullptr), Size(0),tail(nullptr) {}
    ~DoublyLinkedList() { clear(); }
   

    void display() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
    }

    void display2() const {
        Node<T>* current = head;
        while (current) {
            cout << current->data <<endl;
            current = current->next;
        }
        cout << endl; 
    }

    T* Search(const string& name) {
        Node<T>* current = head;
        while (current) {
            if (current->data.getName() == name) {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr; 
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        Size = 0; 
    }

    T* getNode(int pos) {
        if (pos < 0 || pos > Size) {
            throw out_of_range("Position out of range"); 
            
        }
        else {
            Node<T>* current = head;
            for (int i = 1; i < pos && current != nullptr; i++) {
                current = current->next;
            }
            return &(current->data);

        }
    }


    int getSize() { return Size; }

    Node<T>* findNode(T& value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    Node<T>* getHead() const { return head; }

    T Searchtoupdate(const string& name) {
        Node<T>* current = head;
        while (current) {
            if (current->data.getName() == name) {
                return current->data;
            }
            current = current->next;
        }
        cout << "Error: Surah not found!" << endl;
        return T(); 
    }

    int findIndx(T& value) {
        Node<T>* current = head;
        int index = 0;
        while (current) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
    vector<T> displayInFile() {
        Node<T>* current = head;
        vector<T> v;
        while (current) {
            v.push_back(current->data);
            current = current->next;
        }
        return v;
    }

    void Append(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = nullptr;
        }
        Size++;
    }

    bool Remove(T& data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;

                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;

                delete current;
                Size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void InsertAtBegin(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        Size++;
    }

    void InsertAtPosition(const T& value, int pos) {
        if (pos < 0 || pos > Size) {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0) {
            InsertAtBegin(value);
        }
        else if (pos == Size) {
            Append(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = head;

            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;

            Size++;
        }
    }

    void DeleteAtPosition(int pos) {
        if (pos < 0 || pos >= Size) {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0) {
            DeleteAtBegin();
        }
        else if (pos == Size - 1) {
            DeleteAtEnd();
        }
        else {
            Node<T>* temp = head;

            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
            Size--;
        }
    }

    void DeleteAtBegin() {
        if (!head) return;

        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        Size--;
    }

    void DeleteAtEnd() {
        if (!tail) return;

        Node<T>* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        Size--;
    }

};

#endif // DOUBLYLINKEDLIST_H
