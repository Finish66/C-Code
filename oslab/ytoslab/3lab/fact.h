int fact(int n){
	int i , ans = 1;
	if(n < 0)
		return -1;
	else{
		for(int i = 1 ;i <= n;i++){
			ans *= i;
		}	
	}

	return ans;
}
