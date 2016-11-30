/*************************************************************************
 > File Name: bTree.h
 > Desc: 使用cs模型，进行socket连接之后，实现客户端连接server进行数据库基本的操作
 > Author: guocheng
 > Mail: 1129134022@qq.com
 > Created Time: 2016-10-29
 from http://www.linuxhowtos.org/C_C++/socket.htm
 ***********************************************************************/

#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <string>
using namespace std;

	class client {
	public:
		client(string serverAddr, string port);

	private:
		string serverAddr;
		string port;
	};
#endif