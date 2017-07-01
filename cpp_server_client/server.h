/*

	Header file for Server class
	Allows the creation of server and client objects

*/
#ifndef SERVER_H
#define SERVER_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>

class Server {

	// variables
	public:
	    int pId, portNo, listenFd;
		socklen_t len; //store size of the address
		//bool loop = false;
		struct sockaddr_in svrAdd, clntAdd;
		
		pthread_t threadA[3];	// establishes multithreading but removed methods related to this
	
	public:
	
		// constructor
		Server();
		
		// 
		void startServer(void);	
		int clientListener(void);

	private:
		int bindSocket(void);
		int setSocketAttributes(void);
		void serverTask(void);

};
#endif