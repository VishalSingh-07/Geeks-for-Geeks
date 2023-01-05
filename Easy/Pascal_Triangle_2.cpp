#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n)
{
      vector<vector<int>> triangle(n);
      // i--> rows and j--> column
      for (int i = 0; i < n;i++)
      {
            int row_size = i + 1;
            vector<int> row(row_size, 1); // initialize the element as 1 and increase vector in each row
            for (int j = 1; j < row_size - 1;j++)
            {
                  row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle[i] = row;
      }

      return triangle;
}
int main()
{
      int n;
      cout << "Enter number of rows of Pascal Triangle: ";
      cin >> n;

      vector<vector<int>> result=generate(n);

      for (int i = 0; i < result.size();i++)
      {
            for (int j = 0; j < result[i].size();j++)
            {
                  cout << result[i][j] << " ";
            }
            cout << endl;
      }

      return 0;
}

/*
Output--
Enter number of rows of Pascal Triangle: 5
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1
*/