chmod +x for all *.sh in a git repo
```
find . -name '*sh' -exec git update-index --chmod=+x {} \;
```
