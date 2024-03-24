# PIPEX

                
SUMMARY:

This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

STATUS:

Result : 
PIPEX - 100%✅
#THEORY :

**Pipes** -> Conceptually, a pipe is a connection between two processes, such that the standard output from one process becomes the standard input of the other process. In UNIX Operating System, Pipes are useful for communication between related processes(inter-process communication).
- Pipe is one-way communication only i.e we can use a pipe such that One process write to the pipe, and the other process reads from the pipe. It opens a pipe, which is an area of main memory that is treated as a “virtual file”.
- The pipe can be used by the creating process, as well as all its child processes, for reading and writing. One process can write to this “virtual file” or pipe and another related process can read from it.
- If a process tries to read before something is written to the pipe, the process is suspended until something is written.
- The pipe system call finds the first two available positions in the process’s open file table and allocates them for the read and write ends of the pipe.

                                    https://media.geeksforgeeks.org/wp-content/uploads/Process.jpg



**fork()** -> It creates a child process that is a duplicate of the calling process (the parent process).
Returns 0 in the child process, and the process ID of the child process in the parent process. This allows the parent process to differentiate between itself and the child process, and to communicate with the child process if necessary.

**execve** -> is used to execute a new program in place of the current process image. This function takes three arguments: the path to the executable file to be executed, an array of strings that specify the command-line arguments passed to the program, and an array of strings that specify the environment variables for the new process.
execve(args[0], args, env)
The execve function replaces the current process image with a new one specified by the path, and does not return if successful. If the function fails, it returns -1 and sets the value of errno to indicate the error.

**waitpid** -> is used by a parent process to wait for the termination of one of its child processes. This function blocks the execution of the parent process until the specified child process terminates or a signal is received.
The waitpid function takes three arguments: the process ID of the child process to wait for, a pointer to a status variable that will be filled with the exit status of the child process, and flags that specify the behavior of the function.
waitpid(pid, &status, 0)

**PID** -> process identifier, is a unique numerical value assigned by an operating system to each process that is created on a computer
