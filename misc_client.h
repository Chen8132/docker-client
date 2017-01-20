#ifndef MISC_CLIENT_H
#define MISC_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"
using namespace std;
class MiscClient : public DockerClient{

public:
	MiscClient(string host) : DockerClient(host){};
	MiscClient() : DockerClient(){};
	RestClient::Response check_auth(string parameters);//lack query
	RestClient::Response display_system_wide();
	RestClient::Response show_docker_version();
	RestClient::Response ping_docker_version();
	RestClient::Response create_image_from_container(string container, string comment, string repo, string parameters);
	RestClient::Response monitor_docker();
	RestClient::Response get_images_f_repo(string name);
	RestClient::Response get_tarball(string parameters);
	RestClient::Response load_tarball_docker(string parameters);
	//RestClient::Response image_tarball_format();
	RestClient::Response exec_create(string name, string parameters);
	RestClient::Response exec_start(string id, string parameters);
	RestClient::Response exec_resize(string id, string parameters);
	RestClient::Response exec_inspect(string id, string parameters);

};
#endif