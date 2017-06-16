// This will allow a c++ application to start the node.js server

/*
 * ----------- Libraries ------------
 */
#include <iostream>
#include <windows.h>

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/*
 * ---------- MACROS ------------
 */

std::string getOsName()
{
    #ifdef __WIN32
    return "Windows 32-bit";
    #elif __WIN64
    return "Windows 64-bit";
    #elif __unix || __unix__
    return "Unix";
    #elif __APPLE__ || __MACH__
    return "Mac OSX";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #else
    return "Other";
    #endif
}    


/*
 * --------- Function Headers -----------
 */

int start_node_linux(char command[], char *path);


int main(void)
{
	int child_pid;
	int status;
	
	std::string windows_root_directory = "C:\\Users\\Daniel\\Documents\\School\\CSE4316\\node";
	std::string linux_root_directory = "/usr/bin/";
	std::string file_name("hello_world.js");

	printf("windows root directory: %s\n", windows_root_directory);

	std::string os_name = getOsName();
	
	// Operating system check
	// windows environment
	std::cout << "Operating System: " + os_name;
	if(os_name.compare("Windows 64-bit") || os_name.compare("Windows 32-bit"))
	{
		
		std::string cd_command = "cd " + windows_root_directory;
		chdir(windows_root_directory.c_str());

		std::string start_node = "node " + file_name;
		system(start_node.c_str());
	}
	else{
		// Machine is unix based
        child_pid = fork();

        if(child_pid == 0)
        {
                //start_node_linux("node", file_name.c_str());

        }
        else if(child_pid == -1)
        {
                printf("fork failed!\n");

        }
        else{
                // parent process
                waitpid(child_pid, &status, 0);

        }

			
	}

	return 0;

}

int start_node_linux(char command[], char *path)
{
	printf("Executing command: %s\n", command);
	printf("path: %s", path);

	if(execl(path, command, NULL,NULL) == 1);


	exit(0);



}
