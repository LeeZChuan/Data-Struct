1. 可以先将本地文件夹进行压缩，tar -cf xxxx.tar xxxx
2. 再将文件远程拷贝到远程服务器上， scp xxxx.tar admin@192.168.83.119:/data/stock/web
3. 然后在进入远程服务器访问具体的文件路径cd /data/stock/web 
4. 然后进行解压