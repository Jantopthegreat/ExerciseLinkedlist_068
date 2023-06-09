#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};
class CircularLinkedList {
private:
	Node* LAST;	
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** rianto, Node** fauzan);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int nim;
	string nm;
	cout << "\nEnter the roll number of student: ";
	cin >> nim;
	cout << "\nEnter the name of student: ";
	cin >> nm;

	Node* newNode = new Node(); 
	newNode->rollNumber = nim; 
	newNode->name; nm; 

	if (LAST == NULL || nim <= LAST->rollNumber) { // check if data null
		if (LAST != NULL && nim == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; 
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->prev = NULL;
		LAST = newNode; 
		return;
	}
	Node* fauzan = LAST->next; 
	Node* rianto = NULL;
	while (fauzan->next != NULL && fauzan->next->rollNumber < nim)	
	{
		rianto = fauzan;
		fauzan = fauzan->next;
	}

	if (fauzan->next != NULL && nim == fauzan->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = fauzan->next; //step 4
	newNode->prev = fauzan; //step5
	if (fauzan->next != NULL)
		fauzan->next->prev = newNode; //step6
	fauzan->next = newNode; //step 7
}


bool CircularLinkedList::search(int rollno, Node** rianto, Node** fauzan) {
	*rianto = LAST->next;
	*fauzan = LAST->next;
	while (*fauzan != LAST) {
		if (rollno == (*fauzan)->rollNumber) {
			return true;
		}
		*rianto = *fauzan;
		*fauzan = (*fauzan)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	Node* rianto, * fauzan;
	rianto = fauzan = NULL;
	if (fauzan->next != NULL);
	fauzan->next->prev = rianto; 
	if (rianto != NULL)
		rianto->next = fauzan->next; 
	else
		LAST->next = fauzan->next;

	delete fauzan; 
	return true;

}
void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* fauzanNode = LAST->next;
		while (fauzanNode != LAST) {
			cout << fauzanNode->rollNumber << " " << fauzanNode->name << endl;
			fauzanNode = fauzanNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}\
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;