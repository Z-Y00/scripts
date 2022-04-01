rsync -avz -e "ssh -p $portNumber -i ~/.ssh/xxx"  user@remoteip:src dec
https://mike-hostetler.com/rsync-non-standard-ssh-port/


for binary file, disable compress via remove -z can speedup the process.

for showing the process, add --progress


rsync -rav  --chown=g:x --progress --include "*/" --include="*.dgraph" --exclude="*"  yoo@x:/x /project/x/yoo/
