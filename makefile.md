# How do I write the 'cd' command in a makefile?
https://stackoverflow.com/questions/1789594/how-do-i-write-the-cd-command-in-a-makefile
For example:

all:
        cd some_dir; echo "I'm in some_dir"; \
          gcc -Wall -o myTest myTest.c

Note also that the semicolon is necessary between every command even though you add a backslash and a newline. This is due to the fact that the entire string is parsed as a single line by the shell. As noted in the comments, you should use '&&' to join commands, which mean they only get executed if the preceding command was successful.

all:
        cd some_dir && echo "I'm in some_dir" && \
          gcc -Wall -o myTest myTest.c

This is especially crucial when doing destructive work, such as clean-up, as you'll otherwise destroy the wrong stuff, should the cd fail for whatever reason.

A common usage though is to call make in the sub directory, which you might want to look into. There's a command line option for this so you don't have to call cd yourself, so your rule would look like this

all:
        $(MAKE) -C some_dir all

which will change into some_dir and execute the Makefile in there with the target "all". As a best practice, use $(MAKE) instead of calling make directly, as it'll take care to call the right make instance (if you, for example, use a special make version for your build environment), as well as provide slightly different behavior when running using certain switches, such as -t.

For the record, make always echos the command it executes (unless explicitly suppressed), even if it has no output, which is what you're seeing.
