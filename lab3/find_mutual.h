//#include <iostream>
using namespace std;
int mutual_frenemy_available(int a[7][7])
{
	int i,j,k=0,n=7;
	  
      for(i=0;i<n;i++)
      	for(j=i;j<n;j++)
      	{
      		if(a[i][j]==1)
      		{
              for(k=j+1;k<n;k++)
              {
              	if(a[i][k]==1)
              	{
              		if(a[j][k]==1)
                    {
                      cout<<"Mutual friends: {"<<i<<","<<j<<","<<k<<"}"<<endl;
                	     return(1);
                    }
              	}
            }
        }
        else if(a[i][j]==0) 
        {
            for(k=j+1;k<n;k++)
            {
              if(a[i][k]==0)
              {
                if(a[j][k]==0)
                {
                  cout<<"Mutual enemies: {"<<i<<","<<j<<","<<k<<"}"<<endl;
        		    	 return(1);
                }
        	  }
        	}
          }
      	}
return(0);
}