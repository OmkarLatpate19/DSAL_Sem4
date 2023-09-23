#include<iostream>
using namespace std;

class Tree{
	int a[10][10] , l, u, w, e, v, i, j, visited[10];
	
	public :
		void input();
		void display();
		void minimum();
};

void Tree :: input(){
	cout<<"Enter number of vertices(Nodes) :";
	cin>>v;
	for(i=0 ; i<v ; i++){
		visited[i]=0;
		for(j=0 ; j<v ; j++){
			a[i][j] = 999;
		}
	}

	cout<<"Enter number of edges :";
	cin>>e;
	for(i=0 ; i<e ; i++){
		
		cout<<"Enter end vertices of edges :"<<endl;
		cin>>l>>u;
	
		cout<<"Enter weight of edge :";
		cin>>w;

		a[l-1][u-1] = a[u-1][l-1] = w;
	}
} 

void Tree::display() {
    cout << "--------Adjacency Matrix--------" << endl;
    for (i = 0; i < v; i++) {
        cout << endl;
        for (j = 0; j < v; j++) {
            cout << a[i][j] << "\t";
        }
    }
    cout << endl;
}

void Tree :: minimum(){
	int p=0, q=0 , total=0, min;
	visited[0]=1;
	for(int c = 0 ; c<(v-1) ; c++){
		min = 999;
		for( i =0 ; i<v ; i++){
			if(visited[i]==1){
				for(j=0 ; j<v ; j++){
					if(visited[j] != 1){
						if( min > a[i][j]){
							min = a[i][j];
							p=i;
							q=j;
						}
					}
				}	
			}
		}
		visited[p]=1;
		visited[q]=1;
		total += min;
		cout<<"Minimum cost edge is "<<p+1<<" --> "<<q+1<<" with weight is :"<<min<<endl;
	}
	cout<<"Minimum cost of Minimum Spanning Tree is "<<total;
}

int main()
{
    int ch;
    Tree t;
    do
    {
        cout << "\n1.INPUT GRAPH \n2.DISPLAY ADJ_MAT \n3.MINIMUM SPANNIG TREE\n"<< endl;
        cout << "Enter your choice :";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "INPUT VERTICES, EDGES AND WEIGHT OF EDGES" << endl;
            t.input();
            break;

        case 2:
            cout << "DISPALY ADJACENCY MATRIX" << endl;
            t.display();
            break;

        case 3:
            cout << "MINIMUM SPANNING TREE" << endl;
            t.minimum();
            break;

	 case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
			
        }

    } while (ch != 4);
    return 0;
}