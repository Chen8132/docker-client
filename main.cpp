#include <iostream>
#include "container_client.h"
#include "network_client.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ContainerClient cc;
	cc.list_container(true, -1, "", "", -1);
	cc.inspect_container("thirsty_pare");
	NetworkClient nn;
	nn.list_network("{\"type\":{\"custom\":true}}");

	return 0;
}