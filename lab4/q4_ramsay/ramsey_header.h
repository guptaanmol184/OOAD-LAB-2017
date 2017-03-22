

int mutual_frenemy_available(int a[7][7],int c,int d,int f)
{
     if(a[c][d]==1 && a[d][f]==1 && a[c][f]==1)
      return 1;
    else if(a[c][d]==0 && a[d][f]==0 && a[c][f]==0)
      return 1;

    return 0;
	
}