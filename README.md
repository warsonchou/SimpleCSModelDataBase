需求：使用shm和fork，编写一个多进程的单棵平衡树数据库。服务器监听，
然后客户端fork，读写shm。

c/s模型：

单个服务器（数据库）
多个客户端（用socket连接读写）
（服务器进程+fork子进程handle客户端的连接，如bbsd代码）

数据库语言：
0A[i] // 插入一个数i到数据库中
G[r] // 取出第r大的数
D[i] // 删除数i
P    // 输出有多少个建立的客户端

为了方便，可以使用文件锁来做全局锁。不用考虑数值的位数等底层问题。

此需求涉及到多方面的内容，需要比较久时间来实现，这里讲一下基本的实现思路

实现语言：c和c++

服务端：
1.数据库的实现，使用b-tree来实现数据库，涉及到数据库的b-tree的实现，同时涉及到文件操作，现在实现状况是知道b-tree的实现原理和基本实现思路，可参考这里(http://blog.csdn.net/hguisu/article/details/7786014), 然后编写了b-tree要实现的方法，其中头文件已经定义(尚未考虑文件读写)但cpp文件为实现
2.数据库多进程共享内存处理多个并发的客户端请求，主要使用的是c里面的<sys/shm.h>,基本实现共享内存操作，可参考这里(http://github.tiankonguse.com/blog/2015/09/03/shm-study.html和https://github.com/tiankonguse/shm-cache/blob/master/test/shm/fork/fork.cpp)
3.实现多进程，使用的是比较简单的fork函数来实现，可参考这里（http://blog.csdn.net/wschq/article/details/11923193），这个比较简单
4.还有很重要的一点就是多进程就可能发生资源竞争，所以需要锁来解决问题，但是发生资源竞争有文件读写的竞争而已(师兄提示使用文件锁来实现，之前有使用信号量来实现过)，共享内存是否存在竞争，目前尚未弄清楚。

服务端和客户端的数据交互：
1.使用的是socket通讯，参考这里（http://www.linuxhowtos.org/C_C++/socket.htm），服务端使用到的函数有<sys/socket.h>里面的 socket()，bind()，listen()，accept()，这里使用的是长轮询的方法接受客户端的请求，
2.客户单使用的也是socket通讯，参考这里（http://www.linuxhowtos.org/C_C++/socket.htm），使用到的是<sys/socket.h>里面的socket()：创建socket的，connect()：建立socket连接，read()和write()：进行数据读写到socket里面去。

总结：里面的东西都听说，而且之前也了解过其原理，但是都没有实战经验，实现起来有点困难，因为接触各方面的知识比较多。