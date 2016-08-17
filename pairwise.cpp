#include <iostream>
#include <vector>

using namespace std;


long long MaxPairwise(const vector<int>& numbers){
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
        result = ((long long)numbers[i]) * numbers[j];
      }
    }
  }
  return result;
}

int main(){
  int n;
  cin >> n;
  vector<int> numbers(n);

  for(int i=0; i<n; ++i){
    cin >> numbers[i];
  }

  long long result = MaxPairwise(numbers);
  cout << "\n";
  cout << result;
  return 0;
}
