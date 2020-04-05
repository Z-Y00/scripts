set output "21.png"
set terminal png truecolor
set autoscale
myencoding = "utf8"

plot 'triangle.citeseer.log.sorted.plot'  u 1:2:3 w points lt 1 pt 5 ps variable
