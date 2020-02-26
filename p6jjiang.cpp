#include <iostream>
#include <string>
#include<queue>

using namespace std;

struct type
{
	string name;
	float probability;
};

struct node
{
	string key;
	node* left;
	node* right;
};


void breadthfirst(node *t) {

	queue<node> q;
	node e;
	e.key = " ";

	q.push(*t);
	q.push(e);

	while (q.size() > 1) { // one nullptr will always remain in the list. So test for size>1

		*t = q.front();
		q.pop();
		if (!t) { cout << endl; q.push(e); continue; }

		
		if (t->left != NULL)
		{
			cout << "The left child is " << t->key << " " << endl;
			q.push(*t->left);
		}
		if (t->right != NULL)
		{
			q.push(*t->right);
			cout << "The left child is " << t->key << " " << endl;
		}
	}
}

node* tree(int *R[],type key[], int i, int j)
{
	int k = R[i][j]; 
	node* p;

	if (k == 0)
		return NULL;
	else
	{
		p = new node;
		p->key = key[k-1].name;
		cout<<key[k-1].name<<endl;
		p->left = tree(R, key, i, k - 1);
		p->right = tree(R,key, k+1, j);
		return p;
	}
}


void opSearchTree(int n, type p[], int & minavg, int *R[])
{

	int i, j, k, diagonal;
	float q,min,sum = 0;

	float **A = new float *[n + 2];

	for (i = 1; i < n + 2; i++)
	{
		A[i] = new float[n+1];
	}

	for (i = 1; i < n + 2; i++)
		for (j = 0; j < n + 1; j++)
			A[i][j] = 0;

	for (i = 1; i <= n; i++)
	{
		A[i][i + 1] = 0;
		A[i][i] = p[i-1].probability;
		R[i][i] = i;
		R[i][i - 1] = 0;
	}

	A[n + 1][n] = 0;
	R[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			min = 32767;
			
		
			for (k = 1; k <= j - 1; k++)
			{
				//For debugging
				//cout << endl<<"q = A[" << i << "][" << k-1 << "] + A[" << k + 1 << "][" << j << "] + sum" << endl;
				
				sum = 0;
				for(int a = i-1; a <j; a++)
				{
					sum += p[a].probability;
					//cout << "p " << a << " = " << p[a].probability << endl;
				}

				//cout << "q =" << A[i][k - 1] << " + " << A[k + 1][j] << " + " <<sum ;

				 q = A[i][k-1] + A[k + 1][j];

				if (q < min && q > 0)
				{
					//cout << " = " << q << endl;
					min = q;
					R[i][j] = k;
					//cout << "R[" << i << "]" << "[" << j << "]" << " = " << k;
				}
			}
			//cout <<endl<< "A[" << i << "]" << "[" << j << "]" << " = " << min<<endl<<endl;
			A[i][j] = min+sum;
			minavg = R[1][n];

		}


	cout << endl << "A: " << endl;

	//display the matrix that stores the minimum multiplication
	for (int a = 1; a <= n; a++)
	{
		cout << endl;
		for (int b = 1; b <= n; b++)
		{
			if (A[a][b] >= 0)
				cout << A[a][b] << " ";
			else
				cout << "   ";
		}
	}

	cout << endl << endl << "R: " << endl;

	//display the matrix that shows where to split the parenthesize
	for (int a = 1; a <= n; a++)
	{
		cout << endl;
		for (int b = 1; b <= n; b++)
		{
			if (R[a][b] >= 0)
				cout << R[a][b] << " ";
			else
				cout << "  ";
		}
	}
	cout << endl<<endl;


	tree(R,p,1,n);
}

int main()
{
	int numOfKey;
	int  minavg;

	cout << "Please enter the number of keys:";
	cin >> numOfKey;

	type * ary = new type[numOfKey];

	int ** R = new int *[numOfKey + 2];

	for (int i = 1; i < numOfKey + 2; i++)
	{
		R[i] = new int[numOfKey+1];
	}

	for (int i = 1; i < numOfKey + 2; i++)
		for (int j = 0; j < numOfKey + 1; j++)
			R[i][j] = 0;

	cout << endl << "Please enter the " << numOfKey << " keys : ";

	for (int i = 0; i < numOfKey; i++)
	{
		cin >> ary[i].name;
	}

	cout << "Please enter the " << numOfKey << " probabilities :";

	for (int i = 0; i < numOfKey; i++)
	{
		cin >> ary[i].probability;
	}

	for (int i = 0; i < numOfKey; i++)
	{
		cout << i << " name: " << ary[i].name << " p: " << ary[i].probability << endl;
	}


	cout << endl;

	opSearchTree(numOfKey,ary,minavg,R);



	char c;
	cin >> c;

	return 0;
}