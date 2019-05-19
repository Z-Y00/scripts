 # Purpose

As a Chinese citizen, you may always wonder if the paper have lied to us, 
So you may wanna to archive the daily paper and glance throungh them years later, which may reveal many secrets
### a simple one
```
wget -r http://paper.people.com.cn/rmrb/ -A .pdf
```
I need to deal with the 01-09 and 10-20 seperately, and
the actual days in month and pages are smaller than what I've written here, just in case we miss any page
```
for year in 2018 2019 
do
  for month in 01 02 03 04 05 06 07 08 09 10 11 12
   do
        for day in 01 02 03 04 05 06 07 08 09
       do
         for page in 01 02 03 04 05 06 07 08 09
           do
            echo $year$month$day$page
            wget paper.people.com.cn/rmrb/page/$year-$month/$day/$page/rmrb$year$month$day$page.pdf 
          done
          for ((page=10;page<=25;page++)) 
           do
            echo $year$month$day$page
            wget paper.people.com.cn/rmrb/page/$year-$month/$day/$page/rmrb$year$month$day$page.pdf
          done
       done
       #all day bigger than 10
     for ((day=10;day<=31;day++)) 
       do
         for page in 01 02 03 04 05 06 07 08 09
           do
            echo $year$month$day$page
            wget paper.people.com.cn/rmrb/page/$year-$month/$day/$page/rmrb$year$month$day$page.pdf
          done
          for ((page=10;page<=25;page++)) 
           do
            echo $year$month$day$page
            wget paper.people.com.cn/rmrb/page/$year-$month/$day/$page/rmrb$year$month$day$page.pdf
          done
     done
   done
done

```
