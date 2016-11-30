/*************************************************************************
 > File Name: bTree.h
 > Desc: 使用cs模型，server端，实现socket监听，实现对客户端的请求进行数据库操作
 > Author: guocheng
 > Mail: 1129134022@qq.com
 > Created Time: 2016-10-29
 from http://www.linuxhowtos.org/C_C++/socket.htm
 ***********************************************************************/

#ifndef _SERVER_H_
#define _SERVER_H_
#include <string>
using namespace std;

	class server {
	public:
		server();

	private:
		int clientNumber;
		string clientAddr;
		
	};
#endif
