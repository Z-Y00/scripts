```
curl ipinfo.io

#socks5
curl --socks5 127.0.0.1:1080  ipinfo.io

#http socket
curl -x http://127.0.0.1:1080 ipinfo.io
```



https://stackoverflow.com/a/19162114/8428146
 to ~/.ssh/config
```


Host foobar.example.com
    ProxyCommand          nc -X connect -x proxyhost:proxyport %h %p
    ServerAliveInterval   10



```
https://stackoverflow.com/a/19213999/8428146
