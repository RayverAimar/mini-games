#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void menu()
{
    cout<<"1. Paper\n2. Rock\n3. Scissors\n";
}
void title(){
    string name = {"###########::##::########:::###########::########::#########:::###########::#########::#######::\n::::##:::::::##::##:::::::::::::##:::::::#::::::#::##::::::::::::::##:::::::#:::::::#::#::::::::\n::::##:::::::##:::##::::::::::::##:::::::#::::::#::##::::::::::::::##:::::::#:::::::#::#::::::::\n::::##:::::::##::##:::::::::::::##:::::::########::##::::::::::::::##:::::::#:::::::#::#######::\n::::##:::::::##::##:::::::::::::##:::::::#::::::#::##::::::::::::::##:::::::#:::::::#::#::::::::\n::::##:::::::##::##:::::::::::::##:::::::#::::::#::##::::::::::::::##:::::::#:::::::#::#::::::::\n::::##:::::::##::########:::::::##:::::::#::::::#::#########:::::::##:::::::#########::#######::\n"};
    cout<< name;
}
char UserMovement(){
    char opt;
    cout << "Please enter a option: \n";
    menu();
    while(true)
    {
        cin >> opt;
        system("cls");
        try{
            if(opt == '1' || opt == '2' || opt =='3')
            {
                return opt;
            }
            else
            {
                throw opt;
            }
        }
        catch(...)
        {
            cout<<"Incorrect option. Availables values were 1 2 or 3\n";
            cout<<"And the given value was: "<<opt<<"\n";
            cout<<"Please enter a valid option: \n";
            menu();
        }
    }
}

int computerOption(){
    srand(time(NULL));
    return rand() % 3 + 1;
}

int rps(int user_opt, int computer_opt)
{
    string options[3] = {"Paper", "Rock", "Scissors"};
    cout<<"Your choice was: "<<options[user_opt  - 1 ]<<endl;
    cout<<"Computer's choice was: "<<options[computer_opt - 1 ]<<endl;
    if(user_opt == computer_opt){
        return 0;
    }
    if(user_opt == 1){
        if(computer_opt == 2 ){
            return 1;
        }
        if(computer_opt == 3){
            return 2;
        }
    }
    if(user_opt == 2){
        if(computer_opt == 1 ){
            return 2;
        }
        if(computer_opt == 3){
            return 1;
        }
    }
    if(user_opt == 3){
        if(computer_opt == 1 ){
            return 1;
        }
        if(computer_opt == 2){
            return 2;
        }
    }
    return 0;
}

void printResult(int result){
    string results[3] = {"DRAW!", "YOU WIN", "YOU LOSE" };
    cout<<results[result];
}

int main(){

    int result;
    title();
    system("pause");
    system("cls");
    printResult(rps(UserMovement() - '0', computerOption()));
}