#define _DEFINE_DEPRECATED_HASH_CLASSES 0
#include <unordered_set>
#include <iostream>
#include<string.h>
#include <bits/stdc++.h>
#include<vector>
#include <list>
#include <algorithm>

#include <hash_set>

#define _hashset_h

#include<hash_map>
#include<set>
#define MAX_SIZE 1000
//using namespace __gnu_cxx;
using namespace std;


void fifo(vector<int>, int);
bool searching (int,vector<int> );
void optimal(vector<int>,int);
int changeOptimal(vector <int>, vector<int>,int);
void LRU(vector<int>,int);
void clock(vector<int>,int);

int main()
{
    int numberOfFrames;
    char method[100];

    scanf("%d",&numberOfFrames);


    cin>>method;


    vector <int> vectorOfPages;

    int i;
    int input;
    int sizeVector;

    for(i=0; i<MAX_SIZE; i++)
    {


        cin >> input;
        if(input!=-1)
        {
            vectorOfPages.push_back(input);
        }
        else
        {
            vectorOfPages.shrink_to_fit();
            sizeVector=vectorOfPages.size();

            break;
        }

    }



    if( strcmp(method,"FIFO") ==0)
    {
        printf("Replacement Policy = FIFO\n");
        printf("-------------------------------------\n");
        printf("Page   Content of Frames\n");
        printf("----   -----------------\n");

        fifo(vectorOfPages,numberOfFrames);


    }

    if (strcmp(method,"LRU")==0)
    {

        printf("Replacement Policy = LRU\n");
        printf("-------------------------------------\n");
        printf("Page   Content of Frames\n");
        printf("----   -----------------\n");
        LRU(vectorOfPages,numberOfFrames);

    }


    if (strcmp(method,"CLOCK")==0)
    {
        printf("Replacement Policy = CLOCK\n");
        printf("-------------------------------------\n");
        printf("Page   Content of Frames\n");
        printf("----   -----------------\n");

        clock(vectorOfPages,numberOfFrames);

    }

    if (strcmp(method,"OPTIMAL")==0)
    {
        printf("Replacement Policy = OPTIMAL\n");
        printf("-------------------------------------\n");
        printf("Page   Content of Frames\n");
        printf("----   -----------------\n");

        optimal(vectorOfPages,numberOfFrames);
    }



}

void fifo( vector<int>vectorOfPages,int numberOfFrames)
{

    int numberOfPages=vectorOfPages.size();
    int temp;
    int pageFaults=0;
    queue <int> index;
    vector<int> frames;

    for(int i=0; i<numberOfPages; i++)
    {


        if(frames.size()<numberOfFrames)
        {
            temp=vectorOfPages[i];
            bool   boolean= searching(vectorOfPages[i],frames);
            if(!boolean)

            {
                frames.push_back(vectorOfPages[i]);
                index.push(temp);

                printf("%02d",vectorOfPages[i]);
                printf("     ");

                for (int j = 0; j < frames.size(); j++)

                {

                    printf("%02d ",frames.at(j));

                }

                printf("\n");


            }

            if(boolean)
            {

                printf("%02d     ",vectorOfPages[i]);


                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");



            }


        }


        else
        {

            bool  boolean= searching(vectorOfPages[i],frames);
            if(!boolean)
            {

                int value=index.front();
                index.pop();
                auto it = std::find(frames.begin(), frames.end(), value);
                frames.erase(it);
                frames.insert(it,vectorOfPages[i]);
                index.push(vectorOfPages[i]);
                pageFaults++;

                printf("%02d",vectorOfPages[i]);
                printf(" F   ");

                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");




            }
            if(boolean)
            {

                printf("%02d     ",vectorOfPages[i]);


                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");







            }
        }





    }

    printf("-------------------------------------\n");


    printf("Number of page faults = %d\n",pageFaults);




}









void optimal ( vector <int> vectorOfPages,int numberOfFrames)
{
    int page_faults2=0;
   // int changeIndex;
    int numberOfPages= vectorOfPages.size();
    bool boolean ;
    vector <int> frames;

    for (int i=0; i<numberOfPages; i++)
    {

        boolean= searching(vectorOfPages[i],frames);

        if(!boolean)
        {

            if(frames.size()<numberOfFrames)
            {

                frames.push_back(vectorOfPages[i]);
                printf("%02d",vectorOfPages[i]);
                printf("     ");

                for (int j = 0; j < frames.size(); j++)

                {

                    printf("%02d ",frames.at(j));

                }

                printf("\n");

            }

            else
            {

                int changeIndex=-1;
                int index=i+1;
                int far =index;
                for (int k = 0; k < frames.size(); k++)
                {  int j;
                    for (j = index; j < numberOfPages; j++)
                    {if (frames[k] == vectorOfPages[j])
                        {if (j > far)
                            {far = j;
                            changeIndex = k;}
                            break;}
                    }
                    if (j == numberOfPages)
                    {changeIndex= k;
                        continue;
                    }
                    else
                        changeIndex=0;
                }
                frames[changeIndex]=vectorOfPages[i];
                page_faults2++;

                printf("%02d",vectorOfPages[i]);
                printf(" F   ");

                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");



            }



        }


        if(boolean)
        {
            printf("%02d",vectorOfPages[i]);
            printf("     ");
            for (int j = 0; j < frames.size(); j++)

            {

                printf("%02d ",frames.at(j));

            }

            printf("\n");

        }




    }


    cout<<"-------------------------------------"<<endl;


    printf("Number of page faults = %d\n",page_faults2);
}


void LRU(vector<int> vectorOfPages,int numberOfFrames)
{
    vector <int> :: iterator it;
    int MAX_VALUE=1000;
    int page_faults=0;
    bool boolean;
    vector<int> frames;
    unordered_map<int,int> myMap;
    int numberOfPages= vectorOfPages.size();
    int value;

    for (int i=0; i<numberOfPages; i++)
    {
        boolean= searching(vectorOfPages[i],frames);


        if(!boolean)
        {

            if(frames.size()<numberOfFrames)
            {

                frames.push_back(vectorOfPages[i]);

                myMap[vectorOfPages[i]]=i;

                printf("%02d",vectorOfPages[i]);
                printf("     ");

                for (int j = 0; j < frames.size(); j++)

                {

                    printf("%02d ",frames.at(j));

                }

                printf("\n");


            }

            else  //if no place left
            {
                int lru=MAX_VALUE;

                for (it = frames. begin(); it != frames. end(); it++)
                {if(myMap[*it]<lru)
                    {lru=myMap[*it];
                     value=*it;}
                }
                page_faults++;
               auto index = std::find(frames.begin(), frames.end(), value);
                int temp=vectorOfPages[i];
                frames.erase(index);
                frames.insert(index,vectorOfPages[i]);
                myMap[temp]=i;

                printf("%02d",vectorOfPages[i]);
                printf(" F   ");

                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");


            }

        }



        if(boolean)
        {

            myMap[vectorOfPages[i]]=i;

            printf("%02d",vectorOfPages[i]);
            printf("     ");
            for (int j = 0; j < frames.size(); j++)

            {

                printf("%02d ",frames.at(j));

            }

            printf("\n");

        }


    }


    cout<<"-------------------------------------"<<endl;


   printf("Number of page faults = %d\n",page_faults);

}


void clock(vector<int> vectorOfPages,int numberOfFrames)
{

    vector<int> frames;
    int numberOfPages=vectorOfPages.size();
    int page_faults=0;
    bool boolean;
    bool arrayOfBoolean[numberOfFrames];
    int pointer=0;
    int y;

    for(int j=0; j<numberOfFrames; j++)
    {

        arrayOfBoolean[j]=false;  //there is no *

    }


    for(int i=0; i<numberOfPages; i++)
    {

        boolean=searching(vectorOfPages[i],frames);


        if(!boolean)  //page not found in frames
        {

            if(frames.size()<numberOfFrames)  //there's a place in frames
            {

                frames.push_back(vectorOfPages[i]);  //insert the page in frames


                arrayOfBoolean[pointer]=true; //put *

                if(pointer<numberOfFrames-1)
                {
                    pointer++;

                }
                else
                {
                    pointer=0;
                }


                printf("%02d",vectorOfPages[i]);
                printf("     ");
                for (int j = 0; j < frames.size(); j++)

                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");


            }


            else  //no place to push_back
            {


                for( y=pointer; y<=frames.size(); y++)
                {


                    if(arrayOfBoolean[pointer]==false)
                    {

                        frames[pointer]=vectorOfPages[i];

                        arrayOfBoolean[pointer]=true;

                         if(pointer<numberOfFrames-1)
                    {
                        pointer++;

                    }
                    else
                    {
                        pointer=0;

                    }




                        break;

                    }

                    else
                    {
                        arrayOfBoolean[pointer]=false;

                         if(pointer<numberOfFrames-1)
                    {
                        pointer++;

                    }
                    else
                    {
                        pointer=0;

                    }




                    }



                }





                page_faults++;

                printf("%02d",vectorOfPages[i]);
                printf(" F   ");

                for (int j = 0; j < frames.size(); j++)
                {
                    printf("%02d ",frames.at(j));

                }

                printf("\n");

            }
        }


        if(boolean)  //found
        {

            if(!arrayOfBoolean[pointer])  //false  there is no *
            {

                arrayOfBoolean[pointer]=true;  //if there is no * put an *

            }


            printf("%02d",vectorOfPages[i]);
            printf("     ");
            for (int j = 0; j < frames.size(); j++)

            {

                printf("%02d ",frames.at(j));

            }

            printf("\n");

        }


    }

    cout<<"-------------------------------------"<<endl;


    printf("Number of page faults = %d\n",page_faults);

}


bool searching(int key,vector <int> frames)
{if(std::find(frames.begin(), frames.end(), key) != frames.end() )
return true;   //found
else return false;   //not found
}

