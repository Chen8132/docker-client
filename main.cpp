#include <iostream>
#include "container_client.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ContainerClient cc("http://127.0.0.1");
	cc.list_container(true, -1, "", "", -1);
	cc.inspect_container("thirsty_pare");

	return 0;
}