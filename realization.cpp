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
	
void Character::incPar(string s, int n)
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

string Character::getName() const
{
	return name;
}
	
void Character::printPar() const
{
	cout << "Attack:" << attack << " Defence:" << defence << " Luck:" << luck << endl;
}



bool Fight(const Character& player, const Character& enemy)
{
	string s;
	cout << player.getName() << " VS " << enemy.getName() << endl;
	int a1 = player.getPar(1), a2 = enemy.getPar(1);
	int d1 = player.getPar(1), d2 = enemy.getPar(1);
	int l1 = player.getPar(1), l2 = enemy.getPar(1);
	cout << "Now your scills are: ";
	player.printPar();
	cout << "Your opponent has: ";
	enemy.printPar();
	while ((d1 > 0) && (d2 > 0))
	{
		cout << "You can attack or defence. Please choose your move" << endl;
		cin >> s;
		if (strcomp(s, "attack") >= strcomp(s, "defence"))
			d2 -= a1*l1 / 100;
		else
			d1 += d1*l1/100;
		cout << "Your enemy attack you by " << a2*l2 / 100 << " points" << endl;
		d1 -= a2*l2 / 100;
		cout << "At the end of turn you have " << d1 << " health points" << endl;
		cout << "Your enemy has " << d2 << " health points" << endl;
	}
	if (d2 <= 0)
		return(1);
	else
		return(0);
}




int game()
{
	Character player;
	Character enemy;
	string s;
	cout << "Hello. Please select game level:" << endl;
	cin >> s;
	if (strcomp(s, "hard") > strcomp(s, "easy"))
		enemy = Character("Enemy", 20, 20, 40);
	else
		enemy = Character("Enemy", 5, 5, 10);
	cout << "Welcome to arena.\n Do you want to create your character?" << endl;
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
		enemy.incPar("attack", 10);
		enemy.incPar("defence", 10);
		enemy.incPar("luck", 5);
	}

}