#set(SRC_LIST userservice.cc ../user.pb.cc)#.. 表示上一级目录
set(SRC_LIST friendservice.cc ../friend.pb.cc)


add_executable(provider ${SRC_LIST})

target_link_libraries(provider mprpc protobuf)