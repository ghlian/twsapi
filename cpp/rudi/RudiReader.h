﻿#pragma once

class RudiClient;
class EDecoder;
struct read_buf;

class TWSAPIDLLEXP RudiReader
{
public:
	RudiReader(RudiClient *clientSocket);
	~RudiReader(void);

	bool processNonBlockingSelect();
	void select_timeout( int msec );
	void onReceive();

private:
	void readV100Plus();
	int decode_one_msg(const char* begin, uint32_t size);

	RudiClient *m_pClientSocket;
	EDecoder *decoder;
	struct read_buf *m_buf;
};
