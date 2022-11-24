#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	cout << "Please input your commit: \n";
	string commit;
	string command;
	cin >> commit;

	system("hexo cl && hexo g && hexo d");

	system("git add .");
	command = "git commit -m \'" + commit + "\'";
	system(command.c_str());
	system("git push");

	return 0;
}