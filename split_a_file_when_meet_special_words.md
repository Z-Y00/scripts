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
