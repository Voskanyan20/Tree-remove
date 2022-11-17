#include <iostream>
// #include <vector>

using namespace std;

template<typename T, typename K>
class Tree {
	private:
		struct Node {
			T key;
			K value;
			Node * left;
			Node * right;
		};
		Node * root;
		void deleteNode(Node *node)
		{
			if(NULL == node) {
				return;
			}
			deleteNode(node->left);
			deleteNode(node->right);
			delete node;
		}
        // void remove(T);
		void _add(Node* node, T key, K value)
		{
			if (node->key == key) {
				node->value = value;
			}
			if ( node->key > key) {
				if (NULL == node->left) {
					node->left = new Node;
					node->left->key = key;
					node->left->value = value;
					node->left->right = NULL;
					node->left->left = NULL;
					return;
				} 
				_add(node->left, key, value);
			} else {
				if (NULL == node->right) {
					node->right = new Node;
					node->right->key = key;
					node->right->value = value;
					node->right->right = NULL;
					node->right->left = NULL;
					return;
				} 
				_add(node->right, key, value);
			
			}
		}
	public:
		Tree() : root{NULL} {}
		~Tree() 
		{
			deleteNode(root);
		}

		void add(T key, K value) {
			if (NULL == root) {
				root = new Node;
				root->key = key;
				root->value = value;
				root->right = NULL;
				root->left = NULL;
			}
			_add(root, key, value);
		}

		bool search(T key) {
			if (NULL == root) {
				return false;
			}
			Node * p = root;
			while (NULL != p) {
				if (p->key == key) {
					return true;
				}
				if (p->key > key) {
					p = p->left;
					continue;
				}
				p = p->right;
			}
			return false;
		}

		K getvalue(T key) 
		{
			Node * p = root;
			while (NULL != p) {
				if (p->key == key) {
					return p->value;
				}
				if (p->key > key) {
					p = p->left;
					continue;
				}
				p = p->right;
			}
			K k;
			return k;
		}
		Node* remove(T key)
		{
            if(root == NULL || root->key == key){
                return delRoot(root);
            }

            Node* tmp = root;
            while(1) {

                if(key < tmp->key){
                if(tmp->left == NULL || tmp->left->key == key){
                    tmp->left = delRoot(tmp->left);
                    break;
                }
                tmp = tmp->left;
                } else {
                if(tmp->right == NULL || tmp->right->key == key){
                    tmp->right = delRoot(tmp->right);
                    break;
                }
                tmp = tmp->right;
            }
        }
        return root;
		}

        Node* delRoot(Node* root){
         if(!root || root->value == 0){
            return NULL;
         };
         if(root->right == NULL){
             return root->left;
         };
         Node* tmp = root->right;
            while(tmp->left){
                tmp = tmp->left;
            }
            tmp->left = root->left;
            return root->right;   
        }
   };

// class Graph {
// 	private:
// 		Tree<int, vector<int>> data;
// 		vector<int> vertices;
// 	public:
//         Graph(Tree<int, vector<int>>);
//         ~Graph(){

//         };
// 		void addEdge(vector<int> arr[],int x, int y){
//             arr[x].push_back(y);
//             arr[y].push_back(x); 
//         }
// 		void addVertex(int);
// 		void printGraph(vector<int> arr[], int x1){
//             for (int i = 0; i < x1; i++)
//             {   
//                 cout << "\n arr list of vertex = "<< i << "\n";
//                 for (auto x : arr[i])
//                 cout << " = " << x;
//                 cout << "\n" << endl;
//             }
              
//         }
// };

int main (){
    Tree<int , int> t;

    t.add(1 , 2);
    t.add(2 , 5);
    t.add(3 , 9);
    t.add(4 , 11);
    cout<<t.search(3) << endl;
    
    t.remove(3);

    cout<<t.search(3) << endl;
    // Tree<int , vector<int>> tv;
    // Graph g(tv);
    
    // int x1 = 5;
    // vector<int> arr[x1];

    // g.addEdge(arr, 0, 1);
    // g.addEdge(arr, 0, 4);
    // g.addEdge(arr, 1, 2);
    // g.addEdge(arr, 1, 3);
    // g.addEdge(arr, 1, 4);
    // g.addEdge(arr, 2, 3);
    // g.addEdge(arr, 3, 4);


    return 0;
}