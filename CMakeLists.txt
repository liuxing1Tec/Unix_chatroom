cmake_minimum_required(VERSION 3.10.2)
project(Unix_chatroom C)

set(CMAKE_C_STANDARD 99)

include_directories(cli/include)
include_directories(srv/include)

add_executable(client.out
        cli/include/chatcli.h
        cli/src/chatcli.c
        cli/main.c)
add_executable(service.out
        srv/include/chatsrv.h
        srv/src/chatsrv.c
        srv/src/usrmgr.c
        srv/main.c)

TARGET_LINK_LIBRARIES(service.out
        pthread)
