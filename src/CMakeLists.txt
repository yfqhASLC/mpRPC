#aux_source_directory(. SRC_LIST)  #将当前目录下的所有源文件放入SRC_LIST
set(SRC_LIST 
    mprpcapplication.cc 
    mprpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc 
    mprpcchannel.cc
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc
    )

#add_library(mprpc SHARED ${SRC_LIST}) #SHARED: 动态库     生成动态库mprpc
add_library(mprpc ${SRC_LIST}) #SHARED: 动态库     生成动态库mprpc

target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt)#注意muduo_net要放在muduo_base前面     muduo_base依赖于muduo_net    zookeeper_mt:多线程版本