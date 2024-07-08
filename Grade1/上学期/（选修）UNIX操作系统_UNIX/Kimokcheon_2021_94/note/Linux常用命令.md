## 目录

1. 查看 Linux 命令帮助信息
2. Linux 文件目录管理
3. Linux 文件内容查看命令
4. Linux 文件压缩和解压
5. Linux 用户管理
6. Linux 系统管理
7. Linux 网络管理
8. Linux 硬件管理
9. Linux 软件管理

---

## 1. 查看 Linux 命令帮助信息

### 1.1 `help`
- 用于显示内建命令的帮助信息。
```sh
help command_name
```

### 1.2 `whatis`
- 显示命令的简短描述。
```sh
whatis command_name
```

### 1.3 `info`
- 提供详细的命令使用说明。
```sh
info command_name
```

### 1.4 `which`
- 显示命令的路径。
```sh
which command_name
```

### 1.5 `whereis`
- 显示命令的二进制文件、源代码和手册页的位置。
```sh
whereis command_name
```

### 1.6 `man`
- 显示命令的手册页。
```sh
man command_name
```

---

## 2. Linux 文件目录管理

### 2.1 `cd`
- 切换目录。
```sh
cd /path/to/directory
```

### 2.2 `ls`
- 列出目录内容。
```sh
ls
```

### 2.3 `pwd`
- 显示当前工作目录。
```sh
pwd
```

### 2.4 `mkdir`
- 创建新目录。
```sh
mkdir directory_name
```

### 2.5 `rmdir`
- 删除空目录。
```sh
rmdir directory_name
```

### 2.6 `tree`
- 以树状图显示目录结构。
```sh
tree
```

### 2.7 `touch`
- 创建空文件或更新文件的时间戳。
```sh
touch file_name
```

### 2.8 `ln`
- 创建链接。
```sh
ln -s target_file link_name
```

### 2.9 `rename`
- 重命名文件。
```sh
rename old_name new_name
```

### 2.10 `stat`
- 显示文件详细信息。
```sh
stat file_name
```

### 2.11 `file`
- 显示文件类型。
```sh
file file_name
```

### 2.12 `chmod`
- 修改文件权限。
```sh
chmod permissions file_name
```

### 2.13 `chown`
- 修改文件所有者。
```sh
chown user:group file_name
```

### 2.14 `locate`
- 快速查找文件。
```sh
locate file_name
```

### 2.15 `find`
- 在文件系统中查找文件。
```sh
find /path -name file_name
```

### 2.16 `cp`
- 复制文件或目录。
```sh
cp source_file destination_file
```

### 2.17 `mv`
- 移动或重命名文件或目录。
```sh
mv source_file destination_file
```

### 2.18 `rm`
- 删除文件或目录。
```sh
rm file_name
```

---

## 3. Linux 文件内容查看命令

### 3.1 `cat`
- 查看文件内容。
```sh
cat file_name
```

### 3.2 `head`
- 显示文件的前几行。
```sh
head file_name
```

### 3.3 `tail`
- 显示文件的后几行。
```sh
tail file_name
```

### 3.4 `more`
- 分页显示文件内容。
```sh
more file_name
```

### 3.5 `less`
- 分页显示文件内容，比 `more` 更强大。
```sh
less file_name
```

### 3.6 `sed`
- 流编辑器，用于文本处理。
```sh
sed 's/old/new/g' file_name
```

### 3.7 `vi`
- 文本编辑器。
```sh
vi file_name
```

### 3.8 `grep`
- 在文件中搜索文本。
```sh
grep 'pattern' file_name
```

---

## 4. Linux 文件压缩和解压

### 4.1 `tar`
- 归档文件。
```sh
tar -cvf archive.tar file_name
```
- 解压归档文件。
```sh
tar -xvf archive.tar
```

### 4.2 `gzip`
- 压缩文件。
```sh
gzip file_name
```
- 解压文件。
```sh
gzip -d file_name.gz
```

### 4.3 `zip`
- 压缩文件。
```sh
zip archive.zip file_name
```
- 解压文件。
```sh
unzip archive.zip
```

---

## 5. Linux 用户管理

### 5.1 `groupadd`
- 添加新组。
```sh
groupadd group_name
```

### 5.2 `groupdel`
- 删除组。
```sh
groupdel group_name
```

### 5.3 `groupmod`
- 修改组。
```sh
groupmod -n new_group_name old_group_name
```

### 5.4 `useradd`
- 添加新用户。
```sh
useradd user_name
```

### 5.5 `userdel`
- 删除用户。
```sh
userdel user_name
```

### 5.6 `usermod`
- 修改用户。
```sh
usermod -c "new_comment" user_name
```

### 5.7 `passwd`
- 修改用户密码。
```sh
passwd user_name
```

### 5.8 `su`
- 切换用户。
```sh
su - user_name
```

### 5.9 `sudo`
- 以超级用户身份运行命令。
```sh
sudo command
```

---

## 6. Linux 系统管理

### 6.1 `reboot`
- 重启系统。
```sh
reboot
```

### 6.2 `exit`
- 退出当前会话。
```sh
exit
```

### 6.3 `shutdown`
- 关闭系统。
```sh
shutdown -h now
```

### 6.4 `date`
- 显示或设置系统日期和时间。
```sh
date
```

### 6.5 `mount`
- 挂载文件系统。
```sh
mount /dev/sdX /mnt
```

### 6.6 `umount`
- 卸载文件系统。
```sh
umount /mnt
```

### 6.7 `ps`
- 显示当前进程。
```sh
ps
```

### 6.8 `kill`
- 终止进程。
```sh
kill PID
```

### 6.9 `systemctl`
- 管理系统服务。
```sh
systemctl start/stop/restart service_name
```

### 6.10 `service`
- 管理系统服务。
```sh
service service_name start/stop/restart
```

### 6.11 `crontab`
- 管理定时任务。
```sh
crontab -e
```

---

## 7. Linux 网络管理

### 7.1 `curl`
- 命令行工具，用于发送HTTP请求。
```sh
curl http://example.com
```

### 7.2 `wget`
- 命令行工具，用于下载文件。
```sh
wget http://example.com/file.zip
```

### 7.3 `telnet`
- 远程连接工具。
```sh
telnet hostname port
```

### 7.4 `ip`
- 显示或配置网络接口。
```sh
ip a
```

### 7.5 `hostname`
- 显示或设置系统主机名。
```sh
hostname
```

### 7.6 `ifconfig`
- 显示或配置网络接口（已过时，推荐使用 `ip`）。
```sh
ifconfig
```

### 7.7 `route`
- 显示或配置路由表。
```sh
route
```

### 7.8 `ssh`
- 通过SSH协议连接远程主机。
```sh
ssh user@hostname
```

### 7.9 `ssh-keygen`
- 生成SSH密钥对。
```sh
ssh-keygen
```

### 7.10 `firewalld`
- 配置防火墙。
```sh
firewall-cmd --state
```

### 7.11 `iptables`
- 配置IP包过滤规则。
```sh
iptables -L
```

### 7.12 `host`
- 查询DNS记录。
```sh
host example.com
```

### 7.13 `nslookup`
- 查询DNS记录。
```sh
nslookup example.com
```

### 7.14 `nc/netcat`
- 网络调试和数据传输工具。
```sh
nc -zv hostname port
```

### 7.15 `ping`
- 测试网络连接。
```sh
ping

 hostname
```

### 7.16 `traceroute`
- 跟踪网络路径。
```sh
traceroute hostname
```

### 7.17 `netstat`
- 显示网络连接、路由表、接口状态等。
```sh
netstat -a
```

---

## 8. Linux 硬件管理

### 8.1 `df`
- 显示文件系统磁盘空间使用情况。
```sh
df -h
```

### 8.2 `du`
- 显示目录或文件的磁盘使用情况。
```sh
du -sh directory_name
```

### 8.3 `top`
- 显示实时系统进程信息。
```sh
top
```

### 8.4 `free`
- 显示系统内存使用情况。
```sh
free -h
```

### 8.5 `iotop`
- 显示实时磁盘I/O使用情况。
```sh
iotop
```

---

## 9. Linux 软件管理

### 9.1 `rpm`
- RPM包管理器。
```sh
rpm -ivh package.rpm
```

### 9.2 `yum`
- 使用YUM软件包管理工具。
```sh
yum install package_name
```

### 9.3 `apt-get`
- 使用APT软件包管理工具。
```sh
apt-get install package_name
```