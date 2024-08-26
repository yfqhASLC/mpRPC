#pragma once
#include <queue> //尾进首出
#include <thread>
#include <mutex>              // pthread_mutex_t
#include <condition_variable> // pthread_condition_t

// 异步写日志的日志队列
template <typename T> // 模板代码只能写在头文件中
class LockQueue
{
public:
    // 多个worker线程都会写日志queue
    void Push(const T &data)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(data);
        m_condvariable.notify_one();
    }

    // 一个线程读日志queue，写日志文件
    T Pop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty())
        {
            // 日志队列为空，停止写日志，线程进入wait状态
            m_condvariable.wait(lock);
        }

        T data = m_queue.front();
        m_queue.pop();//m_queue.front()被接收后，弹出来释放queue空间
        return data;
    }

private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_condvariable;
};