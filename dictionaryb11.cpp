#include<iostream>
#include<string>
using namespace std;

struct node{
	string key;
	string meaning;
	node *left = NULL;
	node *right = NULL;
} *root;

class Dictionary_Tree{
	public:
	Dictionary_Tree(){
		root = NULL;
	}

	node *Add(node *r , node*temp){
		if ( r == NULL){
			return temp;
		}

		if ( r->key > temp->key){
			r->left = Add(r->left , temp);
		}

		else{
			r->right = Add( r->right , temp);
		}
		return r;
	}

	node *minval(node *root){
		while ( root->left != NULL){
			root = root->left;	
		}
		return root;
	}

	node *Delete( node *r, string k){
	
		if ( r == NULL){
			return NULL;
		}
		if ( r->key == k){
			if( !r->left && !r->right){
				delete(r);
				return NULL;
			}

			if( r->left && !r->right){
				node *temp = r->left;
				delete(r);
				return temp;
			}

			if( !r->left && r->right){
				node *temp = r->right;
				delete(r);
				return temp;
			}

			if( r->left && r->right){
				node *rep = minval(r->right);
				r->key = rep->key;
				r ->meaning = rep->meaning;
				r->right = Delete(r->right , rep->key);
				return r;
			}
		}
		if( r->key > k){
			r->left = Delete(r->left , k);	
		}
		else{
			r->right = Delete(r->right, k);
		}
	} 

	void Display(node *r){
		if( r != NULL){
			Display(r->left);
			cout<<r->key<<" : "<<r->meaning<<endl;
			Display(r->right);
		}
	}

	node *Update( node*r , string t){
		if( r!=NULL){
			r -> meaning = t;
		}
		else
			cout<<"Invalid Input"<<endl;
	}

	node *Find( node*r , string k){
		
		while( r!=NULL){
		
			if( r->key == k){
				return r;
			}
			if( r->key > k){
				r = r -> left;
			}
			else{
				r = r -> right;
			}
		}
		return NULL;
	}
};

int main(){
	Dictionary_Tree d;
	string s,k;
	node *t;
	int ch;
	bool flag = true;
	
	while(flag){
		
		cout<<"\n----------MENU----------"<<endl;
		cout<<"1.Add Key"<<endl;
		cout<<"2.Delete Key"<<endl;
		cout<<"3.Update Meaning"<<endl;
		cout<<"4.Display Dictionary"<<endl;
		cout<<"5.Find Key"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		
		switch(ch){
			
			case 1:
				t = new node();
				cout<<"Enter key to add :";
				cin>>t->key;
				cout<<"Enter meaning :";
				cin>>t->meaning;
				if( root == NULL){
					root = t; 
				}
				else{
					d.Add(root , t);
				}
				break;

		case 2:
			cout<<"Enter key to delete :";
			cin>>k;
			d.Delete(root, k);
			break;

		case 3:
			cout<<"Enter key to update :";
			cin>>k;
			cout<<"Enter new meaning :";
			cin>>s;
			d.Update(d.Find(root, k),s);
			break;

		case 4:
			d.Display(root);
			cout<<endl;
			break;

		case 5:
			cout<<"Enter key to find :";
			cin>>k;
			t = d.Find(root, k);
			if( t != NULL){
				cout<<t->key<<" : "<<t->meaning;
			}
			else{
				cout<<"Not Present"<<endl;
			}
			break;
			
		case 6:
			flag = false;
			break;
		default:
			cout<<"Wrong choice !!"<<endl;
		}
	}
	return 0;
}