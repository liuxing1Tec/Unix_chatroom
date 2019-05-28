#include "../include/usrmgr.h"

pClient head;

void InitLink() {
    head = (pClient) malloc(sizeof(Client)); //创建一个头结点
    if (head == NULL)
        ERR_EXIT("malloc");
    head->next = NULL;
}

pClient GetHeadNode() {
    return head;
}

void AddClient(pClient client) {
    client->next = head->next;
    head->next = client;
}

void RemoveClient(int fd) {
    pClient p = head->next;
    pClient pre = head;
    while (p != NULL) {
        if (p->conn == fd) {
            pre->next = p->next;
            free(p);
            break;
        }
        pre = p;
        p = p->next;
    }
}

pClient FindClient(int fd) {
    if (0 == fd)
        return NULL;
    pClient p = head->next;
    while (p != NULL) {
        if (fd == p->conn)
            break;
        p = p->next;
    }
    return p;
}

int CountConn() {
    int count = 0;
    pClient p = head->next;
    while (p != NULL) {
        p = p->next;
        ++count;
    }
    return count;
}

void ClearClient() {
    pClient p = head->next;
    while (p != NULL) {
        head->next = p->next;
        free(p);
        p = head->next;
    }
    free(head);
}

//void CheckConnection(){
//    	pClient p = head->next;
//    	while (p != NULL){
//		if (send(p->conn, "", sizeof(""), 0) == SOCKET_ERROR){
//			close(p->conn);
//			RemoveClient(p->conn);
//		}
//		p = p->next;
//	}
//}

