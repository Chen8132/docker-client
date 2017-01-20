#ifndef IMAGE_CLIENT_H
#define IMAGE_CLIENT_H

#include "restclient.h"
#include <string>
#include <vector>
#include <json/json.h>
#include "docker_client.h"
using namespace std;
class ImageClient : public DockerClient{

public:
	ImageClient(string host) : DockerClient(host){};
	ImageClient() : DockerClient(){};
	RestClient::Response list_image(bool all=0);//lack query
	RestClient::Response build_image(string file);//lack query
	RestClient::Response create_image(string from_Image, string latest);
	RestClient::Response ispect_image(string image_name);
	RestClient::Response history_image(string image_name);
	RestClient::Response tag_image(string image_name, string repo, string tag);
	RestClient::Response remove_image(string image_name);
	RestClient::Response search_image(string term);
	RestClient::Response push_image(string image_name);
};
#endif