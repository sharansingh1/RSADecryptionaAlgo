#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


using namespace std;

bool areprime(int p)
{
    for (int i = 2; i < p; i++)
    {
        if (p % i == 0)
        { 
            return false;
        }
    }
    return true;
}

int arecoprime(int e, int phin)
{
    int g = 0;
    for (int i = 1; i <= e && i <= phin; i++)
    {
        if (e % i == 0 && phin % i == 0)
        {
            g = i;
        }
    }

    return g;
}

int main()
{
    int e;
    int n;
    int m;
    vector<int> ciphertext;

    cin >> e;
    cin >> n;
  
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int ct;
        cin >> ct;
        ciphertext.push_back(ct);

    }




    int p;
    int q;
    int phin;
    int d = 0;

    int lprime;
    int sprime;
    vector <int> primes;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            primes.push_back(i);


        }
    }



    lprime = primes.size() - 1;
    sprime = lprime - 1;
    p = primes[sprime];
    q = primes[lprime];
    phin = (p - 1) * (q - 1);


    for (int i = 1; i <= phin - 1; i++)
    {
        int x;
        x = (e * i) % phin;
        if (x == 1)
        {
            d = i;
        }
    }

    if (e <= 1 || n <= 1)
    {
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    else if (p == q)
    {
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    else if (areprime(p) == false || areprime(q) == false)
    {
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    else if (e > n)
    {
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    else if (arecoprime(e, phin) != 1)
    {
        cout << "Public key is not valid!" << endl;
        return 0;
    }

    cout << p << " " << q << " " << phin << " " << d << " " << endl;

   
   
   

    int cToTheD = 0;
    vector<int> D;
    int t = d - 1;
  //  cout << endl << "T IS: " << t << endl;
   for (int j = 0; j <= m-1; j++)
   {

    int c = ciphertext[j]; //84;
       int cprime = c;
       for (int i = 1; i <= t; i++)
       {
          d = t;
           cToTheD = c;
           if (d >= 0)
           {
               d = d - 1;

               cToTheD = (cprime * c); //* (c ^ (d));

               cprime = cToTheD % n;
               
           }
        
          
       }
       D.push_back(cprime);
   }
  
   for (int i = 0; i <= D.size() - 1; i++)
   {
       cout << D[i] << " ";
   }
   cout << endl; 
   for (int i = 0; i <= D.size() - 1; i++)
   {
       if (D[i] == 33)
       {
           cout << " ";
       }
       else if (D[i] == 34)
       {
           cout << '"';
       }
       else if (D[i] == 35)
       {
           cout << ",";
       }
       else if (D[i] == 36)
       {
           cout << ".";
       }
       else if (D[i] == 37)
       {
           cout << "'";
       }
       else
       {
           char message = D[i] + ('A' - 7);
           cout << message;
       }
   }

 
   
}



