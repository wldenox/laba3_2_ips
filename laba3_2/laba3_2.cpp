#include <iostream>
#include <fstream>

using namespace std;

bool checkValidInput(double value) {
	if (cin.fail()) {
		cin.clear();
		throw "Invalid input";
	}
	return true;
}


bool CheckValidParams(double& a, double& b, double& h, int& n) {
	ofstream fout("cppstudio.txt");
	
	

	if (h <= 0 && a > b && n < 2) {
		fout << "Error: h is less than or equal to 0 and a is greater than b or n < 2." << endl;

		throw "Error_Incorect_Data";
		return false;
		
	}

	else if (a > b || h <= 0 || n < 2) {
		fout << "Error: a is greater than b or h is less than or equal to 0 or n < 2." << endl;
		throw "Error_Incorect_Data";
		return false;
	}

	else {

		return true;
	}
}


double solve(double a, int n)
{
	double s;

	double  y;



	if (a <= 0)
	{
		if (n < 1) {
			return 0;
		}
		else {
			y = 1;
			for (int i = 0; i <= n; i++) {



				y *= (i * i - a);


			}

			y = y + a;

		}
	}
	else {
		if (n < 2) {

			return 0;
		}
		else
		{
			y = 0;
			s = 0;

			for (int i = 1; i <= n; i++) {



				for (int j = 0; j <= n; j++) {
					if ((i + j) == 0) {
						continue;
					}
					else {

						s += (a) / (i + j);

					}


				}
				y += s;
			}
		}
	}

	return y;
}


void osn_for_(double a, int n, double b, double h) {
	
	ofstream fout("cppstudio.txt");

	int l;

	for (a; a <= b; a += h)
	{

		cout << "Вот тут X = " << a <<"\t" << endl;

		cout << "Вот тут Y = " << solve(a, n) << "\t" << endl;
		
		cout << "Бажаєте зберігти данні?(1-Yes / 0 - NO)" << endl;

		cin>> l;

		switch (l){
		case(1):
			fout << "Вот тут X = " << a << endl;
			fout << "Вот тут Y = " << solve(a, n) << endl;
		case(0):
			cout << "Принято, продовжуємо далі"<<endl;

		
		
	}
}
	
}


int main() {
	setlocale(LC_ALL, "RU");
	double a, b, h; int n;
	
	

	try{
		cout << "Введите a , b , h ,n :  " << endl;

		cin >> a;
		checkValidInput(a);

		cin >> b;


		checkValidInput(b);

		cin >> h;

		checkValidInput(h);
		cin >> n;
		checkValidInput(n);

		if (CheckValidParams(a, b, h, n) == false) {

		cout << "У вас что то не так , попробуйте еще раз" << endl;
		return main();

	}
	else {

		cout << "Данные были приняты ожидайте" << endl;

		osn_for_(a, n, b, h);


		return 0;
		}
	}

	catch (const char* ex) {
		cout << ex << endl;
		return -1;
	}
	catch (...) {
		cout << "Unknown error" << endl;
		return -2;
	}

}







