# changed all files from CRLF to LF.
https://stackoverflow.com/a/65628702/8428146

Make sure to commit any changes before running this!

In the root folder type the following.
```
git config core.autocrlf false

git rm --cached -r .         # Don’t forget the dot at the end

git reset --hard
```

# vscode sync key mapping
https://stackoverflow.com/questions/52726849/how-to-transfer-vscode-key-mapping-on-windows-to-ubuntu
https://marketplace.visualstudio.com/items?itemName=fredhappyface.linuxkeybindings


# sync with oneDrive
https://github.com/abraunegg/onedrive/blob/master/docs/USAGE.md#show-your-configuration


# WSL mount disk
mount -t drvfs e: /mnt/e -o uid=1000,gid=1000
https://github.com/microsoft/WSL/issues/3187#issuecomment-388904048
https://superuser.com/questions/1360276/cannot-access-external-drive-in-windows-10-linux-subsystem-bash
