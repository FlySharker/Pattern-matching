#include<bits/stdc++.h>
using namespace std;
int bf_find(string& ob, string& pat,int &c) {
	int i = 0, j = 0, k = 0;
	while (i < ob.size() && j < pat.size() && pat.size() - j <= ob.size() - i) {
		if (ob[i] == pat[j]) {
			i++;
			j++;
			k++;
		}
		else {
			i = i - j + 1;
			j = 0;
			k++;
		}
	}
	c = k;
	if (j >= pat.size()) return 1;
	else return -1;
}

void GetNext(string& pat, int* next) {
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < pat.size() - 1) {
		if (k == -1 || pat[j] == pat[k]) {
			next[++j] = ++k;
		}
		else k = next[k];
	}
}

int kmp(string& ob, string& pat, int& c) {
	int* next = new int[pat.size()];
	GetNext(pat, next);
	int i = 0, j = 0, m = 0;
	int x = j - pat.size();
	while (i < ob.size()&&pat.size()-j<=ob.size()-i&&x<0){
		if (j == -1 || ob[i] == pat[j]) {
			if (j != -1) m++;
			i++;
			j++;
		}
		else {
			j = next[j];
			m++;
		}
		x = j - pat.size();
	}
	c = m;
	delete[]next;
	if (j >= pat.size()) return 1;
	else return -1;
}

void s_GetNext(string& pat, int* next) {
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < pat.size() - 1) {
		if (k == -1 || pat[j] == pat[k]) {
			k++;
			j++;
			if (pat[j] != pat[k]) next[j] = k;
			else next[j] = next[k];
		}
		else k = next[k];
	}
}

int s_kmp(string& ob, string& pat, int& c) {
	int* next = new int[pat.size()];
	s_GetNext(pat, next);
	int i = 0, j = 0, m = 0;
	int x = j - pat.size();
	while (i < ob.size() && x<0 && pat.size() - j <= ob.size() - i) {
		if (j == -1 || ob[i] == pat[j]) {
			if (j != -1) m++;
			i++;
			j++;
		}
		else {
			j = next[j];
			m++;
		}
		int x = j - pat.size();
	}
	c = m;
	if (j >= pat.size()) return 1;
	else return -1;
}

int main() {
	string ob = "aaaacaaaaab";
	string pat = "aaaaab";
	int d1 = 0, d2 = 0, d3 = 0;
	cout << "BF算法："<< bf_find(ob, pat, d1) << endl;
	cout << "比较次数：" << d1 << endl;
	cout << endl;
	cout << "KMP算法：" << kmp(ob, pat, d2) << endl;
	cout << "比较次数：" << d2 << endl;
	cout << endl;
	cout << "KMP优化算法：" << s_kmp(ob, pat, d3) << endl;
	cout << "比较次数：" << d3 << endl;
	cout << endl;
	return 0;
}