//
// p2pchat.c
// C_Learning
//
// Created by Vousmevoyez Liu on 2019/5/12.
//
// Description:
// 点对点聊天 C/S模型 全双工通信聊天工具设计

#include "../include/chatcli.h"

int sockfd;

void init() {
    if ((sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        ERR_EXIT("socket");

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
        ERR_EXIT("connect");
    printf("client start!\n");
}

void start(char *usrname) {
    send(sockfd, usrname, strlen(usrname), 0);
    pid_t pid;
    pid = fork();
    if (pid == -1) {
        ERR_EXIT("fork");
    } else if (pid == 0) {
        char recvbuf[MSGLENGTH];
        while (1) {
            bzero(&recvbuf, sizeof(recvbuf));
            int ret = read(sockfd, recvbuf, sizeof(recvbuf));
            if (ret == -1) {
                ERR_EXIT("read");
            } else if (ret == 0) {
                printf("peer close\n");
                break;
            } else {
                fputs(recvbuf, stdout);
            }
        }
        printf("child close\n");
        kill(getppid(), SIGKILL);
        close(sockfd);
    } else {
//		struct sockaddr_in localaddr;
//		socklen_t locallen = sizeof(localaddr);
//		if (getsockname(sockfd, (struct sockaddr*)&localaddr, &locallen) < 0)
//			ERR_EXIT("getsocketname");
        char sendbuf[MSGLENGTH];
//		char temp[MSGLENGTH];
//		sprintf(temp, "%s:online,from(%s:%d)\n", usrname, inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port));
//		write(sockfd, temp, strlen(temp));
//		bzero(&temp, sizeof(temp));
        while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
//			sprintf(temp, "%s:%s", argv[1], sendbuf);
            write(sockfd, sendbuf, strlen(sendbuf));
            bzero(&sendbuf, sizeof(sendbuf));
//			bzero(&temp, sizeof(temp));
        }
        kill(pid, SIGKILL);
        printf("parent close\n");
        close(sockfd);
    }
}


