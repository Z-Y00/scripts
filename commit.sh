#!/bin/bash
git add .
git commit -m $1
git -c http.proxy=socks5h://localhost:7891 push  -v
