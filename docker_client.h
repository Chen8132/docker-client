#include <string>
#include <iostream>
#include <json/json.h>
#include "restclient.h"
using namespace std;

class DockerClient{
public:
	DockerClient():uri("http://127.0.0.1"){
		cout << "hello world!" << endl;
		RestClient::init();
	}
	DockerClient(string host):uri(host){
		RestClient::init();
	}
	virtual ~DockerClient(){
		RestClient::disable();
	}


	string param(string param_name, string param_value);

	string param(string param_name, const char* param_value);

	string param(string param_name, bool param_value);

	string param(string param_name, int param_value);

protected:
	string uri;

};