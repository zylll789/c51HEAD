int pow(int num, int a){
	int i = 0;
	int ans = 1;
	for(i; i < a; i++){
		ans *= num;
	}
	return ans;
}