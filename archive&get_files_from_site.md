
wget -r  -A *.jpg


 wget -r -np https://www.**.net/tianzhongfangshu/yinheyingxiongchuanshuiwaichuan/

 
 wget -r -np -p -k https://www.douban.com/people/cclethe
 
 wget -r -np -p -k  https://www.douban.com/people/1412680

 
 https://blog.csdn.net/tangyin025/article/details/80057995
 -c：继续执行上次终端的任务

-L：仅顺着关联的连接

-r：递归下载方式

-nc：文件存在时，下载文件不覆盖原有文件

-np：不查询父目录

-p：下载页面所需所有资源，如图片、声音等

-k：将下载内容中的链接转换为本地连接



wget \
     --recursive \
     --no-clobber \
     --page-requisites \
     --html-extension \
     --convert-links \
     --restrict-file-names=windows \
     --domains carrotlsp.github.io \
     --no-parent \
     
https://blog.csdn.net/roshy/article/details/90640849
https://www.jianshu.com/p/7da33ba4410b
