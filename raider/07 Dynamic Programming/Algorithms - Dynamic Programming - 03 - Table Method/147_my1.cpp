const int COINS = 11;
const int MAX_COIN = 30000+1;

int coins[COINS] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

ll mem[COINS][MAX_COIN];

ll nWays(int idx, int rem)
{
	if(rem == 0)
		return 1;

	if(rem < coins[idx] || idx == COINS)
		return 0;

	ll &ret = mem[idx][rem];

	if(ret != -1)
		return ret;

	ret = nWays(idx+1, rem);	//Leave it

	while(rem - coins[idx] >= 0) {
		ret += nWays(idx+1, rem - coins[idx]);
		rem -= coins[idx];
	}

	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	clr(mem, -1);

	double n;
	while(cin>>n)
	{
		int val = (int)(n*100 + EPS);
		if(val == 0)
			break;

		cout<<setiosflags(ios::fixed)
			<<setiosflags(ios::showpoint)
			<<setprecision(2)
			<<setw(6)
			<<n
			<<setw(17)
			<<nWays(0, val)
			<<"\n";
	}


	return 0;
}
