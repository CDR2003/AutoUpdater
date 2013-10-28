#include <iostream>
#include <cstdlib>
#include "AuClient.h"

using namespace std;


int main()
{
	AuClient * client = new AuClient( "http://127.0.0.1:4000", "res" );
	cout << "AuClient initialized." << endl;

	client->Start();

	system( "PAUSE" );
	return 0;
}