#include "service_client.h"

using namespace std;

RestClient::Response ServiceClient::list_service(/*string filters_json*/){
	string uri = this -> uri + "/services";
//	uri += param("filters", filters_json);

	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ServiceClient::create_service(string parameters){
	string uri = this -> uri + "/services/" + "create";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ServiceClient::inspect_service(string service_id){
	string uri = this -> uri + "/services/" + service_id;
	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ServiceClient::remove_service(string service_id){
	string uri = this -> uri + "/services/" + service_id;
	RestClient::Response ret = RestClient::del(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ServiceClient::update_service(string service_id, string parameters){
	string uri = this -> uri + "/services/" + service_id + "/update";
	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}