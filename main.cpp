#include <iostream>
#include "LinkedList.cpp"
#include <cstdlib>

using namespace std;
node *header;
int mainMenuFunction(string,string);
int schedulingModeMenu();


int main(int argc, char const *argv[]) {

    header = NULL;
    header = insertFront(header,5);
    header = insertFront(header,1);
    header = insertFront(header,2);
    header = insertFront(header,1);
    header = insertFront(header,10);
    

    int Option = 0;
    int modeChoice = 0;
    int preemptiveModeInt = 0;
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
                break;
            case 3://show the result on the console
                if (modeChoice == 1){

                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != header) {
                        avgWT = wt+ avgWT;

                        cout<<"P"<<pID<<".)  "<< wt << endl;
                        pID++;

                        wt = wt + header->data;
                        header = header->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl<<endl;
                    menu = true;
                }
                else if (modeChoice == 2 && preemptiveModeInt == 0)
                {
                    sortList(header);
                    
                    cout<<"Process scheduling method: "<<schedulerMode<<endl;
                    cout<<"Processes waiting time: "<<endl;
                    while (NULL != header) {
                        avgWT = wt+ avgWT;

                        cout<<"P"<<pID<<".)  "<< wt << endl;
                        pID++;

                        wt = wt + header->data;
                        header = header->next;

                    }
                    pID = pID - 1;
                    avgWT = avgWT/pID;
                    cout<<"Average waiting time: "<<avgWT<<endl;
                    menu = true;
                }
                else if (modeChoice == 2 && preemptiveModeInt == 1)
                {
                    sortList(header);
                }
                
                else{
                    cout<<"Select the right options"<<endl;
                    menu = false;
                }

                
                //menu = true;
                break;
            case 4://exit the program and calculate the result
                cout << endl <<"CPU Scheduling Simulator has been exited" << '\n';
                menu=true;
                exit(1);
                break;
            default://if main menu option does not exist run the loop again
                cout << "Enter an option in the menu" << '\n';

        }
    }
    return 0;
}

int mainMenuFunction(string mode,string PEMode){
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
