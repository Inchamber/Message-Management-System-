#ifndef messageList_h
#define messageList_h
#include "message.h"
#include <iostream>
using namespace std;
// Name: Gagandeep Bhatia
// Assignment: Messages, this assignment keeps track of messages for users,
// specifically messages for each person and all messages in total with an id
// and recipient name.
// Purpose of this Class: The purpose of this class is to be able to add,
// list, delete and list all of the people and their message ID's via linked
// lists. 

struct Node {
	Message* message;
	Node* next;
};

class MessageList {
	private:
		Node* head;
		Node* tail;
	
	public:
		MessageList();
		~MessageList();

		void addMessage(int id, const char* recipient);
		void listAll() const;
		void listRecipient(const char* recipienct) const;
		void deleteMessage(int id);

		MessageList& operator=(const MessageList&) = delete;
		MessageList(const MessageList&) = delete;
};

#endif
