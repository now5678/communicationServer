#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <functional>
using namespace std;
using namespace muduo;
using namespace muduo::net;
using namespace placeholders;

/* 基于muduo网络库开发服务器程序
1、组合TcpServer对象
2、创建EventLoop事件循环对象的指针
3、明确TcpServer构造函数需要什么参数，输出ChatServer的构造函数
4、在当前服务器类的构造函数中，添加注册处理连接的回调函数和处理读写事件的回调函数
5、设置合适的服务端线程数量，muduo会自动分配I/O线程和worker线程


*/

class ChatServer
{
public:
    //初始化TcpServer
    ChatServer(muduo::net::EventLoop* loop,
            const muduo::net::InetAddress& listenAddr)
            :_server(loop, listenAddr, "ChatServer")
    {
       // 通过绑定器设置回调函数
       _server.setConnectionCallback(bind(&ChatServer::onConnection, this, _1));

       //给服务器注册用户读写事件回调
      _server.setMessageCallback(bind(&ChatServer::onMessage, this, _1, _2, _3));

      // 设置服务器线程数量
      _server.setThreadNum(4);
    }
    void start(){
        _server.start();
    }
private:

    // 专门处理用户的连接和断开
    void onConnection(const TcpConnectionPtr& conn){
        if (conn->connected()){
            cout << conn->peerAddress().toIpPort() << "->" 
            << conn->localAddress().toIpPort() << "on connect" <<endl;
        }else{
            cout << conn->peerAddress().toIpPort() << "->" 
            << conn->localAddress().toIpPort() << "off connect" <<endl;
            conn->shutdown();
            // loop.quit();
        }

        
    }

    // 专门处理用户的读写事件
    void onMessage(const TcpConnectionPtr & conn,
                            Buffer* buffer,
                            Timestamp time){
                                string buf = buffer->retrieveAllAsString();
                                cout << time.toFormattedString() << " : " << buf << endl;
                                conn->send(buf);
                            }
    muduo::net::TcpServer _server;
};


int main(){
    EventLoop loop;
    InetAddress ipport("127.0.0.1", 6001);
    ChatServer chatServer(&loop, ipport);
    chatServer.start();
    loop.loop();
    return 0;
}