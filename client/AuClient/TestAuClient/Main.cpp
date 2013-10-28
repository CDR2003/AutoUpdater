#include <iostream>
#include <cstdlib>
#include "AuClient.h"

using namespace std;


int main()
{
	AuClient * client = new AuClient();
	cout << "AuClient initialized." << endl;
	delete client;

	system( "PAUSE" );
	return 0;
}