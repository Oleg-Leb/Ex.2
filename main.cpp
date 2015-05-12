#define _CRT_SECURE_NO_WARNINGS
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "md5.cpp"
#include <Windows.h>
using namespace std;
using namespace boost::filesystem;
void search(path dir_path)
{
	ofstream f("AbFiles.tsv");
	if (is_directory(dir_path) && exists(dir_path))
	{

		recursive_directory_iterator end;
		for (recursive_directory_iterator it(dir_path); it != end; ++it)
			if (is_regular_file(it->path()))
			{

				stringstream result;
				string a;
				ifstream myfile;
				myfile.open(it->path().string(), ios::binary);
				result << myfile.rdbuf();
				a = result.str();
				f << it->path().filename().string() << "\n" << it->path() << "\n" << file_size(it->path()) << "\n" << md5(a) << endl;
				f << endl;
			}
	}
	else
	{
		cout << dir_path << " does not exist\n";
	}


	f.close();
	return;
};

int main(int argc, char* argv[1])
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Enter the directory path:\n" << std::endl;
	string dir_path;
	cin >> dir_path;
	search(dir_path);
	system("pause");
	return 0;
}
