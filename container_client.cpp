#include <iostream>
#include "container_client.h"

RestClient::Response ContainerClient::list_container(bool all, int limit, string since, string before, int size){
	string uri = this -> uri + "/containers/"+ "json?";
	uri += param("all", all);
	uri += param("limit", limit);
	uri += param("since", since);
	uri += param("before", before);
	uri += param("size", size);

	RestClient::Response ret = RestClient::get(uri);

	cout << "response code: " << ret.code << endl;
	cout << "response body: " << ret.body << endl;

	return ret;
}

RestClient::Response ContainerClient::create_container(string parameters){
	string uri = this->uri + "/containers/"+"create";
    RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

    cout<<"response code: "<<ret.code<<endl;
    cout<<"response body: "<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::inspect_container(string container_id){
    string uri = this->uri + "/containers/"+ container_id + "/json";
    RestClient::Response ret = RestClient::get(uri);

    cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::top_container(string container_id){
    string uri = this->uri + "/containers/"+ container_id + "/top";
    RestClient::Response ret = RestClient::get(uri);

    cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::logs_container(string container_id, bool follow, bool o_stdout, bool o_stderr, bool timestamps, string tail){
    string uri =  this->uri + "/containers/"+ container_id + "/logs?";
    uri += param("follow", follow);
    uri += param("stdout", o_stdout);
    uri += param("stderr", o_stderr);
    uri += param("timestamps", timestamps);
    uri += param("tail", tail);
    
    RestClient::Response ret = RestClient::get(uri);

    cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::inspect_container_changes(string container_id){
    string uri = this->uri + "/containers/"+ container_id + "/changes";
    RestClient::Response ret = RestClient::get(uri);

    cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::export_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/export";
 	RestClient::Response ret = RestClient::get(uri);

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::get_container_stats(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/stats";
 	RestClient::Response ret = RestClient::get(uri);

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::resize_container_tty(string container_id, int h, int w){
 	string uri = this -> uri + "/containers/"+ container_id + "/resize?";
 	uri += param("h", h);
 	uri += param("w", w);

 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::start_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/start";
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::stop_container(string container_id, int time){
 	string uri = this -> uri + "/containers/"+ container_id + "/stop?";
 	uri += param("t", time);
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::restart_container(string container_id, int time){
 	string uri = this -> uri + "/containers/"+ container_id + "/restart?";
 	uri += param("t", time);
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::kill_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/kill";
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::update_container(string container_id, string parameters){
 	string uri = this -> uri + "/containers/"+ container_id + "/update";
 	RestClient::Response ret = RestClient::post(uri, "application/json", parameters);

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::rename_container(string container_id, string new_name){
 	string uri = this -> uri + "/containers/"+ container_id + "/rename?";
 	uri += param("name", new_name);
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::pause_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/pause";
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::unpause_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/unpause";
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::attach_container(string container_id, int logs, int stream, int stdout){
 	string uri = this -> uri + "/containers/"+ container_id + "/attach?";
 	uri += param("logs", logs);
 	uri += param("stram", stream);
 	uri += param("stdout", stdout);

 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::wait_container(string container_id){
 	string uri = this -> uri + "/containers/"+ container_id + "/wait";
 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::remove_container(string container_id, bool if_remove_volumes){
 	string uri = this -> uri + "/containers/"+ container_id + "/remove?";
 	uri += param("v", if_remove_volumes);

 	RestClient::Response ret = RestClient::post(uri, "application/json", "");

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::archieve_in_container(string container_id, string path){
 	string uri = this -> uri + "/containers/"+ container_id + "/archive?";
 	uri += param("path", path);

 	RestClient::Response ret = RestClient::get(uri);

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

RestClient::Response ContainerClient::extract_container(string container_id, string path, string tar_stream){
 	string uri = this -> uri + "/containers/"+ container_id + "/archive?";
 	uri += param("path", path);

 	RestClient::Response ret = RestClient::put(uri, "application/x-tar", tar_stream);

 	cout<<"response code:"<<ret.code<<endl;
    cout<<"response body:"<<ret.body<<endl;
    return ret;
}

