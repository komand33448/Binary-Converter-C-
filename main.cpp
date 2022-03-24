#include <iostream>

using namespace std;

int binaryCompar[] = {256, 128, 64, 32, 16, 8, 4, 2, 1};

//BtoD=BinaryToDecimal
static void BtoD() {
    int input[] = {0,0,0,0,0,0,0,0,};
    int output = 0;

    bool isBinary = true;

    //Takes input and puts into array
    cout << "Write your binary number" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "Nr." << i + 1 << ": ";
        cin >> input[i];
    }

    //Converts decimal to binary and checks if input is binary
    for (int i = 0; i < 8; ++i) {
        if(input[i] == 1) {
            output += binaryCompar[i + 1];
        }
        else if(input[i] > 1) {
            isBinary = false;
        }
    }

    if(!isBinary) {
        cout << "\x1B[31mError: Binary value can only be 1 or 0!!!";
    }
    else {
        cout << output;
    }
}

//DtoB=DecimalToBinary
void DtoB() {
    int input = 0;

    cout << "Write your decimal number" << endl;
    cin >> input;

    //Checks if value is over 8 bits & converts to decimal
    if(input > 256) {
        cout << "\x1B[31mError: Input is over 8 bits!";
    }
    else {
        for (int i = 0; i < 8; ++i) {
            if (input <= binaryCompar[i] && input >= binaryCompar[i + 1]) {
                cout << "1";
                input -= binaryCompar[i + 1];
            } else {
                cout << "0";
            }

        }
    }
}

int main() {
    int choose = 0;

    cout << "0: Binary To Decimal" << endl;
    cout << "1: Decimal To Binary" << endl;
    cin >> choose;

    switch (choose) {
        case 0:
            BtoD();
            break;
        case 1:
            DtoB();
            break;
        default:
            break;
    }

    return 0;
}