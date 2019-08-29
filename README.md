# :fire: :shell: Simple Shell - A Hell of a Shell (In a Shell...) :shell: :fire:
- Jessica Bathel and Yashar Mateen

### simple_shell:
Basically a lite version of the Unix shell command line interpreter
that is used to control the execution of a system. Our shell receives input from the user
by displaying a prompt and then executes that command. It works in interactive mode by
invoking `./hsh` and also in non-interactive mode by invoking for example: `echo "/bin/ls" | ./hsh`

## List of Allowed Functions and System Calls

* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror` (man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__xstat) (man 2 stat)
* `lstat` (__lxstat) (man 2 lstat)
* `fstat` (__fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Contents
* AUTHORS
* LICENSE
* README.md (this file)
* man_1_simple_shell - man page for our shell
* shell.c - the main file that contains the code for an executable program that works like an interactive shell
* shell.h - header file including all of our libraries, prototypes, and struct definitions to be used in our shell.c file
* strops.c - contains functions that handle string operations and manipulations
* signal_control.c - handles the function that returns PIDs and signal sfor parent processes and commands to execute
* pathfuncs.c - these functions handle searching path and searching the environment
* list.c - functions for building the linked list
* helpers.c - miscellaneous functions that are included in the shell.c file
* err_handlers.c - functions that handle all the errors
* conversions.c - these functions handle all the data converter
## Compilation:
The program is compiled with the following command:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
## Usage:
The way to use it in interactive mode is to type the command:
`./hsh`.

This will display another shell prompt beginning with `($)`

You will now be inside of your shell.

## Some Command Outputs
In Interactive Mode:
`$ ./hsh`
`($) /bin/ls`
hsh main.c shell.c
`($)`
`($) exit`
`$`

In Non-Interactive Mode:
`$ echo "/bin/ls" | ./hsh`
`hsh main.c shell.c test_ls_2`
`$`
`$ cat test_ls_2`
`/bin/ls`
`/bin/ls`
`$`
`$ cat test_ls_2 | ./hsh`
`hsh main.c shell.c test_ls_2`
`hsh main.c shell.c test_ls_2`
`$`

# Other Commands
 - exit
 - ^D
 - ^C
 - ls
 - ls -l
 - env


## Exceptions:
	Doesn't handle advanced commands and options like grep
and PATH, and there are some errors with help as it only works w/ command
 followed by --help

## Contributors
	* **Jessica Bathel** - [jbathel](https://github.com/jbathel)
	* **Yashar Mateen** - [yasheymateen](https://github.com/yasheymateen)

## License

	MIT License

	Copyright (c) [2019]

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
