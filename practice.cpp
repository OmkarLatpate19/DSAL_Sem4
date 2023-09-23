/*
#include<iostream>
#define max 10
using namespace std;

class Priority_Queue{
	private:
		string queue[max];
		int priority_val[max];
		int front;
		int rear;

	public:
			
		Priority_Queue(){
			front = -1;
			rear = -1;
		}
		
		bool isEmpty() { return front == -1; }
		
		bool isFull(){ return rear == max-1;  }
		
		void enqueue(string data, int priority){
			
			if(isFull()){
				cout<<"Queue is Full "<<endl;
			}
			if( isEmpty()){
				front = 0;
				rear = 0;
				queue[rear] = data;
				priority_val [rear]= priority;
			}
			else{
				int i ;
				rear++;
				for( i= rear-1 ; i>=front ; i--){
					if(priority_val[i]<priority){		
						queue[i+1]=queue[i];
						priority_val[i+1]=priority_val[i];
					}
					else{
						queue[i+1]=data;
						priority_val[i+1]=priority;
						break;
					}
					queue[i+1]=data;
					priority_val[i+1]=priority;
				}
			}
		}

		string dequeue(){
			
			if(isEmpty()){
				cout<<"Queue is empty !!"<<endl;
			}
			string data = queue[front];
			if( front == rear){
				front=-1;
				rear=-1;
			}
			else{
				front++;
			}
			return data;
		}

		int getPriority(){
			if(isEmpty()){
				return -1;
			}
			return priority_val[front];
		}

		int display(){
			if(isEmpty()){
				return -1;
			}
			else{
				cout<<"Patient\t\tPriority"<<endl;
				for(int i=front ; i<=rear ; i++){
					cout<<queue[i]<<"\t\t"<<priority_val[i]<<endl;
				}
				cout<<endl;
			}
			
		}
};

int main(){
	
	Priority_Queue p;
	int ch = 0;
	string name;
	int priority;
	
	cout<<"\nPriority :- for general check up 0, for non serious patient 1, for serious patient 2\n"<<endl;

	do{
		cout<<"\nMENU\n1.Add Patient\n2.Remove Patient\n3.Display\n4.Exit\n\nEnter your choice :";
		cin>>ch;

		switch(ch){
			case 1:
				cout<<"Enter name of patient :";
				cin>>name;
				cout<<"Enter priority :";
				cin>>priority;
				p.enqueue(name,priority);
				cout<<"Patient Added"<<endl;
				break;

			case 2:
				name = p.dequeue();
				priority=p.getPriority();
				cout<<"Patient "<<name<<" discharged !!"<<endl;
				break;

			case 3:
				cout<<"Patient Queue is :"<<endl;
				p.display();
				break;

			case 4:
  				cout<<"Extting , Thank You !!"<<endl;
				break;					
		}
	}while(ch != 4);
	return 0;	
}
*/




#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#define MAX 10
using namespace std;

int v;
int adj_mat[MAX][MAX] = {0};
vector<vector<int>>adj_list = {{}};

void dfs ( int mat[MAX][MAX]){
	
	bool visited[MAX] = {false};
	stack<int>s;
	s.push(0);

	while(!s.empty()){
		
		int t =s.top();
		if(visited[t] == false ){
			cout<<t<<" ";
		}	
		visited[t] =true;
		bool flag = false;
		for( int i =0 ; i<v ; i++){
			if( adj_mat[t][i] == 1 && visited[i] == false){
				s.push(i);
				flag = true;
				break;
			}
		}
		if(!flag){
			s.pop();
		}
	}
}

void bfs(){

	bool visited[MAX] = {false};
	queue<int>q;
	q.push(0);
	visited[0]=true;

	while(!q.empty()){
		
		int t=q.front();
		cout<<t<<" ";
		q.pop();

		for( int i=0 ; i<adj_list[t].size() ; i++){
			if( visited[adj_list[t][i]] == false){
				visited[adj_list[t][i]] = true;
				q.push(adj_list[t][i]);
			}	
		}
	}
}

int main(){
	int e, i, j;
	cout<<"Enter number of vertices :";
	cin>>v;
	for(int i=0 ; i<v ; i++){
		adj_list.push_back({});
	}
	cout<<"Enter number of edges :";
	cin>>e;
	for(int c=0 ; c<e ; c++){
		cout<<"Enter vertices of edge "<<c+1<<endl;
		cin>>i>>j;
		adj_mat[i][j]=1;
		adj_mat[j][i]=1;
		adj_list[i].push_back(j);
		adj_list[j].push_back(i);
	}
	
	cout<<"------Adjacency Matrix------"<<endl;
	for(int i =0 ; i<v ; i++){
		for(int j =0 ;j<v ; j++){
			cout<<adj_mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"------Adjacency List------"<<endl;
	for(int i= 0 ; i<v ; i++){
		cout<<i<<"->";
		for(int j=0 ; j<adj_list[i].size() ; j++){
			cout<<adj_list[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"\n------DFS------"<<endl;
	dfs(adj_mat);
	cout<<"\n------BFS------"<<endl;
	bfs();

	return 0;
}





















