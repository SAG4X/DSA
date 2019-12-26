/*
sample input
1 2 1
1 3 2
2 4 3
2 3 4
3 4 5
4 6 4
5 2 3
*/
#define v 6
#include<bits/stdc++.h> 
#include<iostream>
using namespace std;



struct advert{
	int vert;
	int val;
	advert *next;
}
*start=NULL,*temp;

vector <advert> graph;

struct advert* search(int x){
	for(int i=0;i<graph.size();i++){
		if(graph[i].vert==x){
			if(graph[i].next==NULL){
				return &graph[i];
			}
			else{
				temp=&graph[i];
			}
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			return temp->next;
		}
	}
}
int addvert(int x){
	advert *newvert;
	newvert = new advert;
	newvert->next=NULL;
	newvert->val=0;
	newvert->vert=x;
	graph.push_back(*newvert);
	return 0;
}
int addadj(int y,int z){
	advert *newvert;
	newvert = new advert;
	newvert->next=NULL;
	newvert->val=z;
	newvert->vert=y;
	temp->next=newvert;
	return 0;
}
int bfs(int s){
	bool visited[v+1];
	for(int i=0;i<v+1;i++) visited[i]=false;
	vector<int> que;
	que.push_back(s);
	cout<<endl<<"BFS ->> ";
	while(que.empty()==false){
		s = que.front();
		que.erase(que.begin());
		visited[s]=true;
		cout<<s<<",";
		for(int i=0;i<v;i++){
			if(graph[i].vert==s){
				temp=graph[i].next;
				while(temp!=NULL){
					if(visited[temp->vert]==false){
						que.push_back(temp->vert);
						visited[temp->vert]=true;
					}
					temp=temp->next;
				}
				break;
			}
		}
		
		
	}
	cout<<endl<<endl;
}

int main(){
	int x,y,z;
	
	for(int i=0;i<7;i++){
		cin>>x>>y>>z;
		if(graph.empty()==true){
			addvert(x);
			temp=&graph.back();
			addadj(y,z);
		}
		else{
			if(temp = search(x)){
				addadj(y,z);
			}
			else{
				addvert(x);
				temp=&graph.back();
				addadj(y,z);
			}			
		}
		//indirect
		x+=y,y=x-y,x-=y;
		if(graph.empty()==true){
			addvert(x);
			temp=&graph.back();
			addadj(y,z);
		}
		else{
			if(temp = search(x)){
				addadj(y,z);
			}
			else{
				addvert(x);
				temp=&graph.back();
				addadj(y,z);
			}			
		}
	}
	///////////////////////////////////////////////////////////////////
	
	bfs(4);
	
	//print
	for(int i=0;i<graph.size();i++){
		cout<<graph[i].vert<<"_"<<graph[i].val<<"->> ";
		if(graph[i].next==NULL){
				continue;
		}
		else{
			temp=&graph[i];
		}
		while(temp->next!=NULL){
			temp=temp->next;
			cout<<temp->vert<<"_"<<temp->val<<" ";
		}
		cout<<endl;	
	}
	///
	return 555;
	
}

