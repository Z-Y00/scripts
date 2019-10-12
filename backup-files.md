some commands that I usually use
```
 tar --lzop -cvf  foo.tar.lzop  foo
cat /dev/sdb6 | lzop > linux-sys-$(date -I).img.lzop 

cd /foo
tar --create ./document | lzop  > ../backup/backup-lzop/xxx-document-$(date -I).tar.lzop

chmod 777 ./*.lzop 
# how to extract
lzop -d <./foo.tar.lzop | tar --extract
```

You can look it here https://www.lzop.org/lzop_man.php
#  ADVANCED USAGE

lzop allows you to deal with your files in many flexible ways. Here are some usage examples:

backup mode

      tar --use-compress-program=lzop -cf archive.tar.lzo files..

      This is the recommended mode for creating backups.
      Requires GNU tar or a compatible version which accepts the
      '--use-compress-program=XXX' option.

# all tar common usage
```
tar -zcvf tar-archive-name.tar.gz source-folder-name
tar -zxvf tar-archive-name.tar.gz
tar -xvjf foo.tar.bz2

```
