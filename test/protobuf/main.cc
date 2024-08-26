#include "test.pb.h"
#include <iostream>
#include <string>

using namespace fixbug;

int main()
{
    // LoginRespense rsp;
    // ResultCode *rc = rsp.mutable_results();
    // rc->set_errcode(0);
    // rc->set_errmsg("登录成功");

    GetFriendListsResponse rsp;
    ResultCode *rc = rsp.mutable_results();  //mutable_results   可变的结果
    rc->set_errcode(0);
    User *usr1 = rsp.add_friend_list();
    usr1->set_name("zhang san");
    usr1->set_age(10);
    usr1->set_sex(User::MAN);

    User *usr2 = rsp.add_friend_list();
    usr2->set_name("zhang san");
    usr2->set_age(10);
    usr2->set_sex(User::MAN);

    std::cout << rsp.friend_list_size() << std::endl;

    return 0;
}

int main1()
{
    // 封装了login请求对象的数据
    LoginRquest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象序列化 >>char*
    std::string send_str;
    if (req.SerializeToString(&send_str))
    {
        std::cout << send_str << std::endl;
    }

    // 对象反序列化
    LoginRquest req1;
    if (req1.ParseFromString(send_str))
    {
        std::cout << req1.name() << std::endl;
        std::cout << req1.pwd() << std::endl;
    }

    return 0;
}