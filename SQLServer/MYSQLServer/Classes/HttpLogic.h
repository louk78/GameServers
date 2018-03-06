#ifndef __HttpLogic_SCENE_H__
#define __HttpLogic_SCENE_H__

#include "stdafx.h"

struct SQLInfo
{
	string _name;
	string _pass;
	string _ip;
	int _port;
	string _db;
};

class HttpLogic
{
public:
	HttpLogic();
	~HttpLogic();
    virtual bool init();
	static HttpLogic *getIns();
	void HandleLogic(YMSocketData sd, char *&buff, int &sz);
	SQLInfo *getSQLInfo(){
		return m_pSQLInfo;
	}
	int aes_encrypt(char* in, int inlen, char* key, char* out);
	int aes_decrypt(char* in, int inlen, char* key, char* out);
private:
	void SqlStart(YMSocketData sd, char *&buff, int &sz);
	void SqlClose(char *&buff, int &sz);
	void SelectDB(string dbname, char *&buff, int &sz);
	void SelectTableData(string tname, char *&buff, int &sz);
	void SqlConnect(char *&buff, int &sz);
	void SqlColumns(string tname, char *&buff, int &sz);
	void SqlFind(YMSocketData sd, char *&buff, int &sz);
	void SqlExcute(YMSocketData sd, char *&buff, int &sz);

	string encryptStringFromProto(::google::protobuf::Message* msg);
	void decryptStringFromProto(string keyvalue, int sz,::google::protobuf::Message* msg);

	string encryptStringFromString(string in, int sz);
	string decryptStringFromString(string in, int sz);
private:
	static HttpLogic *m_Ins;
	SQLInfo *m_pSQLInfo;
public:
	
};

#endif 