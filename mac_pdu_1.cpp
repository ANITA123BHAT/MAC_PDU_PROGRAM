#include<iostream>
#include <bitset>
using namespace std;

int getbit1(int n,int pos){
    return ((n & (1 << pos))!=0);
}

int hexadecimalToDecimal(string hexVal)
{
    int len = hexVal.size();
    // Initializing base value to 1, i.e 16^0
    int base = 1;
     int dec_val = 0;
    // Extracting characters as digits from last
    // character
    for (int i = len - 1; i >= 0; i--) {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
 
            // incrementing base by power
            base = base * 16;
        }
 
        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if ((hexVal[i] >= 'A' && hexVal[i] <= 'F' )) {
            dec_val += (int(hexVal[i]) - 55) * base;
 
            // incrementing base by power
            base = base * 16;
        }
        else{
            dec_val+=(int(hexVal[i])-87) * base;
            base=base *16;
        }

    }
    return dec_val;
}

int main(){
    string hexadecimal;
    unsigned int decimal;
    cout<<"User input for hexadecimal number:"<<endl;
    cin>>hexadecimal;
    // Size of string
    int n = hexadecimal.length();
    if(n>2){
        cout<<"Invalid data!"<<endl;
        exit(0);
    }

    // Iterate over string
    for(int i = 0; i < n; i++)
    {
        //char ch = hexadecimal[i];

        // Check if the character is invalid
        // if (!((hexadecimal[i] < '0' || hexadecimal[i] > '9') && (hexadecimal[i] < 'A' || hexadecimal[i] > 'F') && (hexadecimal[i] < 'a' || hexadecimal[i] > 'f')))
        // {
        //     cout << "Invalid user input" << endl;
        //     exit(0);
        // }
        if (!((hexadecimal[i] >= '0' && hexadecimal[i] <= '9') || (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') || (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f'))) {
            cout << "Invalid user input" << endl;
            exit(0);
        }
    }
    // for (int i = 0x00; i <= 0xFF; ++i) {
    //     std::cout << "0x" << std::hex << i << " ";
    //     if ((i + 1) % 16 == 0) {
    //          decimal =hexadecimalToDecimal("i");
    //     }
    // }
    

    
    cout<<"Decimal number for given hexadecimal"<<hexadecimalToDecimal(hexadecimal)<<endl;   
    cout<<"R="<<getbit1(decimal,7)<<endl; 
    cout<<"F2="<<getbit1(decimal,6)<<endl;
    cout<<"E="<<getbit1(decimal,5)<<endl;

    // initialization with decimal number
    uint8_t lcid = decimal & 0x1F;
    bitset<5> decimalBitset(decimal);
    //uint8_t k = decimal;
    int data = static_cast<int> (lcid);
    cout << "Initialized with decimal: " << decimalBitset << endl;
    cout<<"Values of LCID for DL-SCH"<<endl;
    cout << "\n LCID data = " << data<<"\n";
    switch(data){
        case 0:
            cout<<"CCCH"<<endl;
            break;
        case 1 ... 10 :
            cout<<"Identity of the logical channel"<<endl;
            break;
        case 11 ... 25:
            cout<<"Reserved"<<endl;
            break;
        case 26:
            cout<<" Long DRX Command"<<endl;
            break;
        case 27:
            cout<<" Activation/Deactivation"<<endl;
            break;
        case 28:
            cout<<"UE Contention Resolution Identity "<<endl;
            break;
        case 29:
            cout<<"Timing Advance Command"<<endl;
            break;
        case 30:
            cout<<"DRX Command "<<endl;
            break;
        case 31:
            cout<<"Padding"<<endl;
            break;
        default :
            cout<<"Invalid LCID"<<endl;
            break;
    }
    return 0;
}