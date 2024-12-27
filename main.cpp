/***
# Author: Gagandeep Bhatia
# Assignment: CS 162 Messages
# Date: June 9, 2024
# Description: This program creates a message class and messageList class.
# With this the program reads date in from a file and calls the appropraite
# functions depending on what the command is. The program can, list a 
# recipient and the ID, list all recipients and the ID, delete messages and
# add messages, all is done via linked lists.
# Input: char command [SIZE], char recip[SIZE], int id 
# Output: int recip/recipient, int ID
# Sources: instructions.txt 
***/
#include "messageList.h"
#include "message.h"
#include <fstream>

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		cerr << "Usage: " << argv[0] << " <datafile> " << endl;
		return 1;
	}
	// File Variable
	ifstream inFile(argv[1]);
	if (!inFile) {
		cerr << "Error opening file: " << argv[1] << endl;
		return 1;
	}
	// Variables
	const int NUM = 1;
	const int SIZE = 256;
	MessageList msgList;
	char command[SIZE];
	char recip[SIZE];
	int id;
	
	// Reading in command
	inFile >> command;
	inFile.ignore();

	// Looping through and calling appropriate functions based on command.
	while (!inFile.eof()) {
		if (strcmp(command, "All") == 0) {
			msgList.listAll();
		}
		else if (strcmp(command, "Delete") == 0) {
			inFile >> id;
			msgList.deleteMessage(id);
		}
		else if (strcmp(command, "List") == 0) {
			inFile.getline(recip, SIZE, '\n');
			msgList.listRecipient(recip);
		}
		else if (strncmp(command, "Recieve", NUM) == 0) {
			inFile >> id;
			inFile.ignore();
			inFile.getline(recip, SIZE, '\n');
			msgList.addMessage(id, recip);
		}
		
		inFile >> command;
		inFile.ignore();
	}

	return 0;
}
