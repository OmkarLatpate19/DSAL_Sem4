#include<iostream>
using namespace std;
#define MAX 10
int find(int, int);
void print(int, int);
int p[MAX], q[MAX], w[10][10], c[10][10], r[10][10], i , j ,k , m , n;
char idnt[10][10];

int main(){
		
	cout<<"Enter number of identifiers :";
	cin>>n;
	cout<<"Enter Identifiers :"<<endl;
	for(i = 1 ; i <= n ; i++){
		cin>>idnt[i];
	}
	
	cout<<"Enter successful probability of search for Identifiers :"<<endl;
	for( i = 1 ;  i<=n ; i++){
		cin>>p[i];
	}

	cout<<"Enter unsuccessful probability of search for Identifiers :"<<endl;
	for( i = 0 ; i<=n ; i++){
		cin>>q[i];
	}
	
	cout<<"\nWeight\t\tCost\t\tRoot"<<endl;

	for( i=0 ; i<=n ; i++){
		w[i][i] = q[i];
		c[i][i] = r[i][i] = 0;
		cout<<"\n"<<w[i][i]<<"\t\t"<<c[i][i]<<"\t\t"<<r[i][j]<<endl;
	}
	cout<<"-----------------------------------------------------------------------"<<endl;

	for( i=0 ; i<n ; i++){
		j=i+1;
		w[i][j] = p[j] + q[j] + w[i][i];
		c[i][j] = w[i][j] +  c[j][j];
		r[i][j] = j;
		cout<<"\n"<<w[i][j]<<"\t\t"<<c[i][j]<<"\t\t"<<r[i][j]<<endl;
	}
	cout<<"-----------------------------------------------------------------------"<<endl;

	for( m=2 ; m<=n ; m++){
		for( i=0 ; i<=n-m ; i++){
			j = i+m ;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			k = find(i, j);
			c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
			r[i][j] = k;
			cout<<"\n"<<w[i][j]<<"\t\t"<<c[i][j]<<"\t\t"<<r[i][j]<<endl;
			cout<<"-----------------------------------------------------------------------"<<endl;
		}
	}
	cout<<"-----------------------------------------------------------------------"<<endl;

	cout<<"\n--------------------FINAL OBST--------------------"<<endl;
	print(0, n);
	return 0;
}

void print(int i, int j ){
	
	if ( i < j )
		cout<<"\n"<<idnt[r[i][j]]<<endl;
	else
		return;
	print(i , r[i][j] - 1 );
	print( r[i][j] , j);
}

int find(int i , int j){
	
	int min = 1000 , l, m ;
	for( m = i+1 ; m<=j ; m++){
		if( c[i][m-1] + c[m][j] < min){
			min = c[i][m-1] + c[m][j];
			l = m;
		}
	}
	return l;
}