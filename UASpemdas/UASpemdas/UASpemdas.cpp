// UASpemdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


struct nilai
{
    int x;
    int y;
};

int main()
{
    nilai data[100];
    int banyak;
    int i;
    float hasil;
    int hasil1[100];
    int hasilsigmaxy;
    int hasilsigmax;
    int hasilsigmay;
    int hasilsigmaxpangkat2;
    int hasilsigmaxdipangkat2;
    int hasilsigmaypangkat2;
    int hasilsigmaydipangkat2;
    int hasilkoefisien;
    string korelasi;
    string bernilai;
    
    //main
    cout << "masukkan banyak data : "; cin >> banyak;

    for (int i = 1; i <= banyak; i++)
    {
        cout << "nilai x ke-" << i << " = "; cin >> data[i].x;
        cout << "nilai y ke-" << i << " = "; cin >> data[i].y;
    }

    cout << "------------------------------------" << endl;

    //sigmaxy
    for (int i = 1; i <= banyak; i++)
    {
        hasil1[i] = data[i].x * data[i].y;
    }
    hasilsigmaxy = 0;
    for (int i = 1; i <= banyak; i++)
    {
        hasilsigmaxy += hasil1[i];
    }

    //sigmax
    hasilsigmax = 0;
    for (int i = 1; i <= banyak; i++)
    {
        hasilsigmax += data[i].x;
    }

    //sigmaxpangkat2
    hasilsigmaxpangkat2 = 0;
    for (int i = 1; i <= banyak; i++)
    {
        hasilsigmaxpangkat2 += ((data[i].x)*(data[i].x));
    }

    //sigmaxdipangkat2
    hasilsigmaxdipangkat2 = hasilsigmax*hasilsigmax;


    //sigmay
    hasilsigmay = 0;
    for (int i = 1; i <= banyak; i++)
    {
        hasilsigmay += data[i].y;
    }

    //sigmaypangkat2
    hasilsigmaypangkat2 = 0;
    for (int i = 1; i <= banyak; i++)
    {
        hasilsigmaypangkat2 += ((data[i].y) * (data[i].y));
    }

    //sigmaydipangkat2
    hasilsigmaydipangkat2 = hasilsigmay * hasilsigmay;


    //hasil r
    hasil = ((banyak*hasilsigmaxy) - (hasilsigmax * hasilsigmay)) / (sqrt((banyak*hasilsigmaxpangkat2) - hasilsigmaxdipangkat2) * sqrt((banyak*hasilsigmaypangkat2) - hasilsigmaydipangkat2));
    

    //hasil koefisien determinasi
    hasilkoefisien = (hasil * hasil) * 100 / 100;

    //kekuatan hubungan korelasi
    if (0.00 <= hasil <= 0.09)
    {
        korelasi = "Hubungan korelasinya diabaikan";
    }
    else if (0.10 <= hasil <= 0.29)
    {
        korelasi = "Hubungan korelasi rendah";
    }
    else if (0.30 <= hasil <= 0.49)
    {
        korelasi = "Hubungan korelasi moderat";
    }
    else if (0.50 <= hasil <= 0.70)
    {
        korelasi = "Hubungan korelasi sedang";
    }
    else if (hasil > 0.70)
    {
        korelasi = "Hubungan korelasi sangat kuat";
    }

    //korelasi bernilai
    if (hasil > 0)
    {
        bernilai = "Hubungan antara variabel X dan Y adalah positif, dimana jika nilai X bertambah, maka nilai Y pun akan bertambah, dan juga sebaliknya";
    }
    else if (hasil < 0)
    {
        bernilai = "Hubungan antara variabel X dan Y adalah negatif, dimana jika nilai X bertambah, maka nilai Y akan mengecil, dan juga sebaliknya";
    }
    else if (hasil = 0)
    {
        bernilai = "Tidak ada hubungan antara variabel X dan Y";
    }

    

    //hasil
    cout << "a. nilai korelasi r adalah = " << hasil << endl;
    cout << endl;
    cout << "b. nilai koefisien determinasi adalah = " << hasilkoefisien << endl;
    cout << endl;
    cout << "c. kekuatan hubungan dari nilai korelasi (r) yang didapat, adalah = " << korelasi << endl;
    cout << "d. Nilai korelasi (r) bernilai ? " << endl;
    cout << "   Jawab : " << endl;
    cout << bernilai << endl;
    

    return 0;
}

 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
