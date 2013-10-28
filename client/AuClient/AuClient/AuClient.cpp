#include "AuClient.h"
#include <curl/curl.h>
#include <cassert>


AuClient::AuClient()
{
	CURLcode code = curl_global_init( CURL_GLOBAL_WIN32 );
	assert( code == CURLE_OK );
}


AuClient::~AuClient()
{
	curl_global_cleanup();
}
