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
    ProxyCommand          nc -X connect -x proxyhost:proxyport %h %p
    ServerAliveInterval   10



```
https://stackoverflow.com/a/19213999/8428146
