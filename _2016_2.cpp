#include <iostream>
#include <fstream>

using namespace std;

struct pratimas
{
    string name = "Error";
    int n = 0;
};

void mysort(pratimas arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].n > arr[j].n)
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    int n;
    pratimas pratimai[100];
    duom >> n;

    for (int i = 0; i < n; i++)
    {
        bool used = 0;
        char temp[22];
        duom.ignore();
        duom.get(temp, 22);
        string name = temp;
        int x;
        duom >> x;
        for (int j = 0; j < n; j++)
        {
            if (name == pratimai[j].name)
            {
                pratimai[j].n += x;
                used = 1;
                break;
            }
        }
        if(!used)
        {
        pratimai[i].name = name;
        pratimai[i].n = x;
        }
    }
    mysort(pratimai, n);

    for (int i = 0; i < n; i++)
    {
        if(pratimai[i].name!= "Error")
        rez << pratimai[i].name << pratimai[i].n << '\n';
    }
    duom.close();
    rez.close();
    return 0;
}
