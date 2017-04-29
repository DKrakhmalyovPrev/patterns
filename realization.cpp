#include "Header.h"

int strcomp(string& a,const string& b)
{
	int i = 0;
	for (int j = 0;j < a.length();j++)
	{
		if (a[j] == b[i])
		{
			i++;
		}
		if (i >= b.length())
		{
			return(b.length());
		}
	}
	return(i);
}

Character::Character(string n , short a , short d, short l): 
		name(n), attack(a), defence(d), luck(l)
	{
		
	}
	
void Character::incPar(string& s, int n)
	{
		int a = strcomp(s, "attack");
		int b = strcomp(s, "defence");
		int c = strcomp(s, "luck");
		if ((c > a) && (c > b))
			luck += n;
		else
			if (b > a)
				defence += n;
			else
				attack += n;
	}
	
int Character::getPar(int n) const
	{
		if (n == 1)
			return(attack);
		if (n == 2)
			return(defence);
		if (n == 3)
			return(luck);
	}
	



bool Fight(const Character& player, const Character& enemy)
{
	int a1 = player.getPar(1), a2 = enemy.getPar(1);
	int d1 = player.getPar(1), d2 = enemy.getPar(1);
	int l1 = player.getPar(1), l2 = enemy.getPar(1);
	while ((d1 > 0) && (d2 > 0))
	{
		d2 -= a1*l1 / 100;
		d1 -= a2*l2 / 100;
	}
	if (d2 <= 0)
		return(1);
	else
		return(0);
}




int game()
{
	Character player;
	string s;
	cout << "Welcome to arena.\n Do you want to create your character?";
	cin>>s;
	if (strcomp(s, "yes") > strcomp(s, "no"))
	{
		string n;
		cout << "Print name of your character"<< endl;;
		cin >> n;
		cout << "Hello, " << n << ". You have 100 points for you attack, defence and luck. Divide them." << endl;
		int a, b, c;
		cin >> a >> b >> c;
		while (a + b + c > 100)
		{
			cout << "Sum of characteristics should be not more than 100. Please repeat." << endl;
			cin >> a >> b >> c;
		}
		player = Character(n, a, b, c);
	}
	else
	player = Character();
	
	for (int i = 1;i < 11;i++)
	{
		cout << "Welcome to the " << i << " stage of the tournament." << endl;
		Character enemy("Enemy", 5 * i, 5 * i, 10 * i);
		bool result = Fight(player, enemy);
		if (result == 0)
		{
			cout << "You lost. Do you want to start new game?" << endl;
			cin >> s;
			if (strcomp(s, "yes") > strcomp(s, "no"))
				return(1);
			else
				return(0);
		}
		else
		{
			if (i != 10)
			{
				cout << "You can increase your skill by 20 points. Select, what skill you will increase." << endl;
				cin >> s;
			}
			player.incPar(s, 20);
		}
	}

}