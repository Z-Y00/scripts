# delete lines from
https://www.folkstalk.com/2013/03/sed-remove-lines-file-unix-examples.html
https://unix.stackexchange.com/questions/45944/delete-specific-line-numbers-from-a-text-file-using-sed
```
7. Delete lines other than the specified range

> sed  -i.bak -e '2,4!d' file
Here the sed command removes lines other than 2nd, 3rd and 4th. 
```
# split a file when meet a special line
 here, we split the file ./z.decaf.out with the ======
```

break=$(awk '/=====/{ print NR; exit }' ./z.decaf.out)
total=$(wc -l < ./z.decaf.out)
#then we got the number of lines
head -n $(($break - 1)) z.decaf.out > z.decaf.tac

tail -n $(($total - $break)) z.decaf.out > z.decaf.asm
```
do this for all files under pwd
```
cd ./samples
for filename in *.decaf.out; do
  break=$(awk '/=====/{ print NR; exit }' ./$filename);
  total=$(wc -l < ./$filename);
  #then we got the number of lines
  head -n $(($break - 1)) $filename > $filename.tac;
 # echo $total; #when the total is 0, there could be wrong
 # echo $break;
 echo $filename
  tail -n $(($total - $break)) $filename > $filename.asm;
done

```


# string in bash
If x is constant, the following parameter expansion performs substring extraction:

b=${a:12:5}

where 12 is the offset (zero-based) and 5 is the length

If the underscores around the digits are the only ones in the input, you can strip off the prefix and suffix (respectively) in two steps:

tmp=${a#*_}   # remove prefix ending in "_"
b=${tmp%_*}   # remove suffix starting with "_"

https://stackoverflow.com/questions/428109/extract-substring-in-bash

