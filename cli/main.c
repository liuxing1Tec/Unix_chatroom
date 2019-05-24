//
// Created by Vousmevoyez 刘 on 2019-05-24.
//
#include "include/chatcli.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ERR_EXIT("usage: a.out <USER_NAME>");
        return 1;
    }
    init();
    start(argv[1]);
    return 0;
}
