#ifndef message_h
#define message_h
#include <cstring>
// Name: Gagandeep Bhatia
// Assignment: Messages, this assignment keeps track of messages for users,
// specifically messages for each person and all messages in total with an id
// and recipient name.
// Purpose of this Class: The class supports a message by setting up a message
//  and maintaining it through a constructor, overloaded assignment operator,
//  getter methods for the ID and recipience.

class Message {
	private:
		int ID;
		char* recipient;
		

	public:
		Message(int id, const char* rec);
		Message(const Message& other);
		Message & operator=(const Message& other);
		~Message();
		int getID() const;
		const char* getRecipient() const;		
};
#endif
