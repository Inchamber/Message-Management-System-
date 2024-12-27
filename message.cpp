#include "message.h"

// Message constructor, sets variables and allocates dynamic memory
Message::Message(int id, const char* rec) {
	ID = id;
	recipient = new char[strlen(rec) + 1];
	strcpy(recipient, rec);
}

// Copy constructor, prevents a shallow copy, orchestrates deep copy
Message::Message(const Message& other) {
	ID = other.ID;
	recipient = new char[strlen(other.recipient) + 1];
	strcpy(recipient, other.recipient);
}

// Copy assignment operator, prevents object from being assigned to itself.
// Also frees resources and creates a deep copy and allocates new memory for
// the resources.
Message& Message::operator=(const Message& other) {
	if (this == &other) {
		return *this;
	}
	delete[] recipient;
	ID = other.ID;
	recipient = new char[strlen(other.recipient) + 1];
	strcpy(recipient, other.recipient);
	return *this;
}

// Destructor deletes dynamically allocated memory for recipient.
Message::~Message() {
	delete[] recipient;
}

// Name: int Message::getID() const
// Desc: This function returns ID. 
// Input: None
// Output: ID
int Message::getID() const {
	return ID;
}

// Name: void Message::getRecipient() const
// Desc: This function returns recipient. 
// Input: None
// Output: recipient
const char* Message::getRecipient() const {
	return recipient;
}

