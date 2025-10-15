#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next_node;

        Node(int val, Node* next= nullptr) :data(val), next_node(next){}
};

ostream& operator<<(ostream& os, const Node& n){
    os << "<Node data: " << n.data << ">";

    return os;
}

class LinkedList{
    public:
        Node* head {nullptr};

        // Destructor to free all nodes.
        // Prevents memory leaks.
        ~LinkedList() {
            Node* current = head;

            while(current){
                Node* temp = current;
                current = current->next_node;
                delete temp;
            }
        }

        string is_empty(){
            if (head == nullptr) {
                return "List is empty.";
            } else {
                return "List is not empty";
            }
        }

        void size() {
             Node* current = head;
             int counter {0};

            while(current) {
                counter++;
                current = current->next_node;
            }

            cout << "The size of the list is: " << counter << " Nodes." << "\n";

            return;
        };

        void add(int value) {
            Node* added = new Node(value); // Allocate in the heap
            added->next_node = head;
            head = added;
        }

        Node* search(int target){
            Node* current = head;

            while(current) {
                if (current->data == target){
                    return current;
                }

                current = current->next_node;
            }

            return nullptr;
        }
};

ostream& operator<<(ostream& os, const LinkedList& list){
    Node* current = list.head;

    while (current){
        if (current == list.head){
            os << "[Head: " << current->data << "]";
        } else if (!(current->next_node)) {
            os << " -> [Tail: " << current->data << "]";
        } else {
            os << " -> " << current->data;
        }

        current = current->next_node;
    }

    return os;
}

int main(){
    Node a(10);
    Node b(20);
    a.next_node = &b;
    cout << a << "\n";
    cout << *(a.next_node) << "\n";

    LinkedList l1;
    cout << l1.is_empty() << "\n";

    l1.head = &a;
    l1.add(5);
    cout << l1.is_empty() << "\n";
    l1.size();

    int target = 0;
    Node* founded = l1.search(target);

    if (founded) {
        cout << target << " was founded in the node: " << *founded << endl;
    } else {
        cout << "Target value not founded in the list." << endl;
    }

    cout << l1 << endl;

    return 0;
}