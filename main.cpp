#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define MAX 10
double determ(double a[MAX][MAX], int n) {
	int  p, h, k, i, j;
	double temp[MAX][MAX];
	double det = 0;
	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
		return det;
	}
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = a[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + a[0][p] * pow(-1, p) * determ(temp, n - 1);
		}
		return det;
	}
}
void satirNorm(double mat[MAX][MAX], int n) {
	double sum1 = 0;
	int sayac1 = 0;
	int satir = 1;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			sum1 += mat[i][j] * mat[i][j];

			if (sayac1 == n - 1)
			{
				cout << "Matrisin " << satir << ". satir normu = " << sqrt(sum1) << endl;

				satir++;
				sayac1 = 0;
				sum1 = 0;
				break;

			}
			sayac1++;
		}
	}
}
void sutunNorm(double mat[MAX][MAX], int n) {
	double sum1 = 0;
	int sayac1 = 0;
	int sutun = 1;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			sum1 += mat[j][i] * mat[j][i];

			if (sayac1 == n - 1)
			{
				cout << "Matrisin " << sutun << ". sutun normu = " << sqrt(sum1) << endl;
				sutun++;
				sayac1 = 0;
				sum1 = 0;
				break;

			}
			sayac1++;
		}

	}

}
void ozDegerBul(double mat[MAX][MAX], int x,int y) {
	double a = 1, b, c, d, kok1, kok2, i, j;
	double e, z, g, h, k, l, m, n, p, r, s, t, u, x1, x2, x3;
	int durum, satir, sutun;

	
	
	if (x == 3 || x == 4 || x==5 || x== 6)
	{
		a = -1;
		b = mat[0][0] + mat[1][1] + mat[2][2];
		c = (mat[0][2] * mat[2][0]) + (mat[1][2] * mat[2][1]) + (mat[0][1] * mat[1][0]) - (mat[0][0] * mat[2][2]) - (mat[0][0] * mat[1][1]) - (mat[1][1] * mat[2][2]);
		d = (mat[1][0] * mat[2][1] * mat[0][2]) + (mat[2][0] * mat[0][1] * mat[1][2]) + (mat[0][1] * mat[1][1] * mat[2][2]) - (mat[0][2] * mat[1][1] * mat[2][0]) - (mat[0][0] * mat[1][2] * mat[2][1]) - (mat[0][1] * mat[1][0] * mat[2][2]);

		
		e = 2.7182818284590;

		z = ((3 * c / a) - (b * b / a * a)) / 3;

		g = ((2 * b * b * b / a * a * a) - (9 * b * c / a * a) + (27 * d / a)) / 27;

		h = (g * g / 4) + (z * z * z / 27);

		i = sqrt(((g * g / 4) - h));

		j = exp(log10(i) / log10(e) / 3);

		k = acos((-1) * (g / (2 * i)));

		l = j * (-1);

		m = cos(k / 3);

		n = sqrt(3) * sin(k / 3);

		p = (b / 3 * a) * (-1);

		r = (-1) * (g / 2) + sqrt(h);

		s = exp(log10(r) / log10(e) / 3);

		t = (-1) * (g / 2) - sqrt(h);

		u = exp(log10(t) / log10(e) / 3);

		if (h > 0)
			durum = 1;

		if (h <= 0)
			durum = 3;

		if ((z == 0) && (g == 0) && (h == 0))
			durum = 2;
		switch (durum)
		{

	

		case 3:

			printf("Matrisin ozdegerleri:\n");
			x1 = 2 * j * cos(k / 3) - (b / 3 * a);

			x2 = l * (m + n) + p;

			x3 = l * (m - n) + p;

			cout << "  x1: "<<  x1 <<"  x2:  "<< x2 << "  x3: "<< x3;
			
			
			break;

		}
	}

}
double oklidNorm(double mat[MAX][MAX], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += mat[i][j] * mat[i][j];
	return sqrt(sum);

}
double izBul(double mat[MAX][MAX], int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += mat[i][j] * mat[i][j];

	return sum;

}
void oklidEsitMiize(double mat[MAX][MAX], int n) {
	double oklid = oklidNorm(mat, n);

	double iz = izBul(mat, n);
	if (oklid == sqrt(iz))
	{
		cout << "N(A)=(iz(ATA))^(1/2) oldugunun saglamasi: "
			<< " Oklid norm = " << oklid
			<< " (iz(ATA))^(1/2) = " << sqrt(iz)
			<< " Birbirine esittir .";
	}
}
// determinantý satir normlarinin carpimina boldugunde sonuc
// 10^-2 den kucuk ise kararsýz buyuk ise kararli matristir.
void hadamardYorumlama(double mat[MAX][MAX], int n) {
	double det = determ(mat, n);

	// satir normlarinin carpimi bulma
	double sum1 = 0;
	int sayac1 = 0;
	double satirNorm = 0;
	double temp = 1;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			sum1 += mat[i][j] * mat[i][j];

			if (sayac1 == n - 1)
			{
				satirNorm = sqrt(sum1);
				temp = temp * satirNorm;


				sayac1 = 0;
				sum1 = 0;
				break;

			}
			sayac1++;
		}
	}
	double sonuc = det / temp;
	cout << "Matrisin Hadamard Sart Sayisi : " << sonuc << endl;

	if (sonuc < 0.01)
	{
		cout << "Hadamard Sonucu= " << sonuc << ", sonuc 10^-2 den kucuk oldugu icin kararsiz bir matristir. " << endl;
	}
	else
		cout << "Hadamard Sonucu= " << sonuc << ", sonuc 10^-2 den buyuk oldugu icin kararli bir matristir. " << endl;

}
// girilen matrisin her deðerinin öklid normuna bölümü
void normlastirma(double mat[MAX][MAX], int n) {
	double oNorm = oklidNorm(mat, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << " " << mat[i][j] / oNorm;
		}
		cout << endl;
	}
	cout << endl
		<< "Normlastirma islemi tamamlandi." << endl;

}
void gaus_jordan_inverse(double mat[MAX][MAX], int n) {
	double x[MAX], d;
	int i, j, k;


	cout << setprecision(3) << fixed;

	


	cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : " << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			
			cin >> mat[i][j];
		}
	}
	

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				mat[i][j + n] = 1;
			}
			else
			{
				mat[i][j + n] = 0;
			}
		}
	}


	for (i = 1; i <= n; i++)
	{
		if (mat[i][i] == 0.0)
		{
			cout << "Hata! Lütfen Degerlerinizi Kontrol Ediniz.";
			exit(0);
		}
		for (j = 1; j <= n; j++)
		{
			if (i != j)
			{
				d = mat[j][i] / mat[i][i];
				for (k = 1; k <= 2 * n; k++)
				{
					mat[j][k] = mat[j][k] - d * mat[i][k];
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = n + 1; j <= 2 * n; j++)
		{
			mat[i][j] = mat[i][j] / mat[i][i];
		}
	}
	/* Displaying Inverse Matrix */
	cout << endl << "Girilen Matrisin Tersi:" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = n + 1; j <= 2 * n; j++)
		{
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

void display(int matris[MAX][MAX], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << " " << matris[i][j];
		cout << endl;
	}


}
void Switch(char choice, double matris[MAX][MAX]) {
	int boyut;
	switch (choice)
	{

	case 'a':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		cout << "Matrisin determinant sonucu : " << determ(matris, boyut) << endl;
		break;

	case 'b':

		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		cout << "Matrisin izinin sonucu : " << izBul(matris, boyut) << endl;
		break;

	case 'c':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		satirNorm(matris, boyut); cout << endl;
		break;

	case 'd':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		sutunNorm(matris, boyut);

		break;

	case 'e':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		cout << "Matrisin Oklid Norm sonucu : " << oklidNorm(matris, boyut) << endl;
		break;

	case 'f':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		oklidEsitMiize(matris, boyut);
		break;

	case 'g':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		cout << "Normlastirilmis matris : " << endl;
		normlastirma(matris, boyut);
		break;

	case 'h':
		cout << "Lutfen kare matrisin Nxn boyutunu tek bir rakam ile giriniz : ";
		cin >> boyut;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		hadamardYorumlama(matris, boyut);
		break;

	case 'i':
		cout << " Matrisin Boyutunu Giriniz: ";
		cin >> boyut;
		gaus_jordan_inverse(matris, boyut);
		break;

	case 'k':
		cout << "Lutfen kare matrisin Nxn boyutunu 2 rakam ile giriniz : ";
		cin >> boyut;
		cout << "Bir diger boyut : ";
		int y;
		cin >> y;
		while (boyut > 10)
		{
			cout << "Lutfen 10'dan kucuk bir boyut giriniz.";
			cin >> boyut;
		}

		cout << "Kare Matrisin elemanlarini sirasi ile alt alta giriniz : ";
		for (int i = 0; i < boyut; i++)
		{
			for (int j = 0; j < boyut; j++)
				cin >> matris[i][j];
		}
		ozDegerBul(matris, boyut,y);
		break;

	case 'q':
		cout << "Iyi gunler dilerim.. Hoscakalin";
		exit(0);
	}
}


int main()
{
	char choice;
	double m[MAX][MAX];
	

	while (true)
	{
		cout << endl<<endl<<"GEO231 Sayisal analiz butunleme odevi" << endl << endl;
		cout << "Lutfen seciminizi yapiniz..\n" <<endl;
		cout << "Bir matrisin determinantini hesaplamak icin 'a' tusuna basiniz.\n";
		cout << "Bir matrisin izini hesaplamak icin 'b' tusuna basiniz.\n";
		cout << "Bir matrisin Satir normlarini hesaplamak icin 'c' tusuna basiniz.\n";
		cout << "Bir matrisin Sutun normlarini hesaplamak icin 'd' tusuna basiniz.\n";
		cout << "Bir matrisin Oklid normunu (N(A)) hesaplamak icin 'e' tusuna basiniz.\n";
		cout << "Bir matrisin N(A)=(iz(ATA))^(1/2) oldugunun saglamasini yapmak icin 'f' tusuna basiniz.\n";
		cout << "Bir matrisi Oklid normuna gore normlastirmak icin 'g' tusuna basiniz.\n";
		cout << "Bir matrisin Hadamard sart sayisini hesaplayarak kararsizligini yorumlamak icin 'h' tusuna basiniz.\n";
		cout << "Bir matrisin tersini hesaplamak icin 'i' tusuna basiniz.\n";
		cout << "Bir matrisin Ozdegerlerini hesaplamak icin 'k' tusuna basiniz.\n";
		cout <<endl<< "Programi sonlandirmak icin 'q' tusuna basiniz..!!\n";
		cin >> choice;

		Switch(choice, m);


	}

	return 0;
}

