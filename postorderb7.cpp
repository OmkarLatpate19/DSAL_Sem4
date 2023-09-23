#include<iostream>
#include<map>
#include<stack>
using namespace std;

class node{
	public:
		char data;
		node *left;
		node *right;

		node(){
			left = NULL;
			right = NULL;
		}

		node(char ch){
			data = ch;
			left = NULL;
			right = NULL;
		}	
};

class Tree{
	private:
		node *root;
		stack<node *>nodestack;

		bool isOperator(char ch){
			
			switch(ch){
				case '+':
				case '-':
				case '*':
				case '/':
					return 1;
					break;
				default:
					return 0;
					break;
			}
		}

		/*void insert(char ch){
			
			if( isOperator(ch)){
				node *newnode = new node(ch);
				newnode->left = nodestack.top();
				nodestack.pop();
				newnode->right = nodestack.top();
				nodestack.pop();
				nodestack.push(newnode);
			}
			else{
				node *newnode = new node(ch);
				nodestack.push(newnode);
			}	
		}*/

	public:
		
		/*void input_prefix(string exp){
			
			for(int i = exp.length()-1  ;  i>-1 ; i--){
				insert(exp[i]);
			}
			root = nodestack.top();
			nodestack.pop();
		}*/

		void postorder(){
			
			node *temp = root;
			stack< node*>stack1,stack2;
			
			stack1.push(root);
		
			while( !stack1.empty()){
				
				temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			
				if( temp->left != NULL){
					stack1.push(temp->left);
				}
				if( temp->right != NULL){
					stack1.push(temp->right);
				}
			}
			cout<<"Postodrder of Expression is :";
			while( !stack2.empty()){
				temp = stack2.top();
				stack2.pop();
				cout<<temp->data;	
			}
			cout<<endl;
		}
};

int main(){
	
	Tree t;
	string e;
	cout<<"Enter Expression  :";
	cin>>e;
	//t.input_prefix(e);
	t.postorder();
	return 0;
}

