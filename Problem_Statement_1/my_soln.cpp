#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

string decrypt(string str,int shift)         //function to decrypt code using known shift value
{
    int size = str.size();
    char ch;
    string str2;

    for(int i =0;i<size;i++)
    {
        ch = str[i];
        if(ch>=65 && ch<=90)
        {
            if(ch - shift >= 65)
                str2 += (char)(ch -shift);
            else
                str2 += (char)(ch - shift +26);
        }
        else if(ch>=97 && ch<=122)
        {
            if(ch - shift >= 97)
                str2 += (char)(ch -shift);
            else
                str2 += (char)(ch - shift +26);
        }else{
            str2 += ch;
        }
    }
    return str2;    


}

string autoDecrypt(string str){          //function to auto decrypt code using character frquency
    int score[26] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float frqData[]={8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07};
    string str2;
    int size = str.size();
    int sizeLetter =0;
    float counter=0;
    float percentage;

    
    for(int j=0;j<size;j++)
    {
        if(str[j] != ' ')
            sizeLetter++;
    }
    //cout<<sizeLetter<<endl;

    for(int i=0;i<26;i++)   
    {
        str2 = decrypt(str,i);
        //cout<< str2<<endl;


        for(int a=0;a<=26;a++)
        {
            for(int j=0;j<size;j++)
            {
                if(str2[j] == (char)(65+a) || str2[j] == (char)(97+a))
                counter ++;
            }
            //cout<<counter<<endl;
            percentage = counter/sizeLetter *100.0;
            score[i] += abs(percentage - frqData[a]); 
            //cout<<percentage<<endl;
            //cout<<score[i]<<endl;
            counter =0;
        }

        //cout<<score[i]<<endl;
        //cout<<endl;

    }
    int minindex =0;
    int minval =0;
    for(int i=0;i<=26;i++)
    {
        if(score[i] < minval){
            minval = score[i];
            minindex = i;
        } 
    }

    auto minElement = min_element(score,score +27);
    minindex = distance(score, minElement);
    //cout<<minindex;
    str2 = decrypt(str,minindex);
    //cout<<str2;

    //str2 = decrypt(str,minindex);
    return str2;
}




int main(){

    cout<<"Enter the serial no. of the task you want to do:"<<endl;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    cout<<"3. Auto Decryption"<<endl;
    int n;
    cin>> n;
    if(n==1){
        int shift,size;
        string str,str2;
        char ch;

        cout<<"Enter the message you want to encrypt"<<endl;
        while(str == ""){
        getline(cin , str,'\n');
        }

        cout<<"Enter the shift value"<<endl;
        cin>> shift;

        size = str.size();

        for(int i=0;i<size;i++)
        {
            ch = str[i];
            if(ch>=65 && ch<=90)
            {
                if(ch + shift <=90)
                    str2 += (char)(ch +shift);
                else
                    str2 += (char)(ch + shift -26);
            }
            else if(ch>=97 && ch<=122)
            {
                if(ch + shift <=122)
                    str2 += (char)(ch +shift);
                else
                    str2 += (char)(ch + shift -26);
            }else{
                str2 += ch;
            }
        }
        cout<<"Encrypted message is: "<<endl;
        cout<< str2;
        
    }else if(n ==2){

        string str,str2;
        int shift,size;
        char ch;
        

        cout<<"Enter the code you want to decrypt"<<endl;
        while(str ==""){
            getline(cin,str);
        }
        cout<<"Enter the shift value of this code"<<endl;
        cin>>shift;

        str2 = decrypt(str,shift);

        cout<<"Decrypted message is: "<<endl;
        cout<< str2;

    }else if(n==3){
        string str,str2;

        cout<<"Enter the code you want to decrypt"<<endl;
        while(str =="")
            getline(cin,str);

        str2 = autoDecrypt(str);
        cout<<"Decrypted message is : "<<endl;
        cout<<str2;

    }else{
        cout<<"Please enter a valid input";
    }


    return 0;
}