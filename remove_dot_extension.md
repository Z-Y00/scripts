```
#!/bin/bash
org=$1
name="${org%.txt}u"
echo $name
echo $org

for fname in r*; do fn="${fname:1}"; mv -f $fname/* $fn; done

# subplace the log
for fname in r*
do
fn="${fname:1}"
mv -f $fname $fn
done
```
