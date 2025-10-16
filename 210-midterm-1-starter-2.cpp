#include <iostream>
using namespace std;

//constants defining value
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private: // node  representing each element in list
    struct Node {
        int data;  // stores the value
        Node* prev; // pointer to previous node in list
        Node* next; // pointer to next node in list
        // Node constructor initializes data  and pointers
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;  // set nodes value
            prev = p;  // set previous pointer
            next = n; // set next pointer null
        }
    };

    Node* head; // the head points to first node in list
    Node* tail; // the tail points to the last node in list

public:
     //Constructor - initializes empty list head and tail null
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
     // Insert a new node  after the specified position 0
    void insert_after(int value, int position) {
        // validates position
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
          //create new node with value
        Node* newNode = new Node(value);
        // if list is empty then new node becomes head and tail
        if (!head) {
            head = tail = newNode;  // new node head tail
            return;
        }
         // Traverse her to see if node at location
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next; // here move temp to next forward
          
            // error handling if position exceeds size report (housekeeping)
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }
         // here this will link node into list
        newNode->next = temp->next; // new node  poits to next to temps next
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode; // Link new node's previous to current temp node
        else
            tail = newNode;  // if temp is tail 
        temp->next = newNode; // new node is now tail
    }
    // delete node containing specified value
    void delete_val(int value) {
        if (!head) return; // if list is empty nothing to delete error (housekeeping)

        // search for node with matching value
        Node* temp = head;
        
        while (temp && temp->data != value) 
            temp = temp->next; // move temp pointer forward

        if (!temp) return; // if value not found exit (return)

        if (temp->prev) // update previous node next pointer if temp is not found
            temp->prev->next = temp->next;
        else
            head = temp->next; // if temp is head, update head pointer

        if (temp->next) //  update next nodes previous pointer
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // if temp is tail update tail pointer

        delete temp; // free memory allocated for delete node
    }
     //Delete node at specified position
    void delete_pos(int pos) {
    // check if list is empty
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
         // pop function to detele the first position
        if (pos == 1) {
            pop_front();
            return;
        }
    
        // continue to travers to find node at specified position
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
       // check if position exists     
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next; // move temp pointer forward
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
          // delete last position
        if (!temp->next) {
            pop_back();
            return;
        }
    
        //Get node befor  the one to delete
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        // bypass  moving backward
        temp->next->prev = tempPrev;

        delete temp; //free memory
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}