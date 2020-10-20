## scripts for find sth 
You can put these scripts with shortname under your /home/foo/bin

find a file with name (regex)
```
#!/bin/bash
if [ "$#" -ne 2 ] || ! [ -d "$1" ]; then
  echo "Usage: $0 dir filename" >&2
  exit 1
fi
find $1 -name $2
```

find a file with content
```
#!/bin/bash
if [ "$#" -ne 3 ] || ! [ -d "$1" ]; then
  echo "Usage: $0 dir filename pattern" >&2
  exit 1
fi
find $1 -name $2 -print | xargs grep $3
```

This will delete all the files in a directory (and below) that are size zero.

find /tmp -size  0 -print -delete

https://stackoverflow.com/questions/5475905/linux-delete-file-with-size-0
