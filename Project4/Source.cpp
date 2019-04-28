#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

void sort(string a[], int n)
{
	int left, right, l, r;
	string mid;
	mid = left = right = l = r = 0;
	stack <int> st;
	for (int i = 0; i < 4; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	st.push(n - 1);
	st.push(0);
	do {
		left = st.top();
		st.pop();
		right = st.top();
		st.pop();
		{
			mid = a[(left + right) / 2];
			l = left;
			r = right;
			while (l < r)
			{
				while (a[l] < mid) l++;
				while (mid < a[r]) r--;
				if (l <= r)
				{
					swap(a[l], a[r]);
					l++;
					r--;
					for (int i = 0; i < 4; i++)
					{
						cout << a[i]<< " ";
					}
					cout << endl;
				}
			}
		}
		if (left < r)
		{
			st.push(r);
			st.push(left);
		}
		if (l < right)
		{
			st.push(right);
			st.push(l);
		}
	} while (st.size() != NULL);
}

void main()
{
	int n;
	cout << "Ved kol el" << endl;
	cin >> n;
	n = 4;
	string *a = new string[n];
	/*
	
	for (int i = 0; i < n; i++)
	{
		a[i] = '0' + rand() % 50;
	}
	*/
	for (int i = 0; i < n; i++)
	{
		cin>> a[i];
	}
	sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
}