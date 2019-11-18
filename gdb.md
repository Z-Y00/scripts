gdb -ex=r --args myprogram arg1 arg2


gdb -ex=r --args myprogram arg1 arg2

-ex=r is short for -ex=run and tells gdb to run your program immediately, rather than wait for you to type "run" at the prompt. Then --args says that everything that follows is the command and arguments, just as you'd normally type them at the commandline prompt.
https://stackoverflow.com/a/18776339/

https://sourceware.org/gdb/onlinedocs/gdb/Backtrace.html


In a multi-threaded program, GDB by default shows the backtrace only for the current thread. To display the backtrace for several or all of the threads, use the command thread apply (see thread apply). For example, if you type 
```
thread apply all backtrace
```
, GDB will display the backtrace for all the threads; this is handy when you debug a core dump of a multi-threaded program. 



info variables  "All global and static variable names".

info locals   "Local variables of current stack frame" (names and values), including static variables in that function.

info args   "Arguments of the current stack frame" (names and values).


https://stackoverflow.com/questions/3483163/how-do-i-halt-the-continuing-in-gdb
 kill -2 
 
 
You should interrupt the process that is attached by gdb. Do not interrupt gdb itself. Interrupt the process by either ctrl-c in the terminal in which the process was started or send the process the SIGINT by kill -2 procid. With procid the id of the process being attached.


