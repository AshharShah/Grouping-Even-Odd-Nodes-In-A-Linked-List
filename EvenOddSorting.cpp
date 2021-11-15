#include <iostream>
using namespace std;

// our structure which represents a single node in the linked list
struct node{
    int data;
    node* next;
};

// our class which will be used to create our linked list and perform operations as per requirenment
class list{
    private:
    	// a pointer to the starting node of our linked list
        node* head = new node;
    public:
    	// constructor used incase when a object is invoked the starting address is empty
        list(){
            head = NULL;
        }
        // our function to return the address stored in the haed pointer
        node* gethead(){
            return this->head;
        }
        // our function which will insert nodes into our linked list at the tail
        void insert(int d){
            node* newnode = new node;
            node* temp = new node;
            temp = gethead();
            newnode->data = d;
            newnode->next = NULL;
            // if there are no nodes in the linked list then the new node will be the first node
            if(temp == NULL){
                head = newnode;
                return;
            }
            // else we will move towards the last node in the linked list
            while(temp->next != NULL){
                temp = temp->next;
            }
            // and we join the new node at the tail of the list
            temp->next = newnode;
        }
        // our print function which will print all the nodes of our linked list in the respective order from head to tail
        void print(){
        	// if the list is empty display a warning and exit function
            if(head == NULL){
                cout << "Error: List is Empty!" << endl << endl;
                return;
            }
            node* temp = new node;
            temp = gethead();
            cout << "[  ";
            while(temp != NULL){
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << "]" << endl;
        }
        // our sort function which will sort the linked list in such a way even indexes will be grouped and then odd indexes
        void sort(){
        	// if the list is empty or has only 1 node we can not perform any sorting operation
        	if(head == NULL || head->next == NULL){
        		return;
			}
			// our 3 nodes which will be used to make changed to our list
        	node* even = new node;
        	node* odd = new node;
        	node* evenref = new node;
        	// the first node will be the odd node
        	odd = head;
        	// the second node will be the even node
        	even = head->next;
        	// we will also make a reference pointer to the first even node since our sorted list should start from 2nd node
        	evenref = head->next;
        	
        	// using a loop and incrementing till we reach the last node of the linked list
        	while(even->next != NULL){
        		// odd node will take the address of the 3rd node then 5th and soo on
        		odd->next = even->next;
        		odd = even->next;
        		even->next = odd->next;
        		// if we have a linked list of odd legnth then we will break the loop so that we dont make the even pointer NULL
        		// if even pointer is assigned null value we cant perform the operation even->next outside the while loop
        		if(odd->next == NULL){
        			break;
				}
        		even = odd->next;
			}
			// we will make the 2nd last node of the orignal linked list to NULL as it is the ending node of the sorted linked list
			odd->next = NULL;
			// we will join the ending even node to the first odd node hence completing the linked list
			even->next = head;
			// we will assign the 2nd node of the orignal list to the head ptr as it is the starting node of our sorted list
			head = evenref;
        }
};

int main(){
	
    list linkedlist;
    int size;
    int num;
    
    cout << "How Many Values Do You Wish To Enter In The List: ";
    cin >> size;
    // loop to add values into our linked list
    for(int i = 0; i < size; i++){
    	cout << "Enter Num " << i+1 << ": ";
    	cin >> num;
    	linkedlist.insert(num);
	}
	cout << endl;
    // displaying the list before being sorting
    cout << "The Value's Entered Are: ";
    linkedlist.print();
    cout << endl << endl;
    // sorting the linked list
    linkedlist.sort();
    // displaying the list after being sorted
    cout << "The Linked List After Being Sorted: ";
    linkedlist.print();
    
    cout << "\nThank You For Using The Program :)" << endl;
    return 0;
}
