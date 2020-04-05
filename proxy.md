# netcat install 
you must use this impl of netcat for the -x ooption
```
apt install netcat-openbsd

https://www.linuxquestions.org/questions/linux-newbie-8/how-to-sftp-using-a-socks-v5-proxy-789824/
```
# curl
```
curl ipinfo.io

#socks5
curl --socks5 127.0.0.1:1080  ipinfo.io

#http socket
curl -x http://127.0.0.1:1080 ipinfo.io
```

# sftp
```
sftp -i ~/.ssh/?? -oProxyCommand='nc -v -x127.0.0.1:1080 %h %p'  ??@??.edu
```
# ssh
https://stackoverflow.com/a/19162114/8428146
 to ~/.ssh/config
```


Host foobar.example.com
    ProxyCommand          nc -X connect -x 127.0.0.1:1080 %h %p
    ServerAliveInterval   10



```
https://stackoverflow.com/a/19213999/8428146


# git 

git config --global https.proxy http://127.0.0.1:1080
	
git config --global https.proxy https://127.0.0.1:1080
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'

git config --global --unset http.proxy
	
git config --global --unset https.proxy

https://gist.github.com/laispace/666dd7b27e9116faece6

# pip
https://blog.csdn.net/qq_34067821/article/details/90721254
mkdir ~/.pip
echo "[global]
index-url = http://mirrors.aliyun.com/pypi/simple/
 
[install]
trusted-host=mirrors.aliyun.com" >~/.pip/pip.conf
