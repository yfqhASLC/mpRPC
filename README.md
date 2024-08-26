# mpRPC
分布式网络通信框架项目源码    muduo网络库+protobuf数据交换+zookeeper分布式协调服务  

编译方式(两种)：  
一：  
cd build  
rm -rf *  
cmake ..  
make  
二：  
使用自动编译脚本 ./autobuild.sh  

技术栈：  
分布式概念  
RPC远程调用及实现  
Protobuf数据序列化和反序列化协议  
ZooKeeper分布式一致性协调服务应用以及编程  
muduo网络库编程  
conf配置文件读取  
异步日志  
