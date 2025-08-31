#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

char decrypt(char ch,int shift)         //function to decrypt code using known shift value
{
        if(ch>=65 && ch<=90)
        {
            if(ch - shift >= 65)
                ch = (char)(ch -shift);
            else
                ch = (char)(ch - shift +26);
        }
        else if(ch>=97 && ch<=122)
        {
            if(ch - shift >= 97)
                ch = (char)(ch -shift);
            else
                ch = (char)(ch - shift +26);
        }
    return ch;    
}

char encrypt(char ch,int shift)
{
        if(ch>=65 && ch<=90)
        {
            if(ch + shift <=90)
                ch = (char)(ch +shift);
            else
                ch = (char)(ch + shift -26);
        }
        else if(ch>=97 && ch<=122)
        {
            if(ch + shift <=122)
                ch = (char)(ch +shift);
            else
                ch = (char)(ch + shift -26);
        }
    
    return ch;
}

string KeyEncrypt(string str,string keyword)     //To encryt the string using varying shift values according to the keyword
{
    int sizeStr = str.size();
    int sizeKey = keyword.size();
    int arr[sizeKey];
    for (int i=0;i<sizeKey;i++) {
        keyword[i] = toupper(keyword[i]);    // Convert each character to uppercase and store the corresponding shift value in an array
        arr[i] = (int)(keyword[i]) - 65;
        //cout<<arr[i]<<endl;
    }
    
    string str2;

    //extract characters from the string one by one and shift them according to the array to create the encrypted string
    char ch;
    for(int i=0;i<sizeStr;i++)
    {
        ch = str[i];
        ch = encrypt(ch,arr[i%sizeKey]);
        str2 += ch;
    }
    return str2;
}

string KeyDecrypt(string str,string keyword)    //To decrypt the string using varying shift values according to the keyword
{
    int sizeStr = str.size();
    int sizeKey = keyword.size();
    int arr[sizeKey];

    for (int i=0;i<sizeKey;i++) {
        keyword[i] = toupper(keyword[i]);    // Convert each character to uppercase and store the corresponding shift value in an array
        arr[i] = (int)(keyword[i]) - 65;
        //cout<<arr[i]<<endl;
    }

    string str2;

    char ch;
    for(int i=0;i<sizeStr;i++)
    {
        ch = str[i];
        ch = decrypt(ch,arr[i%sizeKey]);
        str2 += ch;
    }
    return str2;
}


int main()
{
    /*string str1 = KeyEncrypt("Hello World ","Keyword");
    cout<<str1;
    cout<< KeyDecrypt(str1,"Keyword");*/

    cout<<"Enter the serial no. of the task you want to do:"<<endl;
    cout<<"1. Encryption Using Keyword"<<endl;
    cout<<"2. Decryption Using Keyword"<<endl;

    int n;
    cin>> n;
    if(n==1){
        string str,str2,keyword;

        cout<<"Enter the message you want to encrypt"<<endl;
        while(str == ""){
            getline(cin , str,'\n');
        }

        cout<<"Enter the keyword"<<endl;
        while(keyword == ""){
            getline(cin , keyword,'\n');
        }

        str2 = KeyEncrypt(str,keyword);
        cout<<"Encrypted message is: "<<endl;
        cout<< str2<<endl;
        cout<<endl;
    }else if(n==2){
        string str,str2,keyword;

        cout<<"Enter the message you want to decrypt"<<endl;
        while(str == ""){
        getline(cin , str,'\n');
        }

        cout<<"Enter the keyword"<<endl;
        while(keyword == ""){
            getline(cin,keyword,'\n');
        }

        str2 = KeyDecrypt(str,keyword);
        cout<<"Decrypted message is: "<<endl;
        cout<< str2<<endl;
        cout<<endl;

    }else{
        cout<<"Invalid Input";
        return 0;
    }

    return 0;
}
