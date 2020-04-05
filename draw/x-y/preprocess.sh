g++ ./preprocess.cc
for d in ./*.log
 do
  echo $d
  sort $d -o $d.sorted
  ./a.out $d.sorted
  echo 'set output "'$d'.png"
set terminal png truecolor
set autoscale
myencoding = "utf8"
plot "'$d'.sorted.plot"  u 1:2:3 w points lt 1 pt 5 ps variable
'|gnuplot
 done
 
