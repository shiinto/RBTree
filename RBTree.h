int potenz(int a, int b);
void space(int n);
void rot(void);
void weiss(void);

class RBnode{

public:
	int data;
	bool red;
	RBnode* left;
	RBnode* right;

	RBnode();
	RBnode(int item, RBnode*node);	
};



class RBtree{
private:
	RBnode* head;
	RBnode* nullnode;
public:
	RBtree();
	void insert(int item);
	bool insert(RBnode*node,int item);
	void leftrotation(RBnode*&node);
	void rightrotation(RBnode*&node);
	void baum_malen(void);

};


