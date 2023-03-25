// and i oops
#include <iostream>

using namespace std;

enum Errors
{
    Continue = 100,
    OK = 200,
    Created = 201,
    Accepted = 202,
    Badrequest = 400,
    Unauthorized = 401,
    Notfound = 404,
    Methodnotallowed = 405,
    Internalservererror = 500,
    Notimplemented = 501,
    Badgateway = 502
};

int main()
{
    int error = 1;
    while (error != 0)
    {
        cin >> error;
        if (error == Errors::Continue)
        {
            cout << "Continue" << ' ';
        }
        if (error == Errors::OK)
        {
            cout << "OK" << ' ';
        }
        if (error == Errors::Created)
        {
            cout << "Created" << ' ';
        }
        if (error == Errors::Accepted)
        {
            cout << "Accepted" << ' ';
        }
        if (error == Errors::Badrequest)
        {
            cout << "Bad Request" << ' ';
        }
        if (error == Errors::Unauthorized)
        {
            cout << "Unauthorized" << ' ';
        }
        if (error == Errors::Notfound)
        {
            cout << "Not Found" << ' ';
        }
        if (error == Errors::Methodnotallowed)
        {
            cout << "Method Not Allowed" << ' ';
        }
        if (error == Errors::Internalservererror)
        {
            cout << "Internal Server Error" << ' ';
        }
        if (error == Errors::Notimplemented)
        {
            cout << "Not Implemented" << ' ';
        }
        if (error == Errors::Badgateway)
        {
            cout << "Bad Gateway" << ' ';
        }
    }
    cout << endl;
    return 0;
}