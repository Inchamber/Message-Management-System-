#include "messageList.h"
// MessageList constructor, sets head and tail to nullptr
MessageList::MessageList() {
	head = nullptr;
	tail = nullptr;
}

// MessageList destructor, clears/deletes the list
MessageList::~MessageList() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current->message;
		delete current;
		current = next;
	}
}
// Name: void MessageList::addMessage(int id, const char* recipient)
// Desc: This function dynamically allocates memory for newNode and 
// message of newNode. It adds a new message to the linked list.
// Input: None
// Output: None
// Return: None
void MessageList::addMessage(int id, const char* recipient) {
	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->message = new Message(id, recipient);
		 
	if(head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}


// Name: void MessageList::listAll() const
// Desc: This function iterates through the list and outputs the message and 
// ID. 
// Input: None
// Output: getID(), getRecipient()
// Return: None
void MessageList::listAll() const {
	Node* current = head;
	cout << "** All Messages **" << endl;
	while (current != nullptr) {
		cout << "Message " << current->message->getID() << " " << 
		current->message->getRecipient() << endl;
		current = current->next;
	}
	cout << "******************" << endl;
}

// Name: void MessageList::listRecipient(const char* recipient) const
// Desc: This function outputs messages for a certain recipient with their
// corresponding ID(s).
// and the corresponding person. 
// Input: None
// Output: getID(), recipient
void MessageList::listRecipient(const char* recipient) const {
	Node* current = head;
	cout << "Messages for " << recipient << ":" << endl;
	
    while (current != nullptr) {
		if (strcmp(current->message->getRecipient(), recipient) == 0) {
			cout << "  " << current->message->getID() << endl;
		}
		current = current->next;
	}
}

// Name: void MessageList::deleteMessage(int id)
// Desc: This function iterates through the list to find an id of a
// recipient and deletes the id and message.
// Input: None
// Output: None
void MessageList::deleteMessage(int id) {
	Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->message->getID() != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
		return;
	}

    if (current == head) {
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
    } 
	else {
        prev->next = current->next;
        if (current == tail) {
            tail = prev;
        }
    }

    delete current->message;
    delete current;
}
