# monty - Stacks, Queues - LIFO, FIFO 🥞  
#### monty functions as a Monty byte code interpreter. Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.  
  
  
## SYNOPSIS  
monty is a simple byte code interpreter in accordance with Holberton School standards and expectations. This project's purpose was to introduce students to working with the stack which is [**LIFO** (last in first out)]([https://en.wikipedia.org/wiki/Stack_(abstract_data_type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))) and the `queue`, which is [**FIFO** (first in first out)]([https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics))).  
  
  
  
  
  
  
## INSTALLATION AND USAGE  
Please use GCC 4.8.4 compiler or later.  
  
```  
$ git clone [repository link]  
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty  
$ ./monty file_name.m  
```  
  
  
  
## SYNTAX OVERVIEW AND EXAMPLES  
  
  
Below are some examples of using monty with bytecode files:  
  
```  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$ cat -e bytecodes/00.m  
push 1$  
push 2$  
push 3$  
pall$  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$ ./monty bytecodes/00.m  
3  
2  
1  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$  
```  
```  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$ cat bytecodes/09.m  
push 1  
push 2  
push 3  
pall  
swap  
pall  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$ ./monty bytecodes/09.m  
3  
2  
1  
2  
3  
1  
vagrant@vagrant-ubuntu-trusty-64:~/0x19-stacks_queues_lifo_fifo$  
```  
## pcodes  
  
------  
Listed below are the opcodes to can be used in monty:  
  
opcode | Function  
--------|---------------  
push | Pushes an element to the stack  
pall | Prints all the values on the stack, starting from the top of the stack  
pint| prints the value at the top of the stack, followed by a new line  
pop| Removes the top element of the stack  
swap | Swaps the top two elements of the stack  
 add | Adds the top two elements of the stack  
 nop| Doesn’t do anything 
  
  
  
  

## File Descriptions  
  
Listed below are the descriptions of the files in this repo:  
  
File | Description  
--------|---------------  
helperfuncs.c | Includes functions for string manipulation.  
main.c| Contains parser and main monty interpreter.  
path_funcs1.c | Contains path functions.  
path_funcs2.c | Contains path functions.  
prompt.c | Displays ps1 prompt.  
rec_cmd_exec_cmd.c | Receives and executes commands.  
monty.h | Contains function prototypes and data structures.  
  
  
  
  
  
  
## Authors  
  
*Faizan Khan* :zap:  
  
  
*Christian Williams* :musical_note:  
  
## FUNCTIONS  
  
```  
extern char **environ;  
void environ1(char **env);  
void shell_init(char **env);  
int main(int argc, char **argv, char **env);  
char *catcmddir(char *dir, char *arg_val);  
char *environ_vars(char **env);  
char **tokenize_Dir(char **env);  
char *path_scan(char **dir, char *cmd);  
void prompt(void);  
char *get_line(void);  
char **line_token(char *line);  
int exec_cmd(char *cmdpath, char **command);  
int exit_hsh(char **cmd);  
int print_env(char **cmd);  
int call_built(char *cmbn, char **cmd);  
int _strlen(char *s);  
int _strcmp(char *s1, char *s2);  
char *_strdup(char *str);  

```