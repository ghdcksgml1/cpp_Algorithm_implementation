#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}


int main(void) {
	int N;
	int n1[100001], n2[100001];
	cin >> N;
	vector<pair<int,int>> v;
	for (int i = 0; i < N; i++) {
		cin >> n1[i];
		cin >> n2[i];
		v.push_back(pair<int, int>(n1[i], n2[i]));
	}

	sort(v.begin(), v.end(),compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first<< ' '<<v[i].second<<endl;
	}
}