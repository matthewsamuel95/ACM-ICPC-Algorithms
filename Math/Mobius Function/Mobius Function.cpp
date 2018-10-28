const int N = 2e6 + 5, mod = 1e9 + 7;
bitset<N> prime;
vector<int> divs[N];
int mobius[N];
int pw[N];

void getMobius()
{
	reset(mobius, -1);
	mobius[1] = 1;

	for (int i = 2; i < N; i++)
	{
		divs[i].push_back(i);
		if (!prime[i])
		{
			mobius[i] = 1;
			for (int j = i + i; j < N; j += i)
				prime[j] = true, mobius[j] =
						j % (i * 1ll * i) == 0 ? 0 : -mobius[j], divs[j].push_back(
						i);
		}
		else
		{
			if (!mobius[i])
				continue;
			for (int j = i + i; j < N; j += i)
				divs[j].push_back(i);
		}
	}
}
