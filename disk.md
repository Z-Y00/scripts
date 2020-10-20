 
udisksctl power-off -b /dev/sdc1

apt install udisks2 

hdparm把磁盘转到待机模式

cd /sys/bus/usb/devices
good_usb=$(grep -H Western usb?/?-?/manufacturer | cut -d"/" -f1,2)
cd ${good_usb}/power
gksudo "sh -c 'echo "suspend" > level'"

# free space
https://linuxhint.com/free_up_hard_drive_space_ubuntu/
