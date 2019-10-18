```
#!/bin/sh
echo $1
./uconvert $1 ;
#delete the .txt
name=$(echo "$1" | cut -f 1 -d '.')
echo $name
./dump $name;
./zero $name;
```
