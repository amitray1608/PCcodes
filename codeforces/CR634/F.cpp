		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
 
		int cDist=0;
		int cMax=1;
		int cRep=1;
		/*
		for(int i=0;i<n-1;i++)
		{
			if(arr[i] ==arr[i+1])
				{
					cRep++;
					if(cRep>cMax)
						cMax=cRep;
				}
			else
				cRep=1;
		}
		*/
		unordered_set<int> dist(arr,arr+n);
		cout<<dist.size();
