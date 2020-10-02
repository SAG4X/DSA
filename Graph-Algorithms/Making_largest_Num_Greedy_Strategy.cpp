#include <iostream>
#include <vector>

using namespace std;

//Finding the max Digit
int largestNum(vector<int> numvec)
{
  int tmp = 0;
  int p = 0;
  for (int i = 0; i < numvec.size(); i++)
  {
    if (numvec[i] >= tmp)
    {
      tmp = numvec[i];
      p = i;
    }
  }
  return p;
}

int main()
{
  vector<int> numvec;
  vector<int> newvec;

  int num;
  int dig;
  int pos;

  cout << "Enter the No. of Digits :";

  cin >> num;
  for (int i = 0; i < num; i++)
  {
    cout << "Enter the Digits:";
    cin >> dig;
    numvec.push_back(dig);
  }

  cout << "\n Digits you entered : ";
  for (int i = 0; i < numvec.size(); i++)
  {
    cout << numvec[i];
  }

  while (true)
  {

    pos = largestNum(numvec);

    newvec.push_back(numvec[pos]);
    numvec.erase(numvec.begin() + pos);

    if (numvec.size() == 0)
    {
      cout << "\n Largest Number that can be made : ";
      for (int i = 0; i < newvec.size(); i++)
      {
        cout << newvec[i];
      }
      exit(1);
    }
  }

  return 0;
}