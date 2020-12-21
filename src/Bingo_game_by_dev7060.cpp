//github.com/dev7060
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unistd.h>
using namespace std;
int main(){
    unsigned int matrix[25]={0}, status[25]={0}; //2 checked
    srand((unsigned) time(0));
    int randoNum;
    int pos;
    int _25counter=0;    
    while(1){
        randoNum = (rand()%25)+1;
        pos = (rand()%25);
        int isPresent = 1;
        for(int i=0; i<25; i++){
            if(randoNum == matrix[i]){
                isPresent = 2;
            }
        }
        if(isPresent!=2 && status[pos]!=2){
             matrix[pos] = randoNum;
             _25counter++;
             status[pos] = 2;
        }
        if(_25counter==25){
            break;
        }
       
    }
    int winCounter = 0;
    int status2[25]={0};
    while(1){
        system("clear");
       for(int i=0; i<25; i++){
            cout<<setw(4);
            
            if(status2[i]==2){
                cout<<matrix[i];
                cout<<"c";
            }else{
                cout<<matrix[i];
                cout<<" ";
            }
            cout<<" ";
            if((i+1)%5==0){
                cout<<"\n";
            }
        }
        int input;
        cout<<"> ";
        cin>>input;
        if(input<1 || input>25){
            cout<<"  Invalid input\n";
            sleep(2);
            continue;
        }
        int position;
        for(int i=0; i<25; i++){
            if(matrix[i]==input){
                position = i;
            }
        }
        if(status2[position]==2){
            cout<<"  Already checked\n";
            sleep(2);
            continue;
        }
        status2[position]=2;
        winCounter++;
        if(winCounter==25){
            system("clear");
            cout<<"* BINGO *";
            break;
        }
    }    
    return 0;
}
