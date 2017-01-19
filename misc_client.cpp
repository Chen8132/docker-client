#include <iostream>
#include "misc_client.h"

RestClient::Response MiscClient::check_auth(string parameters){
	string uri = this->uri+"/auth";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::display_system_wide(){
	string uri = this->uri+"/info";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::show_docker_version(){
	string uri = this->uri+"/version";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::ping_docker_version(){
	string uri = this->uri+"/_ping";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::create_image_from_container(string container, string comment, string repo, string parameters){
	string uri = this->uri+"/auth";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::monitor_docker(){
	string uri = this->uri+"/events";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::get_images_f_repo(string name){
	string uri = this->uri+name +"/get";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::get_tarball(string parameters){
	string uri = this->uri+"/images/get";
	RestClient::Response ret = RestClient::post(uri, "application/x-tar", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::load_tarball_docker(string parameters){
	string uri = this->uri+"/images/load";
	RestClient::Response ret = RestClient::post(uri, "application/x-tar", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::exec_create(string name, string parameters){
	string uri = this->uri+"/containers/"+name+"/exec ";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::exec_start(string id, string parameters){
	string uri = this->uri+"/exec/"+id+"/start ";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::exec_resize(string id, string parameters){
	string uri = this->uri+"/exec/"+id+"/resize ";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response MiscClient::exec_inspect(string id, string parameters){
	string uri = this->uri+"/exec/"+id+"/json ";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}


