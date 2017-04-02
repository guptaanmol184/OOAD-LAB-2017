template <typename C>
class node
{

//private data members
private:
	C data;
	node *next;
	node *losers;

//public interface functions
public:
	node(C value);
	void setNextValue(node *nxt_node);
	C getData();
	node *getNext();
	node *getLosers();
	void addLoser(node *lost_node);
};

template <typename C>
class linkedList
{
private:
	node<C> *root;
	int size;

//public interface functions
public:
	linkedList();
	void insert(C value);
	void displayLL();
	void runKnockout();

	//getMax(), getSecondMax() doesn't exist: returns -1
	C getMax();
	C getSecondMax();
};
