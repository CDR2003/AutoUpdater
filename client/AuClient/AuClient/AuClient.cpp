#include "AuClient.h"
#include <curl/curl.h>
#include <cassert>
#include <iostream>


const std::string AuClient::UpdateInfoUrl = "/info.json";


AuClient::AuClient( const std::string & host, const std::string & downloadPath )
	: mCurl( NULL )
	, mHost( host )
	, mDownloadPath( downloadPath )
{
	mCurl = curl_easy_init();
	assert( mCurl );
}


AuClient::~AuClient()
{
	curl_easy_cleanup( mCurl );
}


void AuClient::Start()
{
	std::string url = mHost + UpdateInfoUrl;
	curl_easy_setopt( mCurl, CURLOPT_URL, url.c_str() );
	curl_easy_setopt( mCurl, CURLOPT_WRITEFUNCTION, OnUpdateInfo );
	curl_easy_setopt( mCurl, CURLOPT_WRITEDATA, this );

	CURLcode result = curl_easy_perform( mCurl );
	if( result != CURLE_OK )
	{
		std::cerr << "Error: curl_easy_perform()" << std::endl;
		std::cerr << curl_easy_strerror( result ) << std::endl;
	}
}


size_t AuClient::OnUpdateInfo( char * ptr, size_t size, size_t memoryBlockCount, void * param )
{
	AuClient * client = reinterpret_cast<AuClient*>( param );
	std::string str( ptr, size * memoryBlockCount );
	str += '\0';

	std::cout << "Data received: " << str << std::endl;

	return size * memoryBlockCount;
}