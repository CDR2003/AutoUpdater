#pragma once
#include <string>
#include <curl/curl.h>


class AuClient
{
public:
	AuClient( const std::string & host, const std::string & downloadPath );
	~AuClient();

	void								Start();

private:
	static const std::string			UpdateInfoUrl;

	static size_t						OnUpdateInfo( char * ptr, size_t size, size_t memoryBlockCount, void * param );

	CURL *								mCurl;
	std::string							mHost;
	std::string							mDownloadPath;
};
