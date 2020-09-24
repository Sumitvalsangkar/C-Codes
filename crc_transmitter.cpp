#include <iostream>
using namespace std;
int main()
{
    string msg, crc, encoded = "";
    cout << "Enter the Data to transmit= ";
    getline(cin, msg);
    cout << "Enter the Generator Polynomial = ";
    getline(cin, crc);
    int m = msg.length(), n = crc.length();
    encoded += msg;
    for (int i = 1; i <= n - 1; i++) //append n 0s to encoded msg

    {

        encoded += "0";
    }

    for (int i = 0; i <= encoded.length() - n;)

    {

        for (int j = 0; j < n; j++)

        {

            encoded[i + j] = encoded[i + j] == crc[j] ? '0' : '1';
        }

        for (; i < encoded.length() && encoded[i] != '1'; i++)
            ;
    }

    cout << "###### Transmitter End ####" << endl;

    cout << "Inout Polynomial = " << crc << endl;
    cout << "The Data to be transmitted = " << msg << endl;
    cout << "The Remainder = " << encoded.substr(encoded.length() - n + 1) << endl;

    cout << "The Data Transmitted with Remainder = " << msg + encoded.substr(encoded.length() - n + 1) << endl;
    return 0;
}
