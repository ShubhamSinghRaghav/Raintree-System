#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<dirent.h>
using namespace std;

vector<string> dirs(){
	DIR *dir;
	struct dirent *ent;
	vector<string> res;
	if ((dir = opendir ("logs\\")) != NULL) {
 		while ((ent = readdir (dir)) != NULL) {
 			string save = "logs";
			save +="\\\\";
			save += ent->d_name;
    		res.push_back(save);
		}
  	closedir (dir);
	} 
    return res;
}
string date_name(string s){
	string save = "";
	save+=s[12];save+=s[13];
	save+="-";
	save+=s[10];save+=s[11];
	save+="-";
	save+=s[6];save+=s[7];save+=s[8];save+=s[9];
	return save;
}
int main(){
	vector<string> dirtry = dirs();
//    for(int i=2;i<dirtry.size();i++){
//		cout<<dirtry[i]<<"\n";
//	}
    cout<<dirtry[4].size();
    cout<<date_name(dirtry[4]);
	return 0;
}


//		for(map<string,node>::iterator it=mp.begin();it!=mp.end();it++){
//			cout<<it->first<<"=>"<<it->second.disconnect<<"=>"<<it->second.average<<"=>"<<it->second.drop;
//			cout<<endl;
//    	}
