#include "headers.h"
#include <iostream>
using namespace std;

main(){
    char main_action = 's';

    while (main_action != 'e')
    {
        cout << "Menu" << endl;
        cout << "1)First Laba" << endl;
        cout << "2)Second Laba" << endl;
        cout << "3)Third Laba" << endl;
        cout << "4)Fourth Laba" << endl;
        cout << "Enter 'e' to escape" << endl;
        cout << "Choose your action: ";
        cin >> main_action;
        switch (main_action)
        {
        case '1':
            {
                char first_laba_action;
                cout << "Enter task number from 1 to 4" << endl;
                cin >> first_laba_action;
                switch (first_laba_action)
                {
                case '1':
                    First();
                    break;
                case '2':
                    Second();
                    break;
                case '3':
                    Third();
                    break;
                case '4':
                    Fourth();
                    break;
                case 'e':
                    system("cls");
                    break;
                default:
                    system("cls");
                    break;
                }
                break;
            }
        case '2':{
            second_laba_menu(); 
            break;
        }
        case '3':{
            third_laba_menu(); 
            break;
        }
        case '4':{
            fourth_laba_menu(); 
            break;
        }
        default:
            break;
        }
    }
}
}
