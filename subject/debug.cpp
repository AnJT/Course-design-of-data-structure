#include<iostream>
#include<queue>

using namespace std;

int main() {
  int N;
  cin >> N;
  priority_queue<int, vector<int>, greater<int> >p;
  for (int i = 0, x; i < N; i++) {
    cin >> x;
    p.push(x);
  }
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int u = p.top(); p.pop();
    int v = p.top(); p.pop();
    ans += u + v;
    p.push(u + v);
  }
  cout << ans << '\n';
}