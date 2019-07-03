https://stackoverflow.com/questions/13716658/how-to-delete-all-commit-history-in-github

Deleting the .git folder may cause problems in your git repository. If you want to delete all your commit history but keep the code in its current state, it is very safe to do it as in the following:

```
    git checkout --orphan latest_branch
    git add -A
    git commit -am "init"
    git branch -D master
    git branch -m master
    git push -f origin master
```
