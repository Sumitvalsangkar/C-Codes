#include <iostream>
using namespace std;
int main()
{
    string crc, encoded;

    cout << "Enter the Data Received = ";
    getline(cin, encoded);
    cout << "Enter the Generator Polynomial = ";
    getline(cin, crc);
    cout << "###### Receiver End ####" << endl;
    cout << "Data Received = " << encoded << endl;
    int n = crc.length();
    for (int i = 0; i <= encoded.length() - n;) //changed the Received data

    {

        for (int j = 0; j < n; j++) //performed the division

        {

            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }

        for (; i < encoded.length() && encoded[i] != '1'; i++)
            ;
    }

    cout << "Divide with Polynomial = " << crc << endl;

    cout << "Remainder = " << encoded.substr(encoded.length() - n + 1) << endl;

    for (char i : encoded.substr(encoded.length() - n)) // checking the Error

    {

        if (i != '0')
        {

            cout << "Error detected in communication	" << endl;

            return 0;
        }
    }

    cout << "No any error detected in communication	" << endl;

    return 0;
}
