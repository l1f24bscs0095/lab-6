#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string name;
    Node* next;

    Node(string patientName) {
        name = patientName;
        next = nullptr;
    }
};
class PatientQueue {
private:
    Node* head;

public:
    
    PatientQueue() {
        head = nullptr;
    }

    
    void addPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Patient added: " << name << endl;
    }

    
    void removePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

       
        if (head->name == name) {
            head = head->next;
            delete temp;
            cout << "Patient removed: " << name << endl;
            return;
        }

   
        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Patient not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Patient removed: " << name << endl;
    }

    
    void displayQueue() {
        if (head == nullptr) {
            cout << "No patients in queue.\n";
            return;
        }

        Node* temp = head;
        cout << "Patient Queue:\n";

        int position = 1;
        while (temp != nullptr) {
            cout << position++ << ". " << temp->name << endl;
            temp = temp->next;
        }
    }

    
    int countPatients() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main() {
    PatientQueue queue;
    int choice;
    string name;

    do {
        cout << "\n--- Hospital Patient Queue ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient (Cancel)\n";
        cout << "3. Display Queue\n";
        cout << "4. Count Patients\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            queue.addPatient(name);
            break;

        case 2:
            cout << "Enter patient name to remove: ";
            cin >> name;
            queue.removePatient(name);
            break;

        case 3:
            queue.displayQueue();
            break;

        case 4:
            cout << "Total patients: " << queue.countPatients() << endl;
            break;

        case 5:
            cout << "Exiting system.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}