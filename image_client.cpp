#include <iostream>
#include "image_client.h"
RestClient::Response ImageClient::list_image(bool all){
	string uri = this->uri+"/images/json?";
	uri += param("all", all);
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::build_image(string file){
	string uri = this->uri+"/build";
	RestClient::Response ret = RestClient::post(uri, "application/tar", file);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::create_image(string from_Image, string latest){
	string uri = this->uri+"/images/create?";
	uri += param("from_Image", from_Image);
	uri += param("latest", latest);
	RestClient::Response ret = RestClient::post(uri, "application/json", "");
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::ispect_image(string image_name){
	string uri = this->uri+"/images/"+image_name+"/json";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::history_image(string image_name){
	string uri = this->uri+"/images/"+image_name+"/history";
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::tag_image(string image_name, string repo, string tag){
	string uri = this->uri+"/images/"+image_name+"/tag?";
	uri += param("repo", repo);
	uri += param("tag", tag);
	RestClient::Response ret = RestClient::post(uri, "application/json", "");
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::remove_image(string image_name){
	string uri = this->uri+"/images/"+image_name;
	RestClient::Response ret = RestClient::del(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::search_image(string term){
	string uri = this->uri+"/images/search?";
	uri += param("term", term);
	RestClient::Response ret = RestClient::get(uri);
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ImageClient::push_image(string image_name){
	string uri = this->uri+"/images/"+image_name+"/push?";
	RestClient::Response ret = RestClient::post(uri, "application/json", "");
	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}