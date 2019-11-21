template< typename KEY_TYPE, typename DATA_TYPE >
class Node{
public:
	KEY_TYPE key;
	DATA_TYPE data;
	Node<KEY_TYPE,DATA_TYPE>* left;
	Node<KEY_TYPE,DATA_TYPE>* right;
	
	Node( KEY_TYPE key, DATA_TYPE data ) : key( key ), data( data ), left( NULL ), right( NULL ) {}
	~Node(){}
	void Display() {
		cout << key << data << " ";
	}
};

template< typename KEY_TYPE, typename DATA_TYPE >
class BST{
private:
	Node<KEY_TYPE,DATA_TYPE>* root;
	
public:
	BST():root( NULL ){}
	
	~BST(){
		Clean( root );
	}
	
	void Clean( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node != NULL ){
			Clean( node->right );
			Clean( node->left );
			delete node;
		}
	}
	
	bool Insert( KEY_TYPE key, DATA_TYPE data ){	
		if( root == NULL ){
			root = new Node<KEY_TYPE,DATA_TYPE>( key, data );
			return true;
		}
		
		Node<KEY_TYPE,DATA_TYPE>* curr = root;
		Node<KEY_TYPE,DATA_TYPE>* prev = NULL;
		while( curr != NULL ){
			prev = curr;
			if( key < curr->key )
				curr = curr->left;
			else if( curr->key < key )
				curr = curr->right;
			else 
				return false;
		}
	
		Node<KEY_TYPE,DATA_TYPE>* newNode = new Node<KEY_TYPE,DATA_TYPE>( key, data );
		if( key < prev->key )
			prev->left = newNode;
		else
			prev->right = newNode;
		return true;
	}
	
	void PreOrder(){
		PreOrderRec( root );
	}
	
	void InOrder(){
		InOrderRec( root );
	}
	
	void PostOrder(){
		PostOrderRec( root );
	}
	
	void LevelOrder(){
		int treeHeight = Height() + 1 ;
		for( int i = 1; i <= treeHeight; i++ )
			printLevel( root, i ); 
	}
	
	void printLevel(Node<KEY_TYPE,DATA_TYPE>* node ,int level){
        if ( node == NULL ) return;
        
		if ( level == 1 )
        	node->Display();	
		else if (level > 1){
			level--;
            printLevel( node->left, level );
            printLevel( node->right, level );
        }
    }
	
	void PreOrderRec( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node != NULL ){
			node->Display();
			PreOrderRec( node->left );
			PreOrderRec( node->right );
		}
	}
	void InOrderRec( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node != NULL ){
			InOrderRec( node->left );
			node->Display();
			InOrderRec( node->right );
		}
	}
	void PostOrderRec( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node != NULL ){
			PostOrderRec( node->left );
			PostOrderRec( node->right );
			node->Display();
		}
	}
	
	int Height(){
		return HeightRec( root ) - 1; 
	}
	
	int HeightRec( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node == NULL ) return 0;
		
		int leftHeight = HeightRec( node->left );
		int rightHeight = HeightRec( node->right );
		
		if( leftHeight > rightHeight )
			return leftHeight+1;
		return rightHeight+1;
	}
	
	DATA_TYPE* Search( KEY_TYPE key ){
		Node<KEY_TYPE,DATA_TYPE>* curr = root;
		
		while( curr != NULL ){
			if( key < curr->key )
				curr = curr->left;
			else if( curr->key < key )
				curr = curr->right;
			else 
				return &(curr->data);
		}	
		return NULL;	
	}
	
	Node<KEY_TYPE,DATA_TYPE>* Parent( Node<KEY_TYPE,DATA_TYPE>* child ){
		if( child == NULL ) return NULL;
		Node<KEY_TYPE,DATA_TYPE>* curr = root;
		while( curr != NULL ){
			if( curr->left == child || curr->right == child )
				return curr;
			if( child->key < curr->key )
				curr = curr->left;
			else
				curr = curr->right;
		}
		return NULL;
	}
	
	Node<KEY_TYPE,DATA_TYPE>* Next( Node<KEY_TYPE,DATA_TYPE>* node ){
		if( node == NULL ) return NULL;
		if( node->right != NULL ){
			Node<KEY_TYPE,DATA_TYPE>* curr = node->right;
			while( curr->left != NULL )
				curr = curr->left;
			return curr;
		} else {
			Node<KEY_TYPE,DATA_TYPE>* parent = Parent( node );
			Node<KEY_TYPE,DATA_TYPE>* path = node;
			while( parent != NULL && parent->left != path ){
				path = parent;
				parent = Parent( parent );
			}
			return parent;
		}
	}
	
	bool Delete( KEY_TYPE key ){
		Node<KEY_TYPE,DATA_TYPE>* checkElement = root;

		while( checkElement != NULL ){
			if( key < checkElement->key )
				checkElement = checkElement->left;
			else if( checkElement->key < key )
				checkElement = checkElement->right;
			else 
				break;
		}
		
		if( checkElement == NULL ) return false;
		
		while( checkElement != NULL ){
			Node<KEY_TYPE,DATA_TYPE>* parent = Parent( checkElement );
			if( checkElement->left == NULL && checkElement->right == NULL){
				if( parent != NULL ){
					if( parent->right == checkElement ) parent->right = NULL;
					else parent->left = NULL;
				} else root = NULL;
				delete checkElement;
				return true;
			}
			else if( checkElement->left != NULL && checkElement->right == NULL ){
				if( parent != NULL ){				
					if( parent->left == checkElement )
						parent->left = checkElement->left;
					else
						parent->right = checkElement->left;
				} else
					root = checkElement->left;
						
				delete checkElement; 
				return true;
			}
			else if( checkElement->left == NULL && checkElement->right != NULL ){
				if( parent != NULL ){
					if( parent->left == checkElement )
						parent->left = checkElement->right;
					else
						parent->right = checkElement->right;
				} else
					root = checkElement->right;
				delete checkElement;
				return true;
			}
			else{
				Node<KEY_TYPE,DATA_TYPE>* next = Next( checkElement );
				checkElement->data = next->data;
				checkElement->key = next->key;
				checkElement = next;
			}
		}
	}
};
