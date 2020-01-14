https://stackoverflow.com/a/19162114/8428146
 to ~/.ssh/config
```


Host foobar.example.com
    ProxyCommand          nc -X connect -x proxyhost:proxyport %h %p
    ServerAliveInterval   10



```
