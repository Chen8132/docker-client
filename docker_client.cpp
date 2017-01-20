#include "docker_client.h"

using namespace std;

string DockerClient::param( string param_name, string param_value){
	if(!param_value.empty()){
		return "&" + param_name + "=" + param_value;
	}
	else{
		return "";
	}
}

string DockerClient::param( string param_name, const char* param_value){
	if(param_value != NULL){
		return "&" + param_name + "=" + param_value;
	}
	else{
		return "";
	}
}

string DockerClient::param(string param_name, bool param_value){
	string ret;
	ret = "&" + param_name + "=";
	if(param_value){
		return ret + "true";
	}
	else{
		return ret + "false";
	}
}

string DockerClient::param(string param_name, int param_value){
	if(param_value != -1){
		ostringstream convert;
		convert << param_value;
		return "&" + param_name + "=" + convert.str();
	}
	else{
		return "";
	}
}