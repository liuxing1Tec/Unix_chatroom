#include "../include/chatsrv.h"

int listenfd;

void init() {
    if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");
    SOCKET servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
        ERR_EXIT("bind");
    if (listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    InitLink();
}


void login(int fd, SOCKET peeraddr) {
    char usrname[20] = {};
    int ret = recv(fd, usrname, sizeof(usrname), 0);
    if (ret < 0)
        ERR_EXIT("recv");
    else if (0 == ret)
        printf("client closed\n");
    else {
        printf("%s login!", usrname);
        pClient cli = (pClient) malloc(sizeof(Client));
        if (cli == NULL)
            ERR_EXIT("malloc");
        bzero(cli, sizeof(Client));
        cli->conn = fd;
        sprintf(cli->usrname, "%s", usrname);
        sprintf(cli->IP, "%s", inet_ntoa(peeraddr.sin_addr));//arpa/inet.h
        cli->port = ntohs(peeraddr.sin_port);
        AddClient(cli);//初始化一个用户
        char initbuf[MSGLENGTH] = {};
        bzero(&initbuf, sizeof(initbuf));
        sprintf(initbuf, "%s:onlion!\n", usrname);
        pClient p = GetHeadNode();
        while (p->next != NULL) {
            send(p->next->conn, initbuf, strlen(initbuf), 0);
            p = p->next;
        }

    }
}

void SendMsgToOthers(char *buf, int thisfd) {
    char sendbuf[MSGLENGTH] = {};
    bzero(&sendbuf, sizeof(sendbuf));
    pClient thiscli = FindClient(thisfd), p = GetHeadNode();
    time_t now;
    struct tm *t;
    time(&now);
    t = gmtime(&now);
    sprintf(sendbuf, "%02d:%02d:%02d->>%s:%s", 8 + t->tm_hour, t->tm_min, t->tm_sec, thiscli->usrname, buf);
    p = p->next;
    while (p != NULL) {
        if (p != thiscli)
            send(p->conn, sendbuf, strlen(sendbuf), 0);
        p = p->next;
    }
    bzero(&sendbuf, sizeof(sendbuf));
}

void *chat(void *arg) {
    int fd = *(int *) arg;
    while (1) {
        char buf[MSGLENGTH] = {};
        bzero(&buf, sizeof(buf));
        int i, ret = recv(fd, buf, sizeof(buf), 0);
        if (ret <= 0) {
            pClient cli = FindClient(fd), p = GetHeadNode();
            if (cli == NULL || p == NULL)
                ERR_EXIT("UsrLink ERROR");
            sprintf(buf, "%s : logout!\n", cli->usrname);
            p = p->next;
            while (p != NULL) {
                if (p != cli)
                    send(p->conn, buf, strlen(buf), 0);
                p = p->next;
            }
            RemoveClient(fd);
            pthread_exit("client close!\n");
        }
        SendMsgToOthers(buf, fd);
    }
}

void service() {
    printf("service start!\n");
//	void* thread_ret;
    while (1) {
        SOCKET peeraddr;
        socklen_t peerlen = sizeof(peeraddr);
        int i, conn;
        if ((conn = accept(listenfd, (SA *) &peeraddr, &peerlen)) < 0)
            ERR_EXIT("accept");

        if (CountConn() == MAXSIZE) {
            char *errStr = "The current connection is full, please connect later!";
            send(conn, errStr, strlen(errStr), 0);
            close(conn);//unistd.h
        }

        login(conn, peeraddr);
//		CheckConnection();
        printf("Current connection : %d\n", CountConn());
        pthread_t pid;
        int ret = pthread_create(&pid, NULL, chat, (void *) &conn);
        if (ret != 0)
            ERR_EXIT("ptread_create");
//		ret = pthread_join(pid, &thread_ret);
//		if(ret!=0)
//			ERR_EXIT("ptread_join");
//		printf("%s\n",(char*)thread_ret);
    }
    close(listenfd);
    ClearClient();
    printf("service close!\n");
}