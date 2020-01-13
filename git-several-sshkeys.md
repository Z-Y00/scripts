Seems not working:
```
 systemctl reload sshd.service
GIT_SSH_COMMAND="ssh -i ~/.ssh/id_rsa_example" git clone example

```
working for me:
```
git config core.sshCommand "ssh -i ~/.ssh/id_rsa_example -F /dev/null"

```
https://superuser.com/a/912281/759206
