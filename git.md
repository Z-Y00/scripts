# several ssh key
Seems not working:
```
 systemctl reload sshd.service
GIT_SSH_COMMAND="ssh -i ~/.ssh/id_rsa_example" git clone example
```
working for me:
```
git config core.sshCommand "ssh -i ~/.ssh/alchem_rgy -F /dev/null"
git config core.sshCommand "ssh -i ~/.ssh/id_rsa -F /dev/null"
 
```
or to change the ~/.ssh/config
```
      ProxyCommand          nc -X 5 -x 127.0.0.1:1080 %h %p
#Host github.com
#   ServerAliveInterval   10
#   IdentityFile ~/.ssh/alchem_rgy
#   User git 

```
for ssh key debugging
```
ssh git@github.com -v
```
https://superuser.com/a/912281/759206
# clean up git
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
# git-update-script-chmod+x
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
# fast git clone
git clone https://github.com/2019ncovmemory/nCovMemory.git --depth 1

# untrack a file

