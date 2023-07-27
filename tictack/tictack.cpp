#include <iostream>
using namespace std;

string n1 = " ";
string n2 = " ";
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token = 'X';
bool tie = false;
int digit;

void functionOne()
{
    cout<<endl;
    cout<<" _______________________\n";
    cout<<"|       |       |       |\n";
    cout<<"|   "<<space[0][0]<<"   |   "<<space[0][1]<<"   |   "<<space[0][2]<<"   |\n";
    cout<<"|_______|_______|_______|\n";
    cout<<"|       |       |       |\n";
        cout<<"|   "<<space[1][0]<<"   |   "<<space[1][1]<<"   |   "<<space[1][2]<<"   |\n";
    cout<<"|_______|_______|_______|\n";
    cout<<"|       |       |       |\n";
        cout<<"|   "<<space[2][0]<<"   |   "<<space[2][1]<<"   |   "<<space[2][2]<<"   |\n";
    cout<<"|_______|_______|_______|\n";
    cout<<endl;

}

void functionTwo()
{
    if(token=='X')
    {
        cout<<n1<<" please enter : ";
        cin>>digit;
    }
    else if(token=='O')
    {
        cout<<n2<<" please enter : ";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        column=0;
    }
    else if(digit==2){
        row=0;
        column=1;
    }
    else if(digit==3){
        row=0;
        column=2;
    }
    else if(digit==4){
        row=1;
        column=0;
    }
    else if(digit==5){
        row=1;
        column=1;
    }
    else if(digit==6){
        row=1;
        column=2;
    }
    else if(digit==7){
        row=2;
        column=0;
    }
    else if(digit==8){
        row=2;
        column=1;
    }
    else if(digit==9){
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid !"<<endl;
    }

    if(token=='X' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column]='X';
        token='O';
    }
    else if(token=='O' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column]='O';
        token='X';
    }
    else{
        cout<<"There is no empty space."<<endl;
        functionTwo();
    }
    functionOne();
}

bool functionThree(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1]&&space[i][0]==space[i][2] || space[0][i]==space[1][i]&&space[0][i]==space[2][i]){
            return false;
        }
    }
    if(space[0][0]==space[1][1]&&space[0][0]==space[2][2] || space[0][2]==space[1][1]&&space[0][2]==space[2][0]){
        return false;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j] != 'X' && space[i][j] != 'O'){
                return true;
            }
        }
    }

    tie=true;
    return false;

}

int main()
{
    cout<<"Enter the name of the first player : \n";
    getline(cin,n1);
    cout<<"Enter the name of the second player : \n";
    getline(cin,n2);
    cout<<n1<<" is player1 so he/she will play first. \n";
    cout<<n2<<" is player2 so he/she will play second. \n";

    while(functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }
    if(token=='X'&&tie==false){
        cout<<n2<<" win the game euuu..!"<<endl;
    }
    else if(token=='O'&&tie==false){
        cout<<n1<<" win the game euuu..!"<<endl;
    }
    else{
        cout<<"It's a draw!"<<endl;
    }
}