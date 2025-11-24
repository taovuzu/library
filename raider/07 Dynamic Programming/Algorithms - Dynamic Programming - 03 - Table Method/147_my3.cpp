
const int COINS = 11;
const int MAX_COIN = 30000+1;

int coins[COINS] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

ll mem[COINS][MAX_COIN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in", "rt", stdin);
#endif

	lp(j, COINS)
		mem[j][0] = 1;

	for (int coin = coins[0]; coin < MAX_COIN; coin += 5) {	// problem said request will be %5 = 0

		for (int j = 0; j < COINS; ++j) {
			if(j)
				mem[j][coin] = mem[j-1][coin];
			if(coin-coins[j] >= 0)
				mem[j][coin] += mem[j][coin-coins[j]];
		}
	}


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
			<<mem[COINS-1][val]
			<<"\n";
	}


	return 0;
}
