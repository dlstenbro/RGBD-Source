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

#define PORT_NUMBER 8080

using namespace std;
static int connFd;

Server::Server(void)
{
	// constructor functions
	setSocketAttributes();
	bindSocket();
}

int Server::setSocketAttributes()
{
	cout << "Using port number " + PORT_NUMBER << endl;
	listenFd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(listenFd < 0)
    {
        cerr << "Cannot open socket" << endl;
        return 0;
    }
    
    bzero((char*) &svrAdd, sizeof(svrAdd));
    
    svrAdd.sin_family = AF_INET;
    svrAdd.sin_addr.s_addr = INADDR_ANY;
    svrAdd.sin_port = htons(PORT_NUMBER);	
}

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

int Server::bindSocket()
{
    if(bind(listenFd, (struct sockaddr *)&svrAdd, sizeof(svrAdd)) < 0)
    {
        cerr << "Cannot bind" << endl;
        return 0;
    }
    
    return 1;
}

void Server::startServer(void)
{
	cout << "Starting server...." << endl;
	clientListener();
	
	
	// LAUNCH POINT CLOUD CODE HERE
	// PointCloudApp point_cloud;
}

void Server::serverTask(void)
{

	cout << "Thread No: " << pthread_self() << endl;
	
    char test[300];
    bzero(test, 301);
    bool loop = false;
    
    while(!loop)
    {    
        bzero(test, 301);
        
        
        read(connFd, test, 300);
        
        string tester (test);
        cout << tester << endl;

        if(tester == "exit")
            break;
    }
    cout << "\nClosing thread and connection!" << endl;
    close(connFd);
    
}