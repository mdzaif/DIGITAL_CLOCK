//Digital Clock.
//Source Code.
/*#include<iostream>
#include<iomanip>
#include<unistd.h>
*/
#include<bits/stdc++.h>
using namespace std;

//color scheme.
void Cyan()
{
    cout<<"\033[0;36m";
}
void Green()
{
    cout<<"\033[0;32m";
}
void Reset()
{
    cout<<"\033[0m";
}

//create the Clear function to clean the console
void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

//driver code
int main()
{
    int h, m, s;
    string format;
    cout<<"SET TIME"<<endl;
    cout<<"---------"<<endl;
    cout<<"Hours: ";
    cin>>h;
    cout<<"Minutes: ";
    cin>>m;
    cout<<"Seconds: ";
    cin>>s;
    cout<<"AM/PM: ";
    cin>>format;
    cout<<endl;

    if(h>12||m>60||s>60)
    {
            cout<<"Error!"<<endl;
            exit(0);

    }
    if(format != "PM" && format != "AM" && format != "pm" && format != "am")
    {
        cout<<"Error!"<<endl;
        exit(0);
    }
    //leap year
    std::transform(format.begin(), format.end(), format.begin(), ::toupper);
    while(1)
    {
        s++;
        if(s>59)
        {
            m++;
            s = 0;
        }
        if(m>59)
        {
            h++;
            m = 0;
        }

        if(h>12)
        {
            h = 1;
        }
        if(h == 12 && m == 0 && s==0)
            {
                 if(format == "AM")
                 {
                     format = "PM";
                 }

                 else
                 {
                     format = "AM";
                 }
             }

        //to enable the console cursor.
        //cout<<"\e[?25h";
        //to disable the console cursor.
        cout<<"\e[?25l";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
        Cyan();
        cout<<"\t\t\t\t\t\t\t\t\t      _DIGITAL CLOCK_"<<endl;
        Reset();
        cout<<"\t\t\t\t\t\t\t\t-------------------------------------------"<<endl;
        cout.fill('0');
        Green();
        cout<<"\t\t\t\t\t\t\t\t\t        "<<setw(2)<<h<<":"<<setw(2)<<m<<":"<<setw(2)<<s<<" "<<format<<endl;
        Reset();
        cout<<"\t\t\t\t\t\t\t\t-------------------------------------------"<<endl;

        //sleep function under unistd.h library.
        //sleep(1);//for 1 second.
        //for 1 second. count in sec. = microsecond.
        usleep(1000000);

        //Clear function to clean the console.
        Clear();

    }
    return 0;

}
