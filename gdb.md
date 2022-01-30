gdb -ex=r --args myprogram arg1 arg2


gdb -ex=r --args myprogram arg1 arg2

-ex=r is short for -ex=run and tells gdb to run your program immediately, rather than wait for you to type "run" at the prompt. Then --args says that everything that follows is the command and arguments, just as you'd normally type them at the commandline prompt.
https://stackoverflow.com/a/18776339/

https://sourceware.org/gdb/onlinedocs/gdb/Backtrace.html


# debug segv
gcc -g -fsanitize=address main.c
https://stackoverflow.com/a/56090796/8428146

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







In addition to options mentioned by @diverscuba23, you could do the following:

gdb -ex=r --args bash <script>

(assuming it's a bash script. Else adapt accordingly)
https://stackoverflow.com/a/32264100/8428146




You can always Python using gdb and set breakpoints as you like

gdb -ex r --args python script.py args

If you want to look what happens in Python while running Python script I suggest to use mixed mode

gdb -ex r --args python -m pdb script.py

This way, you can break in pdb, then press Ctrl-C and end up inside gdb. Then, bt will give you stack trace inside Python.


https://stackoverflow.com/a/51553546/8428146


https://codeyarns.github.io/tech/2019-12-30-how-to-generate-assembly-code-using-gcc.html

```
Thankfully, all these options can be combined to generate the most detailed annotated assembly code:

$ gcc -g -Wa,-adhln -fverbose-asm foobar.cpp > foobar.s
```
