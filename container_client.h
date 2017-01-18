#ifndef CONTAINER_CLIENT_H
#define CONTAINER_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"
using namespace std;


class ContainerClient : public DockerClient {

public:
	ContainerClient():DockerClient(){};
	ContainerClient(string host):DockerClient(host){};



	RestClient::Response list_container(bool all, int limit, string since, string before, int size);
	RestClient::Response create_container(string parameters);
	RestClient::Response inspect_container(string container_id);
	RestClient::Response top_container(string container_id);
	RestClient::Response logs_container(string container_id, bool follow, bool o_stdout, bool o_stderr, bool timestamps, string tail);
	RestClient::Response inspect_container_changes(string container_id);
	RestClient::Response export_container(string container_id);
	RestClient::Response get_container_stats(string container_id);
	RestClient::Response resize_container_tty(string container_id, int h, int w);
	RestClient::Response start_container(string container_id);
	RestClient::Response stop_container(string container_id, int time);
	RestClient::Response restart_container(string container_id, int time);
	RestClient::Response kill_container(string container_id);
	RestClient::Response update_container(string container_id, string parameters);
	RestClient::Response rename_container(string container_id, string new_name);
	RestClient::Response pause_container(string container_id);
	RestClient::Response unpause_container(string container_id);
	RestClient::Response attach_container(string container_id, int logs, int stream, int stdout);
	RestClient::Response wait_container(string container_id);
	RestClient::Response remove_container(string container_id, bool if_remove_volumes);
	RestClient::Response archieve_in_container(string container_id, string path);
	RestClient::Response extract_container(string container_id, string path, string tar_stream);

};


#endif
