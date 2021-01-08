#include<string.h>
#include<cstring>
#include<stdio.h>
#include<math.h>
#include <iostream>
#include "queue.h"
using namespace std;
Queue <int> q;
bool dump=false;
int dump1=0;
int item=0,res;
int main(int argc,char* argv[])
{   if(argc<=5) {cout<<"Invalid Configuration"; return 0;}
    int n=argv[1][0]-48;
    int input=0;
    int m=argv[2][0]-48;
    int init= argv[3][0]-48;
    for(unsigned i=1;i<strlen(argv[1]);i++)
    {
            n=10*n+(argv[1][i]-48);
    }
    for(unsigned j=1;j<strlen(argv[2]);j++)
    {
            m=10*m+(argv[2][j]-48);
    }
    for(unsigned k=1;k<strlen(argv[3]);k++)
    {
            init=10*init+(argv[3][k]-48);
    }
    int maxseqbits=pow(2,n)-1;
    int windowsize=pow(2,m);
    int result=init-1;
    if(!(init<=maxseqbits))
    {
        cout<<"Invalid Configuration";
        return 0;
    }
    for(int i=1;i<4;i++)
    {
        for(unsigned j=0;j<strlen(argv[i]);j++)
            {
                if(!(argv[i][j]>=48&&argv[i][j]<=57)){cout<<"Invalid Configuration"; return 0;}
            }
    }
    for(int i=4;i<argc;i++)
    {
        if(argv[4][0]!=':'||argv[4][1]!=0) {cout<<"Invalid Configuration"; return 0;}
        if(i!=4)
        {
            for(unsigned j=0;j<strlen(argv[i]);j++)
            {
                if(!(argv[i][j]>=48&&argv[i][j]<=57)){cout<<"Invalid Packet"; return 0;}
            }
            input = argv[i][0]-48;
            for(unsigned f=1;f<strlen(argv[i]);f++)
            {
                    input=10*input+(argv[i][f]-48);
            }
            if(input>maxseqbits && argc>5) {cout<<"Invalid Packet"; return 0;}
        }
    }
    cout<<"R ";
    for(int i=5;i<argc;i++)
    {
        input = argv[i][0]-48;
        for(unsigned f=1;f<strlen(argv[i]);f++)
        {
                input=10*input+(argv[i][f]-48);
        }
        if(input<=maxseqbits)
            {
                if(input<init)
                    {
                        input=input+maxseqbits+1;
                    }
                if(input>init && input<=init+windowsize-1)
                {
                    q.enqueue(input,dump);
                    if(dump==true)
                        {
                            dump1++;
                            dump= false;
                        }

                }
                else if(input==init)
                {
                    q.enqueue(input,dump);
                    if(dump==true)
                        {
                            dump1++;
                            dump= false;
                        }
                    q.dequeue(result);
                    if(result>maxseqbits)
                        result=result-maxseqbits-1;
                    cout<<result<<" ";
                    init=result+1;
                    if(init>maxseqbits)
                        init=init-maxseqbits-1;
                }

                else
                    {
                        dump1++;
                    }
            }
        q.Front(res);
        if(res>maxseqbits)
            res=res-maxseqbits-1;
        while(!q.isEmpty() && res==init)
        {
            q.dequeue(result);
            if(result>maxseqbits)
                result=result-maxseqbits-1;
            cout<<result<<" ";
            q.Front(res);
            init=result+1;
            if(init>maxseqbits)
                init=init-maxseqbits-1;
        }
    }
    cout<<"E "<<init<<' ';
    cout<<"W ";
    while(!q.isEmpty())
    {
        q.dequeue(result);
        if(result>maxseqbits)
            result=result-maxseqbits-1;
        cout<<result<<" ";
    }
    cout<<"D# "<<dump1;
    return 0;
}
