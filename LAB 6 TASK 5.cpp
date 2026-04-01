#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string name;
    int priority;
    Node* next;

    Node(string n, int p) {
        name = n;
        priority = p;
        next = nullptr;
    }
};


class ReservationList {
private:
    Node* head;

public:
    ReservationList() {
        head = nullptr;
    }

  
    void addStudent(string name, int priority) {
        Node* newNode = new Node(name, priority);

        if (head == nullptr || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Student added: " << name << " (Priority: " << priority << ")\n";
    }


    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (head->name == name) {
            head = head->next;
            delete temp;
            cout << "Removed: " << name << endl;
            return;
        }

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Removed: " << name << endl;
    }

    
    void updatePriority(string name, int newPriority) {
        removeStudent(name);
        addStudent(name, newPriority);
        cout << "Priority updated for " << name << endl;
    }

    
    void serveNext() {
        if (head == nullptr) {
            cout << "No students waiting.\n";
            return;
        }

        Node* temp = head;
        cout << "Book issued to: " << temp->name << endl;
        head = head->next;
        delete temp;
    }

 
    void display() {
        if (head == nullptr) {
            cout << "No reservations.\n";
            return;
        }

        Node* temp = head;
        cout << "Reservation List:\n";

        while (temp != nullptr) {
            cout << temp->name << " (P:" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int count() {
        int c = 0;
        Node* temp = head;

        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }

        return c;
    }
};


class Book {
public:
    string title;
    ReservationList list;

    Book(string t) {
        title = t;
    }
};

int main() {
   
    Book book1("Data Structures");
    Book book2("Operating Systems");

    cout << "\n--- Adding Students ---\n";
    book1.list.addStudent("Ali", 2);
    book1.list.addStudent("Sara", 5);
    book1.list.addStudent("Ahmed", 3);

    book2.list.addStudent("Zara", 1);
    book2.list.addStudent("Usman", 4);

    cout << "\n--- Display Lists ---\n";
    cout << "Book: " << book1.title << endl;
    book1.list.display();

    cout << "Book: " << book2.title << endl;
    book2.list.display();

    cout << "\n--- Update Priority ---\n";
    book1.list.updatePriority("Ali", 6);

    cout << "Book: " << book1.title << endl;
    book1.list.display();

    cout << "\n--- Remove Student ---\n";
    book2.list.removeStudent("Zara");
    book2.list.display();

    cout << "\n--- Serve Next Student ---\n";
    book1.list.serveNext();
    book1.list.display();

    cout << "\n--- Count---\n";
    cout << "Book1 Count: " << book1.list.count() << endl;
    cout << "Book2 Count: " << book2.list.count() << endl;

    return 0;
}