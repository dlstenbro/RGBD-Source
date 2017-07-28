#include "server.h"

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fstream>
#include <strings.h>
#include <stdlib.h>
#include <string>
#include <pthread.h>

#define PORT_NUMBER 8080	// default port. Can easily change port if needed

using namespace std;
static int connFd;

/*
	Member Function name: Server
	Function: Server object Constructor
*/
Server::Server(void)
{
	// constructor functions
	setSocketAttributes();
	bindSocket();
}

/*
	Member Function name: setSocketAttributes
	Function: takes in the default port number and sets up listener attributes for a given port
*/
int Server::setSocketAttributes()
{
	cout << "Using port number " + PORT_NUMBER << endl;
	listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }
    
    // clear memory using bzero http://fdiv.net/2009/01/14/memset-vs-bzero-ultimate-showdown
    bzero((char*) &svrAdd, sizeof(svrAdd));
    
    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(PORT_NUMBER);	
}

/*
	Member Function name: clientListener
	Function: Listens for a given connection from a client machine. If the listener fails to start then return 0
*/
int Server::clientListener()
{
    
    listen(listenFd, 5);
    
    len = sizeof(clntAdd);
    
	socklen_t len = sizeof(clntAdd);
	//cout << "Listening" << endl;
	printf("Listening on port number %d\n", PORT_NUMBER);

	//this is where client connects. svr will hang in this mode until client conn
	connFd = accept(listenFd, (struct sockaddr *)&clntAdd, &len);

	if (connFd < 0)
	{
		cerr << "Cannot accept connection" << endl;
		return 0;
	}
	else
	{
		cout << "Connection successful" << endl;
		serverTask();
	}
}

/*
	Member Function name: bindSocket
	Function: bind memory address at the socket address 
*/
int Server::bindSocket()
{
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }
    
    return 1;
}

/*	
	Member Function name: startServer
	Function: start server then listen for incoming connections.
	point cloud application can start here.
		
*/
void Server::startServer(void)
{
	cout << "Starting server...." << endl;
	clientListener();
}

/*	
	Member Function name: serverTask
	Function: Server task after the connection is established
	
	1. once the connection is established and the point cloud application is started stream point cloud data
	2. create a buffer of the current pcd file, and stream the data in bytes through the pipe to client machine
	3. on client machine implement checksum to ensure the data is not corrupt?
		- if data is corrupt then send a message back to server  to resend packet.
		
*/
void Server::serverTask(void)
{

	cout << "Thread No: " << pthread_self() << endl;
	
    char test[300];
    bzero(test, 301);
    bool loop = false;
    
    while(!loop)
    {    
        bzero(test, 301);
        
        // write data in bytes to client
        write(connFd, test, 300);
        
        string tester (test);
        cout << tester << endl;

        if(tester == "exit")
            break;
    }
    cout << "\nClosing thread and connection!" << endl;
    close(connFd);
    
}
