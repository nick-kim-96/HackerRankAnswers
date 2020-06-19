#include <asm-generic/errno-base.h>
#include <bits/stdc++.h>
#include <math.h>
#include <pthread.h>
#include <cstdio>
#include <ctime>

using namespace std;

vector<string> split_string(string);

void countSort(vector <int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 
// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {

    std::clock_t start;
    double duration;

    start = std::clock();

    int ans = 0;

    if(d % 2 == 0)
    {
        int count = 0;
        int median = (d / 2) -1;
        vector<int> trailing;

        for(int i = 0; i < expenditure.size(); i++){
            if(i >= d)
            {
                countSort(trailing);
                if(expenditure[i] >= (expenditure[median] + expenditure[median +1])) {
                   ans++;
                }
            count++;
            trailing.erase(trailing.begin());
            }
            trailing.push_back(expenditure[i]);
        }
    }

    else {
        int count = 0;
        int median = d / 2;
        vector<int> trailing;

        for(int i = 0; i < expenditure.size(); i++){
            if(i >= d) {
                std::sort(trailing.begin(), trailing.end());
                if(expenditure[i] >= (2 * trailing[median])) {
                    ans++;
                }
            count++;
            trailing.erase(trailing.begin());
            }
            trailing.push_back(expenditure[i]);
        }
    }
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"printf: "<< duration <<'\n';

    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
