#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define ERR_EXIT(m)\
    do\
{\
    perror(m);\
    exit(EXIT_FAILURE);\
} while(0)
#define SEND_OVER 1
#define SEND_WAIT 0
#define MAXSIZE 10
#define MSGLENGTH 100
typedef struct sockaddr SA;
typedef struct sockaddr_in SOCKET;


//function	初始化服务器连接
void init();

//function	用户登录
//param		fd表示该用户的套接字描述符
//param		peeraddr表示登录连接对端客户端的SOCKET
void login(int fd, SOCKET peeraddr);

//function	将消息发送给其他客户端
//param		buf表示消息缓存，thisfd表示当前客户端的套接字描述符
void SendMsgToOthers(char *buf, int thisfd);

//function	接受和发送消息
//param		pthread_create函数第三个参数的标准格式
void *chat(void *arg);

//function	启动服务器
void service();


#define INVALID_SOCKET -1

typedef struct _Client {
    int conn;
    char usrname[20];
    char IP[20];
    unsigned short port;
    struct _Client *next;
} Client, *pClient;

/*
* function  初始化链表
*/
void InitLink();

/*
* function  获取头节点
* return    返回头节点
*/
pClient GetHeadNode();

/*
* function  添加一个客户端
* param     client表示一个客户端对象
*/
void AddClient(pClient client);

/*
* function  删除一个客户端
* param     flag标识一个客户端对象
* return    返回true表示删除成功，false表示失败
*/
void RemoveClient(int flag);

/*
* function  根据套接字查找指定客户端
* param     fd是指定客户端的连接套接字描述符
* return    返回一个Client指针表示查找成功，返回NULL表示无此用户
*/
pClient FindClient(int fd);

/*
* function  计算客户端连接数
* param     client表示一个客户端对象
* return    返回连接数
*/
int CountConn();

/*
* function  清空链表
*/
void ClearClient();

/*
* function  检查连接状态并关闭一个连接
*/
void CheckConnection();
