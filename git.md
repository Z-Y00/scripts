# several ssh key
Seems not working:
```
 systemctl reload sshd.service
GIT_SSH_COMMAND="ssh -i ~/.ssh/id_rsa_example" git clone example
```
working for me:
```
git config core.sshCommand "ssh -i ~/xxx -F /dev/null"
 
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

# ProxyCommand
git -c http.proxy=socks5h://localhost:1080  push xxx
just add the -c http.proxy=socks5h://localhost:1080 to whatever the command is

git -c http.proxy=socks5h://localhost:1080 clone https://git.overleaf.com/xxxx

# unset proxy
git config --global --unset http.proxy
git config --global --unset https.proxy
git config --global --unset core.gitproxy
https://askubuntu.com/questions/838856/how-to-remove-proxy-from-git-i-try-but-still-showing-the-error-how-to-resolve-i

# Force git to use SSH on GitHub
https://ricostacruz.com/til/github-always-ssh
This forces GitHub to always use SSH, even for HTTPS URL's! This way, you can use https:// GitHub URL's and they will still use your SSH key.

git config --global url."git@github.com:".insteadOf "https://github.com/"

# parallel git clone
https://stackoverflow.com/a/4438292/8428146

With version 2.13 of Git and later, --recurse-submodules can be used instead of --recursive:

git clone --recurse-submodules -j8 git://github.com/foo/bar.git
cd bar

For already cloned repos, or older Git versions, use:

git clone git://github.com/foo/bar.git
cd bar
git submodule update --init --recursive


# cache credential

 git config --global credential.helper store

 then do git pull, and it will store your credential 
 https://stackoverflow.com/a/35942890/8428146
 
 
https://medium.com/@jamomani/work-on-overleaf-projects-offline-420fc16ca31b
```
main.aux
main.log
main.out
main.pdf
main.toc
main.xmpdata
pdfa.xmpi
main.bbl
main.blg
```
Now, if you want to avoid inserting username and password every time you push the changes to Overleaf, use the command below, otherwise ship to “push the changes” part. The timeout option specifies for how long in milliseconds the credentials are stored, in this example it corresponds to 6 months. Be aware that the credentials are stored in a plaintext file in ~/.git-credentials.

git config --global credential.helper ‘cache --timeout 15552000000’
