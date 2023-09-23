#includ<iostream>
using namespace std;

class node{
	public:
		string key;
		string value;
		node *left;
		node *right;
		node( string key , string value){
			this->key = key;
			this->value = value;
			this->left = NULL;
			this->right = NULL;
		}
};

class AVL{

	node *root = NULL;
	int height(node *n){
		if( n == NULL ){
			return 0;
		}
		return 1 + max(height(n->left) , height(n->right));
	}

	int balanceFactor(node *n){
		if( n == NULL ){
			return 0;
		}
		return (height(n->left) - height(n->right));
	}

	node *leftRotate(node *x){
		
		node *y = x->right;
		node *t2 = y->left;
	
		x = y->left;
		t2 = x->right;

		return y;
	}

	node *rightRotate(node *y){
		
		node *x = y->left;
		node *t2 = x->right;
	
		y = x->right;
		t2 = y->left;

		return x;
	}

	node *insertion( node *temp ,string key, string value){

		if( temp == NULL){
			node *nn = new node(key, value)
			return nn;
		}
		if(key > temp->key){
			temp->right = insertion(temp->right ,key, value);
		}
		if(key < temp->key){
			temp->left = imsertion(temp->left, key, value);
		}
		
		int bf = balanceFactor(temp);
		
		if( bf>1 &&  balanceFactor(temp->left)>=0 ){
			return rightRotate(temp);
		}

		if( bf<-1 && balanceFactor(temp->right)>=0 ){
			return leftRotate(temp);
		}

		if( bf>1 && balanceFactor(temp->left)<0 ){
			temp->left = leftRotate(temp->left);
			return rightRotate(temp);
		}

		if( bf<-1 && balanceFactor(temp->right)>0){
			temp->right = rightRotate(temp->right);
			return leftRotate(temp);
		}
		return temp;

	}
	
	void ascending(node *n){
		if ( n != NULL){
			ascending(n->left);
			cout<<n->key<<" : "<<n->value;
			ascendint(n->right);
		}
	}

	void descending(node *n){
		if ( n != NULL){
			descending(n->left);
			cout<<n->key<<" : "<<n->value;
			descending(n->right);
		}
	}
	
	bool isPresent(string key){
		
		node *temp =root;
		while( temp != NULL){
			
			if(temp->key == key){
				return true;
			}
			else if(temp->key > key){
				temp = temp->left;
			}	
			else{
				temp = temp->right;
			}
		}
		return False;
	}

	node *minnode(node *root){
		node *n = root;
		if ( n->left != NULL ){
			n = n->left;
		}
		return n;
	}

	node *remove( node *&temp_root, string key){
		
		if( temp_root == NULL ){
			return NULL;
		}
		if( temp_root->key < key ){
			temp_root->right = remove(temp_root->right ,key);
		}
		else if( temp_root->key > key){
			temp_root->left = remove(temp_root->left ,key);
		}
		else{
			
			new *temp1 = temp_root;
			if( temp_root->left == NULL || temp_root->right == NULL){
				if(temp_root->left == NULL){
					temp_root=temp_root->right;
				}
				else{
					temp_root = temp_root->left;
				}
				delete temp1;
			}
			else{
				new *temp2 = minnode(temp_root->right);
				temp_root->key = temp2->key;
				temp_root->value= temp2->value;
				temp_root->right=remove(temp_root->right, temp2->key);
			}
		}
		
		if( temp_root ==  NULL ){
			return temp_root;
		}
		int bf = balanceFactor(temp_root);
			
		if( bf > 1 &&  balanceFactor(root->left) >= 0 ){
			return rightRotate(temp_root);
		}

		if(bf < -1 && balanceFactor(root->right)<=0){
			return leftRotate(temp_root);
		}
		
		if( bf>1 && balanceFactor(root->left)<0){
			temp_root->left = leftRotate(temp_root->left);
			return rightRotate(temp_root);
		}

		if( bf<-1 && balanceFactor(root->right)>0){
			temp_root->right = rightRotate(temp_root->right);
			return leftRotate(temp_root);
		}

		return temp_root;
	}

public:
	string search( string key){
		new *temp == root ;
		while( temp != NULL){
			if(temp->key == key){
				cout<<"Value for key :"<<temp->value;
               			 break;
			}
			else if( temp->key < key ){
				temp = temp->right;
			}
			else{
				temp = temp->left;
			}
		}
		return "\0";
	}

	bool insert(string key, string value){
		if( isPresent(key) ){
			return false;
		}
		else{
			root=insertion(root, key, value);	
			return true;
		}
		cout<<"Element inserted successfully !!"<<endl;	
	}

	bool update(string key,string value){
		new *temp = root;
		while( temp != NULL ){
			if(temp->key==key){
				temp->value=value;
				return true;
			}
			else if(temp->key > key){
				temp= temp->left;
			}	
			else{
				temp =temp->right;
			}
		}
		return false;
	}

	b00l remove(string key){
		if(!isPresent(key)){
			return false;
		}
		else{
			root = remove(root,key);
			cout<<"Key removed successfully"<<endl;
			return true;
		}
	}

	void ascending(){
		if(root == NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		else{
			cout<<"Ascending Traversal is:"<<endl;
			ascending(root);
		}
	}

	void descending(){
		if(root == NULL){
			cout<<"Tree is Empty"<<endl;
			return;
		}
		else{
			cout<<"Descending Traversal is:"<<endl;
			descending(root);
		}
	}
};

int main(){

	AVL a;
	string key, string val;
	int ch;

	do{
		cout<<"\n----MENU----\n1.Insert\n2.Update\n3.Search\n4.Remove\n5.Ascending & Descending\n6.Exit\n\nEnter your choice :"<<;
		cin>>ch;
		
		switch(ch){
			case 1:
				cout<<"Enter key :";
				cin>>key;
				cout<<"Enter value :";
				cin>>val;
				a.insert(key, val);
				break;

			case 2:
				cout<<"Enter key to update :";
				cin>>key;
				cout<<"Enter value to update :";
				cin>>val;
				a.update(key, val);
				break;
		
			case 3:
				cout<<"Enter key to search :";
				cin>>key;
				a.search(key);
				break;

			case 4:
				cout<<"Enter key to remove :";
				cin>>key;
				a.remove(key);
				break;

			case 5:
				a.ascending();
				cout<<endl;
				a.descending();
				break;

			case 6:
				cout<<"Thank you !!"<<endl;
				break;

			default:
				cout<<"Wrong Choice !!"<<endl;
				break;	
		}
	}
	return 0;	
}