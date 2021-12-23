#include <iostream>
//#include "LinkedList.cpp"
#include <cstdlib>
using namespace std;

struct node{
    long burstTime;
	long priority;
    struct node * next;
};


node *header;


int is_emptyll(struct node *);
void displayll(struct node *);
struct node *newnode(long, long);
struct node * insertFront(struct node *, long ,long);
struct node * insertBack(struct node *, long ,long);
void insertAfter(struct node *, long);
struct node *sortList(struct node *);
struct node *sortPriority(struct node *);
int mainMenuFunction(string,string);
int schedulingModeMenu();


int main(int argc, char const *argv[]) {

    header = NULL;
    header = insertFront(header,5,3);
    header = insertFront(header,1,1);
    header = insertFront(header,2,4);
    header = insertFront(header,1,5);
    header = insertFront(header,10,2);
    
    

    int Option = 0;
    int modeChoice = 0;
    int preemptiveModeInt = 0;
    int quantum = 2;
    double pID = 1.0;
    double wt = 0;
    double avgWT = 0;
    bool menu = false;
    string preemptiveModeSTR;
    string schedulerMode;
    preemptiveModeSTR.assign("OFF");
    schedulerMode.assign("NONE");


    while (menu == false) {

        Option = mainMenuFunction(schedulerMode,preemptiveModeSTR);//load main menu

        switch (Option) {
            case 1:
                modeChoice = schedulingModeMenu();//load scheduling menu
                if(modeChoice == 1){
                    schedulerMode.assign("FCFS Scheduler");
                }//set scheduling mode to FCFS
                else if(modeChoice == 2){
                    schedulerMode.assign("SJF Scheduler");
                }//set scheduling mode to SJF
                else if(modeChoice == 3){
                    schedulerMode.assign("Priority Scheduler");
                }//set scheduling mode to Priority scheduler
                else if(modeChoice == 4){
                    schedulerMode.assign("RR Scheduler");
                }//set scheduling mode to RR
                else {
                    cout << "Enter a valid option"<<endl;
                    modeChoice = schedulingModeMenu();
                }//if scheduling option doesn't exist loop the scheduling menu
                break;
            case 2:
                if (modeChoice == 1){
                    cout<<"Selected mode doesn't support Preemptive mode"<<endl;
                    preemptiveModeSTR.assign("OFF");
                }//if FCFS is selected turn off preemptive mode
                else if (modeChoice == 4){
                    cout<<"Selected mode doesn't support Preemptive mode"<<endl;
                    preemptiveModeSTR.assign("OFF");
                }//if SJF is selected turn off preemptive mode
                else
                {
                    cout<<"==========[Preemptive mode(ON/OFF)]=========="<<endl;
                    cout<<"1) ON"<<endl;
                    cout<<"2) OFF"<<endl;
                    cin>>preemptiveModeInt;
                    switch (preemptiveModeInt) {
                        case 1:
                            preemptiveModeSTR.assign("ON");
                            break;
                        case 0:
                            preemptiveModeSTR.assign("OFF");
                            break;
                        default:
                            cout<<"Enter a valid option";

                    }//turn preemptive mode
                }
                break;//trun preemptive mode on/off
            case 3:
                if (modeChoice == 1)
                {
                        node *temp = header;
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != temp) {
                        avgWT = wt+ avgWT;

                        cout<<"P"<<pID<<".)  "<< wt << endl;
                        pID++;

                        wt = wt + temp->burstTime;
                        temp = temp->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl<<endl;
                    menu = true;
                }
                else if (modeChoice == 2 && preemptiveModeInt == 0)
                {   node *temp = header;
                    sortList(temp);
                    
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != temp) {
                        avgWT = wt+ avgWT;

                        cout<<"P"<<pID<<".)  "<< wt << endl;
                        pID++;

                        wt = wt + temp->burstTime;
                        temp = temp->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl;
                    menu = true;
                }
                else if (modeChoice == 2 && preemptiveModeInt == 1)
                {   node *temp = header;
                    sortList(temp);
                    displayll(temp);
                    
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != temp) {
                        avgWT = wt+ avgWT;

                        cout<<"P"<<pID<<".)  "<< avgWT << endl;
                        pID++;

                        wt = wt + temp->burstTime;
                        temp = temp->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl;
                    menu = true;
                }
                else if (modeChoice == 3 && preemptiveModeInt == 0)
                { 
                    node *temp = header;
                    sortPriority(temp);
                    
                    
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != temp) {

                        avgWT = wt+ avgWT;
                        cout<<"P"<<pID<<".)  "<< wt << endl;
                        pID++;

                        wt = wt + temp->burstTime;
                        temp = temp->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl;
                    menu = true;
                }
                else if (modeChoice == 3 && preemptiveModeInt == 1)
                {
                    
                }
                else if(modeChoice == 4 && preemptiveModeInt == 0)
                {
                        node *temp = header,*rem_bt = temp;
displayll(rem_bt);
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                        while (rem_bt != NULL)
                        {   
                        }
                        pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl;
                   
                    menu = true;

                }        
                else{
                    cout<<"Select the right options"<<endl;
                    menu = false;
                }

                
                //menu = true;
                break;//show the result on the console
            case 4:
                cout << endl <<"CPU Scheduling Simulator has been exited" << '\n';
                menu=true;
                exit(1);
                break;//exit the program and calculate the result
            default:
                cout << "Enter an option in the menu" << '\n';
        }//if main menu option does not exist run the loop again
    }
    return 0;
}

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
		cout<<Htemp->burstTime;
		cout<<Htemp->priority<<" \n";
		Htemp=Htemp->next;
	}
	cout<<endl;

}

struct node *newnode(long bt, long pt){
	struct node *temp;
	temp=(struct node*) malloc(sizeof(node));
	temp->burstTime = bt;
	temp->priority = pt;
	temp->next=NULL;
	return temp;
}

struct node * insertFront(struct node *header, long bt,long pt){
	struct node *temp;
	temp=newnode(bt,pt);
	temp->next=header;
	header=temp;
	return header;
}

struct node * insertBack(struct node *header, long d,long pt){
	struct node *temp, *Htemp;
	temp=newnode(d,pt);
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

void insertAfter(struct node *afterNode, long d,long pt){
	struct node *temp;
	temp=newnode(d,pt);
	temp->next=afterNode->next;
	afterNode->next=temp;
}

struct node *sortList(struct node *current) {
    //Node current will point to head


    struct node *index = NULL;
    int temp;

    if(is_emptyll(current)) {
        return index;
    }
    else {
        while(current != NULL) {
            //Node index will point to node next to current
            index = current->next;

            while(index != NULL) {
                //If current node's data is greater than index's node data, swap the data between them
                if(current->burstTime > index->burstTime) {
                    temp = current->burstTime;
                    current->burstTime = index->burstTime;
                    index->burstTime = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

struct node *sortPriority(struct node *current) {
    //Node current will point to head


    struct node *index = NULL;
    int tempBT,tempPT;

    if(is_emptyll(current)) {
        return index;
    }
    else {
        while(current != NULL) {
            //Node index will point to node next to current
            index = current->next;

            while(index != NULL) {
                //If current node's data is greater than index's node data, swap the data between them
                if(current->priority > index->priority) {
                    tempBT = current->burstTime;
					tempPT = current->priority;
                    current->burstTime = index->burstTime;
					current->priority = index->priority;
                    index->burstTime = tempBT;
					index->priority = tempPT;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int mainMenuFunction(string mode,string PEMode)
{
    int menuChoice;
    cout << "==========[ CPU Scheduler Simulator ]==========" << '\n';
    cout << "1) Scheduling Mode (" <<mode<<")"<< '\n';
    cout << "2) Preemptive Mode (" <<PEMode<<")"<< '\n';
    cout << "3) Show result" << '\n';
    cout << "4) End program" << '\n' << endl;
    cout <<"Select an option:  ";
    cin >> menuChoice;
    return menuChoice;
}

int schedulingModeMenu(){
    int Choice;
    cout << "******** CPU Scheduler Simulator MODE ********" << '\n';
    cout << "1) First Come First Serve (FCFS) Scheduler "<< '\n';
    cout << "2) Shortest Job First (SJF) Scheduler" << '\n';
    cout << "3) Priority Scheduler" << '\n';
    cout << "4) Round Robin" << '\n' << endl;
    cout <<"Select an option:  ";
    cin >> Choice;
    return Choice;
}
