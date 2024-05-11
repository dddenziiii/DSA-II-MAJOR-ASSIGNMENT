/*
  ><><>< BURAK DENIZ KARAKAYA ><><><
  ><><>< 221504036 ><><><

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPartValid(string part) {
    int length = part.length();
    if (length > 3)
        return false;
    if (part[0] == '0' && length > 1)
        return false;
    int num = stoi(part);
    return num >= 0 && num <= 255;
}

void generateIPAddresses(string str, int position, vector<string>& result, vector<string>& current) {
    if (current.size() == 4 && position == str.length()) {
        result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]);
        return;
    }
    if (current.size() == 4 || position == str.length())
        return;

    for (int len = 1; len <= 3 && position + len <= str.length(); ++len) {
        string part = str.substr(position, len);
        if (isPartValid(part)) {
            current.push_back(part);
            generateIPAddresses(str, position + len, result, current);
            current.pop_back();
        }
    }
}

vector<string> generateIP(string &str) {
    vector<string> result;
    if (str.length() < 4 || str.length() > 12)
        return {"-1"};
    vector<string> current;
    generateIPAddresses(str, 0, result, current);
    if (result.empty())
        return {"-1"};
    return result;
}

int main() {
    string ipAddress = "12345";
    vector<string> result = generateIP(ipAddress);
    if (result.size() == 1 && result[0] == "-1")
        cout << "Output: -1" << endl;
    else {
        cout << "Output:";
        cout << endl;
        for (auto ip : result)
        {
            cout << " " << ip;
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
