#ifndef VOLUME_CLIENT_H
#define VOLUME_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"

class VolumeClient : public DockerClient{

public:
	VolumeClient():DockerClient(){};
	VolumeClient(string host):DockerClient(host){};

	RestClient::Response list_volume(/*string filters_json*/);
	RestClient::Response create_volume(string parameters);
	RestClient::Response inspect_volume(string volume_name);
	RestClient::Response remove_volume(string volume_name);

};


#endif