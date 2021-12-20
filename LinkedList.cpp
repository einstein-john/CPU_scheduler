#include<iostream>  
#include<cstdlib>
using namespace std;
struct node{
    long data;
    struct node * next;
};

int is_emptyll(struct node *);
void displayll(struct node *);
struct node * insertFront(struct node *, int );
struct node * insertBack(struct node *, int d);
void insertAfter(struct node *, int);
struct node * deleteBack(struct node *);
struct node * deleteFront(struct node *);
void deleteAfter(struct node *);
struct node * oddn(struct node *);
int noNode(struct node *);
int nthNode(struct node *, int);
struct node * mult(struct node *, int, int);
struct node * maxElmt(struct node *);
struct node * delAll(struct node *);
struct node * delEven(struct node *);
struct node * delEvenNodes(struct node *);
struct node * insertInSort(struct node *, int);
struct node * appendList(struct node *, struct node *);
int middleList(struct node *);
/*
int main(){
	
	struct node *header, *later;
	header = NULL;
	header = insertFront(header,5);
	header = insertFront(header,9);
	header = insertFront(header,8);
	header = insertFront(header,6);
	header = insertFront(header,45);
	header = insertFront(header,18);
	header = insertFront(header,12);
	header = insertFront(header,55);
	header = insertFront(header,63);
	later = NULL;
	later = insertFront(later,1);
	later = insertFront(later,11);
	later = insertFront(later,21);
	
	
	//display linked list
	displayll(header);
	//display odd numbers in the list
	cout<<"Odd numbers: ";
	oddn(header);
	//Display the number of nodes in the list
	cout<<"Number of Nodes : "<<noNode(header)<<endl;
	//display the element in the nth position in the node
	cout<<"Data in nth Node : "<<nthNode(header, 8)<<endl;
	//display the multiplication of the nth node by x
	cout<<"Multiplication of Node : ";
	mult(header, 2, 4);
	//display the maximum element in the node
	cout<<"Maximum element in the Node : ";
	maxElmt(header);
	
	//cout<<"Delete all nodes : ";
	//	delAll(header);
	
	//delete even nodes
	delEvenNodes(header);
	displayll(header);
	//insert node in a sorted linkedlist
	cout<<"Insert this : ";
	header=insertInSort(header, 82);
	displayll(header);
	/*
	if somehow, header is going to be changed
	you have to say "header= whatever function you are operating"
	if header is not going to be involved, just put the expression
	plainly.
	*/
/*
	//append two different lists together
	cout<<"Append two linked lists : ";
	appendList(header, later);
	displayll(header);
	//return the middle number in a list if its an odd list
	
	cout<<"Middle number : ";
	middleList(header);
	
	return 0;
}*/

int is_emptyll(struct node *header){
	if(header==NULL)
		return 1;
	else
		return 0;
}
void displayll(struct node *header){
	struct node * Htemp;
	Htemp=header;
	//cout<<"Linked list is: ";
	while(Htemp!=NULL){
		cout<<Htemp->data<<" \n";
		Htemp=Htemp->next;
	}
	cout<<endl;

}
struct node *newnode(int d){
	struct node *temp;
	temp=(struct node*) malloc(sizeof(node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}
struct node * insertFront(struct node *header, int d){
	struct node *temp;
	temp=newnode(d);
	temp->next=header;
	header=temp;
	return header;
}
struct node * insertBack(struct node *header, int d){
	struct node *temp, *Htemp;
	temp=newnode(d);
	if(is_emptyll(header)){
		header=temp;
		return header;
	}
	Htemp=header;
	while(Htemp->next!=NULL)
		Htemp = Htemp->next;
	Htemp->next=temp;
	
	return header;
}
void insertAfter(struct node *afterNode, int d){
	struct node *temp;
	temp=newnode(d);
	temp->next=afterNode->next;
	afterNode->next=temp;
}
struct node * deleteBack(struct node *header){
	struct node *temp, *Htemp;
	if(header==NULL)
		return header;
	if(header->next==NULL)
	{
        free(header);
        header=NULL;
		return header;
    }
	Htemp=header;
	while(Htemp->next->next!=NULL)
		Htemp=Htemp->next;
	temp=Htemp->next;
	Htemp->next=NULL;
	free(temp);
	return header;
}
struct node * deleteFront(struct node *header){
	struct node *temp;
	if(header==NULL)
		return header;
	temp=header;
	header=header->next;
	free(temp);
	return header;
}
void deleteAfter(struct node *afterNode){
	struct node *temp;
	if(afterNode->next==NULL || afterNode==NULL)
		return;
	temp =afterNode->next;
	afterNode->next=temp->next;
	free(temp);
}
struct node * oddn(struct node *header){
	struct node *Htemp;
	Htemp = header;
	while(Htemp!=NULL){
		if(Htemp->data%2!=0)
		cout<<Htemp->data<<" ";
		Htemp=Htemp->next;
	}
	cout<<endl;
}
int noNode(struct node *header){
	struct node *Htemp;
	Htemp=header;
	int count = 0;
	while(Htemp!=NULL){
		Htemp=Htemp->next;
		count+=1;
	}
	//cout<<count<<endl;
	return count;
}
int nthNode(struct node *header, int d){
	struct node *Htemp;
	Htemp=header;
	int count = 1;
	while(Htemp!=NULL){
		
		if(count==d)
			return Htemp->data;
		
		Htemp=Htemp->next;
		count++;
	}
	cout<<endl;
}
struct node * mult(struct node *header, int d, int c){
	struct node *Htemp;
	Htemp=header;
	int count, x, mul; 
	count= 1;
	mul=c;
	while(Htemp!=NULL){
		
		if(count==d)
			x=Htemp->data;
		
		Htemp=Htemp->next;
		count++;
	}
	cout<<x*mul;
	cout<<endl;
}
struct node * maxElmt(struct node *header){
	struct node *Htemp;
	Htemp=header;
	int max=Htemp->data;
	
	while(Htemp!=NULL){
		
		if(max<Htemp->data)
			max=Htemp->data;
			
	Htemp=Htemp->next;
	}
	cout<<max;
	cout<<endl;
}
struct node * delAll(struct node *header){
	struct node *Htemp;
	Htemp = header;
	if(header==NULL)
		return header;
	while(Htemp!=NULL){
		Htemp=deleteFront(Htemp);
	}
	return header;
}
struct node * delEvenNodes(struct node *header){
	struct node *Htemp;
	Htemp = header;
	while(Htemp->next!=NULL){
		if((Htemp->next->data)%2==0){
			deleteAfter(Htemp);
		}
		else
			Htemp=Htemp->next;
	}
	if(header->data%2==0){
		header=deleteFront(header);
	}
		return header;
}
struct node * insertInSort(struct node *header, int d){
	struct node *Htemp;
	Htemp=newnode(d);
		if(d>=(header->next->data)){
			header=insertFront(header, d);
			return header;
		}else{	
			while(Htemp->next!=NULL){
			
				if(d>(Htemp->next->data)){
					insertAfter(header, d);
					return header;
			}
			else
				Htemp = Htemp->next;
			}
		}
		header=insertBack(header, d);
		return header;	
}
struct node * appendList(struct node *header, struct node *later){
	struct node *Htemp;
	struct node *temp;
	Htemp=header;
	temp=later;
	if(header==NULL){
		header=later;
		return header;
	}
	while(Htemp->next!=NULL)
		Htemp=Htemp->next;
		
	Htemp->next=temp;
	
	return header;
}
int middleList(struct node *header){
	int c = noNode(header);
	return nthNode(header,(c/2+1));
}
