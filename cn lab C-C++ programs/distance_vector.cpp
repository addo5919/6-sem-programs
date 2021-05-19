//reference-https://www.thelearningpoint.net/computer-science/c-program-distance-vector-routing-algorithm-using-bellman-ford-s-algorithm
#include<iostream> //program is correct (checked) . So dont make any changes
using namespace std;
struct routingTable//routing table
{
    int dist[20];
    int via[20];

};

int main()
{
    struct routingTable rt[20]; 
    int nodes,costmatrix[20][20],i,j,k,count=0;
    cout<<"\nEnter the no of routers:";
    cin>>nodes;
    
    for(i=0;i<nodes;i++)
    {
        cout<<"\nEnter the details of router "<<i<<":-";
        for(j=0;j<nodes;j++)
        {
            cout<<"\nEnter the distance to router "<<j<<" (999 if infinity):";
            cin>>costmatrix[i][j];
            rt[i].dist[j]=costmatrix[i][j];
            costmatrix[i][i]=0;//optional
            rt[i].via[j]=j;
        }
    }

    do{
        count=0;
        for(i=0;i<nodes;i++)
        {
         for(j=0;j<nodes;j++)
         {
             for(k=0;k<nodes;k++)
             {
                 if(rt[i].dist[j]>costmatrix[i][k]+rt[k].dist[j]) //cost matrix is important here
                 {
                     rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                     rt[i].via[j]=k;
                     count++;
                 }
             }
          }
        }
    }while(count!=0);

    for(i=0;i<nodes;i++)
    {
        cout<<"\nRouting table of router "<<i<<":-";
        for(j=0;j<nodes;j++)
        {
            cout<<"\nTo router "<<j<<": distance-"<<rt[i].dist[j]<<", via router-"<<rt[i].via[j];
        }
        cout<<"\n";
    }
return 0;
}