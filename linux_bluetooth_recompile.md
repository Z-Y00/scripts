credit to: Miao Wang in Debian Chinese User Group for helping me with the following steps.
# English

# Solving Bluetooth Issues on Linux: Recompiling Bluetooth Modules from Source Code

In Linux systems, when dealing with Bluetooth-related issues, we sometimes need to recompile the Bluetooth driver from the kernel source code. The following steps outline how to apply a Bluetooth patch and recompile the corresponding kernel module on Linux.

## Background

The stable kernel version of the existing distribution sometimes does not support the latest Bluetooth devices. Sometimes we need to patch the `bluetooth` module of Linux to add support for the latest hardware. The following are the steps to manually compile and install a Bluetooth module. The example kernel version is `6.12.9+bpo-amd64`, which can be checked using the `uname -r` command.

## Step 1: Obtain the Kernel Source Code

First, we need to obtain and prepare the kernel source code for modification and compilation. You can get the Linux kernel source code through `apt`:

```bash
sudo apt update
sudo apt install linux-source
```

After installation, the source code will be located in the `/usr/src/linux-source-<version>.tar.xz`.
## Step 2: Extract Bluetooth Driver Files
We do not need to recompile the entire kernel, but only need to modify and compile the Bluetooth-related driver files. We only need to get the Bluetooth driver directory drivers/bluetooth and extract the necessary parts. Here you can modify the code and apply your patch. Since the kernel code evolve very fast, which can lead to patch failure, you may need to edit the code manually and try to understand the difference.

## Step 3: Compile the Bluetooth Driver Module
Once you have obtained and prepared the source code for the Bluetooth driver, you can compile it under the bluetooth folder. Use the make command to compile the specified kernel module.

```bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules CONFIG_BT_HCIBTUSB=m
```

This command will compile the module file. After successful compilation, you will get a .ko file.

## Step 4: Install the Compiled Module
Move the compiled .ko file to the update directory of the current kernel version. The following instructions are for the kernel version '6.12.9+bpo-amd64', sudo/root permission needed:


```bash
mkdir /lib/modules/6.12.9+bpo-amd64/updates
cp ./btusb.ko /lib/modules/6.12.9+bpo-amd64/updates/
```
Then use depmod to update the module dependencies, you should exec it as root or use sudo:

```bash
 depmod
```
## Step 5: Check if the Module is Loaded Correctly
You can use the modinfo command to check if the new module is loaded correctly:

```bash
modinfo btusb
```
If everything goes well, you should see the information of the module you just compiled and installed.

Then you can try to remove the old module with rmmod (if it is already loaded), or simply restart if you dont want to bother. You will need to recompile and install the module every time you upgrade the kernel. Another option is to use DKMS. 

# 中文

# 在 Linux 上解决蓝牙问题：从源代码重新编译蓝牙模块


在 Linux 系统中，解决蓝牙相关问题时，我们有时需要从内核源代码重新编译蓝牙驱动。以下步骤为在 Linux 下应用蓝牙补丁并重新编译相应的内核模块。

## 需求背景

现有发行版的 stable 内核版本有时不支持最新的蓝牙设备，
有时我们需要为 Linux 的 `bluetooth` 模块打上补丁，以增加最新的硬件支持。以下是针对如何手动编译并安装一个蓝牙模块的步骤。举例的版本是 `6.12.9+bpo-amd64`，可以通过 `uname -r` 命令查看当前内核版本。

## 步骤 1：获取内核源代码

首先，我们需要获取并准备好内核源代码，以便进行修改和编译。你可以通过 `apt` 获取 Linux 内核源代码：

```bash
sudo apt update
sudo apt install linux-source
```

安装后，源码将会位于 `/usr/src/linux-source-<version>.tar.xz`。

## 步骤 2：提取蓝牙驱动文件

我们不需要重新编译整个内核，而是只需要修改和编译蓝牙相关的驱动文件。 `drivers/bluetooth`。 你可以在这步修改源代码， apply 上 patch

## 步骤 3：编译蓝牙驱动模块

一旦你获取并准备好蓝牙驱动的源代码，你可以在 bluetooth 目录下编译它。使用 `make` 命令来编译指定的内核模块。

```bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules CONFIG_BT_HCIBTUSB=m
```

成功编译后，你会得到一个 `.ko` 文件。

## 步骤 4：安装编译出的模块

将编译出来的 `.ko` 文件移动到当前内核版本的更新目录下，下面的指令是针对内核版本为'6.12.9+bpo-amd64'的情况：

```bash
mkdir /lib/modules/6.12.9+bpo-amd64/updates
cp ./btusb.ko /lib/modules/6.12.9+bpo-amd64/updates/
```

然后使用 `depmod` 更新模块依赖，需要 root 权限：

```bash
 depmod
```

## 步骤 5：检查模块是否正确加载

你可以使用 `modinfo` 命令来检查新的模块是否正确加载：

```bash
modinfo btusb
```

如果一切顺利，你应该会看到刚刚编译并安装的模块信息。

然后可以设法把旧模块 rmmod 掉（如果已经载入了的话），或者不想折腾就直接重启。
以后每次升级内核，都需要重新编一下放进去。
另一种选择是挂 dkms
