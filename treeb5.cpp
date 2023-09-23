#include<iostream>
using namespace std;

struct node{
	char label[10];
	int count;
	struct node *child[10];
} *root;

class Book{
	public:
		void create_tree();
		void display_tree(node *r1);
		Book(){
			root = NULL;
		}
};

void Book :: create_tree(){
	int chapter, i, j, k;
	root = new node;
	cout<<"Enter name of Book :";
	cin>>root->label;
	cout<<"Enter No of chapters in Book :";
	cin>>root->count;
	for( i = 0 ; i < root->count ; i++){

		root->child[i] = new node;
		cout<<"Enter name of Chapter :";
		cin>>root->child[i]->label;
		cout<<"Enter No of section in chapter :";
		cin>>root->child[i]->count;

		for( j = 0 ; j < root->child[i]->count ; j++){

			root->child[i]->child[j] = new node;
			cout<<"Enter section "<<j+1<<"  name :";
			cin>>root->child[i]->child[j]->label;
			cout<<"Enter No of subsection in section :";
			cin>>root->child[i]->child[j]->count;
				
			for( k = 0 ; k < root->child[i]->child[j]->count ; k++){

			root->child[i]->child[j]->child[k] = new node;
			cout<<"Enter subsection "<<k+1<<"  name :";
			cin>>root->child[i]->child[j]->child[k]->label;

			}
			
		}

	}

}

void Book :: display_tree( node *r1){
	int i, j, k;
	if( r1 != NULL ){
		cout<<"-------------------Book Hierarchy-------------------"<<endl;
		cout<<"Book Title :"<<r1->label<<endl;

		for( i = 0 ; i < r1->count ; i++){
			cout<<"Chapter "<<i+1<<" Name :"<<endl;
			cout<<r1->child[i]->label<<endl;

			for( j = 0 ; j < r1->child[i]->count ; j++){
				cout<<"Section "<<j+1<<" Name :"<<endl;
				cout<<r1->child[i]->child[j]->label<<endl;

				for( k = 0 ; k < r1->child[i]->child[j]->count ; k++){
					cout<<"Subsection "<<k+1<<" Name :"<<endl;
					cout<<r1->child[i]->child[j]->child[k]->label<<endl;
				}
			}
			cout<<endl; 	 
		}
	}
	


}
int main()
{
    int choice;
    Book gt;
    while (1)
    {
        cout << "\nBook tree creation" << endl;
        cout << "\n1.create" << endl;
        cout << "2.display" << endl;

        cout << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;

        case 2:
            gt.display_tree(root);
            break;

        case 3:
            cout << "Program ended";
            break;

        default:
            cout << "Wrong choice" << endl;
        }
    }
}