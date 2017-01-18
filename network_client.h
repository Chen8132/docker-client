#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"
using namespace std;
class NetworkClient : public DockerClient{

public:
	NetworkClient(string host):DockerClient(host){};
	NetworkClient():DockerClient(){};

	
	RestClient::Response list_network(string filters_json);
	RestClient::Response inspect_network(string network_id);
	RestClient::Response create_network(string parameters);
	RestClient::Response connect_container_network(string network_id, string parameters);
	RestClient::Response disconnect_container_network(string network_id, string parameters);
	RestClient::Response remove_network(string network_id);


};


#endif