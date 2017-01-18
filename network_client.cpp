#include "network_client.h"
using namespace std;

RestClient::Response NetworkClient::list_network(string filters_json){
	string uri = this -> uri + "/networks?";
	uri += param("filters", filters_json);

	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response NetworkClient::inspect_network(string network_id){
	string uri = this -> uri + "/networks/" + network_id;
	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response NetworkClient::create_network(string parameters){
	string uri = this -> uri + "/networks/" + "create";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response NetworkClient::connect_container_network(string network_id, string parameters){
	string uri = this -> uri + "/networks/" + network_id + "/connect";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response NetworkClient::disconnect_container_network(string network_id, string parameters){
	string uri = this -> uri + "/networks/" + network_id + "/disconnect";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response NetworkClient::remove_network(string network_id){
	string uri = this -> uri + "/networks/" + network_id;
	RestClient::Response ret = RestClient::del(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}