#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<dirent.h>
using namespace std;
struct node{
	int disconnect;
	int drop;
	int average;
	newnode(){
		disconnect=0;
		drop=0;
		average=0;
	}
};

struct fino{
	int drop;
	int disconnect;
	int avg;
	string nam;
};

vector<string> splitter(string ss){
    vector<string> input;
	int pos = 0, word = 0,len=0;
	for(int i=0;i<ss.size();i++){
	    len++;
	    if(ss[i]==' '){
	       input.push_back(ss.substr(pos,len-1));
	       len=0;
	       pos=i+1;
	    }
	}
	return input;
}

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
//Date Calculation
string date_name(string s){
	string save = "";
	save+=s[12];save+=s[13];
	save+="-";
	save+=s[10];save+=s[11];
	save+="-";
	save+=s[6];save+=s[7];save+=s[8];save+=s[9];
	return save;
}

//sort by drops
bool compare1(fino a,fino b){
	return a.drop > b.drop;
}

//sort by disconnects
bool compare2(fino a,fino b){
	return a.disconnect > b.disconnect;
}

//sort by average
bool compare3(fino a,fino b){
	return a.avg > b.avg;
}


int main(){
	fstream f("solution.txt", f.out);
	vector<string> savior;
	vector<string> drty = dirs();
	int skipper=1;
	for(auto dirname:drty){
		if(skipper<3){
			skipper++;
			continue;
		}
		std::ifstream input(dirname);
		map<string,node> mp;
		vector<string> namo;
		for( std::string line; getline( input, line ); ){
			if(line.length()==0)continue;
			vector<string> all = splitter(line);
		    string name = all[1].substr(13);
		    node check;
			check.newnode();
			mp.insert(make_pair(name,check));
		    for(int i=0;i<all.size();i++){
		    	if(all[i]=="Average"){
		    		mp[name].average++;
		    		break;
				}if(all[i]=="Drop"){
					mp[name].drop++;
					break;
				}if(all[i]=="disconnected"){
					mp[name].disconnect++;
					break;
				}
		    }	
		}
		fino comp[mp.size()];
		int q=0;
		for(map<string,node>::iterator it=mp.begin();it!=mp.end();it++){
			comp[q].nam = it->first;
			comp[q].drop = it->second.drop;
			comp[q].avg = it->second.average;
			comp[q].disconnect = it->second.disconnect;
			q++; 
    	}
        //Date Display
        f << date_name(dirname)<<"\n\n";
		//Storing Drops on Particular Date
	    f<<"Computer Name     No of Drops\n";
		sort(comp,comp+q,compare1);
		for(int ii=0;ii<q;ii++){
			if(comp[ii].drop==0)break;
			f<<comp[ii].nam<<" "<<comp[ii].drop<<"\n";
		}
		f<<"Computer Name     No of Disconnects\n";
	    sort(comp,comp+q,compare2);
		for(int ii=0;ii<q;ii++){
			if(comp[ii].disconnect==0)break;
			f<<comp[ii].nam<<" "<<comp[ii].disconnect<<"\n";
		}
		
		f<<"Computer Name     No of Average Limit\n";
		sort(comp,comp+q,compare3);
		for(int ii=0;ii<q;ii++){
			if(comp[ii].avg==0)break;
			f<<comp[ii].nam<<" "<<comp[ii].avg<<"\n";
		}
		f<<"\n";
	}
	return 0;
}
