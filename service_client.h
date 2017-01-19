#ifndef SERVICE_CLIENT_H
#define SERVICE_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"
class ServiceClient : public DockerClient{

public:
	ServiceClient():DockerClient(){};
	ServiceClient(string host):DockerClient(host){};

	RestClient::Response list_service(/*string filters_json*/);
	RestClient::Response create_service(string parameters);
	RestClient::Response inspect_service(string service_id);
	RestClient::Response remove_service(string service_id);
	RestClient::Response update_service(string service_id, string parameters);

};


#endif