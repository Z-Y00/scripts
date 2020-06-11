debootstrap --arch amd64 jessie ./jessie/ http://mirrors.aliyun.com/debian
chroot just uses your current Kernel
(btw, I fixed the zsim to let it run on new kernel with one more pin param)
# inside
```
cat > ./usr/sbin/policy-rc.d <<EOF
#!/bin/sh
exit 101
EOF
chmod a+x ./usr/sbin/policy-rc.d

echo jessie >> /etc/debian_chroot
apt install vim

apt-get install deborphan
deborphan -a
apt install  build-essential
```
https://wiki.debian.org/chroot
https://help.ubuntu.com/community/BasicChroot

# in host 
```
ln -s /bin/true /usr/bin/ischroot

NAME=jessie
mount -o bind /proc /var/chroot/$NAME/proc
mount -o rw,bind /home /var/chroot/$NAME/home
mount --bind /dev/pts /var/chroot/$NAME/dev/pts/
mount -o rw,bind /media/rgy/exchange/ /var/chroot/$NAME/media/rgy/exchange/
cp /etc/resolv.conf /var/chroot/$NAME/etc/resolv.conf

# never do this! you should adduser and set passwd 
cp /etc/passwd /var/chroot/$NAME/etc/passwd
cp /etc/group /var/chroot/$NAME/etc/group


rm -f /dev/null; mknod -m 666 /dev/null c 1 3
# adduser and no sudo
```
## conf
As an administrator, open /etc/schroot/schroot.conf in a text editor. Type cd /etc/schroot, followed by gksu gedit schroot.conf. This will allow you to edit the file.

Add the following lines into schroot.conf and then save and close the file. Replace your_username with your username.

    [jessie]
    description=Debian jessie
    location=/var/chroot/jessie
    priority=3
    users=your_username
    groups=sbuild
    root-groups=root
    
schroot -c jessie -u rgy
## .bashrc
```
if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac


# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

```
