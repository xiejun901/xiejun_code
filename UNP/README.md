#本文件夹包含了unix network programming上的练习题目

###一个最基本的TCP回射客户服务器程序示例,[here](./回射客户服务器程序)

###IO复用的回射客户服务程序示例,[here](./IO复用)

本例采用select来复用stdin和sockfd，使得客户端不会因为阻塞在标准输入而无法立马接收到服务器已经关闭的信息，同时采用了半关闭shutdown(fd,SHUT_SR)来保证服务器发送的数据能完全接收。

服务器端采用select而不是fork生成子进程的方式来处理多个连接，将每个连接加入select监控中，然后通过对比来判断是哪个客户端发送来的消息并回射

###udp回射客户服务器程序示例,[here](./UDP回射客户服务器程序)

###采用select同时回射TCP,UDP的服务器程序示例,[here](./采用select同时回射TCP,UDP的服务程序)

###非阻塞I/O客户程序示例,[here](./非阻塞IO)