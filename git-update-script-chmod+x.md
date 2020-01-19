windows file sys
```
git config core.fileMode false

git config --global core.fileMode false
```
https://stackoverflow.com/a/1580644/8428146

chmod +x for all *.sh in a git repo
```
find . -name '*sh' -exec git update-index --chmod=+x {} \;
```
