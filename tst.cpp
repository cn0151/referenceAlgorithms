/*   NAME: NWANKWO CHUKWUEBUKA JUSTIN
     DATE: 10/8/2016
*/



#include <iostream>

using namespace std;

struct node{
	char ch;
	int val;
	node * left;
	node * mid;
	node * right;
	node(char alpha){
		ch = alpha;
		val = -2;
	}
};

int  get(node * root, string key, int index){
	if(root == NULL)
		return -1;
	
	if(index == key.size() - 1)
		return root->val;

	
	if(key[index] < root->ch)
		return get(root->left, key, index);

	else if(key[index] > root->ch)
		return get(root->right, key, index);

	else
		return get(root->mid, key, ++index);

}

node *  insert(node *& root, string key, int value, int index){

	if(root == NULL){
		root = new node(key[index]);
		root->left = NULL;
		root->mid = NULL;
		root->right = NULL;
	}

	if(key[index] < root->ch){
		cout<<"in left\n";
		root->left = insert(root->left, key, value, index);
	}
		

	else if(key[index] > root->ch){
		cout<<"in right\n";
		root->right = insert(root->right, key, value, index);
	}
	
	else{

		if(index < key.size() - 1){
			cout<<"in mid\n";
			root->mid = insert(root->mid, key, value, ++index);
		}
		else
			root->val = value;

	}

	return root;
}

int main(){
	node * root = NULL;

	root = insert(root, "shell", 5, 0);


	cout<<"\n\n\n";
	cout << get(root, "shell", 0)<<endl;
	cout << get(root, "love", 0)<<endl;
	root = insert(root, "sea", 7, 0);

	cout<<endl<<endl;
	root = insert(root, "seabird", 21, 0);
	cout<< get(root, "sea", 0)<<endl;

	cout<< get(root, "seabird", 0)<<endl;


}
