#pragma once

#include <semaphore.h>//信号量
#include <zookeeper/zookeeper.h>
#include <string>

// 封装的zk客户端类
class ZkClient
{
public:
    ZkClient();
    ~ZkClient();

    // zkclient启动连接zkserver
    void Start();

    // 在zkserver上根据指定的path来创建znode节点
    void Create(const char *path, const char *data, int datalen, int state=0);//state=0表示创建的是永久性节点，默认为永久性节点

    // 根据参数指定的znode节点路径，获取znode节点的值
    std::string GetData(const char *path);
    
private:
    // zk的客户端句柄
    zhandle_t *m_zhandle;
};