#include "volume_client.h"

using namespace std;

RestClient::Response VolumeClient::list_volume(/*string filters_json*/){
	string uri = this -> uri + "/networks";
//	uri += param("filters", filters_json);

	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response VolumeClient::create_volume(string parameters){
	string uri = this -> uri + "/volumes/" + "create";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response VolumeClient::inspect_volume(string volume_name){
	string uri = this -> uri + "/volumes/" + volume_name;
	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response VolumeClient::remove_volume(string volume_name){
	string uri = this -> uri + "/volumes/" + volume_name;
	RestClient::Response ret = RestClient::del(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}