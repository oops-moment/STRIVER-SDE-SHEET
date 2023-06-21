 sort(at,at+n);
    sort(dt,dt+n);
    int currentPlatform=1;
    int finalAnswer=1;
    
    int i=1;
    int j=0;

    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            currentPlatform++;
            i++;
        }
        else
        {   
            currentPlatform--;
            j++;
            // i++;
        }
        finalAnswer=max(finalAnswer,currentPlatform);
    
    }
    return finalAnswer;
