# overleaf at your laptop


## install packages
https://medium.com/@jamomani/work-on-overleaf-projects-offline-420fc16ca31b

## enable git

```
 git config --global credential.helper store

```

 then do git pull, and it will store your credential 
 
## build script
```
#!/bin/bash
FILE=main.tex
pdflatex $FILE
bibtex $FILE
pdflatex $FILE
pdflatex $FILE 
```

## config vscode
I'm using this https://marketplace.visualstudio.com/items?itemName=James-Yu.latex-workshop
